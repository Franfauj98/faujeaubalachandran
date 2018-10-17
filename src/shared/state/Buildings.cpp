#include "Buildings.h"
#include<iostream>
using namespace state;

Buildings::Buildings() : Element(){
  Position pos0(0,0);
  this->position= pos0;
  this->idBuilding=0;
  this->level=0;
  BuildingCost buildingCost(0,0);
  this->buildingCost=buildingCost;
  
}

Buildings::Buildings (int id, Position position, int level,IdTexture idTexture, BuildingCost buildingCost, int life) : Element(position){
  try{
    if(idBuilding>=0){
      this->idBuilding= id;
    } else {
      throw std::string("idBuilding must be positive");
      this->idBuilding= 0;
    }
    if(level>=0 && level<5){
      this->level= level;
    } else {
      throw std::string("level must be positive or smaller than 5");
      this->level= 0;
    }
    this->idTexture=idTexture;
    this->buildingCost=buildingCost;
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

int Buildings::getLevel () const {
  return this->level;
}
void Buildings::setLevel (const int level) {
  try{
    if(level>=0 && level<5){
      this->level=level;
    } else {
      throw std::string("level must be positive or smaller than 5");
      this->level=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

BuildingCost Buildings::getBuildingCost () const {
  return this->buildingCost;
}
void Buildings::setBuildingCost (BuildingCost buildingCost) {
  try{
    if(buildingCost.getGold()>0 && buildingCost.getWood()>0 && buildingCost.getGold()<=10000 && buildingCost.getWood()<=10000){
      this->buildingCost=buildingCost;
    } else {
        throw std::string("buldingCost must be positive or smaller than 10000");
        BuildingCost buildingCostnull(0,0);
        this->buildingCost=buildingCostnull;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

int Buildings::getLife () const {
  return this->life;
}

void Buildings::setLife (const int life) {
  try{
    if(life>=0 && life<=1000){
      this->life=life;
    } else {
      throw std::string("life must be positive or smaller than 1000");
      this->life=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
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
  try{
    if (idBuilding>=0){
      this->idBuilding=idBuilding;
    } else {
      throw std::string("idBuilding must be positive");
      this->idBuilding=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}
bool Buildings::isPassable(){
  return false;
}
Buildings::~Buildings(){

}
