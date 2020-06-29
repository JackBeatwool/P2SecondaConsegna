#include "edittripdialog.h"

EditTripDialog::EditTripDialog(qTripAbstract* n, unsigned int t): trip(n), tipo(t){
    setFixedSize(600,500);

    //Layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* gridLayout = new QGridLayout();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->setAlignment(Qt::AlignRight);

    //TitleLayout
    QLabel* titleLabel = new QLabel("Titolo:");
    titleEdit = new QLineEdit();
    titleEdit->setText(QString::fromStdString(trip->getTitolo()));
    gridLayout->addWidget(titleLabel, 0, 0);
    gridLayout->addWidget(titleEdit, 0, 1);

    //PartenzaLayout
    QLabel* partenzaLabel = new QLabel("Partenza:");
    partenzaEdit = new QLineEdit();
    partenzaEdit->setText(QString::fromStdString(trip->getPartenza()));
    gridLayout->addWidget(partenzaLabel, 1, 0);
    gridLayout->addWidget(partenzaEdit, 1, 1);

    //ArrivoLayout
    QLabel* arrivoLabel = new QLabel("Arrivo:");
    arrivoEdit = new QLineEdit();
    arrivoEdit->setText(QString::fromStdString(trip->getArrivo()));
    gridLayout->addWidget(arrivoLabel, 2, 0);
    gridLayout->addWidget(arrivoEdit, 2, 1);

    //KmLayout
    QLabel* kmLabel = new QLabel("Distanza Percorsa:");
    kmEdit = new QLineEdit();
    kmEdit->setText(QString::number(trip->getKM()));
    QLabel* kmLbl = new QLabel("km");
    QHBoxLayout* kmEditLayout = new QHBoxLayout();
    kmEditLayout->addWidget(kmEdit);
    kmEditLayout->addWidget(kmLbl);
    gridLayout->addWidget(kmLabel, 3, 0);
    gridLayout->addLayout(kmEditLayout, 3, 1);

    //DataLayout
    QLabel* dataLabel = new QLabel("Data:");
    dataEdit = new QCalendarWidget();
    dataEdit->setSelectedDate(trip->getData());
    gridLayout->addWidget(dataLabel, 4, 0);
    gridLayout->addWidget(dataEdit, 4, 1);

    //DurataLayout
    QLabel* durataLabel = new QLabel("Durata:");
    durataSecEdit = new QLineEdit();
    durataSecEdit->setText(QString::number(trip->getDurataSec()));
    QLabel* secLbl = new QLabel("sec");
    durataMinEdit = new QLineEdit();
    durataMinEdit->setText(QString::number(trip->getDurataMin()));
    QLabel* minLbl = new QLabel("min    ");
    durataOreEdit = new QLineEdit();
    durataOreEdit->setText(QString::number(trip->getDurataOre()));
    QLabel* oreLbl = new QLabel("ore    ");
    QHBoxLayout* editDurataLayout = new QHBoxLayout();
    editDurataLayout->addWidget(durataOreEdit);
    editDurataLayout->addWidget(oreLbl);
    editDurataLayout->addWidget(durataMinEdit);
    editDurataLayout->addWidget(minLbl);
    editDurataLayout->addWidget(durataSecEdit);
    editDurataLayout->addWidget(secLbl);
    gridLayout->addWidget(durataLabel, 5, 0);
    gridLayout->addLayout(editDurataLayout, 5, 1);

    mainLayout->addLayout(gridLayout);

    QGroupBox* groupBox = new QGroupBox();
    QVBoxLayout* typeSpecificLayout = new QVBoxLayout();
    switch(tipo)
    {
    case 0: //Car
        benzina = new QRadioButton("Benzina");
        diesel = new QRadioButton("Diesel");
        metano = new QRadioButton("Metano");
        elettrica = new QRadioButton("Elettrica");
        if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::diesel) diesel->setChecked(true);
        else if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::petrol) benzina->setChecked(true);
        else if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::methane) metano->setChecked(true);
        else if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::electric) elettrica->setChecked(true);
        typeSpecificLayout->addWidget(benzina);
        typeSpecificLayout->addWidget(diesel);
        typeSpecificLayout->addWidget(metano);
        typeSpecificLayout->addWidget(elettrica);
        groupBox->setTitle("Tipo di carburante");
        groupBox->setLayout(typeSpecificLayout);
        break;
    case 1: //Train
        altaVel = new QRadioButton("Alta Velocità");
        lowVel = new QRadioButton("Regolare");
        dynamic_cast<qTripTrain*>(trip)->getAltaVel() == Train::highVel ? altaVel->setChecked(true) : lowVel->setChecked(true);
        typeSpecificLayout->addWidget(altaVel);
        typeSpecificLayout->addWidget(lowVel);
        groupBox->setTitle("Tipo di treno");
        groupBox->setLayout(typeSpecificLayout);
        break;
    case 2:
        calorieEdit = new QLineEdit();
        calorieEdit->setText(QString::number(dynamic_cast<qTripBike*>(trip)->getCalories()));
        typeSpecificLayout->addWidget(calorieEdit);
        groupBox->setTitle("Attività effettuata");
        groupBox->setLayout(typeSpecificLayout);
        break;
    case 3:
        walk = new QRadioButton("Camminata");
        run = new QRadioButton("Corsa");
        dynamic_cast<qTripFoot*>(trip)->getTipologia() == Walk::walk ? walk->setChecked(true) : run->setChecked(true);
        typeSpecificLayout->addWidget(walk);
        typeSpecificLayout->addWidget(run);
        groupBox->setTitle("Calorie per ora");
        groupBox->setLayout(typeSpecificLayout);
        break;
    case 4:
        benzina = new QRadioButton("Benzina");
        diesel = new QRadioButton("Diesel");
        metano = new QRadioButton("Metano");
        elettrica = new QRadioButton("Elettrica");
        if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::diesel) diesel->setChecked(true);
        else if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::petrol) benzina->setChecked(true);
        else if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::methane) metano->setChecked(true);
        else if(dynamic_cast<qTripCar*>(trip)->getFuel() == Fuel::electric) elettrica->setChecked(true);
        walk = new QRadioButton("Camminata");
        run = new QRadioButton("Corsa");
        dynamic_cast<qTripMixed*>(trip)->getTipologia() == Walk::walk ? walk->setChecked(true) : run->setChecked(true);
        QVBoxLayout* mixedButtonLayoutLeft = new QVBoxLayout();
        QVBoxLayout* mixedButtonLayoutRight = new QVBoxLayout();
        mixedButtonLayoutLeft->addWidget(benzina);
        mixedButtonLayoutLeft->addWidget(diesel);
        mixedButtonLayoutLeft->addWidget(metano);
        mixedButtonLayoutLeft->addWidget(elettrica);
        mixedButtonLayoutRight->addWidget(walk);
        mixedButtonLayoutRight->addWidget(run);
        QGroupBox* leftMixedGroupBox = new QGroupBox(tr("Tipo di carburante"));
        leftMixedGroupBox->setLayout(mixedButtonLayoutLeft);
        QGroupBox* rightMixedGroupBox = new QGroupBox(tr("Attività effettuata"));
        rightMixedGroupBox->setLayout(mixedButtonLayoutRight);
        QHBoxLayout* mixedButtonLayout = new QHBoxLayout();
        mixedButtonLayout->addWidget(leftMixedGroupBox);
        mixedButtonLayout->addWidget(rightMixedGroupBox);
        groupBox->setLayout(mixedButtonLayout);
        break;
    }
    mainLayout->addWidget(groupBox);

    //Buttons
    QPushButton* okBtn = new QPushButton("Ok");
    QPushButton* cancBtn = new QPushButton("Cancella");
    buttonsLayout->addWidget(okBtn);
    buttonsLayout->addWidget(cancBtn);
    mainLayout->addLayout(buttonsLayout);
    connect(okBtn, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(cancBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

qTripAbstract* EditTripDialog::getTrip() {
    qTripAbstract* temp = nullptr; //Viaggio temporaneo da istanziare secondo il tipo di viaggio selezionato

    //Default values
    std::string t, p, a;
    double km;
    unsigned int sec, min, ore;

    titleEdit->text()!="" ? t = titleEdit->text().toStdString() : t = "Nuovo Viaggio";
    partenzaEdit->text()!="" ? p = partenzaEdit->text().toStdString() : p = "Partenza";
    arrivoEdit->text()!="" ? a = arrivoEdit->text().toStdString() : a = "Arrivo";
    kmEdit->text()!="" ? km = kmEdit->text().toDouble() : km = 0.1;
    durataSecEdit->text()!="" ? sec = static_cast<unsigned int>(durataSecEdit->text().toInt()) : sec = 0;
    durataMinEdit->text()!="" ? min = static_cast<unsigned int>(durataMinEdit->text().toInt()) : min = 0;
    durataOreEdit->text()!="" ? ore = static_cast<unsigned int>(durataOreEdit->text().toInt()) : ore = 1;

    switch(tipo) {
    case 0:
        temp = new qTripCar(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, getCurrentFuel());
        break;
    case 1:
        temp = new qTripTrain(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, altaVel->isChecked() ? Train::highVel : Train::regional);
        break;
    case 2:
        temp = new qTripBike(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, calorieEdit->text()!="" ? calorieEdit->text().toDouble() : 300);
        break;
    case 3:
        temp = new qTripFoot(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, walk->isChecked() ? Walk::walk : Walk::run);
        break;
    case 4:
        temp = new qTripMixed(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, walk->isChecked() ? Walk::walk : Walk::run, getCurrentFuel());
        break;
    default:
        temp = nullptr;
        break;
    }

    return temp;
}

Fuel EditTripDialog::getCurrentFuel() const
{
    if(benzina->isChecked()) return Fuel::petrol;
    else if(diesel->isChecked()) return Fuel::diesel;
    else if(metano->isChecked()) return Fuel::methane;
    else if(elettrica->isChecked()) return Fuel::electric;

    return Fuel::petrol;
}
