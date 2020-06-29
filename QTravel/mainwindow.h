#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "newtripdialog.h"
#include "tripwidget.h"
#include <QLayout>
#include <QWidget>

class Controller;
class MainWindow : public QWidget{
    Q_OBJECT
private:
    Controller *contr;
    QVBoxLayout *layout; //layout per il content - contiene i viaggi
public:
    MainWindow(Controller*, QWidget *parent = nullptr);
    void addTripWidget(QWidget*); //aggiunge un widget al contLayout
private slots:
    void newTrip(); //Apro una finestra di inserimento
    void save();    //Apro una finestra per salvare il file
    void load();    //Apro una finestra per caricare il file
};

#endif // MAINWINDOW_H
