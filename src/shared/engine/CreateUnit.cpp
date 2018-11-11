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
void CreateUnit::execute (state::Observable& map, int x, int y, int x2, int y2, int unit){
  Buildings* barrack =(Buildings*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
  int id = barrack->getIdBuilding();
  int shot = map.getAllMaps().getEmpires()[id-1]->getShot();
  if (x2>=x-1 && x2<=x+1 && y2>=y-1 && y2<=y+1 && shot==1){
    map.notifyObserver(map,y+25*x,30, 2,unit,y2+25*x2);
  }
}
