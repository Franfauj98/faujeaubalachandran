#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void BuildingsObserver::changeBuildings(std::unique_ptr<Element> buildings,
Observable& mapToChange,
int position){
  // std::vector<std::unique_ptr<Element>> const& map = mapToChange.getAllMaps().getBuildingsMap();
  Buildings* build = ((Buildings *) buildings.get());
  std::cout << "BuildingsObserver" << std::endl;
  int level = build->getLevel();
  std::cout << level << std::endl;
  std::cout << "levelUp" << std::endl;
  build->setLevel(++level);
  level = build->getLevel();
  std::cout << level << std::endl;
}
