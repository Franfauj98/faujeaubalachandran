#include "Layer.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

  Layer::Layer (){
      Map principalMap; // to put in engine

      vector<int> basicId = principalMap.getBasicMapId();
      DecorTileSet decor;
      LayerCreator basicMap(decor.getImageFile(),principalMap.getSize(),basicId);

      vector<int> decorId = principalMap.getDecorMapId();
      LayerCreator decorMap(decor.getImageFile(),principalMap.getSize(),decorId);

      vector <int> buildingsId = principalMap.getBuildingsMapId();
      BuildingTileSet building;
      LayerCreator buildingMap(building.getImageFile(),principalMap.getSize(),buildingsId);

      this->basicMap=basicMap;
      this->decorMap=decorMap;
      this->buildingMap=buildingMap;
}

LayerCreator Layer::getBasicMap() const{
  return this->basicMap;
}

LayerCreator Layer::getDecorMap() const {
  return this->decorMap;
}


LayerCreator Layer::getBuildingMap() const {
  return this->buildingMap;
}

LayerCreator Layer::getUnitMap() const {
  return this->unitMap;
}

LayerCreator Layer::getStatsMap() const {
  return this->statsMap;
}

  Layer::~Layer (){


  }
