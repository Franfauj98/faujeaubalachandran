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
  // if (map.getAllMaps().getUnitsMap()[x2+25*y2]==26 || map.getAllMaps().getUnitsMap()[x2+25*y2]==27 ||
  // map.getAllMaps().getUnitsMap()[x2+25*y2]==28 || map.getAllMaps().getUnitsMap()[x2+25*y2]==29){
  //   map.notifyObserver(map,map.getAllMaps().getUnitsMap()[x+25*y],x+25*y,map.getAllMaps().getMapMatrix()[x][y], 4,-1,
  //   1,x2+25*y2);
  // }
  // else if (map.getAllMaps().getUnitsMap()[x2+25*y2]==10 || map.getAllMaps().getUnitsMap()[x2+25*y2]==14 ||
  // map.getAllMaps().getUnitsMap()[x2+25*y2]==18 || map.getAllMaps().getUnitsMap()[x2+25*y2]==22) {
  //   map.notifyObserver(map,map.getAllMaps().getUnitsMap()[x+25*y],x+25*y,map.getAllMaps().getMapMatrix()[x][y], 3,-1,
  //   1,x2+25*y2);
  // }
}
