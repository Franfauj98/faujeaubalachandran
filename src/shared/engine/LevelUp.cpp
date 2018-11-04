#include "LevelUp.h"
#include <iostream>
using namespace engine;
using namespace std;

LevelUp::~LevelUp (){

}

CommandTypeId LevelUp::getTypeId () const{
  return CommandTypeId::LEVELUP;
}
void LevelUp::execute (){

}
