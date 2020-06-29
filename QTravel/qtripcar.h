#ifndef QTRIPCAR_H
#define QTRIPCAR_H

#include "qtripabstract.h"

enum Fuel {petrol, diesel, methane, electric};

class qTripCar: virtual public qTripAbstract
{
private:
    static constexpr double costoPerKMBenzina = 0.7, costoPerKMDiesel = 0.5, costoPerKMMetano = 0.2, costoPerKMElettrica = 0.01; //valori dimostrativi
    Fuel fuel;
public:
    qTripCar(std::string, std::string, std::string, double, QDate, unsigned int, unsigned int, unsigned int, Fuel);
    qTripCar(std::string, std::string, std::string, double, QDate, unsigned int, Fuel);

    Fuel getFuel() const;
    void setFuel(Fuel);

    virtual double calcolo() const;
    virtual Type type() const;
    virtual qTripCar* clone() const;
};

#endif // QTRIPCAR_H
