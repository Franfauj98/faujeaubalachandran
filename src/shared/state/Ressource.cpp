#include "Ressource.h"
#include<iostream>
using namespace state;

Ressource::Ressource():Buildings(){
  this->production=0;
}

Ressource::Ressource(int production, int id, Position position, int level, BuildingCost ressourceCost,IdTexture idTexture,int life):Buildings(id,position,level,idTexture, ressourceCost){
  try{
    if(production>=0 && production<=100){
      this->production=production;
      this->type = 7;
    } else {
      this->production=0;
      this->type = 7;
      throw std::string("production must be positive or be smaller than 100");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

Ressource::Ressource (int id, Position position, int level) : Buildings() {
  switch(level){
    case 1 :{
      setProduction(50);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(RESSOURCE1);
      BuildingCost ressourceCost(100,100);
      setBuildingCost(ressourceCost);
      setLife(0);
      this->type = 31;

      break;}
    case 2 :{
      setProduction(100);
      setIdBuilding(id);
      setPosition(position);
      setLevel(2);
      setIdTexture(RESSOURCE1);
      BuildingCost ressourceCost(200,200);
      setBuildingCost(ressourceCost);
      setLife(0);
      this->type = 31;
      break;}
    case 3 :{
      setProduction(150);
      setIdBuilding(id);
      setPosition(position);
      setLevel(3);
      setIdTexture(RESSOURCE1);
      BuildingCost ressourceCost(300,300);
      setBuildingCost(ressourceCost);
      setLife(0);
      this->type = 31;
      break;}
    case 4 :{
      setProduction(200);
      setIdBuilding(id);
      setPosition(position);
      setLevel(4);
      setIdTexture(RESSOURCE1);
      BuildingCost ressourceCost(400,400);
      setBuildingCost(ressourceCost);
      setLife(0);
      this->type = 31;
      break;}
    default :{
      setProduction(50);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(RESSOURCE1);
      BuildingCost ressourceCost(100,100);
      setBuildingCost(ressourceCost);
      setLife(0);
      this->type = 31;
      break;}
  }
}

int Ressource::getProduction() const {
  return this->production;
}

void Ressource::setProduction(const int production) {
  try{
    if(production>=0 && production<=100){
      this->production=production;
    } else {
      this->production=0;
      throw std::string("production must be positive or be smaller than 100");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

Ressource::~Ressource(){

}
