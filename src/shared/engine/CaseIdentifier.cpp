#include "CaseIdentifier.h"
#include <iostream>
using namespace engine;
using namespace std;

CaseIdentifier::~CaseIdentifier (){

}

CommandTypeId CaseIdentifier::getTypeId () const{
  return CommandTypeId::CASEIDENTIFIER;
}
// void CaseIdentifier::execute (state::map& map,int x, int y){
//
// }
