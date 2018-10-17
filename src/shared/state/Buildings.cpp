#include "Buildings.h"
#include<iostream>
using namespace state;


Buildings::Buildings() : Element(){
}

Buildings::Buildings (int id, Position position, int level,IdTexture idTexture, BuildingCost buildingCost, int life) : Element(position){
  if(idBuilding>=0){
    this->idBuilding= id;
  }else{
    std::cerr<<"idBuilding must be positive"<<std::endl;
    this->idBuilding= 0;
  }
  if(level>=0 && level<5){
    this->level= level;
  }else{
    std::cerr<<"level must be positive or smaller than 5"<<std::endl;
    this->level= 0;
  }
  this->idTexture=idTexture;
  this->buildingCost=buildingCost;
}

int Buildings::getLevel () const {
  return this->level;
}
void Buildings::setLevel (const int level) {
  if(level>=0 && level<5){
    this->level=level;
  }else{
    std::cerr<<"level must be positive or smaller than 5"<<std::endl;
    this->level=0;
  }
}

BuildingCost Buildings::getBuildingCost () const {
  return this->buildingCost;
}
void Buildings::setBuildingCost (BuildingCost buildingCost) {
  if(buildingCost.getGold()>0 && buildingCost.getWood()>0 && buildingCost.getGold()<10000 && buildingCost.getWood()<10000){
    this->buildingCost=buildingCost;
  }else{
    std::cerr<<"buldingCost must be positive or smaller than 10000";
    BuildingCost buildingCostnull(0,0);
    this->buildingCost=buildingCostnull;
    }
  }

  int Buildings::getLife () const {
    return this->life;
  }
  void Buildings::setLife (const int life) {
    if(life>=0 && life<1000){
      this->life=life;
    }else{
      std::cerr<<"life must be positive or smaller than 1000"<<std::endl;
      this->life=0;
    }
  }

// Setters and Getters
IdTexture Buildings::getIdTexture() const{
  return this->idTexture;
}
void Buildings::setIdTexture(const IdTexture idTexture){
  this->idTexture=idTexture;
}
int Buildings::getIdBuilding() const{
  return this->idBuilding;
}
void Buildings::setIdBuilding(const int idBuilding){
  if (idBuilding>=0){
    this->idBuilding=idBuilding;
  }
  else {
    std::cerr<<"idBuilding must be positive"<<std::endl;
    this->idBuilding=0;
  }
}
bool Buildings::isPassable(){
  return false;
}
Buildings::~Buildings(){

}
