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

Observable::Observable(bool record, bool replay){
  if(record){
    this->allMaps.beginRecord();
  }
  if(replay){
    this->allMaps.beginReplay();
  }
  this->allMaps.constructMap();
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

void Observable::notifyObserverPrev(Observable& observable,
int position, int id, int action, int unitToDestroy, int position2) const{

  UnitsObserver units;
  BuildingsObserver buildings;
  switch(id){

    case 26:
    buildings.changeBuildingsPrev(observable, position, action, unitToDestroy, position2);
    break;

    case 30:
    buildings.changeBuildingsPrev(observable, position, action, unitToDestroy, position2);
    break;

    case 31:
    buildings.changeBuildingsPrev(observable, position, action, unitToDestroy, position2);
    break;

    case 14:
    units.changeUnitsPrev(observable, position, action, position2);
    break;

    case 10:
    units.changeUnitsPrev(observable, position, action, position2);
    break;

    case 18:
    units.changeUnitsPrev(observable, position, action, position2);
    break;

    case 22:
    units.changeUnitsPrev(observable, position, action, position2);
    break;

    default:
    break;
  }
}


state::Map& Observable::getAllMaps(){
  return allMaps;
}

std::vector<std::unique_ptr<Units>>& Observable::getRessurectionUnits(){
  return this->ressurectionUnits;
}

void Observable::setRessurectionUnits(std::vector<std::unique_ptr<Units>>& rElement){
   this->ressurectionUnits=move(rElement);
}

std::vector<std::unique_ptr<Buildings>>& Observable::getRessurectionPalace(){
  return this->ressurectionPalace;
}

void Observable::setRessurectionPalace(std::vector<std::unique_ptr<Buildings>>& rElement){
   this->ressurectionPalace=move(rElement);
}


std::vector<int> Observable::getRessurectionId(){
  return this->ressurectionId;
}

void Observable::setRessurectionId(std::vector<int> reId){
   this->ressurectionId=reId;
}
