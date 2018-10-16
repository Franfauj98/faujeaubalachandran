#include "BuildingCost.h"
#include<iostream>
using namespace state;

BuildingCost::BuildingCost(){
  this->gold=0;
  this->wood=0;
}

BuildingCost::BuildingCost(int gold,int wood){
  if (gold>=0){
    this->gold=gold;
  }else {
    std::cerr << "gold must be positive" <<std::endl;
    this->gold=0;
  }
  if (wood>=0){
    this->wood=wood;
  }else {
    std::cerr << "wood must be positive" <<std::endl;
    this->wood=0;
  }
}

void BuildingCost::setGold ( int gold){
  if (gold>=0){
    this->gold=gold;
  }else{
    std::cerr << "gold must be positive" <<std::endl;
    this->gold=0;
  }
}
 int BuildingCost::getGold () const{
  return this->gold;
}
void BuildingCost::setWood ( int wood){
  if (wood>=0){
    this->wood=wood;
  }else {
    std::cerr << "wood must be positive" <<std::endl;
    this->wood=0;
  }
}
int BuildingCost::getWood () const{
  return this->wood;
}

BuildingCost::~BuildingCost(){

}
