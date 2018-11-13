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
bool Attack::execute(){
    std::vector<std::vector<int>> Matrix = this->map.getAllMaps().getMapMatrix();

    Units* unitToChange = (Units *)this->map.getAllMaps().getUnitsMap()[this->y+25*this->x].get();
    Units* unitToChange2 = (Units *)this->map.getAllMaps().getUnitsMap()[this->y2+25*this->x2].get();
    Buildings* buildingToAttack = (Buildings *)this->map.getAllMaps().getBuildingsMap()[this->y2+25*this->x2].get();
    std::cout << unitToChange->getIdUnits() << '\n';
    std::cout << buildingToAttack->getIdBuilding() << '\n';
    std::cout << unitToChange2->getIdUnits() << '\n';

    if ((Matrix[this->x2][this->y2]==26 || Matrix[this->x2][this->y2]==27 || Matrix[this->x2][this->y2]==28 || Matrix[this->x2][this->y2]==29)) {
      if(unitToChange->getIdUnits()!=buildingToAttack->getIdBuilding()){
        this->map.notifyObserver(map,this->y+25*this->x,Matrix[this->x][this->y], 3,-1,this->y2+25*this->x2);
      } else {
        return false;
      }
    } else if ((Matrix[this->x2][this->y2]==10 || Matrix[this->x2][this->y2]==14 || Matrix[this->x2][this->y2]==18 || Matrix[this->x2][this->y2]==22)) {
      if(unitToChange->getIdUnits()!=unitToChange2->getIdUnits()){
        this->map.notifyObserver(this->map,this->y+25*this->x,Matrix[this->x][this->y], 2,-1,this->y2+25*this->x2);
      } else {
        return false;
      }
    }
    return true;
}
