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

bool CreateUnit::execute (){
  Buildings* building = (Buildings *)this->map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
  for(size_t i = 0; i<this->map.getAllMaps().getEmpires().size();i++){
    if((this->map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      switch(building->getLevel()){
        case 1: {
          if((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 50 &&
          (this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 50 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (this->map.getAllMaps().getEmpires()[i].get())->setGoldRessource((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 50);
            (this->map.getAllMaps().getEmpires()[i].get())->setFoodRessource((this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 50);
            this->map.notifyObserver(this->map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          } else return false;
          break;
        }
        case 2: {
          if((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 100 &&
          (this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 100 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (this->map.getAllMaps().getEmpires()[i].get())->setGoldRessource((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 100);
            (this->map.getAllMaps().getEmpires()[i].get())->setFoodRessource((this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 100);
            this->map.notifyObserver(this->map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          } else return false;
          break;
        }
        case 3: {
          if((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 150 &&
          (this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 150 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (this->map.getAllMaps().getEmpires()[i].get())->setGoldRessource((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 150);
            (this->map.getAllMaps().getEmpires()[i].get())->setFoodRessource((this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 150);
            this->map.notifyObserver(this->map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          } else return false;
          break;
        }
        case 4: {
          if((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 200 &&
          (this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 200 && this->x2>=this->x-1 && this->x2<=this->x+1 && this->y2>=this->y-1 && this->y2<=this->y+1){
            (this->map.getAllMaps().getEmpires()[i].get())->setGoldRessource((this->map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 200);
            (this->map.getAllMaps().getEmpires()[i].get())->setFoodRessource((this->map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 200);
            this->map.notifyObserver(this->map,this->y+25*this->x,30, 2,this->unit,this->y2+25*this->x2);
          } else return false;
          break;
        }
      }
      break;
    }

  }
  return true;
}
