#include "Layer.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;




  Layer::Layer (){
      Map principalMap;

      MapCreator basicMap;
      vector<int> basicId = principalMap.getBasicMapId();
      DecorTileSet decor;
      basicMap.loadTexture(decor.getImageFile());
      basicMap.initQuads(principalMap.getSize());
      for (int x=0;x<principalMap.getSize();x++){
        for(int y=0;y<principalMap.getSize();y++){
          basicMap.setSpriteLocation (principalMap.getSize(),x,y,0);
          basicMap.setSpriteTexture(principalMap.getSize(),basicId,0,x,y);
        }
      }


      MapCreator decorMap;
      vector<int> decorId = principalMap.getDecorMapId();

      decorMap.loadTexture(decor.getImageFile());
      decorMap.initQuads(principalMap.getSize());
      for (int x=0;x<principalMap.getSize();x++){
        for(int y=0;y<principalMap.getSize();y++){
          decorMap.setSpriteLocation (principalMap.getSize(),x,y,0);
          decorMap.setSpriteTexture(principalMap.getSize(),decorId,0,x,y);
        }
      }

      MapCreator buildingMap;
      vector <int> buildingsId = principalMap.getBuildingsMapId();
      BuildingTileSet building;
      buildingMap.loadTexture(building.getImageFile());
      buildingMap.initQuads(principalMap.getSize());
      for (int x=0;x<principalMap.getSize();x++){
        for(int y=0;y<principalMap.getSize();y++){
          buildingMap.setSpriteLocation (principalMap.getSize(),x,y,0);
          buildingMap.setSpriteTexture(principalMap.getSize(),buildingsId,0,x,y);
        }
      }
      this->basicMap=basicMap;
      this->decorMap=decorMap;
      this->buildingMap=buildingMap;
}

MapCreator Layer::getBasicMap() const{
  return this->basicMap;
}

MapCreator Layer::getDecorMap() const {
  return this->decorMap;
}


MapCreator Layer::getBuildingMap() const {
  return this->buildingMap;
}


  Layer::~Layer (){


  }
