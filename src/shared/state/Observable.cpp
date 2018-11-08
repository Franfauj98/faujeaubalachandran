#include "Observable.h"
#include "Palace.h"
#include "Arrow.h"
#include <iostream>
using namespace state;
using namespace std;

Observable::~Observable(){
}

Observable::Observable(){
}

void Observable::notifyObserver(Observable& observable,
int position, int id, int action, int unitToCreate, int position2) const{

  UnitsObserver units;
  BuildingsObserver buildings;
  switch(id){

    case 26:
    buildings.changeBuildings(observable, position, action, unitToCreate, position2);
    break;

    case 30:
    buildings.changeBuildings(observable, position, action, unitToCreate, position2);
    break;

    case 31:
    buildings.changeBuildings(observable, position, action, unitToCreate, position2);
    break;

    case 14:
    units.changeUnits(observable, position, action, position2);
    break;

    case 10:
    units.changeUnits(observable, position, action, position2);
    break;

    case 18:
    units.changeUnits(observable, position, action, position2);
    break;

    case 22:
    units.changeUnits(observable, position, action, position2);
    break;

    default:
    break;
  }
}

state::Map& Observable::getAllMaps(){
  return allMaps;
}
