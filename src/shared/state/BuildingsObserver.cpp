#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void BuildingsObserver::changeBuildings(std::unique_ptr<Element> buildings,
Observable& mapToChange,
int position){
  std::vector<std::unique_ptr<Element>> const& map = mapToChange.getAllMaps().getBuildingsMap();
  std::cout << "BuildingsObserver" << std::endl;
}
