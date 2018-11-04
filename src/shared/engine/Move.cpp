#include "Move.h"
#include <iostream>
using namespace engine;
using namespace std;

Move::~Move (){

}

CommandTypeId Move::getTypeId () const{
  return CommandTypeId::MOVE;
}
void Move::execute (){

}
