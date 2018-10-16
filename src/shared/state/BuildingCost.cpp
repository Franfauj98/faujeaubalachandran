#include "BuildingCost.h"
#include<iostream>
using namespace state;

BuildingCost::BuildingCost(){
  this->gold=0;
  this->wood=0;
}

BuildingCost::BuildingCost(int gold, int wood){
  this->gold=gold;
  this->wood=wood;
}

void BuildingCost::setGold (int gold){
  this->gold=gold;
}
int BuildingCost::getGold () const{
  return this->gold;
}
void BuildingCost::setWood (int wood){
  this->wood=wood;
}
int BuildingCost::getWood () const{
  return this->wood;
}

void BuildingCost::operator<<(BuildingCost buildingCost){
  std::cout << "BuildingCost:" << buildingCost.getGold() << "gold," << buildingCost.getWood() <<"wood"<<std::endl;
}

BuildingCost::~BuildingCost(){

}
