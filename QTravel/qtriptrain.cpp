#include "qtriptrain.h"

qTripTrain::qTripTrain(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int ore, unsigned int min, unsigned int sec, Train train):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, ore, min, sec), train(train) {}

qTripTrain::qTripTrain(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int dur, Train train):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, dur), train(train) {}

qTripTrain* qTripTrain::clone() const {
    return new qTripTrain(*this);
}

Train qTripTrain::getAltaVel() const {
    return train;
}

void qTripTrain::setAltaVel(Train newTrain) {
    train = newTrain;
}

double qTripTrain::calcolo() const{
    return train == Train::highVel ? costoHighVel*getKM(): costoRegional*getKM();
}

Type qTripTrain::type() const{
    return Type::trainTrip;
}
