#include "qtripmixed.h"

qTripMixed::qTripMixed(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int ore, unsigned int min, unsigned int sec, Walk walk, Fuel fuel):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, ore, min, sec), qTripCar::qTripCar(t, part, arr, dist, data, ore, min, sec, fuel), qTripFoot::qTripFoot(t, part, arr, dist, data, ore, min, sec, walk) {}

qTripMixed::qTripMixed(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int dur, Walk walk, Fuel fuel):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, dur), qTripCar::qTripCar(t, part, arr, dist, data, dur, fuel), qTripFoot::qTripFoot(t, part, arr, dist, data, dur, walk) {}

double qTripMixed::calcoloCar() const
{
    return qTripCar::calcolo();
}

double qTripMixed::calcoloFoot() const
{
    return qTripFoot::calcolo();
}

double qTripMixed::calcolo() const
{
    return calcoloFoot() + calcoloCar(); // never called but necessary to build, looking to modify this to make it useful, not gonna be easy
}

Type qTripMixed::type() const
{
    return Type::mixedTrip;
}

qTripMixed* qTripMixed::clone() const
{
    return new qTripMixed(*this);
}
