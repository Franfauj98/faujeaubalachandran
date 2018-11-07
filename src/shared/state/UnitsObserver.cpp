#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void UnitsObserver::changeUnits(Observable& mapToChange,
int position, int action, int position2){
  std::cout << "UnitsObserver" << std::endl;
  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }
  // Position* pos1 = new Position(x,y);

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
  Units* buildingToAttack = (Units *)map.getBuildingsMap()[position2].get();

  switch(action){
    case 1: //move
    {
      std::vector<std::vector<int>>& mapMatrix = map.getMapMatrix();
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
      unitToChange->attack(*unitToChange2);
      break;
    }
    case 3: //attackBuilding
    {
      unitToChange->attack(*buildingToAttack);
      break;
    }
    default: break;
  }


}
