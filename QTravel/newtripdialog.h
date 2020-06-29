#ifndef NEWTRIPDIALOG_H
#define NEWTRIPDIALOG_H

#include "qtripbike.h"
#include "qtripcar.h"
#include "qtriptrain.h"
#include "qtripmixed.h"
#include "qtripfoot.h"

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QString>
#include <QCalendarWidget>
#include <QRadioButton>
#include <QMessageBox>
#include <QStackedWidget>
#include <QComboBox>
#include <QListWidget>
#include <QGroupBox>

class NewTripDialog: public QDialog{
Q_OBJECT
private:
    int type;
    QLineEdit *titleEdit, *partenzaEdit, *arrivoEdit, *kmEdit, *durataSecEdit, *durataMinEdit, *durataOreEdit, *calorieEdit;
    QCalendarWidget* dataEdit;
    QRadioButton *benzinaCar, *dieselCar, *metanoCar, *elettricaCar, *altaVel, *lowVel, *runFoot, *walkFoot, *benzinaMixed, *dieselMixed, *metanoMixed, *elettricaMixed, *runMixed, *walkMixed;
    Fuel getCurrentFuel() const;
    Fuel getCurrentFuelMixed() const;
public:
    NewTripDialog();
    qTripAbstract* getTrip(); //Creazione e restituzione di un nuovo viaggio
private slots:
    void tabChanged(int);
};

#endif // NEWTRIPDIALOG_H
