#include "Move.h"
#include <iostream>
using namespace engine;
using namespace std;

Move::~Move (){

}

CommandTypeId Move::getTypeId () const{
  return CommandTypeId::MOVE;
}
void Move::execute(state::Observable& map, int x, int y, int x2, int y2){
  if (map.getAllMaps().getMapMatrix()[x+1][y]!=1 && map.getAllMaps().getMapMatrix()[x+1][y]!=3 &&
      map.getAllMaps().getMapMatrix()[x-1][y]!=1 && map.getAllMaps().getMapMatrix()[x-1][y]!=3 &&
      map.getAllMaps().getMapMatrix()[x][y+1]!=1 && map.getAllMaps().getMapMatrix()[x][y+1]!=3 &&
      map.getAllMaps().getMapMatrix()[x][y-1]!=1 && map.getAllMaps().getMapMatrix()[x][y-1]!=3){

  map.notifyObserver(map,x+25*y,map.getAllMaps().getMapMatrix()[x][y], 2,-1,x2+25*y2);
  }

}
