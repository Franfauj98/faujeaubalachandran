#include "Buildings.h"
#include<iostream>
using namespace state;


Buildings::Buildings() : Element(){
}

Buildings::Buildings (int id, Position position, int level,IdTexture idTexture, BuildingCost buildingCost) : Element(position){
  if(idBuilding>=0){
    this->idBuilding= id;
  }else{
    std::cerr<<"idBuilding must be positive"<<std::endl;
    this->idBuilding= 0;
  }
  if(level>=0){
    this->level= level;
  }else{
    std::cerr<<"level must be positive"<<std::endl;
    this->level= 0;
  }
  this->idTexture=idTexture;
  this->buildingCost=buildingCost;
}

int Buildings::getLevel () const {
  return this->level;
}
void Buildings::setLevel (int level) {
  if(level>=0){
    this->level=level;
  }else{
    std::cerr<<"level must be positive"<<std::endl;
    this->level=0;
  }
}

BuildingCost Buildings::getBuildingCost () const {
  return this->buildingCost;
}
void Buildings::setBuildingCost (BuildingCost buildingCost) {
  if(buildingCost.getGold()>0 && buildingCost.getWood()>0){
    this->buildingCost=buildingCost;
  }else{
    BuildingCost buildingCostnull(0,0);
      this->buildingCost=buildingCostnull;
    }
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
