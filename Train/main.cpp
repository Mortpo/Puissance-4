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


    QMaster master;




    master.setLayout(&master.layout);

    master.show();

    return app.exec();
}
