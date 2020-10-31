#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QMessageBox>
#include <QDebug>
#include <QGridLayout>
#include <QPalette>


MainWindow::MainWindow() : QWidget()
{

    QGridLayout *layout = new QGridLayout;
    const int x = 8 ; //nb ligne // 1 en haut //1 en bas
    const int nbBut=7*x;
    int q=0;

    for (int i=0 ; i<x;i++){

        for(int h=0;h<7;h++){
          q++;
         m_bouton[q] = new QPushButton("        ");

         layout->addWidget(m_bouton[q], i, h);

         if(q<8){
             m_bouton[q]->setStyleSheet("background-color: grey;");
         }
         if(q > nbBut - 7){
             m_bouton[q]->setStyleSheet("background-color: grey;");
         }
        }
    }


    m_bouton[q-3]->setText("Joueur 1");
    m_bouton[q-1]->setText("   >>   ");

    m_bouton[q-5]->setText("   <<   ");
    setLayout(layout);

}

/*void MainWindow::on_BGButton_clicked( )
{
   ui->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

}*/
