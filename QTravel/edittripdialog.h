#ifndef EDITTRIPDIALOG_H
#define EDITTRIPDIALOG_H

#include "qtripbike.h"
#include "qtripcar.h"
#include "qtriptrain.h"
#include "qtripfoot.h"
#include "qtripmixed.h"

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
#include <QString>
#include <QGroupBox>

class EditTripDialog: public QDialog{
Q_OBJECT
private:
    qTripAbstract* trip;
    unsigned int tipo;

    QLineEdit *titleEdit, *partenzaEdit, *arrivoEdit, *kmEdit, *durataSecEdit, *durataMinEdit, *durataOreEdit, *calorieEdit;
    QCalendarWidget* dataEdit;
    QRadioButton *benzina, *diesel, *metano, *elettrica, *altaVel, *lowVel, *walk, *run;
    Fuel getCurrentFuel() const;
public:
    EditTripDialog(qTripAbstract*, unsigned int);
    qTripAbstract* getTrip(); //Restituzione di viaggio modificato
};

#endif // EDITTRIPDIALOG_H
