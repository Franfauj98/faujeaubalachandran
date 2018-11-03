#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void UnitsObserver::changeUnits(std::unique_ptr<Element> unit,
Observable& mapToChange,
int position){
  Map& map = mapToChange.getAllMaps();
  map.addUnitsToMap(unit, position);
  std::cout << "UnitsObserver" << std::endl;
}
