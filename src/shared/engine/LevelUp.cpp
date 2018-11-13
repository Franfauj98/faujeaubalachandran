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
bool LevelUp::execute (state::Observable& map, int x, int y){
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[y+25*x].get();
  for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
    if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= building->getBuildingCost().getGold() &&
      (map.getAllMaps().getEmpires()[i].get())->getWoodRessource() >= building->getBuildingCost().getWood()){
        (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - building->getBuildingCost().getGold());
        (map.getAllMaps().getEmpires()[i].get())->setWoodRessource((map.getAllMaps().getEmpires()[i].get())->getWoodRessource() - building->getBuildingCost().getWood());
        map.notifyObserver(map,y+25*x,map.getAllMaps().getMapMatrix()[x][y], 1,0,0);
        return true;
      }
    }
  }
  return false;
}
