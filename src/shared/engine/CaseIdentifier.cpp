#include "CaseIdentifier.h"
#include "../../shared/state.h"
#include "../../client/render.h"
#include <iostream>
using namespace engine;
using namespace std;


CaseIdentifier::CaseIdentifier(int x, int y){
  this->x = x;
  this->y = y;
}

CaseIdentifier::~CaseIdentifier (){

}


CommandTypeId CaseIdentifier::getTypeId () const{
  return CommandTypeId::CASEIDENTIFIER;
}

void CaseIdentifier::execute (){
  this->map.getAllMaps().getMapMatrix()[this->x][this->y];
}
