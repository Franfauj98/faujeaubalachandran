#include "CreateUnit.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;

CreateUnit::~CreateUnit (){

}

CommandTypeId CreateUnit::getTypeId () const{
  return CommandTypeId::CREATEUNIT;
}
void CreateUnit::execute (state::Observable& map, int x, int y, int unit){
  map.notifyObserver(map,x+25*y,map.getAllMaps().getMapMatrix()[x][y], 2,unit,0);
}
