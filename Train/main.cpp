#include "mainwindow.h"
#include "qmaster.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>
#include <QObject>

#include <iostream>





int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QWidget fenetre;
    QMaster master;



       //QObject::connect(master.boutons[q-5], SIGNAL(clicked()),&master, SLOT(master.moveleftslot())); // PEUT ETRE L INIT DE MASTER //marche pas



    master.setLayout(&master.layout);

    master.show();

    return app.exec();
}
