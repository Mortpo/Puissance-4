#include "qmaster.h"
#include <iostream>
QMaster::QMaster(){
    select=3;
    player=true;

    for (int x=0 ; x<6;x++){
        for (int y=0 ; y<7;y++){
            gamestate[x][y]=0;
        }
    }


    for (int i=0 ; i<8;i++){

        for(int h=0;h<7;h++){
            bouton[i][h].setText("\n\n        \n\n");

         layout.addWidget(&bouton[i][h], i, h);



         bouton[0][h].setStyleSheet("background-color: grey;");
         bouton[7][h].setStyleSheet("background-color: grey;");
        }


    }

       bouton[7][7-4].setText("\n\n PLACER \n\n");
       bouton[7][7-2].setText("\n\n   >>   \n\n");
       bouton[7][7-6].setText("\n\n   <<   \n\n");

       if(player){
           bouton[0][select].setStyleSheet("background-color: red;");
           bouton[0][select].setText("\n\nJoueur 1\n\n");

       }else{
           bouton[0][select].setStyleSheet("background-color: blue;");
           bouton[0][select].setText("\n\nJoueur 2\n\n");
       }


       QObject::connect(&bouton[7][7-6], SIGNAL(clicked()),this, SLOT(moveleftslot()));
       QObject::connect(&bouton[7][7-2], SIGNAL(clicked()),this, SLOT(moverightslot()));
       QObject::connect(&bouton[7][7-4], SIGNAL(clicked()),this, SLOT(playerswitch()));


}

QMaster::~QMaster()
{


}


void QMaster::moverightslot(){
          int newselect=(select+1)%7;
          bouton[0][select].setText("\n\n        \n\n");
          bouton[0][select].setStyleSheet("background-color: grey;");
      if(player){
       bouton[0][newselect].setStyleSheet("background-color: red;");
       bouton[0][newselect].setText("\n\nJoueur 1\n\n");

      }else{
       bouton[0][newselect].setStyleSheet("background-color: blue;");
       bouton[0][newselect].setText("\n\nJoueur 2\n\n");
      }
    select=newselect;

}


void QMaster::moveleftslot(){


    int newselect=(select-1)%7;
    if(newselect<0){
    newselect = 6;
    }
    bouton[0][select].setText("\n\n        \n\n");
    bouton[0][select].setStyleSheet("background-color: grey;");
if(player){
 bouton[0][newselect].setStyleSheet("background-color: red;");
 bouton[0][newselect].setText("\n\nJoueur 1\n\n");

}else{
 bouton[0][newselect].setStyleSheet("background-color: blue;");
 bouton[0][newselect].setText("\n\nJoueur 2\n\n");
}
select=newselect;
}

void  QMaster::playerswitch(){

    bool full=true;
    if(player){ //joueur 1


        //posage de block et regarde si il a gagné
       for (int i=5; i>=0;i--){
            if(gamestate[i][select]==0){
                bouton[i+1][select].setStyleSheet("background-color: red;");
                gamestate[i][select]=1;
                i=-1;
                full=false;
            }
        }

       if(full){

       }else{
           player=false;
           bouton[0][select].setStyleSheet("background-color: grey;");
           bouton[0][select].setText("\n\n        \n\n");
           select=3;
           bouton[0][select].setStyleSheet("background-color: blue;");
           bouton[0][select].setText("\n\nJoueur 2\n\n");
       }




    }else{

        for (int i=5; i>=0;i--){
             if(gamestate[i][select]==0){
                 bouton[i+1][select].setStyleSheet("background-color: blue;");
                 gamestate[i][select]=1;
                 i=-1;
                 full=false;
             }
         }
        if(full){

        }else{
            player=true;
            bouton[0][select].setStyleSheet("background-color: grey;");
            bouton[0][select].setText("\n\n        \n\n");
            select=3;
            bouton[0][select].setStyleSheet("background-color: red;");
            bouton[0][select].setText("\n\nJoueur 1\n\n");
        }



    }

}
