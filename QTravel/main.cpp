#include "mainwindow.h"
#include "controller.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(QLatin1String(file.readAll()));

    Controller c; //the controller starts the model and the view
    return a.exec();
}
