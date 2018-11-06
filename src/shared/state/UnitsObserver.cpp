#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void UnitsObserver::changeUnits(std::unique_ptr<Element> unit,
Observable& mapToChange,
int position, int action, int level, int position2){
  // Map& map = mapToChange.getAllMaps();
  // map.addUnitsToMap(unit, position);

  Units* uni = ((Units *) unit.get());
  std::cout << "UnitsObserver" << std::endl;

  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }
  std::cout << "posx : " << x << std::endl;
  std::cout << "posy : " << y << std::endl;
  Position* pos1 = new Position(x,y);
  Map& map = mapToChange.getAllMaps();
  Units* unitToChange = (Units *)map.getUnitsMap()[position].get();

  switch(action){
    case 1: //levelup
    {
      int level2 = unitToChange->getLevel();
      std::cout << level2 << std::endl;
      std::cout << "levelUp" << std::endl;
      unitToChange->setLevel(++level2);
      level2 = unitToChange->getLevel();
      std::cout << level2 << std::endl;
      break;
    }
    case 2: //move
    {
      unitToChange->move(*pos1, 1);
      // map.getUnitsMap()[position2].reset(std::move(map.getUnitsMap()[position]));
      // map.getUnitsMap()[position].reset(std::move());
      std::unique_ptr<Element> tmp = std::move(map.getUnitsMap()[position]);
      std::unique_ptr<Element> wideUnit(new Units());
      map.addUnitsToMap(tmp, position2);
      map.addUnitsToMap(wideUnit, position);
      break;
    }
    default: break;
  }


}
