#include "Attack.h"
#include <iostream>
using namespace engine;
using namespace std;

Attack::~Attack (){

}

CommandTypeId Attack::getTypeId () const{
  return CommandTypeId::ATTACK;
}
void Attack::execute (){

}
