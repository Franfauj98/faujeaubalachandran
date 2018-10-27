#include "Layer.h"
#include "MenuLayer.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;




  Layer::Layer (){
      Map principalMap; // to put in engine

      MapCreator basicMap;
      vector<int> basicId = principalMap.getBasicMapId();
      DecorTileSet decor;
      basicMap.loadTexture(decor.getImageFile());
      basicMap.initQuads(principalMap.getSize());
      for (int x=0;x<principalMap.getSize();x++){
        for(int y=0;y<principalMap.getSize();y++){
          basicMap.setSpriteLocation (principalMap.getSize(),x,y);
          basicMap.setSpriteTexture(principalMap.getSize(),basicId,x,y);
        }
      }


      MapCreator decorMap;
      vector<int> decorId = principalMap.getDecorMapId();

      decorMap.loadTexture(decor.getImageFile());
      decorMap.initQuads(principalMap.getSize());
      for (int x=0;x<principalMap.getSize();x++){
        for(int y=0;y<principalMap.getSize();y++){
          decorMap.setSpriteLocation (principalMap.getSize(),x,y);
          decorMap.setSpriteTexture(principalMap.getSize(),decorId,x,y);
        }
      }

      MapCreator buildingMap;
      vector <int> buildingsId = principalMap.getBuildingsMapId();
      BuildingTileSet building;
      buildingMap.loadTexture(building.getImageFile());
      buildingMap.initQuads(principalMap.getSize());
      for (int x=0;x<principalMap.getSize();x++){
        for(int y=0;y<principalMap.getSize();y++){
          buildingMap.setSpriteLocation (principalMap.getSize(),x,y);
          buildingMap.setSpriteTexture(principalMap.getSize(),buildingsId,x,y);
        }
      }


      // MenuLayer menu1("res/helvetica.ttf", "Stats", 14, sf::Color::White, 100, 100);
      // this->text.push_back(menu1.getText());
      // MenuLayer menu2("res/helvetica.ttf", "Level", 14, sf::Color::White, 100, 130);
      // this->text.push_back(menu2.getText());
      // MenuLayer menu3("res/helvetica.ttf", "Life", 14, sf::Color::White, 100, 160);
      // this->text.push_back(menu3.getText());
      // MenuLayer menu4("res/helvetica.ttf", "Damage", 14, sf::Color::White, 100, 190);
      // this->text.push_back(menu4.getText());
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

MapCreator Layer::getUnitMap() const {
  return this->unitMap;
}

vector<sf::Text> Layer::getText() const {
  return this->text;
}

  Layer::~Layer (){


  }
