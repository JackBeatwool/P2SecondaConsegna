#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H

namespace xml {}

#include "controller.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class XmlController{
private:
    Controller* controller;
    QString getUsedFuel(Fuel) const;
public:
    XmlController(Controller*);
    void save(QString) const;
    void load(QString) const;
};

#endif // XMLCONTROLLER_H
