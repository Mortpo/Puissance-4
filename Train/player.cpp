#include "player.h"




Player::Player()
{
    QString color="";

    type=Null;
cerveau =0;

}
Player::~Player(){

}

Player::Player(const QString &color,Typejoueur type){
cerveau =0;
    this->color=color;

    this->type=type;

  // nbjoueur= nbjoueur+1;


}

Typejoueur Player::getType(){
    return type;

}
QString Player::getColor(){

    return color;

}

int Player::getCerveau(){

    return cerveau;

}


void Player::setCerveau(int qi){

     cerveau = qi;

}
void Player::setType(Typejoueur type){
    this->type=type;

}
void Player::setColor(QString color){
    this->color=color;

}

