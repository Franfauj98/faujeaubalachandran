#include "Barrack.h"
#include "Units.h"
#include "Arrow.h"
#include "Cavalier.h"
#include "Decurion.h"
#include "Catapult.h"
#include <iostream>
using namespace state;

Barrack::Barrack():Buildings(){
  this->capacity=0;
  this->unitsNumber=0;
}

Barrack::Barrack(int capacity, int id, Position position, int level,BuildingCost barrackCost,IdTexture idTexture,int life):Buildings(id,position,level,idTexture,barrackCost){
  try{
    if (capacity>=0 && capacity<=10){
      this->capacity=capacity;
      this->unitsNumber=0;
    } else {
      this->capacity=0;
      this->unitsNumber=0;
      throw std::string("capacity must be positive or smaller than 10");
    }
    } catch (std::string error){
    std::cerr << error << std::endl;
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
      setLife(0);

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
      setLife(0);
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
      setLife(0);
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
      setLife(0);
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
      setLife(0);
      break;}
  }
}

int Barrack::getCapacity() const{
  return this->capacity;
}

void Barrack::setCapacity(const int capacity){
  try{
    if (capacity>=0 && capacity<=10){
      this->capacity=capacity;
    } else {
      this->capacity=0;
      throw std::string("capacity must be positive or smaller than 10");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

int Barrack::getUnitsNumber() const{
  return this->unitsNumber;
}

void Barrack::setUnitsNumber(const int unitsNumber){
  try{
    if (unitsNumber>=0 && unitsNumber<=capacity){
      this->unitsNumber=unitsNumber;
    } else {
      this->unitsNumber=0;
      throw std::string("unitsNumber must be positive or smaller than capacity ");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

Arrow* Barrack::createArrow(int level,Position position, int id){
    Arrow* arrow=0;
    if (this->unitsNumber < this->capacity){
      arrow=new Arrow(level,position,id);
    } else {
      std::cerr << "UnitsNumber is bigger than capacity" << std::endl;
    }
    return arrow;
}

Cavalier* Barrack::createCavalier (int level, Position position, int id){
    Cavalier* cavalier=0;
    if (this->unitsNumber < this->capacity){
      cavalier=new Cavalier(level,position,id);
    } else {
      std::cerr << "UnitsNumber is bigger than capacity" << std::endl;
    }
      return cavalier;
}

Decurion* Barrack::createDecurion (int level, Position position, int id){
    Decurion* decurion=0;
    if (this->unitsNumber<this->capacity){
      decurion=new Decurion(level,position,id);
    } else {
      std::cerr << "UnitsNumber is bigger than capacity" << std::endl;
    }
    return decurion;
}

Catapult* Barrack::createCatapult (int level, Position position, int id){
    Catapult* catapult=0;
    if (this->unitsNumber<this->capacity){
      catapult=new Catapult(level,position,id);
    } else {
      std::cerr << "UnitsNumber is bigger than capacity" << std::endl;
    }
    return catapult;
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
