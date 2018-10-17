#include "BuildingCost.h"
#include<iostream>
using namespace state;

BuildingCost::BuildingCost(){
  this->gold=0;
  this->wood=0;
}

BuildingCost::BuildingCost(int gold,int wood){
  if (gold>=0 && gold<10000){
    this->gold=gold;
  }else {
    std::cerr << "gold must be positive or smaller than 10000" <<std::endl;
    this->gold=0;
  }
  if (wood>=0 && wood<10000){
    this->wood=wood;
  }else {
    std::cerr << "wood must be positive or smaller than 10000" <<std::endl;
    this->wood=0;
  }
}

void BuildingCost::setGold (const int gold){
  if (gold>=0 && gold<10000){
    this->gold=gold;
  }else{
    std::cerr << "gold must be positive or smaller than 10000" <<std::endl;
    this->gold=0;
  }
}
 int BuildingCost::getGold () const{
  return this->gold;
}
void BuildingCost::setWood (const int wood){
  if (wood>=0 && wood<10000){
    this->wood=wood;
  }else {
    std::cerr << "wood must be positive or smaller than 10000" <<std::endl;
    this->wood=0;
  }
}
int BuildingCost::getWood () const{
  return this->wood;
}

BuildingCost::~BuildingCost(){

}
