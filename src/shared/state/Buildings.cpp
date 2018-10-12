#include "Buildings.h"
using namespace state;


Buildings::Buildings() : Element(){
}

Buildings::Buildings (int id, Position position, int level,IdTexture idTexture) : Element(position){
  this->idBuilding= id;
  this->level=level;
  this->idTexture=idTexture;
}
int Buildings::getId () const {
  return this->idBuilding;
}
void Buildings::setId (int id){
  this->idBuilding=id;
}

int Buildings::getLevel () const {
  return this->level;
}
void Buildings::setLevel (int level) {
  this->level=level;
}
// Setters and Getters
IdTexture Buildings::getIdTexture() const{
  return this->idTexture;
}
void Buildings::setIdTexture(IdTexture idTexture){
  this->idTexture=idTexture;
}
int Buildings::getIdBuilding() const{
  return this->idBuilding;
}
void Buildings::setIdBuilding(int idBuilding){
  this->idBuilding=idBuilding;
}
bool isPassable(){
  return false;
}
Buildings::~Buildings(){

}
