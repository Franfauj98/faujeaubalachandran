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

int CaseIdentifier::execute (state::Observable& map,int x, int y){
  return map.getAllMaps().getMapMatrix()[y][x];
}
