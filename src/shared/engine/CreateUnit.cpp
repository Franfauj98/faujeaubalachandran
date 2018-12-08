#include "CreateUnit.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;

CreateUnit::~CreateUnit (){

}

CreateUnit::CreateUnit (int x, int y, int x2, int y2, int unit){
  this->x = x;
  this->y = y;
  this->x2 = x2;
  this->y2 = y2;
  this->unit = unit;
}

CommandTypeId CreateUnit::getTypeId () const{
  return CommandTypeId::CREATEUNIT;
}

void CreateUnit::execute (state::Observable& map){
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
    if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      switch(building->getLevel()){
        case 1: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 50 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 50 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 50);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 50);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
        case 2: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 100 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 100 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 100);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 100);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
        case 3: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 150 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 150 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 150);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 150);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
        case 4: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 200 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 200 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 200);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 200);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
      }
      break;
    }
  }
}

void CreateUnit::rollback(state::Observable& map){
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
    if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      switch(building->getLevel()){
        case 1: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 50 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 50 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 50);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 50);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
        case 2: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 100 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 100 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 100);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 100);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
        case 3: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 150 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 150 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 150);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 150);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
        case 4: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 200 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 200 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 200);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 200);
            map.notifyObserver(map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          }
          break;
        }
      }
      break;
    }
  }
}
