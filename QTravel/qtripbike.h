#ifndef QTRIPBIKE_H
#define QTRIPBIKE_H

#include "qtripabstract.h"

class qTripBike: public qTripAbstract
{
private:
    double calories;
public:
    qTripBike(std::string, std::string, std::string, double, QDate, unsigned int, unsigned int, unsigned int, double);
    qTripBike(std::string, std::string, std::string, double, QDate, unsigned int, double);

    double getCalories() const;
    void setCalories(double);

    virtual double calcolo() const final;
    virtual Type type() const final;
    virtual qTripBike* clone() const final;
};

#endif // QTRIPBIKE_H
