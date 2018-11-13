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
void LevelUp::execute (){
  Buildings* building = (Buildings *)this->map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  for(size_t i = 0; i<this->map.getAllMaps().getEmpires().size();i++){
    if((this->map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      if((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= building->getBuildingCost().getGold() &&
      (this->map.getAllMaps().getEmpires()[i].get())->getWoodRessource() >= building->getBuildingCost().getWood()){
        (this->map.getAllMaps().getEmpires()[i].get())->setGoldRessource((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - building->getBuildingCost().getGold());
        (this->map.getAllMaps().getEmpires()[i].get())->setWoodRessource((this->map.getAllMaps().getEmpires()[i].get())->getWoodRessource() - building->getBuildingCost().getWood());
        this->map.notifyObserver(map,this->y+25*this->x,map.getAllMaps().getMapMatrix()[this->x][this->y], 1,0,0);
      }
    }
  }
}
