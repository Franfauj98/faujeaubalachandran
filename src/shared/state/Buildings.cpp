#include "Buildings.h"
#include<iostream>
using namespace state;

Buildings::Buildings() {
  Position p(0,0);
  this->position = p;
  this->idBuilding=0;
  this->level=0;
  BuildingCost buildingCost(0,0);
  this->buildingCost=buildingCost;
  this->idTexture=NONE_BUILDING;
  this->type=0;
}

Buildings::Buildings (int id, Position position, int level,IdTexture idTexture, BuildingCost buildingCost, int life) {
  try{
    if(id>=0 && position.getX()>=0 && position.getX()<=30 && position.getY()>=0 && position.getY()<=30 && level>=0 && level<5
  && buildingCost.getWood()>=0 && buildingCost.getWood()>=10000 && buildingCost.getGold()>=0 && buildingCost.getGold()>=10000 && life >=0 && life <=1000){
      this->position = position;
      this->idBuilding= id;
      this->level= level;
      this->idTexture=idTexture;
      this->buildingCost=buildingCost;
      this->life=life;
    } else {
        this->idBuilding= 0;
        this->level= 0;
        this->idTexture=NONE_BUILDING;
        BuildingCost buildingCostNull(0,0);
        this->buildingCost=buildingCostNull;
        this->life=0;
        std::string message="idBuilding must be positive";
        message+='\n';
        message+="Position must be on the map";
        message+='\n';
        message+="level must be positive and smaller than 5";
        message+='\n';
        message+="buildingCost must be positive and smaller than 1000";
        message+='\n';
        message+="life must be positive and smaller than 1000";
        message+='\n';
        throw std::string(message);
    }
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
      this->level=0;
      throw std::string("level must be positive or smaller than 5");
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
    if(buildingCost.getGold()>=0 && buildingCost.getWood()>=0 && buildingCost.getGold()<=1000 && buildingCost.getWood()<=1000){
      this->buildingCost=buildingCost;
    } else {
        BuildingCost buildingCostnull(0,0);
        this->buildingCost=buildingCostnull;
        throw std::string("buldingCost must be positive or smaller than 1000");
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
      this->life=0;
      throw std::string("life must be positive or smaller than 1000");
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
      this->idBuilding=0;
      throw std::string("idBuilding must be positive");
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
