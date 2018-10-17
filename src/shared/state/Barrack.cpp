#include "Barrack.h"
#include "Units.h"
#include "Arrow.h"
#include "Cavalier.h"
#include "Decurion.h"
#include "Catapult.h"
#include <iostream>
using namespace state;

Barrack::Barrack():Buildings(){

}

Barrack::Barrack(int capacity, int id, Position position, int level, IdTexture idTexture,BuildingCost barrackCost):Buildings(id,position,level,idTexture,barrackCost){
  if (capacity>=0 && capacity<10){
    this->capacity=capacity;
  } else{
    std::cerr << "capacity must be positive or smaller than 10" <<std::endl;
    this->capacity=0;
  }

  if (unitsNumber>=0 && unitsNumber<=capacity){
    this->unitsNumber=unitsNumber;
  }else{
    std::cerr << "unitsNumber must be positive or smaller than capacity " <<std::endl;
    this->unitsNumber=0;
  }
}

Barrack::Barrack (int id, Position position, int level) : Buildings() {
  switch(level){
    case 1 : {
      setCapacity(2);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(BARRACK);
      BuildingCost barrackCost(50,50);
      setBuildingCost(barrackCost);
      setUnitsNumber(0);
      break;}
    case 2 :{
      setCapacity(4);
      setIdBuilding(id);
      setPosition(position);
      setLevel(2);
      setIdTexture(BARRACK);
      BuildingCost barrackCost(100,100);
      setBuildingCost(barrackCost);
      setUnitsNumber(0);
      break;}
    case 3 :{
      setCapacity(6);
      setIdBuilding(id);
      setPosition(position);
      setLevel(3);
      setIdTexture(BARRACK);
      BuildingCost barrackCost(150,150);
      setBuildingCost(barrackCost);
      setUnitsNumber(0);
      break;}
    case 4 :{
      setCapacity(8);
      setIdBuilding(id);
      setPosition(position);
      setLevel(4);
      setIdTexture(BARRACK);
      BuildingCost barrackCost(200,200);
      setBuildingCost(barrackCost);
      setUnitsNumber(0);
      break;}
    default :{
      setCapacity(2);
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(BARRACK);
      BuildingCost barrackCost(50,50);
      setBuildingCost(barrackCost);
      setUnitsNumber(0);
      break;}
  }
}

int Barrack::getCapacity() const{
  return this->capacity;
}

void Barrack::setCapacity(const int capacity){
  if (capacity>=0 && capacity<10){
    this->capacity=capacity;
  }
  else {
    std::cerr << "capacity must be positive or smaller than 10" <<std::endl;
    this->capacity=0;
  }
}

int Barrack::getUnitsNumber() const{
  return this->unitsNumber;
}

void Barrack::setUnitsNumber(const int unitsNumber){
  if (unitsNumber>=0 && unitsNumber<=capacity){
    this->unitsNumber=unitsNumber;
  }
  else {
    std::cerr << "unitsNumber must be positive or smaller than capacity " <<std::endl;
    this->unitsNumber=0;
  }

}

Arrow* Barrack::createArrow(Arrow* arrowName, int level,Position position, int id){
  arrowName=0;
  if (this->unitsNumber<this->capacity){
     arrowName=new Arrow(level,position,id);
  }
  return arrowName;
}

Cavalier* Barrack::createCavalier (Cavalier* cavalierName, int level, Position position, int id){
  cavalierName=0;
  if (this->unitsNumber<this->capacity){
     cavalierName=new Cavalier(level,position,id);
  }
  return cavalierName;
}

Decurion* Barrack::createDecurion (Decurion* decurionName, int level, Position position, int id){
  decurionName=0;
  if (this->unitsNumber<this->capacity){
     decurionName=new Decurion(level,position,id);
  }
  return decurionName;
}

Catapult* Barrack::createCatapult (Catapult* catapultName, int level, Position position, int id){
  catapultName=0;
  if (this->unitsNumber<this->capacity){
     catapultName=new Catapult(level,position,id);
  }
  return catapultName;
}

void Barrack::destructArrow (Arrow* arrow) {
  delete arrow;
}
void Barrack::destructCavalier (Cavalier* cavalier){
  delete cavalier;
}

void Barrack::destructDecurion (Decurion* decurion){
  delete decurion;
}

void Barrack::destructCatapult (Catapult* catapult){
  delete catapult;
}

Barrack::~Barrack(){

}
