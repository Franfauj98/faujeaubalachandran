#include "LevelUp.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace std;
using namespace state;

LevelUp::~LevelUp (){

}

CommandTypeId LevelUp::getTypeId () const{
  return CommandTypeId::LEVELUP;
}
void LevelUp::execute (state::Observable& map, int x, int y){
   map.notifyObserver(map,y+25*x,map.getAllMaps().getMapMatrix()[x][y], 1,0,0);
}
