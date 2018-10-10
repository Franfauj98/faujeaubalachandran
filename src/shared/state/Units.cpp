#include "Units.h"
using namespace state;

Units::Units () : Element(){
}

Units::Units (int idUnits, Position position, int life,
  int damage, int strikeRange, int movingRange,
  int level, int idTextureUnits) : Element(position){
  this->idUnits = idUnits;
  this->life = life;
  this->damage = damage;
  this->strikeRange = strikeRange;
  this->movingRange = movingRange;
  this->level = level;
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

void Units::move (Position p1, Position p2){}

bool Units::moveAllowed (Position p1, Position p2, int movingRange, int moveNumber){
  return true;
}

void Units::attack (Element unit1, Element unit2){}

bool Units::attackAllowed (Element unit1, Element unit2, int strikeRange){
  return true;
}

Units::~Units () {}
