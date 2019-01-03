#include "Attack.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;

Attack::~Attack (){

}

Attack::Attack (int x, int y, int x2, int y2){
  this->x = x;
  this->y = y;
  this->x2 = x2;
  this->y2 = y2;
}

int Attack::getX() const{
  return this->x;
}
int Attack::getY() const{
  return this->y;
}
int Attack::getX2() const{
  return this->x2;
}
int Attack::getY2() const{
  return this->y2;
}


CommandTypeId Attack::getTypeId () const{
  return CommandTypeId::ATTACK;
}

void Attack::execute(state::Observable& map){
    std::vector<std::vector<int>> Matrix = map.getAllMaps().getMapMatrix();

    Units* unitToChange = (Units *)map.getAllMaps().getUnitsMap()[this->y+25*this->x].get();
    Units* unitToChange2 = (Units *)map.getAllMaps().getUnitsMap()[this->y2+25*this->x2].get();
    Buildings* buildingToAttack = (Buildings *)map.getAllMaps().getBuildingsMap()[this->y2+25*this->x2].get();

    if ((Matrix[this->x2][this->y2]==26 || Matrix[this->x2][this->y2]==27 || Matrix[this->x2][this->y2]==28 || Matrix[this->x2][this->y2]==29)) {
      if(unitToChange->getIdUnits()!=buildingToAttack->getIdBuilding()){
        map.notifyObserver(map,this->y+25*this->x,Matrix[this->x][this->y], 3,-1,this->y2+25*this->x2);
      }
    } else if ((Matrix[this->x2][this->y2]==10 || Matrix[this->x2][this->y2]==14 || Matrix[this->x2][this->y2]==18 || Matrix[this->x2][this->y2]==22)) {
      if(unitToChange->getIdUnits()!=unitToChange2->getIdUnits()){
        map.notifyObserver(map,this->y+25*this->x,Matrix[this->x][this->y], 2,-1,this->y2+25*this->x2);
      }
    }
}

void Attack::rollback(state::Observable& map){
    std::vector<std::vector<int>> Matrix = map.getAllMaps().getMapMatrix();
    map.notifyObserverPrev(map,this->y+25*this->x,Matrix[this->x][this->y], 2,-1,this->y2+25*this->x2);
}
