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
std::unique_ptr<Element> toChange,
int position, int id) const{

  UnitsObserver units;
  BuildingsObserver buildings;
  //
  // Map map = observable.getAllMaps();
  //
  switch(id){

    case 26:
    cout<<"Do stg on Palace"<<endl;
    buildings.changeBuildings(move(toChange), observable, position);
    break;

    case 30:
    cout<<"Do stg on Barrack"<<endl;
    buildings.changeBuildings(move(toChange), observable, position);
    break;

    case 31:
    cout<<"Do stg on Ressource"<<endl;
    buildings.changeBuildings(move(toChange), observable, position);
    break;

    case 14:
    cout<<"Do stg on Arrow"<<endl;
    units.changeUnits(move(toChange), observable, position);
    break;

    case 10:
    cout<<"Do stg on Decurion"<<endl;
    units.changeUnits(move(toChange), observable, position);
    break;

    case 18:
    cout<<"Do stg on Cavalier"<<endl;
    units.changeUnits(move(toChange), observable, position);
    break;

    case 22:
    cout<<"Do stg on Catapult"<<endl;
    units.changeUnits(move(toChange), observable, position);
    break;

    default:
    break;
  }

  // units.changeUnits(std::unique_ptr<Element> (new Arrow()));
}

state::Map& Observable::getAllMaps(){
  return allMaps;
}
