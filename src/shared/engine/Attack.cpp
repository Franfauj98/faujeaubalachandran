#include "Attack.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;

Attack::~Attack (){

}

CommandTypeId Attack::getTypeId () const{
  return CommandTypeId::ATTACK;
}
void Attack::execute(state::Observable& map, int x, int y, int x2, int y2){
  std::vector<std::vector<int>> Matrix = map.getAllMaps().getMapMatrix();
  Units* unit =(Units*) map.getAllMaps().getUnitsMap()[y+25*x].get();
  int id = unit->getIdUnits();
  int shot = map.getAllMaps().getEmpires()[id-1]->getShot();
  if ((Matrix[x2][y2]==26 || Matrix[x2][y2]==27 || Matrix[x2][y2]==28 || Matrix[x2][y2]==29) && shot==1) {
    map.notifyObserver(map,y+25*x,Matrix[x][y], 3,-1,y2+25*x2);
  }
  else if ((Matrix[x2][y2]==10 || Matrix[x2][y2]==14 || Matrix[x2][y2]==18 || Matrix[x2][y2]==22)&& shot==1) {
    map.notifyObserver(map,y+25*x,Matrix[x][y], 2,-1,y2+25*x2);
  }
}
