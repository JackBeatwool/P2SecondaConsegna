#include "controller.h"

Controller::Controller():
    trips(new qTravel), //Creo il modello
    view(new MainWindow(this)),  //Creo la View
    widgetList(tripVector<TripWidget*>()) { //Creo un contenitore per i viaggi

    view->show(); //Avvio la view
}

Controller::~Controller() {
    delete trips;
    delete view;
}

const tripVector<qTripAbstract*>& Controller::getTrips() const{
    return trips->getAllTrips();
}

qTripAbstract* Controller::trip(unsigned int i) {
    return trips->trip(i);
}

void Controller::add(qTripAbstract* n){
    unsigned int last_id = trips->getSize(); //Salvo l'indice dell'ultimo viaggio
    trips->add(n); //Aggiungo il viaggio al modello
    TripWidget* temp = new TripWidget(n, last_id, this);
    widgetList.push_back(temp);
    view->addTripWidget(temp);
}

void Controller::remove(unsigned int i, TripWidget* trip){
    trips->removeTrip(i); //Elimino dal modello
    widgetList.erase(i); //Elimino dalla lista di viaggi effettuati
    delete trip; //Elimino il widget dalla vista

    for (unsigned int j=i; j<trips->getSize(); j++) //Sposto gli indici delle note successive di 1
        widgetList[j]->setIndex(j);
}

void Controller::edit(qTripAbstract* toEdit, qTripAbstract* edited)
{
    for(unsigned int i=0;i<trips->getSize(); i++) {
        if (trip(i) == toEdit){
            trips->editTrip(edited, i);
        }
    }
}

void Controller::calcolo(){
    QMessageBox* result = new QMessageBox();
    double eur = 0, cal = 0, km = 0;

    for(unsigned int it=0; it<trips->getSize(); it++){
        km += trips->trip(it)->getKM();
        if (dynamic_cast<qTripMixed*>(trips->trip(it)))
        {
            qTripMixed* temp = dynamic_cast<qTripMixed*>(trips->trip(it));
            cal += temp->calcoloFoot();
            eur += temp->calcoloCar();
        }
        else if (dynamic_cast<qTripFoot*>(trips->trip(it)) || dynamic_cast<qTripBike*>(trips->trip(it)))
            cal += trips->trip(it)->calcolo();
        else
            eur += trips->trip(it)->calcolo();
    }

    QString s = "La stima del consumo effettuato con i viaggi registrati è di:\n\t" + QString::number(eur) + " €\n\nLa stima delle calorie consumate con i viaggi registrati è di:\n\t" + QString::number(cal) + " cal\n\nLa distanza percorsa totale è di:\n\t" + QString::number(km) + " km";
    result->setText(s);
    result->show();
}

void Controller::search(const QString& x){
    if(x==""){ //Visualizza tutti i viaggi
        for(unsigned int i=0; i<widgetList.getSize(); i++)
            widgetList[i]->setHidden(false);
    }
    else{
        QString a = x.toLower(); //Converto in minuscolo
        bool found;
        for(unsigned int i=0; i<trips->getSize(); i++){ //Ciclo tutti gli elementi
            QString titolo = QString::fromStdString(trip(i)->getTitolo()).toLower();
            found = titolo.contains(a); //Controllo il titolo

            //Se non presente nel titolo controllo Partenza e Arrivo
            if(!found){
                QString partenza = QString::fromStdString(trip(i)->getPartenza()).toLower();
                found = partenza.contains(a);
            }
            if(!found){
                QString arrivo = QString::fromStdString(trip(i)->getArrivo()).toLower();
                found = arrivo.contains(a);
            }

            //Se non è ancora presente confronto i campi numerici
            if(!found){
                QString data = trip(i)->getData().toString().toLower();
                found = data.contains(a);
            }
            if(!found){
                QString km = QString::number(trip(i)->getKM()) + " km";
                found = km.contains(a);
            }
            if(!found){
                QString durata = QString::number(trip(i)->getDurataOre()) + "h " + QString::number(trip(i)->getDurataMin()) + "m " + QString::number(trip(i)->getDurataSec()) + "s";
                found = durata.contains(a);
            }

            widgetList[i]->setHidden(!found); //Nascondo l'elemento se non viene trovato
        }
    }
}

void Controller::save(const QString& s){
    if(s!=""){
        XmlController x(this);
        x.save(s);
    }
}

void Controller::load(const QString& s){
    if(s!=""){
        XmlController x(this);
        x.load(s);
    }
}
