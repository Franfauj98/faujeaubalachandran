#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void BuildingsObserver::changeBuildings(std::unique_ptr<Element> buildings,
Observable& mapToChange,
int position, int action){
  // std::vector<std::unique_ptr<Element>> const& map = mapToChange.getAllMaps().getBuildingsMap();
  Buildings* build = ((Buildings *) buildings.get());
  std::cout << "BuildingsObserver" << std::endl;


  switch(action){

    case 1:
    {
      int level = build->getLevel();
      std::cout << level << std::endl;
      std::cout << "levelUp" << std::endl;
      build->setLevel(++level);
      level = build->getLevel();
      std::cout << level << std::endl;
      break;
    }

    case 2:
    {
      Barrack* barrack = ((Barrack *) build);
      Position* pos1 = new Position(1,1);
      barrack->createArrow(1, *pos1, 1);
      break;
    }

    default:
    break;
  }

}
