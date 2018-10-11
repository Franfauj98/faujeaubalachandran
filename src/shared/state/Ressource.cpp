#include "Ressource.h"
using namespace state;

Ressource::Ressource():Buildings(){

}

Ressource::Ressource(int production, int id, Position position, int level, IdTexture idTexture):Buildings(id,position,level,idTexture){
  this->production=production;
}

int Ressource::getProduction() const {
  return this->production;
}

void Ressource::setProduction(int production) {
   this->production=production;
}
