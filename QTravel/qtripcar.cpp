#include "qtripcar.h"

qTripCar::qTripCar(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int ore, unsigned int min, unsigned int sec, Fuel carb):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, ore, min, sec), fuel(carb) {}

qTripCar::qTripCar(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int dur, Fuel carb):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, dur), fuel(carb) {}

Fuel qTripCar::getFuel() const {
    return fuel;
}

void qTripCar::setFuel(Fuel newFuel) {
    fuel = newFuel;
}

double qTripCar::calcolo() const {
    double result;
    switch(fuel)
    {
    case diesel:
        result = getKM()*costoPerKMDiesel;
        break;
    case petrol:
        result = getKM()*costoPerKMBenzina;
        break;
    case methane:
        result = getKM()*costoPerKMMetano;
        break;
    case electric:
        result = getKM()*costoPerKMElettrica;
        break;
    }
    return result;
}

qTripCar* qTripCar::clone() const {
    return new qTripCar(*this);
}

Type qTripCar::type() const {
    return Type::carTrip;
}
