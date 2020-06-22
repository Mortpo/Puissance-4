#include "qmaster.h"
#include <iostream>



void QMaster::restartgame(QPushButton bouton[8][7], int gamestate[6][7] , QGridLayout &layout , int &select , int playerturn){
    for (int x=0 ; x<6;x++){
        for (int y=0 ; y<7;y++){
            gamestate[x][y]=0; // on initialise notre plateau de jeu, c'est un tableau de 0 au quel sera associé des boutons.
        }
    }


    for (int i=0 ; i<8;i++){

        for(int h=0;h<7;h++){

            bouton[i][h].setText("\n\n        \n\n");
            bouton[i][h].setStyleSheet("background-color: solid gray;");

            layout.addWidget(&bouton[i][h], i, h);



            bouton[0][h].setStyleSheet("background-color: grey;");
            bouton[7][h].setStyleSheet("background-color: grey;");
        }


    }

    bouton[7][7-4].setText("\n\n PLACER \n\n");
    bouton[7][7-2].setText("\n\n   >>   \n\n");
    bouton[7][7-6].setText("\n\n   <<   \n\n");

    bouton[0][select].setStyleSheet("background-color:" + player[playerturn].getColor() +";"); // Couleur du joueur suivant.
    bouton[0][select].setText("\n\nJoueur "+QString::number((playerturn+1))+"\n\n"); // Affichage joueur suivant sur le colonne selectionnée.
}


int QMaster::Rand( int a, int b)
{
       int nRand ;
       nRand= a + (int)((float)rand() * (b-a+1) / (RAND_MAX-1)) ;
       return nRand;
}



void QMaster::putblock(){
putblock(select);
}

void QMaster::putblock(int &select){

    QString colorbg= "background-color:" + player[playerturn].getColor() +";"  ;
    bool full=true;


    for (int i=5; i>=0;i--){

        if(gamestate[i][select]==0){ // Le joueur selectionne sa colonne et ensuite le bouton devient rouge.

            bouton[i+1][select].setStyleSheet(colorbg);
            gamestate[i][select]=(playerturn+1);

            if(end_Game( playerturn+1)){
                QMessageBox msgBox;
                msgBox.setText("Partie finie, le joueur "+player[playerturn].getColor()+ " a gagné... !");
                msgBox.setInformativeText("Voulez-vous rejouer ?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);
                int ret=msgBox.exec();

                switch (ret) {

                case QMessageBox::Yes:

                    // Changement de layout pour recommencer la partie.... // Ici :
                    restartgame(bouton,gamestate , layout ,select , playerturn);

                    replay=true;
                    break;
                case  QMessageBox::No:
                    QApplication::quit();
                    break;
                default:
                    break;
                }
                // QApplication::quit(); // En cours... // Quitte le jeu quand on a un gagnant.
            }
            i=-1;
            full=false;

        }
    }

    if(!full){

        playerturn=(playerturn+1)%nbjoueur;
        bouton[0][select].setStyleSheet("background-color: grey;");
        bouton[0][select].setText("\n\n        \n\n");

        select=3;

        bouton[0][select].setStyleSheet("background-color:" + player[playerturn].getColor() +";"); // Couleur du joueur suivant.
        bouton[0][select].setText("\n\nJoueur "+QString::number((playerturn+1))+"\n\n"); // Affichage joueur suivant sur le colonne selectionnée.




    }

}

QMaster::QMaster(){

    select=3;
    nbjoueur=2;
    playerturn=1; // bool qui permet de definir le tour des joueurs, true pour le joueur 1 et false pour le joueur 2.
    player=new Player[2];
    player[0]= Player("blue",Typejoueur::Humain);
    player[1]= Player("red",Typejoueur::Humain);
    restartgame(bouton,gamestate , layout ,select , playerturn);


    QObject::connect(&bouton[7][7-6], SIGNAL(clicked()),this, SLOT(moveleftslot())); // On connecte les boutons de direction aux slots que l'on instancie ici plus bas.
    QObject::connect(&bouton[7][7-2], SIGNAL(clicked()),this, SLOT(moverightslot()));
    QObject::connect(&bouton[7][7-4], SIGNAL(clicked()),this, SLOT(playerswitch()));


}

QMaster::QMaster(int nbIA){

    select=3;
    nbjoueur=2;
    playerturn=1; // bool qui permet de definir le tour des joueurs, true pour le joueur 1 et false pour le joueur 2.
    player=new Player[2];
    switch (nbIA) {
    case 0 :{
        player[0]= Player("blue",Typejoueur::Humain);
        player[1]= Player("red",Typejoueur::Humain);
        break;
    }
    case 1:{
        player[0]= Player("blue",Typejoueur::Humain);
        player[1]= Player("red",Typejoueur::Machine);
        break;
    }
    case 2 : {
    player[0]= Player("blue",Typejoueur::Machine);
    player[1]= Player("red",Typejoueur::Machine);
    break;
    }
    default:
        QApplication::quit();
    }


    restartgame(bouton,gamestate , layout ,select , playerturn);

    if(player[playerturn].getType()==Typejoueur::Machine){
        iaturn(player[playerturn].getCerveau());
    }


    QObject::connect(&bouton[7][7-6], SIGNAL(clicked()),this, SLOT(moveleftslot())); // On connecte les boutons de direction aux slots que l'on instancie ici plus bas.
    QObject::connect(&bouton[7][7-2], SIGNAL(clicked()),this, SLOT(moverightslot()));
    QObject::connect(&bouton[7][7-4], SIGNAL(clicked()),this, SLOT(playerswitch()));


}


QMaster::~QMaster() // Destructeur
{
    delete [] player;

}

bool QMaster::getreplay(){

    return replay;
}


bool QMaster::verif_verti(int val){
    bool end_vert=false;
    for(int columns=0; columns<7;columns++){
        for(int lines=5;lines>=0;lines--){
            if(lines>2){

                if(gamestate[lines][columns]==val && gamestate[lines-1][columns]==val && gamestate[lines-2][columns]==val && gamestate[lines-3][columns]==val){
                    end_vert=true;

                }

            }


        }

    }
    return end_vert;
}

bool QMaster::verif_horiz(int val){
    bool end_hor=false;
    for(int lines=5;lines>=0;lines--){
        for(int columns=0; columns<7;columns++){
            if(columns<4){
                if(gamestate[lines][columns]==val && gamestate[lines][columns+1]==val && gamestate[lines][columns+2]==val && gamestate[lines][columns+3]==val){
                    end_hor=true;
                }

            }


        }
    }


    return end_hor;


}


bool QMaster::verif_diag_g(int val){
    bool end_diag_g=false;
    for(int lines=2;lines>=0;lines--){
        for(int columns=0; columns<4;columns++){
            if(gamestate[lines][columns]==val && gamestate[lines+1][columns+1]==val && gamestate[lines+2][columns+2]==val && gamestate[lines+3][columns+3]==val){
                end_diag_g=true;
            }

        }


    }



    return end_diag_g;

}

bool QMaster::verif_diag_d(int val){
    bool end_diag_d=false;

    for(int lines=5;lines>=3;lines--){
        for(int columns=0; columns<4;columns++){
            if(gamestate[lines][columns]==val && gamestate[lines-1][columns+1]==val && gamestate[lines-2][columns+2]==val && gamestate[lines-3][columns+3]==val){
                end_diag_d=true;
            }

        }

    }

    return end_diag_d;
}





bool QMaster::end_Game(int value){
    bool end=false;

        if(verif_horiz(value) || verif_verti(value)|| verif_diag_d(value)|| verif_diag_g(value))
            end=true;


    return end;
}


void QMaster::moverightslot(){

    int newselect=(select+1)%7; // +1 car on se decalle d'un bouton vers la droite.

moveswitch(newselect);

    select=newselect;

}


void QMaster::moveleftslot(){


    int newselect=(select-1)%7; // -1 car on se decalle d'un bouton vers la gauche.

    if(newselect<0){ // on vérifie qu'on ne sort pas de la 'grille' de jeu, donc si le joueur ne fait qu'appuyer sur la flèche de gauche cela va refaire un tour en repassant par la droite.
        newselect = 6;
    }


moveswitch(newselect);


    select=newselect;

}

void  QMaster::playerswitch(){


    putblock();

    if(player[playerturn].getType()==Typejoueur::Machine){
        iaturn( player[playerturn].getCerveau());
    }

}



void QMaster::moveswitch(int newselect){
    bouton[0][select].setText("\n\n        \n\n");
    bouton[0][select].setStyleSheet("background-color: grey;");
    bouton[0][newselect].setStyleSheet("background-color:" + player[playerturn].getColor() +";");
    bouton[0][newselect].setText("\n\nJoueur "+QString::number((playerturn+1))+"\n\n");
}


int QMaster::nombredia(){
    QPushButton *IA0 = new QPushButton("2");
    QPushButton *IA1 = new QPushButton("0");
    QPushButton *IA2 = new QPushButton("1");

    QMessageBox msgBox;
    msgBox.setText("Choisissez le nombre d'humains ?");
    msgBox.setInformativeText("Jouer contre qui ?");

    msgBox.addButton(IA1 , QMessageBox::RejectRole);
    msgBox.addButton(IA2 , QMessageBox::DestructiveRole);
    msgBox.addButton(IA0 , QMessageBox::AcceptRole);



    int ret=msgBox.exec();
std::cout << ret << std::endl;
    if(ret != 1 && ret !=  2 && ret != 3)
        QApplication::quit();

    return (ret);
}


void QMaster::iaturn(int qi){

    switch (qi) {

    case 0:{


        int a=Rand(0,6);

    putblock(a);

    break;
    }


     default:{

        QApplication::quit();

    }

    }
}
