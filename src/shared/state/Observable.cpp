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
    cout<<"Do stg on Palace"<<endl;
    buildings.changeBuildings(observable, position, action, unitToCreate, position2);
    break;

    case 30:
    cout<<"Do stg on Barrack"<<endl;
    buildings.changeBuildings(observable, position, action, unitToCreate, position2);
    break;

    case 31:
    cout<<"Do stg on Ressource"<<endl;
    buildings.changeBuildings(observable, position, action, unitToCreate, position2);
    break;

    case 14:
    cout<<"Do stg on Arrow"<<endl;
    units.changeUnits(observable, position, action, position2);
    break;

    case 10:
    cout<<"Do stg on Decurion"<<endl;
    units.changeUnits(observable, position, action, position2);
    break;

    case 18:
    cout<<"Do stg on Cavalier"<<endl;
    units.changeUnits(observable, position, action, position2);
    break;

    case 22:
    cout<<"Do stg on Catapult"<<endl;
    units.changeUnits(observable, position, action, position2);
    break;

    default:
    break;
  }
}

state::Map& Observable::getAllMaps(){
  return allMaps;
}
