#include "mainwindow.h"
#include "controller.h"

#include <sstream>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QScrollArea>
#include <QDialog>
#include <QToolBar>
#include <QFileDialog>

MainWindow::MainWindow(Controller *c, QWidget *parent) :
    QWidget(parent),
    contr(c){

    setMinimumSize(800,600); //Dimensioni minime per una visualizzazione agevole

    //Layout principale
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    //Scroll Area
    QWidget* scroll = new QWidget(this); //Widget di supporto per la scroll area
    scroll->setObjectName("scroll_area");
    QScrollArea* scrollArea = new QScrollArea(this); //Scroll area dove inserire la view del viaggio
    layout = new QVBoxLayout(scroll); //Layout per il contenuto

    //Opzioni Scroll Area
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scroll); //Imposto il widget di appoggio
    layout->setAlignment(Qt::AlignCenter); //Allineo

    //Menu Bar
    QMenuBar* menuBar = new QMenuBar(this);
        QMenu* fMenu = new QMenu("File", menuBar);
            QAction* loadAct = new QAction("Load...", fMenu);
            QAction* saveAct = new QAction("Save", fMenu);
            QAction* exitAct = new QAction("Quit", fMenu);

    //Toolbar
    QToolBar* toolBar = new QToolBar(this);
        QPushButton* loadBtn = new QPushButton(this);
        QPushButton* saveBtn = new QPushButton(this);
        QPushButton* newTripBtn = new QPushButton(this);
        QPushButton* calcoloBtn = new QPushButton(this);
        QPushButton* searchBtn = new QPushButton(this);
        QLineEdit* searchTxt = new QLineEdit(this);
    toolBar->setObjectName("toolBar");

    loadBtn->setIcon(QIcon(":/icons/load_btn"));
    loadBtn->setCursor(Qt::PointingHandCursor);
    loadBtn->setObjectName("saveload_btn");

    saveBtn->setIcon(QIcon(":/icons/save_btn"));
    saveBtn->setCursor(Qt::PointingHandCursor);
    saveBtn->setObjectName("saveload_btn");

    newTripBtn->setIcon(QIcon(":/icons/add_btn"));
    newTripBtn->setCursor(Qt::PointingHandCursor);
    newTripBtn->setObjectName("newTrip_btn");

    calcoloBtn->setIcon(QIcon(":/icons/calcola_btn"));
    calcoloBtn->setCursor(Qt::PointingHandCursor);
    calcoloBtn->setObjectName("calcolo_btn");

    newTripBtn->setIcon(QIcon(":/icons/add_btn"));
    newTripBtn->setCursor(Qt::PointingHandCursor);
    newTripBtn->setObjectName("newTrip_btn");

    searchBtn->setIcon(QIcon(":/icons/search_btn"));
    searchBtn->setCursor(Qt::PointingHandCursor);
    searchBtn->setCheckable(true);
    searchBtn->setObjectName("search_btn");

    searchTxt->setEnabled(false);
    searchTxt->setPlaceholderText("Ricerca...");
    searchTxt->setObjectName("search_txt");

        //Assemblo la menu bar
    menuBar->addMenu(fMenu);
        fMenu->addActions({loadAct, saveAct, exitAct});

        //Assemblo la toolbar
    toolBar->addWidget(loadBtn);
    toolBar->addWidget(saveBtn);
    toolBar->addWidget(newTripBtn);
    toolBar->addWidget(calcoloBtn);
    toolBar->addWidget(searchBtn);
    toolBar->addWidget(searchTxt);

        //Assemblo il layout
    setLayout(mainLayout);
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(toolBar);
    mainLayout->addWidget(scrollArea);

        //Connessioni
    connect(exitAct, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(newTripBtn, SIGNAL(clicked(bool)), this, SLOT(newTrip()));
    connect(calcoloBtn, SIGNAL(clicked(bool)), contr, SLOT(calcolo()));
    connect(loadBtn, SIGNAL(clicked(bool)), this, SLOT(load()));
    connect(loadAct, SIGNAL(triggered(bool)), this, SLOT(load()));
    connect(saveBtn, SIGNAL(clicked(bool)),this, SLOT(save()));
    connect(saveAct, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(searchBtn, SIGNAL(clicked(bool)), searchTxt, SLOT(setEnabled(bool)));
    connect(searchBtn, SIGNAL(clicked(bool)), searchTxt, SLOT(setFocus()));
    connect(searchTxt, SIGNAL(textChanged(QString)), contr, SLOT(search(QString)));

}

void MainWindow::addTripWidget(QWidget* w){
    layout->addWidget(w);
}

void MainWindow::newTrip(){
    NewTripDialog* tripDialog = new NewTripDialog(); //Creo il tripDialog per inserire il nuovo viaggio
    tripDialog->setWindowTitle("Crea nuovo viaggio");
    if(tripDialog->exec() == QDialog::Accepted){
        qTripAbstract* newTrip = tripDialog->getTrip();
        delete tripDialog;
        contr->add(newTrip);
    }
}

void MainWindow::save(){
    QFileDialog* saveDialog = new QFileDialog(this);
    saveDialog->setAcceptMode(QFileDialog::AcceptSave);
    contr->save(saveDialog->getSaveFileName(this, tr("Save file"), "", tr("XML files (*.xml)")));
}

void MainWindow::load(){
    QFileDialog* openDialog = new QFileDialog(this);
    openDialog->setAcceptMode(QFileDialog::AcceptOpen);
    contr->load(openDialog->getOpenFileName(this, tr("Open File"), "", tr("XML files (*.xml)")));
}
