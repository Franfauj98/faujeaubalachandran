#include "UnitCost.h"
#include<iostream>
using namespace state;

UnitCost::UnitCost(){
  this->gold=0;
  this->food=0;
}

UnitCost::UnitCost(int gold, int food){
  try{
    if (gold>=0 && gold<1000){
      this->gold=gold;
    }
    else {
      throw std::string("gold must be positive or be smaller than 1000");
      this->gold=0;
    }
    if (food>=0 && food<1000){
      this->food=food;
    }
    else{
      throw std::string("food must be positive or be smaller than 1000");
      this->food=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

void UnitCost::setGold (const int gold){
  try{
    if (gold>=0 && gold<1000){
      this->gold=gold;
    }
    else {
      throw std::string("gold must be positive or be smaller than 1000");
      this->gold=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}
int UnitCost::getGold () const{
  return this->gold;
}
void UnitCost::setFood (const int food){
  try{
    if (food>=0 && food<1000){
      this->food=food;
    }
    else{
      throw std::string("food must be positive  or be smaller than 1000");
      this->food=0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}
int UnitCost::getFood () const{
  return this->food;
}

UnitCost::~UnitCost(){

}
