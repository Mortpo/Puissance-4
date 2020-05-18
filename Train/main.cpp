#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
    QGridLayout *layout = new QGridLayout;
    const int x = 8 ; //nb ligne // 1 en haut //1 en bas
    const int nbBut=7*x;
    QPushButton *bouton[nbBut];
    int q=0;


    for (int i=0 ; i<x;i++){

        for(int h=0;h<7;h++){
          q++;
         bouton[q] = new QPushButton("        ");

         layout->addWidget(bouton[q], i, h);

         if(q<8){
             bouton[q]->setStyleSheet("background-color: grey;");
         }
         if(q > nbBut - 7){
             bouton[q]->setStyleSheet("background-color: grey;");
         }
        }
    }

       bouton[q-3]->setText("Joueur 1");
       bouton[q-1]->setText("   >>   ");
       bouton[q-5]->setText("   <<   ");





    fenetre.setLayout(layout);

    fenetre.show();

    return app.exec();
}
