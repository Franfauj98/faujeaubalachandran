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
    1, 14, 1, 0, 0, 0);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Palace(2,pos2,2)),
    24, 26, 2, 1, 1, 0);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Palace(2,pos2,2)),
    25, 26, 2, 2, 2, 0);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Palace(2,pos2,3)),
    49, 26, 2, 3, 1, 0);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Palace(2,pos2,3)),
    50, 26, 2, 4, 2, 0);

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Palace(2,pos2,3)),
    2, 26, 2, 2, 2, 0);

  vector<int> basicId = principalMap.getAllMaps().getBasicMapId();
  DecorTileSet decor;
  Layer basicMap(decor.getImageFile(),principalMap.getAllMaps().getSize(),basicId,1);

  vector<int> decorId = principalMap.getAllMaps().getDecorMapId();
  Layer decorMap(decor.getImageFile(),principalMap.getAllMaps().getSize(),decorId,1);

  vector<int> selectedId=principalMap.getAllMaps().getSelectedMapId();
  Layer selectedMap(decor.getImageFile(),principalMap.getAllMaps().getSize(),selectedId,1);

  vector <int> buildingsId = principalMap.getAllMaps().getBuildingsMapId();
  BuildingTileSet building;
  Layer buildingMap(building.getImageFile(),principalMap.getAllMaps().getSize(),buildingsId,1);

<<<<<<< HEAD
  // print to Test
=======
  vector <int> statsId = principalMap.getAllMaps().getStatsMapId();;
  StatsTileSet stats;
  Layer statsMap(stats.getImageFile(),4,statsId,0);

>>>>>>> 8641e8554654447652fe762139bcc3a7e7f2e1dc
  vector <int> unitsId = principalMap.getAllMaps().getUnitsMapId();
  for(size_t i=0; i<unitsId.size(); i++){
    if(i%25==0) std::cout<<"\n";
    std::cout << unitsId[i];
  }
  std::cout<<"\n";

  std::vector<unique_ptr<state::Element>> const& unitsMap = principalMap.getAllMaps().getUnitsMap();
  for(size_t i=0; i<unitsMap.size(); i++){
    if(i%25==0) std::cout<<"\n";
    std::cout << unitsMap[i].get()->getLevel();
  }
  std::cout<<"\n";
  // print to Test

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Arrow(2,pos2,3)),
    2, 10, 1, 2, 2, 0);

  std::cout<<"\n";

  std::vector<unique_ptr<state::Element>> const& unitsMap2 = principalMap.getAllMaps().getUnitsMap();
  for(size_t i=0; i<unitsMap2.size(); i++){
    if(i%25==0) std::cout<<"\n";
    std::cout << unitsMap2[i].get()->getLevel();
  }
  std::cout<<"\n";

  principalMap.notifyObserver(principalMap,
    std::unique_ptr<Element> (new Arrow(2,pos2,3)),
    2, 10, 2, -1, 2, 3);

  std::cout<<"\n";

  vector <int> unitsId2 = principalMap.getAllMaps().getUnitsMapId();
  for(size_t i=0; i<unitsId2.size(); i++){
    if(i%25==0) std::cout<<"\n";
    std::cout << unitsId2[i];
  }
  std::cout<<"\n";

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
  this->statsMap=*statsLayer;
}

void renderMap::setSelectedMap(Layer* selectedLayer) {
  this->selectedMap=*selectedLayer;
}

void renderMap::setBuildingMap(Layer* buildingLayer) {
  this->buildingMap=*buildingLayer;
}

void renderMap::setUnitMap(Layer* unitLayer) {
  this->unitMap=*unitLayer;
}

  renderMap::~renderMap (){


  }
