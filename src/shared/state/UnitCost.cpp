#include "UnitCost.h"
using namespace state;

UnitCost::UnitCost(){
  this->gold=0;
  this->food=0;
}

UnitCost::UnitCost(int gold, int food){
  this->gold=gold;
  this->food=food;
}

void UnitCost::setGold (int gold){
  if (gold>0){
    this->gold=gold;
  }
  else {
    this->gold=0;
  }
}
int UnitCost::getGold () const{
  return this->gold;
}
void UnitCost::setFood (int food){
  if (food>0){
    this->food=food;
  }
  else{
    this->food=0;
  }
}
int UnitCost::getFood () const{
  return this->food;
}

UnitCost::~UnitCost(){

}
