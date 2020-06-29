#include "xmlcontroller.h"
#include <QFile>

XmlController::XmlController(Controller *c) : controller(c) {}

//Salvataggio su xml
void XmlController::save(QString path) const{
    QFile file(path);
    file.open(QFile::WriteOnly); //Apro in scrittura
    QXmlStreamWriter out(&file); //Creo lo stream xml
    out.setAutoFormatting(true);

    out.writeStartDocument();
    out.writeStartElement("qtrips"); //QTrips è la tag principale

    //Ciclo le note e le salvo
    for(unsigned int i=0; i<controller->getTrips().getSize(); i++){
        out.writeStartElement("trip"); //Start trip

        switch (controller->trip(i)->type()){
        case Type::carTrip:
            out.writeAttribute("type", "car");
            out.writeTextElement("titolo", QString::fromStdString(controller->trip(i)->getTitolo())); //titolo
            out.writeTextElement("partenza", QString::fromStdString(controller->trip(i)->getPartenza())); //partenza
            out.writeTextElement("arrivo", QString::fromStdString(controller->trip(i)->getArrivo())); //arrivo
            out.writeTextElement("data", controller->trip(i)->getData().toString()); //data
            out.writeTextElement("distanza", QString::number(controller->trip(i)->getKM())); //distanza
            out.writeTextElement("durata", QString::number(controller->trip(i)->getDurata())); //durata
            out.writeTextElement("carburante", getUsedFuel(dynamic_cast<qTripCar*>(controller->trip(i))->getFuel()));
            break;
        case Type::bikeTrip:
            out.writeAttribute("type", "bike");
            out.writeTextElement("titolo", QString::fromStdString(controller->trip(i)->getTitolo())); //titolo
            out.writeTextElement("partenza", QString::fromStdString(controller->trip(i)->getPartenza())); //partenza
            out.writeTextElement("arrivo", QString::fromStdString(controller->trip(i)->getArrivo())); //arrivo
            out.writeTextElement("data", controller->trip(i)->getData().toString()); //data
            out.writeTextElement("distanza", QString::number(controller->trip(i)->getKM())); //distanza
            out.writeTextElement("durata", QString::number(controller->trip(i)->getDurata())); //durata
            out.writeTextElement("calorie", QString::number(dynamic_cast<qTripBike*>(controller->trip(i))->getCalories()));
            break;
        case Type::trainTrip:
            out.writeAttribute("type", "train");
            out.writeTextElement("titolo", QString::fromStdString(controller->trip(i)->getTitolo())); //titolo
            out.writeTextElement("partenza", QString::fromStdString(controller->trip(i)->getPartenza())); //partenza
            out.writeTextElement("arrivo", QString::fromStdString(controller->trip(i)->getArrivo())); //arrivo
            out.writeTextElement("data", controller->trip(i)->getData().toString()); //data
            out.writeTextElement("distanza", QString::number(controller->trip(i)->getKM())); //distanza
            out.writeTextElement("durata", QString::number(controller->trip(i)->getDurata())); //durata
            out.writeTextElement("tipologia", dynamic_cast<qTripTrain*>(controller->trip(i))->getAltaVel() == Train::highVel ? "Alta Velocita" : "Regionale");
            break;
        case Type::footTrip:
            out.writeAttribute("type", "foot");
            out.writeTextElement("titolo", QString::fromStdString(controller->trip(i)->getTitolo())); //titolo
            out.writeTextElement("partenza", QString::fromStdString(controller->trip(i)->getPartenza())); //partenza
            out.writeTextElement("arrivo", QString::fromStdString(controller->trip(i)->getArrivo())); //arrivo
            out.writeTextElement("data", controller->trip(i)->getData().toString()); //data
            out.writeTextElement("distanza", QString::number(controller->trip(i)->getKM())); //distanza
            out.writeTextElement("durata", QString::number(controller->trip(i)->getDurata())); //durata
            out.writeTextElement("tipologia", dynamic_cast<qTripFoot*>(controller->trip(i))->getTipologia() == Walk::walk  ? "Camminata" : "Corsa");
            break;
        case Type::mixedTrip:
            out.writeAttribute("type", "mixed");
            out.writeTextElement("titolo", QString::fromStdString(controller->trip(i)->getTitolo())); //titolo
            out.writeTextElement("partenza", QString::fromStdString(controller->trip(i)->getPartenza())); //partenza
            out.writeTextElement("arrivo", QString::fromStdString(controller->trip(i)->getArrivo())); //arrivo
            out.writeTextElement("data", controller->trip(i)->getData().toString()); //data
            out.writeTextElement("distanza", QString::number(controller->trip(i)->getKM())); //distanza
            out.writeTextElement("durata", QString::number(controller->trip(i)->getDurata())); //durata
            out.writeTextElement("tipologia", dynamic_cast<qTripMixed*>(controller->trip(i))->getTipologia() == Walk::walk  ? "Camminata" : "Corsa");
            out.writeTextElement("carburante", getUsedFuel(dynamic_cast<qTripMixed*>(controller->trip(i))->getFuel()));
            break;
        }
        out.writeEndElement(); //Termino trip
    }
    out.writeEndElement(); //Termino qtrips
    out.writeEndDocument(); //Termino il documento
    file.close(); //Chiudo il file
}

void XmlController::load(QString path) const {
    QFile file(path);
    file.open(QFile::ReadOnly); //Apro il File in Lettura
    QXmlStreamReader in(&file);

    in.readNextStartElement(); //Leggo il primo tag
    if(in.name() == "qtrips"){
        while(in.readNextStartElement()){
            if(in.name() == "trip"){
                QString type;
                if(in.attributes().hasAttribute("type")) type = in.attributes().value("type").toString();

                in.readNextStartElement();
                QString titolo;
                if(in.name() == "titolo") titolo = in.readElementText();

                in.readNextStartElement();
                QString partenza;
                if(in.name() == "partenza") partenza = in.readElementText();

                in.readNextStartElement();
                QString arrivo;
                if(in.name() == "arrivo") arrivo = in.readElementText();

                in.readNextStartElement();
                QDate data;
                if(in.name() == "data") data = QDate::fromString(in.readElementText());

                in.readNextStartElement();
                double distanza = 0.1; //Valore di default
                if(in.name() == "distanza") distanza = in.readElementText().toDouble();

                in.readNextStartElement();
                unsigned int durata = 1; //Valore di default
                if(in.name() == "durata") durata = static_cast<unsigned int>(in.readElementText().toInt());

                in.readNextStartElement();
                qTripAbstract* temp = nullptr;

                if(type == "car"){
                    Fuel carburante = Fuel::petrol;
                    QString aux;
                    if(in.name() == "carburante") aux = in.readElementText();
                    if(aux == "Benzina") carburante = Fuel::petrol;
                    else if(aux == "Diesel") carburante = Fuel::diesel;
                    else if(aux == "Metano") carburante = Fuel::methane;
                    else if(aux == "Elettrica") carburante = Fuel::electric;

                    temp = new qTripCar(titolo.toStdString(), partenza.toStdString(), arrivo.toStdString(), distanza, data, durata, carburante);
                }else if(type == "train"){
                    Train tipologia = Train::highVel;
                    QString aux;
                    if(in.name() == "tipologia") aux = in.readElementText();
                    if(aux == "Alta Velocita") tipologia = Train::highVel;
                    else if(aux == "Regionale") tipologia = Train::regional;

                    temp = new qTripTrain(titolo.toStdString(), partenza.toStdString(), arrivo.toStdString(), distanza, data, durata, tipologia);
                }else if(type == "bike"){
                    double calorie = 300;
                    if(in.name() == "calorie") calorie = in.readElementText().toDouble();

                    temp = new qTripBike(titolo.toStdString(), partenza.toStdString(), arrivo.toStdString(), distanza, data, durata, calorie);
                } else if (type == "foot") {
                    Walk tipologia = Walk::walk;
                    QString aux;
                    if(in.name() == "tipologia") aux = in.readElementText();
                    if(aux == "Camminata") tipologia = Walk::walk;
                    else if(aux == "Corsa") tipologia = Walk::run;

                    temp = new qTripFoot(titolo.toStdString(), partenza.toStdString(), arrivo.toStdString(), distanza, data, durata, tipologia);
                } else if (type == "mixed") {
                    Walk tipologia = Walk::walk;
                    Fuel carburante = Fuel::petrol;
                    QString aux;
                    if(in.name() == "tipologia") aux = in.readElementText();
                    if(aux == "Camminata") tipologia = Walk::walk;
                    else if(aux == "Corsa") tipologia = Walk::run;

                    in.readNextStartElement();

                    if(in.name() == "carburante") aux = in.readElementText();
                    if(aux == "Benzina") carburante = Fuel::petrol;
                    else if(aux == "Diesel") carburante = Fuel::diesel;
                    else if(aux == "Metano") carburante = Fuel::methane;
                    else if(aux == "Elettrica") carburante = Fuel::electric;

                    temp = new qTripMixed(titolo.toStdString(), partenza.toStdString(), arrivo.toStdString(), distanza, data, durata, tipologia, carburante);
                }else in.skipCurrentElement(); //In caso sia sconosciuto

                if(temp != nullptr) controller->add(temp);
                in.readNextStartElement();
            }
            else in.skipCurrentElement(); //Se l'elemento non è di tipo trip
        }
    }

    file.close(); //Chiudo il file
}

QString XmlController::getUsedFuel(Fuel f) const {
    switch(f) {
    case Fuel::diesel:
        return "Diesel";
    case Fuel::petrol:
        return "Benzina";
    case Fuel::methane:
        return "Metano";
    case Fuel::electric:
        return "Elettrica";
    }
    return "Benzina";
}
