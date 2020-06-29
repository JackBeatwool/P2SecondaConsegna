#ifndef QTRIPACTIVITY_H
#define QTRIPACTIVITY_H

#include "qtripabstract.h"

class qTripActivity: public qTripAbstract
{
private:
    double calPerKM;
public:
    qTripActivity(std::string, std::string, std::string, double, QDate, unsigned int, unsigned int, unsigned int, double);
    qTripActivity(std::string, std::string, std::string, double, QDate, unsigned int, double);

    virtual double getCal() const;
    virtual void setCal(double);

    virtual double calcolo() const = 0;
    virtual Type type() const = 0;
    virtual qTripAbstract* clone() const = 0;
};

#endif // QTRIPACTIVITY_H
