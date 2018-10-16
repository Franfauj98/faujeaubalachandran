#include "Ressource.h"
#include<iostream>
using namespace state;

Ressource::Ressource():Buildings(){

}

Ressource::Ressource(int production, int id, Position position, int level, IdTexture idTexture,BuildingCost ressourceCost):Buildings(id,position,level,idTexture, ressourceCost){
  if(production>=0){
    this->production=production;
  }else{
    std::cerr<<"production must be positive"<<std::endl;
    this->production=0;
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

      break;}
    case 2 :{
      setProduction(4);
      setIdBuilding(id);
      setPosition(position);
      setLevel(2);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(100,100);
      setBuildingCost(ressourceCost);
      break;}
    case 3 :{
      setProduction(6);
      setIdBuilding(id);
      setPosition(position);
      setLevel(3);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(150,150);
      setBuildingCost(ressourceCost);
      break;}
    case 4 :{
      setProduction(8);
      setIdBuilding(id);
      setPosition(position);
      setLevel(4);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(200,200);
      setBuildingCost(ressourceCost);
      break;}
    default :{
      setProduction(2);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(RESSOURCE);
      BuildingCost ressourceCost(50,50);
      setBuildingCost(ressourceCost);
      break;}
  }
}

int Ressource::getProduction() const {
  return this->production;
}

void Ressource::setProduction(int production) {
  if(production>=0){
    this->production=production;
  }
  else {
    std::cerr<<"production must be positive"<<std::endl;
    this->production=0;
  }
}

Ressource::~Ressource(){

}
