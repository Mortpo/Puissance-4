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
    QMaster( );
    ~QMaster();
int select;
const int x = 8 ; //nb ligne // 1 en haut //1 en bas
const int y=7;
QPushButton bouton[8][7];
int gamestate[6][7];
bool player;
    QGridLayout layout ;


public slots:
    void moverightslot();
    void moveleftslot();
    void playerswitch();



};

#endif // QMASTER_H





