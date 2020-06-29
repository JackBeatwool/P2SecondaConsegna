#ifndef TRIPWIDGET_H
#define TRIPWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

#include "qtripabstract.h"

class Controller;
class TripWidget: public QWidget{
    Q_OBJECT
private:
    qTripAbstract* trip; //Viaggio rappresentato
    unsigned int index; //Indice del viaggio
    Controller* contr;
    unsigned int tipo;
    QLabel *titleLbl, *startLbl, *endLbl, *kmLbl, *dataLbl, *timeLbl, *carbLbl, *hvLbl, *calLbl, *activityLbl;

    void carTrip(QGridLayout*);
    void trainTrip(QGridLayout*);
    void bikeTrip(QGridLayout*);
    void footTrip(QGridLayout*);
    void mixedTrip(QGridLayout*);
private slots:
    void edit();
public:
    TripWidget(qTripAbstract*, unsigned int, Controller*);

    void setIndex(unsigned int);
    unsigned int getIndex() const;
};

#endif // TRIPWIDGET_H
