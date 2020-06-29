#include "qtravel.h"

qTravel::qTravel(): trips() {}

qTravel::~qTravel() {clearTrips();} //Richiamo clearTrips per pulire il container

void qTravel::add(qTripAbstract *n) {
    trips.push_back(n);
}

const tripVector<qTripAbstract*>& qTravel::getAllTrips() const {
    return trips;
}

qTripAbstract* qTravel::trip(unsigned int i) const {
    return trips[i];
}

void qTravel::editTrip(qTripAbstract* toEdit, unsigned int i) {
    trips[i] = toEdit;
}

void qTravel::clearTrips() {
    for(auto it = trips.begin(); trips.getSize()>1;) {
        delete *it;
        trips.erase(it);
    }
}

void qTravel::removeTrip(unsigned int i) {
    delete trips[i];
    trips.erase(i);
}

unsigned int qTravel::getSize() const {
    return trips.getSize();
}
