#include "LevelUp.h"
#include <iostream>
using namespace engine;
using namespace std;

LevelUp::~LevelUp (){

}

CommandTypeId LevelUp::getTypeId () const{
  return CommandTypeId::LEVELUP;
}
void LevelUp::execute (state::Observable& map, int x, int y){
   map.notifyObserver(map,x+25*y,map.getAllMaps().getMapMatrix()[x][y], 1,0,0);

}
