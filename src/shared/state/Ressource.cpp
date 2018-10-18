#include "Ressource.h"
#include<iostream>
using namespace state;

Ressource::Ressource():Buildings(){
  this->production=0;
}

Ressource::Ressource(int production, int id, Position position, int level, BuildingCost ressourceCost,IdTexture idTexture,int life):Buildings(id,position,level,idTexture, ressourceCost){
  try{
    if(production>=0 && production<=1000){
      this->production=production;
    } else {
      this->production=0;
      throw std::string("production must be positive or be smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

Ressource::Ressource (int id, Position position, int level) : Buildings() {
  switch(level){
    case 1 :{
      setProduction(2);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(50,50);
      setBuildingCost(ressourceCost);
      setLife(0);

      break;}
    case 2 :{
      setProduction(4);
      setIdBuilding(id);
      setPosition(position);
      setLevel(2);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(100,100);
      setBuildingCost(ressourceCost);
      setLife(0);
      break;}
    case 3 :{
      setProduction(6);
      setIdBuilding(id);
      setPosition(position);
      setLevel(3);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(150,150);
      setBuildingCost(ressourceCost);
      setLife(0);
      break;}
    case 4 :{
      setProduction(8);
      setIdBuilding(id);
      setPosition(position);
      setLevel(4);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(200,200);
      setBuildingCost(ressourceCost);
      setLife(0);
      break;}
    default :{
      setProduction(2);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(50,50);
      setBuildingCost(ressourceCost);
      setLife(0);
      break;}
  }
}

int Ressource::getProduction() const {
  return this->production;
}

void Ressource::setProduction(const int production) {
  try{
    if(production>=0 && production<=1000){
      this->production=production;
    } else {
      this->production=0;
      throw std::string("production must be positive or be smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

Ressource::~Ressource(){

}
