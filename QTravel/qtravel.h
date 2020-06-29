#ifndef QTRAVEL_H
#define QTRAVEL_H

#include <qtripbike.h>
#include <qtripcar.h>
#include <qtriptrain.h>
#include <qtripfoot.h>
#include <qtripmixed.h>

//Questa classe serve da contenitore per i vari viaggi effettuati

class qTravel {
private:
    tripVector<qTripAbstract*> trips; //Container
public:
    qTravel();
    ~qTravel();

    void add(qTripAbstract*); //Aggiunta di un viaggio
    void editTrip(qTripAbstract*, unsigned int);

    const tripVector<qTripAbstract*>& getAllTrips() const; //Sola lettura di tutti i viaggi effettuati
    qTripAbstract* trip(unsigned int) const; //Sola lettura del viaggio allo specifico indice i

    void clearTrips(); //Rimuove tutti i viaggi
    void removeTrip(unsigned int); //Rimuove il singolo viaggio allo specifico indice i

    unsigned int getSize() const; //Numero di viaggi memorizzati
};

#endif // QTRAVEL_H
