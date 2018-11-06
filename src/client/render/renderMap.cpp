#include "renderMap.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include "StatsTileSet.h"
#include "../../shared/state.h"

#include <iostream>
using namespace render;
using namespace state;
using namespace std;

renderMap::renderMap (){
  Observable principalMap; // to put in engine

  Position pos1(1,1);
  Position pos2(1,2);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Arrow(2, pos1, 1)),
    1,
    14, 1);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Decurion(2, pos2, 2)),
    2,
    10, 2);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Palace(2,pos2,2)),
    1,
    26, 1);


  vector<int> basicId = principalMap.getAllMaps().getBasicMapId();
  DecorTileSet decor;
  Layer basicMap(decor.getImageFile(),principalMap.getAllMaps().getSize(),basicId,1);

  vector<int> decorId = principalMap.getAllMaps().getDecorMapId();
  Layer decorMap(decor.getImageFile(),principalMap.getAllMaps().getSize(),decorId,1);

  vector<int> selectedId=principalMap.getAllMaps().getSelectedMap();
  Layer selectedMap(decor.getImageFile(),principalMap.getAllMaps().getSize(),selectedId,1);

  vector <int> buildingsId = principalMap.getAllMaps().getBuildingsMapId();
  BuildingTileSet building;
  Layer buildingMap(building.getImageFile(),principalMap.getAllMaps().getSize(),buildingsId,1);

  vector <int> unitsId = principalMap.getAllMaps().getUnitsMapId();
  for(size_t i=0; i<unitsId.size(); i++){
    if(i%25==0) std::cout<<"\n";
    std::cout << unitsId[i];
  }
  std::cout<<"\n";


  vector <int> statsId = principalMap.getAllMaps().getStatsMapId();;
  StatsTileSet stats;
  Layer statsMap(stats.getImageFile(),4,statsId,0);
  
  this->background=unique_ptr<Layer> (new Layer("res/background.png"));
  //this->background=new Layer("res/background.png");
  this->basicMap=basicMap;
  this->decorMap=decorMap;
  this->buildingMap=buildingMap;
  this->statsMap=statsMap;
  this->selectedMap=selectedMap;
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

Layer renderMap::getSelectedMap() const {
  return this->selectedMap;
}

std::unique_ptr<Layer> const& renderMap::getBackground() const {
  return this->background;
}

void renderMap::setStatsMap(Layer* statsLayer) {

}

void renderMap::setSelectedMap(Layer* selectedLayer) {

}

void renderMap::setBuildingMap(Layer* buildingLayer) {

}

void renderMap::setUnitMap(Layer* unitLayer) {

}

  renderMap::~renderMap (){


  }
