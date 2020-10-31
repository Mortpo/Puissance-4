#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <iostream>


enum Typejoueur{
    Humain,
    Machine,
    Null
};

class Player
{
private:
    QString color;
    Typejoueur type;
    int cerveau;



public:
    Player();
    ~Player();
    Player(const QString &color,Typejoueur type);
    Typejoueur getType();
    QString getColor();
    int getCerveau();

    void setCerveau(int qi);
    void setType(Typejoueur type);
    void setColor(QString color);

};

#endif // PLAYER_H
