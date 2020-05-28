#ifndef QMASTER_H
#define QMASTER_H


#include <QPushButton>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>
#include <QObject>

class QMaster : public QWidget
{
    Q_OBJECT

public:

    QMaster( ); // Constructeur de notre plateau de jeu.
    ~QMaster(); // Destructeur.

    int select; // represente la colonne que l'on selectionne.

    const int x=8; // Représente le nombre de ligne, on a ici deux lignes de plus une en haut (la ligne d'indication de la colonne choisit) et celle du bas qui permet  de switcher entre ces dernières.
    const int y=7;// colonne

    QPushButton bouton[8][7]; // tableau de boutons.
    int gamestate[6][7]; // tableau d'entier qui va être relier au tableau de boutons.

    bool player; // Si true, alors Joueur 1 doit jouer, si false, Joueur 2 doit jouer.
    QGridLayout layout ; // Permet  de positionner nos Widgets.


public slots:

    void moverightslot(); // Slot de deplacements
    void moveleftslot(); //
    void playerswitch();// Slot qui permet lors du tour de chaque joueur, qu'on passe à l'autre;



};

#endif // QMASTER_H





