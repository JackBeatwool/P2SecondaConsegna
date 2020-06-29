#include "qtripbike.h"

qTripBike::qTripBike(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int ore, unsigned int min, unsigned int sec, double cal):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, ore, min, sec), calories(cal) {}

qTripBike::qTripBike(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int dur, double cal):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, dur), calories(cal) {}

double qTripBike::getCalories() const {
    return calories;
}

void qTripBike::setCalories(double newCalories) {
    calories = newCalories;
}

double qTripBike::calcolo() const {
    return calories*getDurataOre();
}

qTripBike* qTripBike::clone() const {
    return new qTripBike(*this);
}

Type qTripBike::type() const {
    return Type::bikeTrip;
}
