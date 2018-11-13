#include "RenderMap.h"
#include "BuildingTileSet.h"
#include "DecorTileSet.h"
#include "UnitsTileSet.h"
#include "StatsTileSet.h"
#include "../../shared/state.h"
#include "../../shared/engine.h"
#include <cmath>
#include <iostream>
using namespace render;
using namespace state;
using namespace std;
using namespace engine;

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
  }
  sf::Vector2i click(X,Y);
  return click;
}

void RenderMap::drawMap(sf::RenderWindow& window){
  // draw the layers
    window.clear();
    getBackground()->drawSprite(window);
    window.draw(getBasicMap());
    window.draw(getSelectedMap());
    window.draw(getDecorMap());
    window.draw(getBuildingMap());
    window.draw(getUnitMap());
    window.draw(getStatsMap());
    Layer gold = getGold();
    Layer food = getFood();
    Layer wood = getWood();
    Layer message = getMessage();
    gold.drawText(window);
    food.drawText(window);
    wood.drawText(window);
    message.drawText(window);
    window.display();
}


void RenderMap::handle(sf::RenderWindow& window, Observable& principalMap, engine::Engine& engine, sf::Event& event){

  sf::Vector2i click = getClick(window,event);
  int element = principalMap.getAllMaps().getMapMatrix()[click.x][click.y];
  engine.addCommand((unique_ptr<Command> (new CaseIdentifier(click.x,click.y))),1);
  engine.addCommand(unique_ptr<Command> (new Possibilities(click.x,click.y,element)),2);
  engine.addCommand(unique_ptr<Command> (new PrintStats(click.x,click.y,element)),3);
  std::cout << "coucou" << '\n';

}



RenderMap::~RenderMap (){
}
