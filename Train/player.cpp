#include "player.h"




Player::Player()
{
    QString color="";

    type=Null;


}
Player::~Player(){

}

Player::Player(const QString &color,Typejoueur type){

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
void Player::setType(Typejoueur type){
    this->type=type;

}
void Player::setColor(QString color){
    this->color=color;

}

