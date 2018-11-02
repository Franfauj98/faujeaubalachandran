#include "Observable.h"
#include <iostream>
using namespace state;

Observable::~Observable(){}
Observable::Observable(){
  allMaps = new Map();
}

void Observable::notifyObserver() const{
  UnitsObserver units;
  BuildingsObserver buildings;
  units.changeUnits();
  buildings.changeBuildings();
}

state::Map* Observable::getAllMaps(){
  return allMaps;
}
