#include "renderMap.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include "StatsTileSet.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

renderMap::renderMap (){
  Observable principalMap; // to put in engine

  principalMap.notifyObserver();

  vector<int> basicId = principalMap.getAllMaps()->getBasicMapId();
  DecorTileSet decor;
  Layer basicMap(decor.getImageFile(),principalMap.getAllMaps()->getSize(),basicId,1);

  vector<int> decorId = principalMap.getAllMaps()->getDecorMapId();
  Layer decorMap(decor.getImageFile(),principalMap.getAllMaps()->getSize(),decorId,1);

  vector <int> buildingsId = principalMap.getAllMaps()->getBuildingsMapId();
  BuildingTileSet building;
  Layer buildingMap(building.getImageFile(),principalMap.getAllMaps()->getSize(),buildingsId,1);

  vector <int> statsId = {1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0};
  StatsTileSet stats;
  Layer statsMap(stats.getImageFile(),4,statsId,0);
  this->background=unique_ptr<Layer> (new Layer("res/background.png"));
  //this->background=new Layer("res/background.png");
  this->basicMap=basicMap;
  this->decorMap=decorMap;
  this->buildingMap=buildingMap;
  this->statsMap=statsMap;
}

Layer renderMap::getBasicMap() const{
  return this->basicMap;
}

Layer renderMap::getDecorMap() const {
  return this->decorMap;
}


Layer renderMap::getBuildingMap() const {
  return this->buildingMap;
}

Layer renderMap::getUnitMap() const {
  return this->unitMap;
}

Layer renderMap::getStatsMap() const {
  return this->statsMap;
}

std::unique_ptr<Layer> const& renderMap::getBackground() const {
  return this->background;
}

  renderMap::~renderMap (){


  }
