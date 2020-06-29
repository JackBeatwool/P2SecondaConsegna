#ifndef QTRIPTRAIN_H
#define QTRIPTRAIN_H

#include "qtripabstract.h"

enum Train {highVel, regional};

class qTripTrain: public qTripAbstract
{
private:
    Train train;
    static constexpr double costoRegional = 0.05, costoHighVel = 0.15;
public:
    qTripTrain(std::string, std::string, std::string, double, QDate, unsigned int, unsigned int, unsigned int, Train);
    qTripTrain(std::string, std::string, std::string, double, QDate, unsigned int, Train);

    Train getAltaVel() const;
    void setAltaVel(Train);

    virtual double calcolo() const final;
    virtual Type type() const final;
    virtual qTripTrain* clone() const final;
};

#endif // QTRIPTRAIN_H
