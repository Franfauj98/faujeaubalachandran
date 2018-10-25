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
    case IdDecor::ARBRE: passable=true;
    break;
    case IdDecor::CHEVAL: passable=true;
    break;
    case IdDecor::RENNE: passable=true;
    break;
    case IdDecor::POISSON: passable=true;
    break;
    case IdDecor::POULE: passable=true;
    break;
    case IdDecor::MONTAGNE: passable=false;
    break;
    case IdDecor::HERBE: passable=true;
    break;
    case IdDecor::EAU: passable=false;
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
