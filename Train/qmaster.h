#ifndef QMASTER_H
#define QMASTER_H

#include <QMessageBox>
#include <QPushButton>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>
#include <QObject>
#include "player.h"

class QMaster : public QWidget
{
    Q_OBJECT

public:

    QMaster( ); // Constructeur de notre plateau de jeu.
    QMaster(int nbderobot); //constructeur avec les IA
    ~QMaster(); // Destructeur.

    int select; // represente la colonne que l'on selectionne.

    const int x=8; // Représente le nombre de ligne, on a ici deux lignes de plus une en haut (la ligne d'indication de la colonne choisit) et celle du bas qui permet  de switcher entre ces dernières.
    const int y=7;// colonne

    QPushButton bouton[8][7]; // tableau de boutons.
    int gamestate[6][7]; // tableau d'entier qui va être relier au tableau de boutons.

    int playerturn; //tour du joueur
    Player *player;
    int nbjoueur;
    int Rand(int a, int b);


    QGridLayout layout ; // Permet  de positionner nos Widgets.
    bool replay=false;

    bool verif_horiz(int val);
    bool verif_verti(int val);
    bool verif_diag_d(int val);
    bool verif_diag_g(int val);
    bool end_Game(int player);
    bool getreplay();
    void restartgame(QPushButton bouton[8][7], int gamestate[6][7] , QGridLayout &layout , int &select , int player);
    void putblock(int select);
    void putblock();
    void moveswitch(int newselect);
    static int nombredia();
    void iaturn(int qi);




public slots:

    void moverightslot(); // Slot de deplacements
    void moveleftslot(); //
    void playerswitch();// Slot qui permet lors du tour de chaque joueur, qu'on passe à l'autre;



};

#endif // QMASTER_H





