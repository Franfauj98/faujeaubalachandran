#include "CaseIdentifier.h"
#include "../../shared/state.h"
#include "../../client/render.h"
#include <iostream>
using namespace engine;
using namespace std;



CaseIdentifier::~CaseIdentifier (){

}

CommandTypeId CaseIdentifier::getTypeId () const{
  return CommandTypeId::CASEIDENTIFIER;
}

int CaseIdentifier::execute (){
  return this->map.getAllMaps().getMapMatrix()[this->x][this->y];
}
