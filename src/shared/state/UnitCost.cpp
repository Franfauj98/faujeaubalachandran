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
  this->gold=gold;
}
int UnitCost::getGold () const{
  return this->gold;
}
void UnitCost::setFood (int food){
  this->food=food;
}
int UnitCost::getFood () const{
  return this->food;
}

UnitCost::~UnitCost(){

}
