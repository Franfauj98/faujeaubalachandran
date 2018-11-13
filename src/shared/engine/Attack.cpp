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
bool Attack::execute(state::Observable& map, int x, int y, int x2, int y2){
    std::vector<std::vector<int>> Matrix = map.getAllMaps().getMapMatrix();

    Units* unitToChange = (Units *)map.getAllMaps().getUnitsMap()[y+25*x].get();
    Units* unitToChange2 = (Units *)map.getAllMaps().getUnitsMap()[y2+25*x2].get();
    Buildings* buildingToAttack = (Buildings *)map.getAllMaps().getBuildingsMap()[y2+25*x2].get();
    std::cout << unitToChange->getIdUnits() << '\n';
    std::cout << buildingToAttack->getIdBuilding() << '\n';
    std::cout << unitToChange2->getIdUnits() << '\n';

    if ((Matrix[x2][y2]==26 || Matrix[x2][y2]==27 || Matrix[x2][y2]==28 || Matrix[x2][y2]==29)) {
      if(unitToChange->getIdUnits()!=buildingToAttack->getIdBuilding()){
        map.notifyObserver(map,y+25*x,Matrix[x][y], 3,-1,y2+25*x2);
      } else {
        return false;
      }
    } else if ((Matrix[x2][y2]==10 || Matrix[x2][y2]==14 || Matrix[x2][y2]==18 || Matrix[x2][y2]==22)) {
      if(unitToChange->getIdUnits()!=unitToChange2->getIdUnits()){
        map.notifyObserver(map,y+25*x,Matrix[x][y], 2,-1,y2+25*x2);
      } else {
        return false;
      }
    }
    return true;
}
