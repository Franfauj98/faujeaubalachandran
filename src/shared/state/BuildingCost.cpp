#include "BuildingCost.h"
#include<iostream>
using namespace state;

BuildingCost::BuildingCost(){
  this->gold=0;
  this->wood=0;
}

BuildingCost::BuildingCost(int gold,int wood){
  try{
    if (gold>=0 && gold<=10000){
      this->gold=gold;
    } else {
      throw std::string("gold must be positive or smaller than 10000");
      this->gold=0;
    }
    if (wood>=0 && wood<=10000){
      this->wood=wood;
    } else {
        throw std::string("wood must be positive or smaller than 10000");
        this->wood=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

void BuildingCost::setGold (const int gold){
  try{
    if (gold>=0 && gold<=10000){
      this->gold=gold;
    } else {
      throw std::string("gold must be positive or smaller than 10000");
      this->gold=0;
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
    if (wood>=0 && wood<=10000){
      this->wood=wood;
    } else {
      throw std::string("wood must be positive or smaller than 10000");
      this->wood=0;
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
