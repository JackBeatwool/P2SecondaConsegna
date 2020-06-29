#ifndef QTRIPMIXED_H
#define QTRIPMIXED_H

#include "qtripfoot.h"
#include "qtripcar.h"


class qTripMixed: public qTripCar, public qTripFoot
{
public:
    qTripMixed(std::string, std::string, std::string, double, QDate, unsigned int, unsigned int, unsigned int, Walk, Fuel);
    qTripMixed(std::string, std::string, std::string, double, QDate, unsigned int, Walk, Fuel);

    double calcoloCar() const;
    double calcoloFoot() const;

    virtual double calcolo() const final;
    virtual Type type() const final;
    virtual qTripMixed* clone() const final;
};

#endif // QTRIPMIXED_H
