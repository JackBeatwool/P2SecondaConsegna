#ifndef QTRIPFOOT_H
#define QTRIPFOOT_H

#include "qtripabstract.h"

enum Walk {run, walk};

class qTripFoot: virtual public qTripAbstract
{
private:
    Walk tipologia;
    static constexpr unsigned int calRun = 653, calWalk = 356; //valori dimostrativi
public:
    qTripFoot(std::string, std::string, std::string, double, QDate, unsigned int, unsigned int, unsigned int, Walk);
    qTripFoot(std::string, std::string, std::string, double, QDate, unsigned int, Walk);

    Walk getTipologia() const;
    void setTipologia(Walk);

    virtual double calcolo() const;
    virtual Type type() const;
    virtual qTripFoot* clone() const;

};

#endif // QTRIPFOOT_H
