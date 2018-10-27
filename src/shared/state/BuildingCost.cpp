#include "BuildingCost.h"
#include<iostream>
using namespace state;

BuildingCost::BuildingCost(){
  this->gold=0;
  this->wood=0;
}

BuildingCost::BuildingCost(int gold,int wood){
  try{
    if (gold>=0 && gold<=1000 && wood>=0 && wood<=1000){
      this->gold=gold;
      this->wood=wood;
    } else {
      this->gold=0;
      this->wood=0;
      throw std::string("ressources must be positive or smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

void BuildingCost::setGold (const int gold){
  try{
    if (gold>=0 && gold<=1000){
      this->gold=gold;
    } else {
      this->gold=0;
      throw std::string("gold must be positive or smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

 int BuildingCost::getGold () const{
  return this->gold;
}
void BuildingCost::setWood (const int wood){
  try{
    if (wood>=0 && wood<=1000){
      this->wood=wood;
    } else {
      this->wood=0;
      throw std::string("wood must be positive or smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}
int BuildingCost::getWood () const{
  return this->wood;
}

BuildingCost::~BuildingCost(){

}
