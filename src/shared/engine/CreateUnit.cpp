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

bool CreateUnit::execute (state::Observable& map, int x, int y, int x2, int y2, int unit){
  Buildings* building = (Buildings *)map.getAllMaps().getBuildingsMap()[y+25*x].get();
  for(size_t i = 0; i<map.getAllMaps().getEmpires().size();i++){
    if((map.getAllMaps().getEmpires()[i].get())->getId() == building->getIdBuilding()){
      switch(building->getLevel()){
        case 1: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 50 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 50 && x2>=x-1 && x2<=x+1 && y2>=y-1 && y2<=y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 50);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 50);
            map.notifyObserver(map,y+25*x,30, 2,unit,y2+25*x2);
          } else return false;
          break;
        }
        case 2: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 100 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 100 && x2>=x-1 && x2<=x+1 && y2>=y-1 && y2<=y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 100);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 100);
            map.notifyObserver(map,y+25*x,30, 2,unit,y2+25*x2);
          } else return false;
          break;
        }
        case 3: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 150 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 150 && x2>=x-1 && x2<=x+1 && y2>=y-1 && y2<=y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 150);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 150);
            map.notifyObserver(map,y+25*x,30, 2,unit,y2+25*x2);
          } else return false;
          break;
        }
        case 4: {
          if((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() >= 200 &&
          (map.getAllMaps().getEmpires()[i].get())->getFoodRessource() >= 200 && x2>=x-1 && x2<=x+1 && y2>=y-1 && y2<=y+1){
            (map.getAllMaps().getEmpires()[i].get())->setGoldRessource((map.getAllMaps().getEmpires()[i].get())->getGoldRessource() - 200);
            (map.getAllMaps().getEmpires()[i].get())->setFoodRessource((map.getAllMaps().getEmpires()[i].get())->getFoodRessource() - 200);
            map.notifyObserver(map,y+25*x,30, 2,unit,y2+25*x2);
          } else return false;
          break;
        }
      }
      break;
    }

  }
  return true;
}
