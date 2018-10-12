#include "Decor.h"
using namespace state;

Decor::Decor():Element() {

}

Decor::Decor(IdDecor id, Position position):Element(position) {
  this->idDecor=id;
  if (id=="ARBRE"){
    passable=true;
  }
  else{
    passable=false;
  }
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
