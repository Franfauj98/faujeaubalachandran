#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void UnitsObserver::changeUnits(std::unique_ptr<Element> unit,
Observable& mapToChange,
int position, int action){
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

  switch(action){
    case 1: //levelup
    {
      Map& map = mapToChange.getAllMaps();
      Units* uniteToUprgrade = (Units *)map.getUnitsMap()[position].get();

      int level = uni->getLevel();
      std::cout << level << std::endl;
      std::cout << "levelUp" << std::endl;
      uni->setLevel(++level);
      level = uni->getLevel();
      std::cout << level << std::endl;
      break;
    }
    case 2: //move
    {
      // uni->move(pos1, 1);
    }
    default: break;
  }


}
