#ifndef CONTROLLER_H
#define CONTROLLER_H

namespace controller {}

#include <QObject>
#include <QWindow>
#include <QString>

#include "qtravel.h"
#include "mainwindow.h"
#include "xmlcontroller.h"

class Controller: public QObject{
    Q_OBJECT
private:
    qTravel *trips; //Interfacciamento con il modello
    MainWindow *view; //Interfacciamento con la view
    tripVector<TripWidget*> widgetList; //Container di widget rappresentanti i viaggi
public:
    Controller();
     ~Controller();

    const tripVector<qTripAbstract*>& getTrips() const; //Restitusice tutti i viaggi in sola lettura
    qTripAbstract* trip(unsigned int); //restituisce un viaggio in lettura o scrittura

public slots:
    void add(qTripAbstract*); //Aggiungo un viaggio al modello e alla view
    void remove(unsigned int, TripWidget*); //Rimuovo un viaggio dal modello ed elimino il widget dalla view
    void edit(qTripAbstract*, qTripAbstract*);
    void search(const QString&); //Effettuo la ricerca di un viaggio
    void save(const QString&); //Salvo in xml
    void load(const QString&); //Carico da file xml
    void calcolo(); //Calcolo euro spesi e calorie consumate e mostro una QMessageBox con i risultati
};

#endif // CONTROLLER_H
