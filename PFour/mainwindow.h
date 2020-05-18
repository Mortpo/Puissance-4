#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QList>
#include <QLabel>
#include <QWidget>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool access_player_one; // Autorisation des joueurs
    bool access_player_two;
    int player_column; // Entier qui va indiquer sur le panneau LCD où est-ce qu'il va mettre le jeton.
    QLabel *Case; // Chaque case est representer par un label. // En Cours...
    QList<QLabel*> Case_Tab; // Tableau de Label.
    void init(); // Fonction qui va initialiser le 'plateau' de jeu.
    void case_color(); // Chaque joueur à une couleur specifique, donc cette fonction va changer la couleur d'un label.
    bool verif(); // Verification qui il y a un gagnant. A chaque tour de joueur.
    void end_game(bool response_of_verif); // A chaque tour de joueur on execute cette fonction qui va desactiver tout les label.


private slots:
    //void action_left_button(); // fleche de gauche qui deplace la colonne où le jeton sera placer.
   // void action_right_button();
   // void action_confirm_button();
   // int lcd_player_column();

};
#endif // MAINWINDOW_H
