#include "qmaster.h"
#include <iostream>


QMaster::QMaster(){

    select=3;
    player=true; // bool qui permet de definir le tour des joueurs, true pour le joueur 1 et false pour le joueur 2.

    for (int x=0 ; x<6;x++){
        for (int y=0 ; y<7;y++){
            gamestate[x][y]=0; // on initialise notre plateau de jeu, c'est un tableau de 0 au quel sera associé des boutons.
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

       }

       else{

           bouton[0][select].setStyleSheet("background-color: blue;");
           bouton[0][select].setText("\n\nJoueur 2\n\n");

       }


       QObject::connect(&bouton[7][7-6], SIGNAL(clicked()),this, SLOT(moveleftslot())); // On connecte les boutons de direction aux slots que l'on instancie ici plus bas.
       QObject::connect(&bouton[7][7-2], SIGNAL(clicked()),this, SLOT(moverightslot()));
       QObject::connect(&bouton[7][7-4], SIGNAL(clicked()),this, SLOT(playerswitch()));


}

QMaster::~QMaster() // Destructeur
{


}


void QMaster::moverightslot(){

          int newselect=(select+1)%7; // +1 car on se decalle d'un bouton vers la droite.

          bouton[0][select].setText("\n\n        \n\n");
          bouton[0][select].setStyleSheet("background-color: grey;");// couleur par default du bouton qui indique les colonnes.

         if(player){

             bouton[0][newselect].setStyleSheet("background-color: red;");
             bouton[0][newselect].setText("\n\nJoueur 1\n\n");// A chaque switch de de bouton vers la gauche, la colonne où le joueur se situr devient identifiable par le joueur avec l'inscriptinon 'joueur 1'.

           }

         else{

             bouton[0][newselect].setStyleSheet("background-color: blue;");
             bouton[0][newselect].setText("\n\nJoueur 2\n\n");// A chaque switch de de bouton vers la gauche, la colonne où le joueur se situr devient identifiable par le joueur avec l'inscriptinon 'joueur 2'.
           }

    select=newselect;

}


void QMaster::moveleftslot(){


    int newselect=(select-1)%7; // -1 car on se decalle d'un bouton vers la gauche.

    if(newselect<0){ // on vérifie qu'on ne sort pas de la 'grille' de jeu, donc si le joueur ne fait qu'appuyer sur la flèche de gauche cela va refaire un tour en repassant par la droite.
        newselect = 6;
    }


    bouton[0][select].setText("\n\n        \n\n");
    bouton[0][select].setStyleSheet("background-color: grey;");

    if(player){

         bouton[0][newselect].setStyleSheet("background-color: red;");
         bouton[0][newselect].setText("\n\nJoueur 1\n\n");

        }

    else{

         bouton[0][newselect].setStyleSheet("background-color: blue;");
         bouton[0][newselect].setText("\n\nJoueur 2\n\n");
        }

    select=newselect;

}

void  QMaster::playerswitch(){

    bool full=true;

    if(player){ // Joueur 1



       for (int i=5; i>=0;i--){

            if(gamestate[i][select]==0){ // Le joueur selectionne sa colonne et ensuite le bouton devient rouge.

                bouton[i+1][select].setStyleSheet("background-color: red;");
                gamestate[i][select]=1;
                i=-1;
                full=false;

            }
        }

       if(full){

       }

       else{ // Si le joueur 1 n'a pas gagné, on switch sur le joueur 2.

           player=false;

           bouton[0][select].setStyleSheet("background-color: grey;");
           bouton[0][select].setText("\n\n        \n\n");

           select=3;

           bouton[0][select].setStyleSheet("background-color: blue;"); // Couleur du joueur 2.
           bouton[0][select].setText("\n\nJoueur 2\n\n"); // Affichage joueur 2 sur le colonne selectionnée.
       }




    }

    else{ // Joueur 2 cad quand le bool joueur est à false

        for (int i=5; i>=0;i--){

             if(gamestate[i][select]==0){

                 bouton[i+1][select].setStyleSheet("background-color: blue;");
                 gamestate[i][select]=1;

                 i=-1;
                 full=false;
             }
         }

        if(full){

        }

        else{

            player=true; // on repasse au joueur 1, avec son affichage.

            bouton[0][select].setStyleSheet("background-color: grey;");
            bouton[0][select].setText("\n\n        \n\n");

            select=3;

            bouton[0][select].setStyleSheet("background-color: red;");
            bouton[0][select].setText("\n\nJoueur 1\n\n");
        }



    }

}
