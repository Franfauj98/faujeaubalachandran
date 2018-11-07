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
  if (map.getAllMaps().getMapMatrix()[x+1][y]==2 && map.getAllMaps().getMapMatrix()[x+1][y]==9 &&
      map.getAllMaps().getMapMatrix()[x-1][y]==2 && map.getAllMaps().getMapMatrix()[x-1][y]==9 &&
      map.getAllMaps().getMapMatrix()[x][y+1]==2 && map.getAllMaps().getMapMatrix()[x][y+1]==9 &&
      map.getAllMaps().getMapMatrix()[x][y-1]==2 && map.getAllMaps().getMapMatrix()[x][y-1]==9){

  map.notifyObserver(map,x+25*y,map.getAllMaps().getMapMatrix()[x][y], 2,-1,x2+25*y2);
  }

}
