#include "newtripdialog.h"

NewTripDialog::NewTripDialog(): type(0){
    setFixedSize(650,550);

    //Layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* gridLayout = new QGridLayout();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->setAlignment(Qt::AlignRight);

    //TitleLayout
    QLabel* titleLabel = new QLabel("Titolo:");
    titleEdit = new QLineEdit();
    titleEdit->setPlaceholderText("Nuovo Viaggio");
    gridLayout->addWidget(titleLabel, 0, 0);
    gridLayout->addWidget(titleEdit, 0, 1);

    //PartenzaLayout
    QLabel* partenzaLabel = new QLabel("Partenza:");
    partenzaEdit = new QLineEdit();
    partenzaEdit->setPlaceholderText("Partenza");
    gridLayout->addWidget(partenzaLabel, 1, 0);
    gridLayout->addWidget(partenzaEdit, 1, 1);

    //ArrivoLayout
    QLabel* arrivoLabel = new QLabel("Arrivo:");
    arrivoEdit = new QLineEdit();
    arrivoEdit->setPlaceholderText("Arrivo");
    gridLayout->addWidget(arrivoLabel, 2, 0);
    gridLayout->addWidget(arrivoEdit, 2, 1);

    //KmLayout
    QLabel* kmLabel = new QLabel("Distanza Percorsa:");
    kmEdit = new QLineEdit();
    kmEdit->setPlaceholderText("0.1");
    QLabel* kmLbl = new QLabel("km");
    QHBoxLayout* kmEditLayout = new QHBoxLayout();
    kmEditLayout->addWidget(kmEdit);
    kmEditLayout->addWidget(kmLbl);
    gridLayout->addWidget(kmLabel, 3, 0);
    gridLayout->addLayout(kmEditLayout, 3, 1);

    //DataLayout
    QLabel* dataLabel = new QLabel("Data:");
    dataEdit = new QCalendarWidget();
    gridLayout->addWidget(dataLabel, 4, 0);
    gridLayout->addWidget(dataEdit, 4, 1);

    //DurataLayout
    QLabel* durataLabel = new QLabel("Durata:");
    durataSecEdit = new QLineEdit();
    durataSecEdit->setPlaceholderText("0");
    QLabel* secLbl = new QLabel("sec");
    durataMinEdit = new QLineEdit();
    durataMinEdit->setPlaceholderText("0");
    QLabel* minLbl = new QLabel("min    ");
    durataOreEdit = new QLineEdit();
    durataOreEdit->setPlaceholderText("1");
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

    //Edits
    calorieEdit = new QLineEdit();
    calorieEdit->setPlaceholderText("300");

    //GroupBoxes
    benzinaCar = new QRadioButton("Benzina");
    dieselCar = new QRadioButton("Diesel");
    metanoCar = new QRadioButton("Metano");
    elettricaCar = new QRadioButton("Elettrica");
    benzinaCar->setChecked(true);
    QVBoxLayout* carButtonLayout = new QVBoxLayout();
    carButtonLayout->addWidget(benzinaCar);
    carButtonLayout->addWidget(dieselCar);
    carButtonLayout->addWidget(metanoCar);
    carButtonLayout->addWidget(elettricaCar);
    QGroupBox* carGroupBox = new QGroupBox(tr("Tipo di carburante"));
    carGroupBox->setLayout(carButtonLayout);

    //_______________________________________________________________________

    altaVel = new QRadioButton("Alta Velocità");
    lowVel = new QRadioButton("Regolare");
    altaVel->setChecked(true);
    QVBoxLayout* trainButtonLayout = new QVBoxLayout();
    trainButtonLayout->addWidget(altaVel);
    trainButtonLayout->addWidget(lowVel);
    QGroupBox* trainGroupBox = new QGroupBox(tr("Tipo di treno"));
    trainGroupBox->setLayout(trainButtonLayout);

    //_______________________________________________________________________

    QVBoxLayout* bikeVLayout = new QVBoxLayout();
    bikeVLayout->addWidget(calorieEdit);
    QGroupBox* bikeGroupBox = new QGroupBox(tr("Calorie per ora"));
    bikeGroupBox->setLayout(bikeVLayout);

    //_______________________________________________________________________

    walkFoot = new QRadioButton("Camminata");
    runFoot = new QRadioButton("Corsa");
    walkFoot->setChecked(true);
    QVBoxLayout* footButtonLayout = new QVBoxLayout();
    footButtonLayout->addWidget(walkFoot);
    footButtonLayout->addWidget(runFoot);
    QGroupBox* footGroupBox = new QGroupBox(tr("Attività effettuata"));
    footGroupBox->setLayout(footButtonLayout);

    //_______________________________________________________________________

    benzinaMixed = new QRadioButton("Benzina");
    dieselMixed = new QRadioButton("Diesel");
    metanoMixed = new QRadioButton("Metano");
    elettricaMixed = new QRadioButton("Elettrica");
    benzinaMixed->setChecked(true);
    walkMixed = new QRadioButton("Camminata");
    runMixed = new QRadioButton("Corsa");
    walkMixed->setChecked(true);
    QVBoxLayout* mixedButtonLayoutLeft = new QVBoxLayout();
    QVBoxLayout* mixedButtonLayoutRight = new QVBoxLayout();
    mixedButtonLayoutLeft->addWidget(benzinaMixed);
    mixedButtonLayoutLeft->addWidget(dieselMixed);
    mixedButtonLayoutLeft->addWidget(metanoMixed);
    mixedButtonLayoutLeft->addWidget(elettricaMixed);
    mixedButtonLayoutRight->addWidget(walkMixed);
    mixedButtonLayoutRight->addWidget(runMixed);
    QGroupBox* leftMixedGroupBox = new QGroupBox(tr("Tipo di carburante"));
    leftMixedGroupBox->setLayout(mixedButtonLayoutLeft);
    QGroupBox* rightMixedGroupBox = new QGroupBox(tr("Attività effettuata"));
    rightMixedGroupBox->setLayout(mixedButtonLayoutRight);

    //Car Tab
    QWidget* carPageWidget = new QWidget;
    QVBoxLayout* carLayout = new QVBoxLayout();
    carLayout->addWidget(carGroupBox);
    carPageWidget->setLayout(carLayout);

    //Train Tab
    QWidget* trainPageWidget = new QWidget;
    QVBoxLayout* trainLayout = new QVBoxLayout();
    trainLayout->addWidget(trainGroupBox);
    trainPageWidget->setLayout(trainLayout);

    //Bike Tab
    QWidget* bikePageWidget = new QWidget;
    QVBoxLayout* bikeLayout = new QVBoxLayout();
    bikeLayout->addWidget(bikeGroupBox);
    bikePageWidget->setLayout(bikeLayout);

    //Foot Tab
    QWidget* footPageWidget = new QWidget;
    QVBoxLayout* footLayout = new QVBoxLayout();
    footLayout->addWidget(footGroupBox);
    footPageWidget->setLayout(footLayout);

    //Mixed Tab
    QWidget* mixedPageWidget = new QWidget;
    QHBoxLayout* mixedButtonLayout = new QHBoxLayout();
    mixedButtonLayout->addWidget(leftMixedGroupBox);
    mixedButtonLayout->addWidget(rightMixedGroupBox);
    mixedPageWidget->setLayout(mixedButtonLayout);


    //Tabs
    QStackedWidget *stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(carPageWidget);
    stackedWidget->addWidget(trainPageWidget);
    stackedWidget->addWidget(bikePageWidget);
    stackedWidget->addWidget(footPageWidget);
    stackedWidget->addWidget(mixedPageWidget);

    QComboBox* pageComboBox = new QComboBox;
        pageComboBox->addItem(tr("Viaggio in Auto"));
        pageComboBox->addItem(tr("Viaggio in Treno"));
        pageComboBox->addItem(tr("Viaggio in Bici"));
        pageComboBox->addItem(tr("Viaggio a Piedi"));
        pageComboBox->addItem(tr("Viaggio Misto (Viaggio in Auto + Viaggio a Piedi)")); //mi pento delle mie scelte nelle nomenclature
    connect(pageComboBox, QOverload<int>::of(&QComboBox::activated),
            stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(pageComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(tabChanged(int)));

    mainLayout->addWidget(pageComboBox);
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(stackedWidget);

    //Buttons
    mainLayout->addLayout(buttonsLayout);
    QPushButton* okBtn = new QPushButton("Ok");
    QPushButton* cancBtn = new QPushButton("Cancella");
    buttonsLayout->addWidget(okBtn);
    buttonsLayout->addWidget(cancBtn);
    connect(okBtn, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(cancBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

qTripAbstract* NewTripDialog::getTrip() {
    qTripAbstract* temp = nullptr; //Viaggio temporaneo da istanziare secondo il tipo di viaggio selezionato

    //Default values
    std::string t, p, a;
    double km, cal;
    unsigned int sec, min, ore;

    titleEdit->text()!="" ? t = titleEdit->text().toStdString() : t = "Nuovo Viaggio";
    partenzaEdit->text()!="" ? p = partenzaEdit->text().toStdString() : p = "Partenza";
    arrivoEdit->text()!="" ? a = arrivoEdit->text().toStdString() : a = "Arrivo";
    kmEdit->text()!="" ? km = kmEdit->text().toDouble() : km = 0.1;
    durataSecEdit->text()!="" ? sec = static_cast<unsigned int>(durataSecEdit->text().toInt()) : sec = 0;
    durataMinEdit->text()!="" ? min = static_cast<unsigned int>(durataMinEdit->text().toInt()) : min = 0;
    durataOreEdit->text()!="" ? ore = static_cast<unsigned int>(durataOreEdit->text().toInt()) : ore = 1;
    calorieEdit->text()!="" ? cal = calorieEdit->text().toDouble() : cal = 300;

    switch(type) {
    case 0:
        temp = new qTripCar(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, getCurrentFuel());
        break;
    case 1:
        temp = new qTripTrain(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, altaVel->isChecked() ? Train::highVel : Train::regional);
        break;
    case 2:
        temp = new qTripBike(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, cal);
        break;
    case 3:
        temp = new qTripFoot(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, walkFoot->isChecked() ? Walk::walk : Walk::run);
        break;
    case 4:
        temp = new qTripMixed(t, p, a, km, dataEdit->selectedDate(), ore, min, sec, walkMixed->isChecked() ? Walk::walk : Walk::run, getCurrentFuelMixed());
        break;
    default:
        temp = nullptr;
        break;
    }
    return temp;
}

Fuel NewTripDialog::getCurrentFuel() const
{
    if(benzinaCar->isChecked()) return Fuel::petrol;
    else if(dieselCar->isChecked()) return Fuel::diesel;
    else if(metanoCar->isChecked()) return Fuel::methane;
    else if(elettricaCar->isChecked()) return Fuel::electric;

    return Fuel::petrol;
}

Fuel NewTripDialog::getCurrentFuelMixed() const
{
    if(benzinaMixed->isChecked()) return Fuel::petrol;
    else if(dieselMixed->isChecked()) return Fuel::diesel;
    else if(metanoMixed->isChecked()) return Fuel::methane;
    else if(elettricaMixed->isChecked()) return Fuel::electric;

    return Fuel::petrol;
}

void NewTripDialog::tabChanged(int i) {type=i;}
