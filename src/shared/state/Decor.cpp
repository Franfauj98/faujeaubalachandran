#include "Decor.h"
using namespace state;

Decor::Decor():Element() {

}

Decor::Decor(IdDecor id, Position position):Element(position) {
  this->idDecor=id;
  switch(id){
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
    case IdDecor::DUNE: passable=true;
    break;
    case IdDecor::HERBE: passable=true;
    break;
    case IdDecor::EAU: passable=false;
    break;
  }
  /*if (id==IdDecor::ARBRE){
    passable=true;
  }
  else{
    passable=false;
  }*/
}
bool Decor::getPassable() const {
  return this->passable;
}

void Decor::setPassable(bool passable){
  this->passable=passable;
}
IdDecor Decor::getIdDecor() const{
  return this->idDecor;
}
void Decor::setIdDecor(IdDecor idDecor){
  this->idDecor=idDecor;
}
