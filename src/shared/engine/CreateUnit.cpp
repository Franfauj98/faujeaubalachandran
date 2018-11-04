#include "CreateUnit.h"
#include <iostream>
using namespace engine;
using namespace std;

CreateUnit::~CreateUnit (){

}

CommandTypeId CreateUnit::getTypeId () const{
  return CommandTypeId::CREATEUNIT;
}
void CreateUnit::execute (){

}
