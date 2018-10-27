#include "Decor.h"
using namespace state;

Decor::Decor() {
  Position p(0,0);
  this->position = p;
  this->idDecor=NONE_DECOR;
  this->passable=true;
  this->type = 0;
}

Decor::Decor(IdDecor id, Position position) {
  this->idDecor=id;
  this->position = position;
  this->type = 0;
  switch(id){
    case IdDecor::NONE_DECOR: passable=true;
    break;
    case IdDecor::TREE: passable=true;
    break;
    case IdDecor::HORSE: passable=true;
    break;
    case IdDecor::RENNE: passable=true;
    break;
    case IdDecor::FISH: passable=true;
    break;
    case IdDecor::CHICKEN: passable=true;
    break;
    case IdDecor::MOUNTAGNE: passable=false;
    break;
    case IdDecor::GRASS: passable=true;
    break;
    case IdDecor::SEA: passable=false;
    break;
    case IdDecor::LIFE: passable=true;
    break;
  }
}
bool Decor::getPassable() const {
  return this->passable;
}

void Decor::setPassable(const bool passable){
  this->passable=passable;
}
IdDecor Decor::getIdDecor() const{
  return this->idDecor;
}
void Decor::setIdDecor(const IdDecor idDecor){
  this->idDecor=idDecor;
}
Decor::~Decor(){

}
