#include "UnitCost.h"
#include<iostream>
using namespace state;

UnitCost::UnitCost(){
  this->gold=0;
  this->food=0;
}

UnitCost::UnitCost(int gold, int food){

  if (gold>=0){
    this->gold=gold;
  }
  else {
    std::cerr<<"gold must be positive"<<std::endl;
    this->gold=0;
  }
  if (food>=0){
    this->food=food;
  }
  else{
    std::cerr<<"food must be positive"<<std::endl;
    this->food=0;
  }
}

void UnitCost::setGold (int gold){
  if (gold>=0){
    this->gold=gold;
  }
  else {
    std::cerr<<"gold must be positive"<<std::endl;
    this->gold=0;
  }
}
int UnitCost::getGold () const{
  return this->gold;
}
void UnitCost::setFood (int food){
  if (food>=0){
    this->food=food;
  }
  else{
    std::cerr<<"food must be positive"<<std::endl;
    this->food=0;
  }
}
int UnitCost::getFood () const{
  return this->food;
}

UnitCost::~UnitCost(){

}
