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
  Buildings* building =(Buildings*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
  int id = building->getIdBuilding();
  int shot = map.getAllMaps().getEmpires()[id-1]->getShot();
  if (shot==1){
       map.notifyObserver(map,y+25*x,map.getAllMaps().getMapMatrix()[x][y], 1,0,0);
  }
}
