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
<<<<<<< HEAD
  // cout<<"x:"<<this->x<<" y:"<<this->y<<endl;
=======
>>>>>>> 03c18a3fec9dad39e6552b8d5fe83dcb2a3567b6
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  int level=building->getLevel();
  Palace* palace=dynamic_cast<Palace*>(map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get());
  Barrack* barrack=dynamic_cast<Barrack*>(map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get());
  Ressource* ressource=dynamic_cast<Ressource*>(map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get());
  if(palace!=nullptr){
    Position pos(0,0);
    Palace palace2(0, pos, level-1);
    for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
      if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
          (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() + palace2.getBuildingCost().getGold());
          (map.getAllMaps().getEmpires()[i].get())->setWoodRessource((map.getAllMaps().getEmpires()[i].get())->getWoodRessource() + palace2.getBuildingCost().getWood());
          map.notifyObserverPrev(map,this->y+25*this->x,map.getAllMaps().getMapMatrix()[this->x][this->y], 1,0,0);
        }
      }
  }
  else if(barrack!=nullptr){
      Position pos(0,0);
      Palace barrack2(0, pos, level-1);
      for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
        if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() + barrack2.getBuildingCost().getGold());
            (map.getAllMaps().getEmpires()[i].get())->setWoodRessource((map.getAllMaps().getEmpires()[i].get())->getWoodRessource() + barrack2.getBuildingCost().getWood());
            map.notifyObserverPrev(map,this->y+25*this->x,map.getAllMaps().getMapMatrix()[this->x][this->y], 1,0,0);
          }
        }
    }
    else if(ressource!=nullptr){
        Position pos(0,0);
        Palace ressource2(0, pos, level-1);
        for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
          if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
              (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() + ressource2.getBuildingCost().getGold());
              (map.getAllMaps().getEmpires()[i].get())->setWoodRessource((map.getAllMaps().getEmpires()[i].get())->getWoodRessource() + ressource2.getBuildingCost().getWood());
              map.notifyObserverPrev(map,this->y+25*this->x,map.getAllMaps().getMapMatrix()[this->x][this->y], 1,0,0);
            }
          }
      }
}

int LevelUp::getX(){
  return this->x;
}

int LevelUp::getY(){
  return this->y;
}
