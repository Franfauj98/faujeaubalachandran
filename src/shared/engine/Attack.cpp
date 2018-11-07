#include "Attack.h"
#include <iostream>
using namespace engine;
using namespace std;

Attack::~Attack (){

}

CommandTypeId Attack::getTypeId () const{
  return CommandTypeId::ATTACK;
}
void Attack::execute(state::Observable& map, int x, int y, int x2, int y2){
  if (map.getAllMaps().getMapMatrix()[x2][y2]==26 || map.getAllMaps().getMapMatrix()[x2][y2]==27 ||
  map.getAllMaps().getMapMatrix()[x2][y2]==28 || map.getAllMaps().getMapMatrix()[x2][y2]==29){
    map.notifyObserver(map,y+25*x,map.getAllMaps().getMapMatrix()[x][y], 3,-1,y2+25*x2);
  }
  else if (map.getAllMaps().getMapMatrix()[x2][y2]==10 || map.getAllMaps().getMapMatrix()[x2][y2]==14 ||
  map.getAllMaps().getMapMatrix()[x2][y2]==18 || map.getAllMaps().getMapMatrix()[x2][y2]==22) {
    map.notifyObserver(map,y+25*x,map.getAllMaps().getMapMatrix()[x][y], 2,-1,y2+25*x2);
  }
}
