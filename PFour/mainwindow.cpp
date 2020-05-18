#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Puissance 4, The Ultimate Game !"); // Titre de la fenêtre


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
player_column=0; // zone ou le joueur peut mettre un jeton par defaut, on commence tout à gauche du tableau
access_player_one=true; // joueur 1 qui commence donc true
access_player_two=false;// joueur 2 qui attend, donc false

for(int i=0;i<7;i++) // tableau 6x6 de label
{
    for(int j=0;j<7;j++)
    {
        Case_Tab.push_back(new QLabel()); // En cours ...

    }
}



}



