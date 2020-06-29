#include "tripwidget.h"
#include "controller.h"
#include "edittripdialog.h"
#include <QFile>

TripWidget::TripWidget(qTripAbstract* n, unsigned int i, Controller *c) : trip(n), index(i), contr(c){

    setObjectName("t_widget");

    QPalette p = palette();
    p.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(p);

    //Layouts
    QGridLayout* gridLayout = new QGridLayout(this);
    QVBoxLayout* btnLayout = new QVBoxLayout();

    QPushButton *deleteBtn = new QPushButton(this);
    deleteBtn->setObjectName("del_btn");
    deleteBtn->setFixedSize(20,20);
    deleteBtn->setIcon(QIcon(":/icons/del_btn"));
    deleteBtn->setCursor(Qt::PointingHandCursor);

    QPushButton *editBtn = new QPushButton(this);
    editBtn->setObjectName("edit_btn");
    editBtn->setFixedSize(20,20);
    editBtn->setIcon(QIcon(":/icons/edit_btn"));
    editBtn->setCursor(Qt::PointingHandCursor);

    titleLbl = new QLabel(QString::fromStdString(trip->getTitolo()));
    titleLbl->setObjectName("title_lbl");
    startLbl = new QLabel("Da: " + QString::fromStdString(trip->getPartenza()));
    endLbl = new QLabel("A: " + QString::fromStdString(trip->getArrivo()));
    kmLbl = new QLabel("KM percorsi: " + QString::number(trip->getKM()) + " km ");
    dataLbl = new QLabel("In data: " + trip->getData().toString());
    timeLbl = new QLabel(QString::number(trip->getDurataOre()) + "h " + QString::number(trip->getDurataMin()) + "m " + QString::number(trip->getDurataSec()) + "s ");

    btnLayout->addWidget(deleteBtn);
    btnLayout->addWidget(editBtn);

    gridLayout->addWidget(titleLbl, 0, 0);
    gridLayout->addLayout(btnLayout, 0, 2, Qt::AlignRight);
    gridLayout->setRowMinimumHeight(1,20);
    gridLayout->addWidget(startLbl, 2, 0);
    gridLayout->addWidget(endLbl, 3, 0);
    gridLayout->addWidget(dataLbl, 4, 0);
    gridLayout->setColumnStretch(1, 200);
    gridLayout->addWidget(kmLbl, 2, 2);
    gridLayout->addWidget(timeLbl, 3, 2);

    switch (trip->type()) {
    case Type::carTrip:
        carTrip(gridLayout);
        break;
    case Type::trainTrip:
        trainTrip(gridLayout);
        break;
    case Type::bikeTrip:
        bikeTrip(gridLayout);
        break;
    case Type::footTrip:
        footTrip(gridLayout);
        break;
    case Type::mixedTrip:
        mixedTrip(gridLayout);
        break;
    }

    //Connessioni
    connect(deleteBtn, &QPushButton::clicked, [this]{ contr->remove(index, this);});
    connect(editBtn, &QPushButton::clicked, [this]{ edit();});
}

void TripWidget::carTrip(QGridLayout* l) {
    qTripCar* temp_car = dynamic_cast<qTripCar*>(trip);
    switch(temp_car->getFuel())
    {
    case Fuel::petrol:
        carbLbl = new QLabel("Auto a Benzina");
        break;
    case Fuel::diesel:
        carbLbl = new QLabel("Auto a Diesel");
        break;
    case Fuel::methane:
        carbLbl = new QLabel("Auto a Metano");
        break;
    case Fuel::electric:
        carbLbl = new QLabel("Auto Elettrica");
        break;
    }
    l->addWidget(carbLbl, 4, 2);
    tipo = 0;
}

void TripWidget::trainTrip(QGridLayout* l) {
    qTripTrain* temp_train = dynamic_cast<qTripTrain*>(trip);
    temp_train->getAltaVel() == Train::highVel ? hvLbl = new QLabel("Treno ad Alta Velocità") : hvLbl = new QLabel("Treno Regolare");
    l->addWidget(hvLbl, 4, 2);
    tipo = 1;
}

void TripWidget::bikeTrip(QGridLayout* l) {
    qTripBike* temp_bike = dynamic_cast<qTripBike*>(trip);
    calLbl = new QLabel(QString::number(temp_bike->calcolo()) + " Calorie consumate");
    l->addWidget(calLbl, 4, 2);
    tipo = 2;
}

void TripWidget::footTrip(QGridLayout *l)
{
    qTripFoot* temp_foot = dynamic_cast<qTripFoot*>(trip);
    activityLbl = new QLabel(temp_foot->getTipologia() == Walk::walk ? "Camminata" : "Corsa");
    calLbl = new QLabel(QString::number(temp_foot->calcolo()) + " Calorie consumate");
    l->addWidget(activityLbl, 4, 2);
    l->addWidget(calLbl, 5, 2);
    tipo = 3;
}

void TripWidget::mixedTrip(QGridLayout *l)
{
    qTripMixed* temp_mixed = dynamic_cast<qTripMixed*>(trip);
    activityLbl = new QLabel(temp_mixed->getTipologia() == Walk::walk ? "Camminata" : "Corsa");
    calLbl = new QLabel(QString::number(temp_mixed->calcoloFoot()) + " Calorie consumate");
    l->addWidget(activityLbl, 4, 2);
    l->addWidget(calLbl, 5, 2);
    switch(temp_mixed->getFuel())
    {
    case Fuel::petrol:
        carbLbl = new QLabel("Auto a Benzina");
        break;
    case Fuel::diesel:
        carbLbl = new QLabel("Auto a Diesel");
        break;
    case Fuel::methane:
        carbLbl = new QLabel("Auto a Metano");
        break;
    case Fuel::electric:
        carbLbl = new QLabel("Auto Elettrica");
        break;
    }
    l->addWidget(carbLbl, 6, 2);
    tipo = 4;
}

//Modifica

void TripWidget::edit() {
    EditTripDialog* tripDialog = new EditTripDialog(trip, tipo); //Creo il tripDialog per modificare un viaggio
    tripDialog->setWindowTitle("Modifica viaggio");
    qTripAbstract* temp;
    if(tripDialog->exec() == QDialog::Accepted){
        temp = tripDialog->getTrip();
        contr->edit(trip, temp);
        trip = temp;
        titleLbl->setText(QString::fromStdString(trip->getTitolo()));
        titleLbl->setObjectName("title_lbl");
        startLbl->setText("Da: " + QString::fromStdString(trip->getPartenza()));
        endLbl->setText("A: " + QString::fromStdString(trip->getArrivo()));
        kmLbl->setText("KM percorsi: " + QString::number(trip->getKM()) + " km ");
        dataLbl->setText("In data: " + trip->getData().toString());
        timeLbl->setText(QString::number(trip->getDurataOre()) + "h " + QString::number(trip->getDurataMin()) + "m " + QString::number(trip->getDurataSec()) + "s ");
        if (tipo == 0){
            qTripCar* temp_car = dynamic_cast<qTripCar*>(trip);
            switch(temp_car->getFuel())
            {
            case Fuel::petrol:
                carbLbl->setText("Auto a Benzina");
                break;
            case Fuel::diesel:
                carbLbl->setText("Auto a Diesel");
                break;
            case Fuel::methane:
                carbLbl->setText("Auto a Metano");
                break;
            case Fuel::electric:
                carbLbl->setText("Auto Elettrica");
                break;
            }
        } else if(tipo == 1){
            qTripTrain* temp_train = dynamic_cast<qTripTrain*>(trip);
            temp_train->getAltaVel() == Train::highVel ? hvLbl->setText("Treno ad Alta Velocità") : hvLbl->setText("Treno Regolare");
        } else if(tipo == 2){
            qTripBike* temp_bike = dynamic_cast<qTripBike*>(trip);
            calLbl->setText(QString::number(temp_bike->calcolo()) + " Calorie consumate");
        } else if(tipo == 3){
            qTripFoot* temp_foot = dynamic_cast<qTripFoot*>(trip);
            activityLbl->setText(temp_foot->getTipologia() == Walk::walk ? "Camminata" : "Corsa");
            calLbl->setText(QString::number(temp_foot->calcolo()) + " Calorie consumate");
        } else if(tipo == 4){
            qTripMixed* temp_mixed = dynamic_cast<qTripMixed*>(trip);
            activityLbl->setText(temp_mixed->getTipologia() == Walk::walk ? "Camminata" : "Corsa");
            calLbl->setText(QString::number(temp_mixed->calcoloFoot()) + " Calorie consumate");
            switch(temp_mixed->getFuel())
            {
            case Fuel::petrol:
                carbLbl->setText("Auto a Benzina");
                break;
            case Fuel::diesel:
                carbLbl->setText("Auto a Diesel");
                break;
            case Fuel::methane:
                carbLbl->setText("Auto a Metano");
                break;
            case Fuel::electric:
                carbLbl->setText("Auto Elettrica");
                break;
            }
        }
    }
}

//Set e Get index

void TripWidget::setIndex(unsigned int newIndex) {
    index = newIndex;
}

unsigned int TripWidget::getIndex() const {
    return index;
}
