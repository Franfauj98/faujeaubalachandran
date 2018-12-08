#include "LevelUp.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace std;
using namespace state;

LevelUp::~LevelUp (){

}

LevelUp::LevelUp (int x, int y){
  this->x = x;
  this->y = y;
}


CommandTypeId LevelUp::getTypeId () const{
  return CommandTypeId::LEVELUP;
}
void LevelUp::execute (state::Observable& map){
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
    if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= building->getBuildingCost().getGold() &&
      (map.getAllMaps().getEmpires()[i].get())->getWoodRessource() >= building->getBuildingCost().getWood()){
        (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - building->getBuildingCost().getGold());
        (map.getAllMaps().getEmpires()[i].get())->setWoodRessource((map.getAllMaps().getEmpires()[i].get())->getWoodRessource() - building->getBuildingCost().getWood());
        map.notifyObserver(map,this->y+25*this->x,map.getAllMaps().getMapMatrix()[this->x][this->y], 1,0,0);
      }
    }
  }
}

void LevelUp::rollback(state::Observable& map){
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
    if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= building->getBuildingCost().getGold() &&
      (map.getAllMaps().getEmpires()[i].get())->getWoodRessource() >= building->getBuildingCost().getWood()){
        (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - building->getBuildingCost().getGold());
        (map.getAllMaps().getEmpires()[i].get())->setWoodRessource((map.getAllMaps().getEmpires()[i].get())->getWoodRessource() - building->getBuildingCost().getWood());
        map.notifyObserver(map,this->y+25*this->x,map.getAllMaps().getMapMatrix()[this->x][this->y], 1,0,0);
      }
    }
  }
}
