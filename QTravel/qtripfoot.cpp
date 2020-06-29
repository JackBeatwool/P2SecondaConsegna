#include "qtripfoot.h"

qTripFoot::qTripFoot(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int ore, unsigned int min, unsigned int sec, Walk walk):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, ore, min, sec), tipologia(walk) {}

qTripFoot::qTripFoot(std::string t, std::string part, std::string arr, double dist, QDate data, unsigned int dur, Walk walk):
    qTripAbstract::qTripAbstract(t, part, arr, dist, data, dur), tipologia(walk) {}

Walk qTripFoot::getTipologia() const
{
    return tipologia;
}

void qTripFoot::setTipologia(Walk newWalk)
{
    tipologia = newWalk;
}

double qTripFoot::calcolo() const
{
    double result;
    switch(tipologia) {
    case run:
        result = getDurataOre()*calRun;
        break;
    case walk:
        result = getDurataOre()*calWalk;
        break;
    }
    return result;
}

qTripFoot* qTripFoot::clone() const {
    return new qTripFoot(*this);
}

Type qTripFoot::type() const {
    return Type::footTrip;
}
