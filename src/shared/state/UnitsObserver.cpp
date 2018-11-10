#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void UnitsObserver::changeUnits(Observable& mapToChange,
int position, int action, int position2){
  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }

  int y2 = position2%25;
  int x2=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x2+=1;
    if(i==position2) break;
  }
  Position* pos2 = new Position(x2,y2);

  Map& map = mapToChange.getAllMaps();
  Units* unitToChange = (Units *)map.getUnitsMap()[position].get();
  Units* unitToChange2 = (Units *)map.getUnitsMap()[position2].get();
  Buildings* buildingToAttack = (Buildings *)map.getBuildingsMap()[position2].get();
  std::vector<std::vector<int>>& mapMatrix = map.getMapMatrix();
  switch(action){
    case 1: //move
    {
      unitToChange->move(*pos2, 1);
      std::unique_ptr<Element> tmp = std::move(map.getUnitsMap()[position]);
      std::unique_ptr<Element> wideUnit(new Units());
      map.addUnitsToMap(tmp, position2);
      map.addUnitsToMap(wideUnit, position);
      mapMatrix[x][y] = 2;
      mapMatrix[x2][y2] = unitToChange->getType();
      break;
    }
    case 2: //attackUnit
    {
      if(unitToChange->getIdUnits()!=unitToChange2->getIdUnits()){
        unitToChange->attack(*unitToChange2);
        if(unitToChange2->getLife()==0){
          map.getUnitsMap()[position2] = std::move(std::unique_ptr<Element> (new Units()));
          mapMatrix[x2][y2] = 2;
        }
      } else std::cout << "Cannot attack your own units" << std::endl;
      break;
    }
    case 3: //attackBuilding
    {
      if(unitToChange->getIdUnits()!=buildingToAttack->getIdBuilding()){
        unitToChange->attackBuilding(*buildingToAttack);
        if(buildingToAttack->getLife()==0){
          map.getBuildingsMap()[position2] = std::move(std::unique_ptr<Element> (new Buildings()));
          map.getBuildingsMap()[position2+1] = std::move(std::unique_ptr<Element> (new Buildings()));
          map.getBuildingsMap()[position2-1] = std::move(std::unique_ptr<Element> (new Buildings()));
          mapMatrix[x2][y2] = 2;
          mapMatrix[x2][y2+1] = 2;
          mapMatrix[x2][y2-1] = 2;
        }
      } else std::cout << "Cannot attack your own Buildings" << std::endl;
      break;
    }
    default: break;
  }


}
