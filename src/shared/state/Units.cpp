#include "Units.h"
using namespace state;

Units::Units () : Element(){
}

Units::Units (int idUnits, Position position, int life,
  int damage, int strikeRange, int movingRange,
  int level, IdTextureUnits idTextureUnits) : Element(position){
  this->idUnits = idUnits;
  this->life = life;
  this->damage = damage;
  this->strikeRange = strikeRange;
  this->movingRange = movingRange;
  this->level = level;
  this->idTextureUnits=idTextureUnits;
}

void Units::setLife (int life){
  this->life = life;
}

int Units::getLife() const{
  return this->life;
}

void Units::setDamage (int damage){
  this->damage = damage;
}

int Units::getDamage() const{
  return this->damage;
}

void Units::setStrikeRange (int strikeRange){
  this->strikeRange = strikeRange;
}

int Units::getStrikeRange() const{
  return this->strikeRange;
}

void Units::setMovingRange (int movingRange){
  this->movingRange = movingRange;
}

int Units::getMovingRange() const{
  return this->movingRange;
}

void Units::setLevel (int level){
  this->level = level;
}

int Units::getLevel() const{
  return this->level;
}

IdTextureUnits Units::getIdTextureUnits () const{
  return this->idTextureUnits;
}

void Units::setIdTextureUnits (IdTextureUnits idTextureUnits){
  this->idTextureUnits = idTextureUnits;
}

int Units::getIdUnits () const{
  return this->idUnits;
}

void Units::setIdUnits (int idUnits){
  this->idUnits = idUnits;
}

void Units::move (Position& p2, int moveNumber){
  if(moveAllowed(p2, moveNumber)) this->position=p2;
}

bool Units::moveAllowed (Position p2, int moveNumber){
  if(moveNumber>0 && p2.getX()>=0 && p2.getY()>=0){
    if(distance(this->position, p2) <= this -> movingRange){
      return true;
    }
    return false;
  } else {
    return false;
  }
}

void Units::attack (Units& unit2){
  if(attackAllowed(unit2)){
    const int tempLife = unit2.getLife()-this->damage;
    if(tempLife>0){
      unit2.setLife(tempLife);
    } else{
      unit2.setLife(0);
    }
  }
}

bool Units::attackAllowed (Units unit2){
  if(unit2.getLife() > 0){
    if(distance(this->position, unit2.getPosition()) <= this -> strikeRange){
      return true;
    } else {
      return false;
    }
  } else {
  return false;
  }
}

bool Units::isPassable(){
  return false;
}

Units::~Units () {}
