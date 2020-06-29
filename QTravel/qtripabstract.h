#ifndef QTRIPABSTRACT_H
#define QTRIPABSTRACT_H

#include <string>
#include "tripvector.h"
#include <QDate>

enum Type {carTrip, bikeTrip, trainTrip, footTrip, mixedTrip};

class qTripAbstract{
private:
    std::string titolo, partenza, arrivo;
    double km;
    QDate data;
    unsigned int durata;

public:
    qTripAbstract(std::string t, std::string part, std::string arr, double dist, QDate d, unsigned int ore, unsigned int min, unsigned int sec):
        titolo(t), partenza(part), arrivo(arr), km(dist), data(d), durata(sec+min*60+ore*3600) {}
    qTripAbstract(std::string t, std::string part, std::string arr, double dist, QDate d, unsigned int dur): //inserimento per xml
        titolo(t), partenza(part), arrivo(arr), km(dist), data(d), durata(dur) {}

    //metodi polimorfici

    virtual std::string getTitolo() const;
    virtual std::string getPartenza() const;
    virtual std::string getArrivo() const;
    virtual double getKM() const;
    virtual QDate getData() const;
    virtual unsigned int getDurata() const;
    virtual unsigned int getDurataSec() const;
    virtual unsigned int getDurataMin() const;
    virtual unsigned int getDurataOre() const;

    virtual void setTitolo(std::string);
    virtual void setPartenza(std::string);
    virtual void setArrivo(std::string);
    virtual void setKM(double);
    virtual void setData(QDate);
    virtual void setDurata(unsigned int, unsigned int, unsigned int);

    virtual double calcolo() const = 0;
    virtual Type type() const = 0;
    virtual qTripAbstract* clone() const = 0;
    virtual ~qTripAbstract() {}
};

#endif // QTRIPABSTRACT_H
