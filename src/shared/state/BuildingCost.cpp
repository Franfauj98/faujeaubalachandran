#include "BuildingCost.h"
using namespace state;

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

BuildingCost::~BuildingCost(){

}
