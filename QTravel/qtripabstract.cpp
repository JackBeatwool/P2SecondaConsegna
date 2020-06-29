#include "qtripabstract.h"

std::string qTripAbstract::getTitolo() const {
    return titolo;
}

std::string qTripAbstract::getPartenza() const {
    return partenza;
}

std::string qTripAbstract::getArrivo() const {
    return arrivo;
}

double qTripAbstract::getKM() const {
    return km;
}

QDate qTripAbstract::getData() const {
    return data;
}

unsigned int qTripAbstract::getDurata() const {
    return durata;
}

unsigned int qTripAbstract::getDurataSec() const {
    return durata%60;
}

unsigned int qTripAbstract::getDurataMin() const {
    return (durata/60)%60;
}

unsigned int qTripAbstract::getDurataOre() const {
    return durata/3600;
}

void qTripAbstract::setTitolo(std::string newTitolo) {
    titolo = newTitolo;
}

void qTripAbstract::setPartenza(std::string newPartenza) {
    partenza = newPartenza;
}

void qTripAbstract::setArrivo(std::string newArrivo) {
    arrivo = newArrivo;
}

void qTripAbstract::setKM(double newKM) {
    km = newKM;
}

void qTripAbstract::setData(QDate newData) {
    data = newData;
}

void qTripAbstract::setDurata(unsigned int newH, unsigned int newM, unsigned int newS) {
    durata = newH*3600+newM*60+newS;
}
