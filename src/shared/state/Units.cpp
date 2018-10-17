#include "Units.h"
#include <iostream>
using namespace state;

Units::Units () : Element(){
}

Units::Units (int idUnits, Position position, int life,
  int damage, int strikeRange, int movingRange,
  int level, IdTextureUnits idTextureUnits, UnitCost uniCost) : Element(position){
  if(idUnits>0) {
    this->idUnits = idUnits;
  } else {
    std::cerr << "idUnits must be >= 0"<< std::endl;
    this->idUnits = 0;
  }
  if(life>0 && life <1000) {
    this->life = life;
  } else {
    std::cerr << "life must be positive or be smaller than 1000"<< std::endl;
    this->life = 0;
  }
  if(damage>0 && damage < 100) {
    this->damage = damage;
  } else {
    std::cerr << "damage must be positive or be smaller than 100"<< std::endl;
    this->damage = 0;
  }
  if(strikeRange>0 && strikeRange < 10) {
    this->strikeRange = strikeRange;
  } else {
    std::cerr << "strikeRange must be positive or be smaller than 10"<< std::endl;
    this->strikeRange = 0;
  }
  if(movingRange>0 && movingRange<5) {
    this->movingRange = movingRange;
  } else {
    std::cerr << "movingRange must be positive or be smaller than 5"<< std::endl;
    this->movingRange = 0;
  }
  if(level>0 && level<5) {
    this->level = level;
  } else {
    std::cerr << "level must be positive and smaller than 5"<< std::endl;
    this->level = 0;
  }
  this->idTextureUnits=idTextureUnits;
  this->unitCost=unitCost;
}

void Units::setLife (int life){
  if(life > 0 && life <1000){
    this->life = life;
  } else {
    std::cerr << "life must be positive  or be smaller than 1000"<< std::endl;
    this->life = 0;
  }
}

int Units::getLife() const{
  return this->life;
}

void Units::setDamage (const int damage){
  if(damage>0 && damage<100){
    this->damage = damage;
  } else {
    this->damage = 0;
    std::cerr << "damage must be positive or be smaller than 100"<< std::endl;
  }
}

int Units::getDamage() const{
  return this->damage;
}

void Units::setStrikeRange (const int strikeRange){
  if(strikeRange > 0 && strikeRange<10){
    this->strikeRange = strikeRange;
  } else {
    this->strikeRange = 0;
    std::cerr << "strikeRange must be positive or be smaller than 10"<< std::endl;
  }
}

int Units::getStrikeRange() const{
  return this->strikeRange;
}

void Units::setMovingRange (const int movingRange){
  if(movingRange > 0 && movingRange<5){
    this->movingRange = movingRange;
  } else {
    this->movingRange = 0;
    std::cerr << "movingRange must be positive or be smaller than 5"<< std::endl;
  }
}

int Units::getMovingRange() const{
  return this->movingRange;
}

void Units::setLevel (const int level){
  if(level>0 && level<5){
    this->level = level;
  } else {
    this->level = 0;
    std::cerr << "level must be positive or be smaller than 5"<< std::endl;
  }
}

int Units::getLevel() const{
  return this->level;
}

IdTextureUnits Units::getIdTextureUnits () const{
  return this->idTextureUnits;
}

void Units::setIdTextureUnits (const IdTextureUnits idTextureUnits){
  this->idTextureUnits = idTextureUnits;
}

int Units::getIdUnits () const{
  return this->idUnits;
}

void Units::setIdUnits (const int idUnits){
  if(idUnits>0){
    this->idUnits = idUnits;
  } else {
    this->idUnits = 0;
    std::cerr << "idUnits must be positive"<< std::endl;
  }
}

UnitCost Units::getUnitCost () const{
  return this->unitCost;
}

void Units::setUnitCost (const UnitCost uniCost){
  this->unitCost=uniCost;
}

void Units::move (Position& p2, int moveNumber){
  if(moveAllowed(p2, moveNumber)) this->position=p2;
}

bool Units::moveAllowed (Position p2, int moveNumber){
  if(moveNumber>0 && p2.getX()>=0 && p2.getY()>=0 && (p2.getX()+moveNumber)<10000 && (p2.getY()+moveNumber)<10000){
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
