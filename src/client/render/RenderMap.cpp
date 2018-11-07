#include "RenderMap.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include "StatsTileSet.h"
#include "../../shared/state.h"

#include <iostream>
using namespace render;
using namespace state;
using namespace std;

RenderMap::RenderMap (){
  // Observable principalMap; // to put in engine
  //
  // Position pos1(1,1);
  // Position pos2(1,2);
  //
  //
  // principalMap.notifyObserver(principalMap,
  //   1, 26, 2, 1, 0);
  //
  // principalMap.notifyObserver(principalMap,
  //   24, 26, 2, 1, 0);
  //
  // principalMap.notifyObserver(principalMap,
  //   25, 26, 2, 2, 0);
  //
  // principalMap.notifyObserver(principalMap,
  //   49, 26, 2, 3, 0);
  //
  // principalMap.notifyObserver(principalMap,
  //   50, 26, 2, 4, 0);
  //
  // principalMap.notifyObserver(principalMap,
  //   2, 26, 2, 2, 0);
  //
  // std::vector<vector<int>>& mapMatrix1 = principalMap.getAllMaps().getMapMatrix();
  // for(size_t i=0; i<25; i++){
  //   for(size_t j=0; j<25; j++){
  //   std::cout << mapMatrix1[i][j];
  //   }
  //   std::cout<<"\n";
  // }
  // std::cout<<"\n";


  // print to Test
  // vector <int> unitsId = principalMap.getAllMaps().getUnitsMapId();
  // for(size_t i=0; i<unitsId.size(); i++){
  //   if(i%25==0) std::cout<<"\n";
  //   std::cout << unitsId[i];
  // }
  // std::cout<<"\n";

  // std::vector<unique_ptr<state::Element>> const& unitsMap = principalMap.getAllMaps().getUnitsMap();
  // for(size_t i=0; i<unitsMap.size(); i++){
  //   if(i%25==0) std::cout<<"\n";
  //   std::cout << unitsMap[i].get()->getLevel();
  // }
  // std::cout<<"\n";
  // print to Test

  // principalMap.notifyObserver(principalMap,
  //   2, 10, 1, -1, 3);
  //
  // std::cout<<"\n";
  // std::cout<<"\n";

  // std::cout << ((Units*)unitsMap[1].get())->getPosition().getX()<<endl;
  // std::cout << ((Units*)unitsMap[1].get())->getPosition().getY()<<endl;

  // std::vector<vector<int>>& mapMatrix2 = principalMap.getAllMaps().getMapMatrix();
  // for(size_t i=0; i<25; i++){
  //   for(size_t j=0; j<25; j++){
  //   std::cout << mapMatrix2[i][j];
  //   }
  //   std::cout<<"\n";
  // }
  //
  // std::cout<<"\n";
  // std::cout<<"\n";

  // std::vector<unique_ptr<state::Element>> const& unitsMap2 = principalMap.getAllMaps().getUnitsMap();
  // for(size_t i=0; i<unitsMap2.size(); i++){
  //   if(i%25==0) std::cout<<"\n";
  //   std::cout << unitsMap2[i].get()->getLevel();
  // }
  // std::cout<<"\n";


  // principalMap.notifyObserver(principalMap,
  //   3, 10, 1, -1, 2);
  //
  // std::cout<<"\n";

  // vector <int> unitsId2 = principalMap.getAllMaps().getUnitsMapId();
  // for(size_t i=0; i<unitsId2.size(); i++){
  //   if(i%25==0) std::cout<<"\n";
  //   std::cout << unitsId2[i];
  // }
  // std::vector<vector<int>>& mapMatrix3 = principalMap.getAllMaps().getMapMatrix();
  // for(size_t i=0; i<25; i++){
  //   for(size_t j=0; j<25; j++){
  //   std::cout << mapMatrix3[i][j];
  //   }
  //   std::cout<<"\n";
  // }
  //
  // std::cout<<"\n";
  // std::cout<<"\n";
  // principalMap.notifyObserver(principalMap,
  //   2, 10, 2, -1, 1);

  // vector <int> unitsId3 = principalMap.getAllMaps().getUnitsMapId();
  // for(size_t i=0; i<unitsId3.size(); i++){
  //   if(i%25==0) std::cout<<"\n";
  //   std::cout << unitsId3[i];
  // }
  // std::cout<<"\n";
  // std::vector<unique_ptr<state::Element>> const& unitsMap3 = principalMap.getAllMaps().getUnitsMap();
  // std::cout<<"\n";
  // std::cout<<"\n";
  //
  // std::cout << ((Units*)unitsMap3[1].get())->getLife()<<endl;
  // std::cout << ((Units*)unitsMap3[2].get())->getLife()<<endl;
  //
  // std::cout<<"\n";
  // std::cout<<"\n";
  // principalMap.notifyObserver(principalMap,
  //   1, 10, 2, -1, 2);
  //
  // std::vector<unique_ptr<state::Element>> const& unitsMap4 = principalMap.getAllMaps().getUnitsMap();
  // std::cout << ((Units*)unitsMap4[1].get())->getLife()<<endl;
  // std::cout << ((Units*)unitsMap4[2].get())->getLife()<<endl;
}

void RenderMap::update(state::Observable& principalMap) {

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

  vector <int> unitsId = principalMap.getAllMaps().getUnitsMapId();
  UnitsTileSet units;
  Layer unitMap(units.getImageFile(),principalMap.getAllMaps().getSize(),unitsId,1);

  vector <int> statsId = principalMap.getAllMaps().getStatsMap();
  StatsTileSet stats;
  Layer statsMap(stats.getImageFile(),6,statsId,0);

  this->background=unique_ptr<Layer> (new Layer("res/background.png"));
  this->basicMap=basicMap;
  this->decorMap=decorMap;
  this->unitMap=unitMap;
  this->buildingMap=buildingMap;
  this->statsMap=statsMap;
  this->selectedMap=selectedMap;

}

Layer RenderMap::getBasicMap() const{
  return this->basicMap;
}

Layer RenderMap::getDecorMap() const {
  return this->decorMap;
}

Layer RenderMap::getBuildingMap() const {
  return this->buildingMap;
}

Layer RenderMap::getUnitMap() const {
  return this->unitMap;
}

Layer RenderMap::getStatsMap() const {
  return this->statsMap;
}

Layer RenderMap::getSelectedMap() const {
  return this->selectedMap;
}

std::unique_ptr<Layer> const& RenderMap::getBackground() const {
  return this->background;
}

void RenderMap::setStatsMap(Layer* statsLayer) {
  this->statsMap=*statsLayer;
}

void RenderMap::setSelectedMap(Layer* selectedLayer) {
  this->selectedMap=*selectedLayer;
}

void RenderMap::setBuildingMap(Layer* buildingLayer) {
  this->buildingMap=*buildingLayer;
}

void RenderMap::setUnitMap(Layer* unitLayer) {
  this->unitMap=*unitLayer;
}

  RenderMap::~RenderMap (){


  }