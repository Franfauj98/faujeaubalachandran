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
}

void RenderMap::update(state::Observable& principalMap,string goldText, string woodText, string foodText, string messageText) {

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
  Layer statsMap(stats.getImageFile(),11,statsId,0);

  std::string fontFile="res/calibri.ttf";
  Layer gold(fontFile,goldText,22, sf::Color::White, 185, 22);
  Layer wood(fontFile,woodText,22, sf::Color::White,249 , 22);
  Layer food(fontFile,foodText,22, sf::Color::White, 313, 22);
  Layer message(fontFile,messageText,22, sf::Color::White, 1000, 100);

  this->background=unique_ptr<Layer> (new Layer("res/background.png"));
  this->basicMap=basicMap;
  this->decorMap=decorMap;
  this->unitMap=unitMap;
  this->buildingMap=buildingMap;
  this->statsMap=statsMap;
  this->selectedMap=selectedMap;
  this->gold=gold;
  this->food=food;
  this->wood=wood;
  this->message=message;

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

Layer RenderMap::getGold() const{
  return this->gold;
}

Layer RenderMap::getWood() const{
  return this->wood;
}

Layer RenderMap::getFood() const{
  return this->food;
}

Layer RenderMap::getMessage() const{
  return this->message;
}


sf::Vector2i getClick(sf::RenderWindow& window, sf::Event& event){
  // manage the events
  int X=0;
  int Y=0;
  if(event.type == sf::Event::Closed){
    window.close();
  }
  if (event.type == sf::Event::MouseButtonPressed)
  {
    if (event.mouseButton.button == sf::Mouse::Left)
    {
      double yy=(double) event.mouseButton.y/32.0;
      double xx=(double) (event.mouseButton.x-800)/64.0;

      Y= floor(yy+xx);
      X= floor(yy-xx);

    }
    break;
  }
  sf::Vector2i click(X,Y);
  return click;
}

sf::Vector2i getClickButton(sf::RenderWindow& window, sf::Event& event){
  // manage the events
  int X=0;
  int Y=0;
  if(event.type == sf::Event::Closed){
    window.close();
  }
  if (event.type == sf::Event::MouseButtonPressed)
  {
    if (event.mouseButton.button == sf::Mouse::Left)
    {
      std::cout << "the click button was pressed" << std::endl;

      X=event.mouseButton.x;
      Y=event.mouseButton.y;
      std::cout << "X: " << X << std::endl;
      std::cout << "Y: " << Y << std::endl;

    }
    break;
  }
  sf::Vector2i click(X,Y);
  return click;
}


void RenderMap::handle(sf::RenderWindow& window, Observable& principalMap, Engine& engine, sf::Event& event){
  sf::Vector2i click = getClick(window);

  element = 
  engine.addCommand(unique_ptr<Command> (new CaseIdentifier(principalMap,click.x,click.y)));
  engine.addCommand(unique_ptr<Command> (new Possibilities(principalMap,click.x,click.y,element)));

  engine.addCommand(unique_ptr<Command> (new PrintStats(principalMap,click.x,click.y,element)));
  map.update(principalMap,"","","","");

  if (element==26 || element==27 || element==28 || element==29 || element==30 || element==31 ){
    pst.execute(principalMap,click.x,click.y,element);
    Buildings* building =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[click.y+25*click.x].get();
    int id = building->getIdBuilding();
    Empire* empire = principalMap.getAllMaps().getEmpires()[id-1].get();
    string gold= to_string(empire->getGoldRessource());
    string wood= to_string(empire->getWoodRessource());
    string food= to_string(empire->getFoodRessource());
    pst.execute(principalMap,click.x,click.y,element);
    update(principalMap,gold,wood,food,"");
    } else {
      pst.execute(principalMap,click.x,click.y,element);
      update(principalMap,"","","","");
    }

  if (element==10||element==14||element==18||element==22) {
    Move mv;
    Attack at;
    sf::Vector2i click2 = getClick(window, map);

    CaseIdentifier cs2;
    element2 = cs2.execute(principalMap,click2.x,click2.y);
    Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[click.y+25*click.x].get();
    int id = unit->getIdUnits();
    int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
    if(shot==1){
      if(element2==2){
        mv.execute(principalMap, click.x, click.y, click2.x, click2.y);
        counter++;
      }
      if(element2==10||element2==14||element2==18||element2==22||element2==26||element2==27||element2==28||element2==29){
        at.execute(principalMap, click.x, click.y, click2.x, click2.y);
        counter++;
      }
    }
  }
  else if ((element==26||element==27||element==28||element==29||element==31)) {
    LevelUp lu;
    sf::Vector2i click2 = getClickButton(window, map);
    Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[click.y+25*click.x].get();
    int id = barrack->getIdBuilding();
    int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
    if(shot==1){
      if (click2.x>= 0 && click2.x<=96 && click2.y>= 128 && click2.y<=192){
        lu.execute(principalMap,click.x,click.y);
        counter++;
      }
    }
  }
  else if (element==30) {
    LevelUp lu;
    CreateUnit cu;
    sf::Vector2i click2 = getClickButton(window, map);
    Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[click.y+25*click.x].get();
    int id = barrack->getIdBuilding();
    int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
    std::vector<std::vector<int>> matrix = principalMap.getAllMaps().getMapMatrix();
    if(shot==1){
      if (click2.x>= 0 && click2.x<=96 && click2.y>= 128 && click2.y<=192){
        sf::Vector2i click3 = getClick(window, map);
        if(matrix[click3.x][click3.y]==2){
          map.update(principalMap,"","","","");
          drawMap(window,map);
          cu.execute(principalMap,click.x,click.y,click3.x,click3.y,1);
          counter++;
        }
      }
      if (click2.x>= 96 && click2.x<=192 && click2.y>= 128 && click2.y<=192){
        sf::Vector2i click3 = getClick(window, map);
        if(matrix[click3.x][click3.y]==2){
          map.update(principalMap,"","","","");
          drawMap(window,map);
          cu.execute(principalMap,click.x,click.y,click3.x,click3.y,2);
          counter++;
        }
      }
      if (click2.x>= 0 && click2.x<=128 && click2.y>= 192 && click2.y<=256){
        sf::Vector2i click3 = getClick(window, map);
        if(matrix[click3.x][click3.y]==2){
          map.update(principalMap,"","","","");
          drawMap(window,map);
          cu.execute(principalMap,click.x,click.y,click3.x,click3.y,4);
          counter++;
        }
      }
      if (click2.x>= 96 && click2.x<=192 && click2.y>= 192 && click2.y<=256){
        sf::Vector2i click3 = getClick(window, map);
        if(matrix[click3.x][click3.y]==2){
          map.update(principalMap,"","","","");
          drawMap(window,map);
          cu.execute(principalMap,click.x,click.y,click3.x,click3.y,3);
          counter++;
        }
      }
      if (click2.x>= 0 && click2.x<=96 && click2.y>= 256 && click2.y<=320){
        lu.execute(principalMap,click.x,click.y);
        counter++;
      }
    }
  }

}

RenderMap::~RenderMap (){
}
