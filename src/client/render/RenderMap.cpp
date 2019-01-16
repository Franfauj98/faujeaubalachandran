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
  std::vector<int> lastClick(6,0);
  this->lastClicks=lastClick;
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
  Layer gold(fontFile,goldText,22, sf::Color::White, 175, 20);
  Layer wood(fontFile,woodText,22, sf::Color::White,239 , 20);
  Layer food(fontFile,foodText,22, sf::Color::White, 303, 20);
  Layer message(fontFile,messageText,22, sf::Color::White, 1100, 100);

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

std::vector<int> RenderMap::getLastClicks(){
  return this->lastClicks;
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
  else if (event.type == sf::Event::MouseButtonPressed)
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


void RenderMap::handle(sf::RenderWindow& window, Observable& principalMap, engine::Engine& engine, sf::Event& event, bool& firstC, bool& secondC, bool& thirdC, int& counter){
  while (window.pollEvent(event)){
    if (event.type == sf::Event::Closed){
        window.close();
    }
    if((event.type == sf::Event::MouseButtonPressed)){
      if (firstC){
        sf::Vector2i click = getClick(window,event);
        std::vector<int> lastClick ={click.x,click.y,0,0,0,0};
        this->lastClicks=lastClick;
        int element = principalMap.getAllMaps().getMapMatrix()[click.x][click.y];
        engine.addCommand((unique_ptr<Command> (new CaseIdentifier(click.x,click.y))),1);
        engine.addCommand(unique_ptr<Command> (new Possibilities(click.x,click.y,element)),2);
        engine.addCommand(unique_ptr<Command> (new PrintStats(click.x,click.y,element)),3);

        if(element == 2 || element == 1 || element == 3 || element == 4 || element == 5 || element == 6 || element == 7 || element == 8){
          firstC = true;
          secondC = false;
          thirdC = false;
        } else {
          firstC = false;
          secondC = true;
          thirdC = false;
        }
      }
      else if(secondC){

        int element = principalMap.getAllMaps().getMapMatrix()[getLastClicks()[0]][getLastClicks()[1]];
        if (element==10||element==14||element==18||element==22) {
          sf::Vector2i click2 = getClick(window,event);
          int element2 = principalMap.getAllMaps().getMapMatrix()[click2.x][click2.y];
          engine.addCommand((unique_ptr<Command> (new CaseIdentifier(click2.x,click2.y))),1);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],click2.x,click2.y,0,0 };
          this->lastClicks=lastClick;

          Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
          int id = unit->getIdUnits();
          int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
          if(shot==1){
            if(element2==2){
              engine.addCommand((unique_ptr<Command> (new Move(getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3]))),6);
              switch(id){
                case 1:
                engine.setMessage("Player 1: Unit Moved");
                break;
                case 2:
                engine.setMessage("Player 2: Unit Moved");
                break;
                case 3:
                engine.setMessage("Player 3: Unit Moved");
                break;
                default:break;
              }
              counter++;
            }
            else if(element2==10||element2==14||element2==18||element2==22||element2==26||element2==27||element2==28||element2==29){
              engine.addCommand((unique_ptr<Command> (new Attack(getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3]))),7);
              switch(id){
                case 1:
                engine.setMessage("Player 1: Unit Attack");
                break;
                case 2:
                engine.setMessage("Player 2: Unit Attack");
                break;
                case 3:
                engine.setMessage("Player 3: Unit Attack");
                break;
                default:break;
              }
              counter++;
            }
          }
          firstC = true;
          secondC = false;
          thirdC = false;
        }

        else if ((element==26||element==27||element==28||element==29||element==31)) {
          sf::Vector2i click2 = getClickButton(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],click2.x,click2.y,0,0 };
          this->lastClicks=lastClick;

          Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
          int id = barrack->getIdBuilding();
          int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
          if(shot==1){
            if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 128 && getLastClicks()[4]<=192){
              engine.addCommand((unique_ptr<Command> (new LevelUp(getLastClicks()[0],getLastClicks()[1]))),5);
              switch(id){
                case 1:
                if(element==31){
                  engine.setMessage("Player 1: Ressource LevelUp");
                } else {
                  engine.setMessage("Player 1: Palace LevelUp");
                }
                break;
                case 2:
                if(element==31){
                  engine.setMessage("Player 2: Ressource LevelUp");
                } else {
                  engine.setMessage("Player 2: Palace LevelUp");
                }
                break;
                case 3:
                if(element==31){
                  engine.setMessage("Player 3: Ressource LevelUp");
                } else {
                  engine.setMessage("Player 3: Palace LevelUp");
                }
                break;
                default:break;
              }
              counter++;
            }
          }
          firstC = true;
          secondC = false;
          thirdC = false;
        }
        else if (element==30) {
          sf::Vector2i click2 = getClickButton(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],click2.x,click2.y,0,0};
          this->lastClicks=lastClick;

          Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
          int id = barrack->getIdBuilding();
          int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
          std::vector<std::vector<int>> matrix = principalMap.getAllMaps().getMapMatrix();
          if(shot==1){
            if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 256 && getLastClicks()[3]<=320){
              engine.addCommand((unique_ptr<Command> (new LevelUp(getLastClicks()[0],getLastClicks()[1]))),5);
              switch(id){
                case 1:
                engine.setMessage("Player 1: Barrack LevelUp");
                break;
                case 2:
                engine.setMessage("Player 2: Barrack LevelUp");
                break;
                case 3:
                engine.setMessage("Player 3: Barrack LevelUp");
                break;
                default:break;
              }
              counter++;
            }
          }
          firstC = false;
          secondC = false;
          thirdC = true;
        }
      } else if(thirdC){
        Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
        int id = barrack->getIdBuilding();
        if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 128 && getLastClicks()[3]<=192){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;
          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,1))),4);
            switch(id){
              case 1:
              engine.setMessage("Player 1: Arrow Created");
              break;
              case 2:
              engine.setMessage("Player 2: Arrow Created");
              break;
              case 3:
              engine.setMessage("Player 3: Arrow Created");
              break;
              default:break;
            }
            counter++;
          }
        }
        if (getLastClicks()[2]>= 96 && getLastClicks()[2]<=192 && getLastClicks()[3]>= 128 && getLastClicks()[3]<=192){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;

          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,2))),4);
            switch(id){
              case 1:
              engine.setMessage("Player 1: Decurion Created");
              break;
              case 2:
              engine.setMessage("Player 2: Decurion Created");
              break;
              case 3:
              engine.setMessage("Player 3: Decurion Created");
              break;
              default:break;
            }
            counter++;
          }
        }
        if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 192 && getLastClicks()[3]<=256){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;

          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,4))),4);
            switch(id){
              case 1:
              engine.setMessage("Player 1: Catapult Created");
              break;
              case 2:
              engine.setMessage("Player 2: Catapult Created");
              break;
              case 3:
              engine.setMessage("Player 3: Catapult Created");
              break;
              default:break;
            }
            counter++;
          }
        }
        if (getLastClicks()[2]>= 96 && getLastClicks()[2]<=192 && getLastClicks()[3]>= 192 && getLastClicks()[3]<=256){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;

          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,3))),4);
            switch(id){
              case 1:
              engine.setMessage("Player 1: Cavalier Created");
              break;
              case 2:
              engine.setMessage("Player 2: Cavalier Created");
              break;
              case 3:
              engine.setMessage("Player 3: Cavalier Created");
              break;
              default:break;
            }
            counter++;
          }
        }

        firstC = true;
        secondC = false;
        thirdC = false;
      }
    }
  }
}



void RenderMap::handleServer(sf::RenderWindow& window, Observable& principalMap, sf::Event& event, bool& firstC, bool& secondC, bool& thirdC, std::deque<std::string>& command){
  while (window.pollEvent(event)){
    if (event.type == sf::Event::Closed){
        window.close();
    }
    if((event.type == sf::Event::MouseButtonPressed)){
      if (firstC){
        sf::Vector2i click = getClick(window,event);
        std::vector<int> lastClick ={click.x,click.y,0,0,0,0};
        this->lastClicks=lastClick;
        int element = principalMap.getAllMaps().getMapMatrix()[click.x][click.y];
        //engine.addCommand((unique_ptr<Command> (new CaseIdentifier(click.x,click.y))),1);
        command.push_back("{\"id\": 1, \"x\":"+ to_string(click.x) +", \"y\":"+to_string(click.y)+", \"x2\": -1, \"y2\": -1, \"unit\": -1, \"element\": -1}");
        //engine.addCommand(unique_ptr<Command> (new Possibilities(click.x,click.y,element)),2);
        command.push_back("{\"id\": 2, \"x\":"+ to_string(click.x) +", \"y\":"+to_string(click.y)+", \"x2\": -1, \"y2\": -1, \"unit\": -1, \"element\":"+to_string(element)+"}");
        //engine.addCommand(unique_ptr<Command> (new PrintStats(click.x,click.y,element)),3);
        command.push_back("{\"id\": 3, \"x\":"+ to_string(click.x) +", \"y\":"+to_string(click.y)+", \"x2\": -1, \"y2\": -1, \"unit\": -1, \"element\":"+to_string(element)+"}");
        if(element == 2 || element == 1 || element == 3 || element == 4 || element == 5 || element == 6 || element == 7 || element == 8){
          firstC = true;
          secondC = false;
          thirdC = false;
        } else {
          firstC = false;
          secondC = true;
          thirdC = false;
        }
      }
      else if(secondC){

        int element = principalMap.getAllMaps().getMapMatrix()[getLastClicks()[0]][getLastClicks()[1]];
        if (element==10||element==14||element==18||element==22) {
          sf::Vector2i click2 = getClick(window,event);
          int element2 = principalMap.getAllMaps().getMapMatrix()[click2.x][click2.y];
          //engine.addCommand((unique_ptr<Command> (new CaseIdentifier(click2.x,click2.y))),1);
          command.push_back("{\"id\": 1, \"x\":"+ to_string(click2.x) +", \"y\":"+to_string(click2.y)+", \"x2\": -1, \"y2\": -1, \"unit\": -1, \"element\": -1}");
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],click2.x,click2.y,0,0 };
          this->lastClicks=lastClick;

          Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
          int id = unit->getIdUnits();
          int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
          if(shot==1){
            if(element2==2){
            //  engine.addCommand((unique_ptr<Command> (new Move(getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3]))),6);
              command.push_back("{\"id\": 6, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":"+to_string(getLastClicks()[2])+", \"y2\":"+to_string(getLastClicks()[3])+", \"unit\": -1, \"element\": -1}");
              // switch(id){
              //   case 1:
              //   engine.setMessage("Player 1: Unit Moved");
              //   break;
              //   case 2:
              //   engine.setMessage("Player 2: Unit Moved");
              //   break;
              //   case 3:
              //   engine.setMessage("Player 3: Unit Moved");
              //   break;
              //   default:break;
              // }
              //counter++;
            }
            else if(element2==10||element2==14||element2==18||element2==22||element2==26||element2==27||element2==28||element2==29){
              //engine.addCommand((unique_ptr<Command> (new Attack(getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3]))),7);
              command.push_back("{\"id\": 7, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":"+to_string(getLastClicks()[2])+", \"y2\":"+to_string(getLastClicks()[3])+", \"unit\": -1, \"element\": -1}");
              // switch(id){
              //   case 1:
              //   engine.setMessage("Player 1: Unit Attack");
              //   break;
              //   case 2:
              //   engine.setMessage("Player 2: Unit Attack");
              //   break;
              //   case 3:
              //   engine.setMessage("Player 3: Unit Attack");
              //   break;
              //   default:break;
              // }
              // counter++;
            }
          }
          firstC = true;
          secondC = false;
          thirdC = false;
        }

        else if ((element==26||element==27||element==28||element==29||element==31)) {
          sf::Vector2i click2 = getClickButton(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],click2.x,click2.y,0,0 };
          this->lastClicks=lastClick;

          Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
          int id = barrack->getIdBuilding();
          int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
          if(shot==1){
            if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 128 && getLastClicks()[4]<=192){
              //engine.addCommand((unique_ptr<Command> (new LevelUp(getLastClicks()[0],getLastClicks()[1]))),5);
              command.push_back("{\"id\": 5, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":-1, \"y2\":-1, \"unit\": -1, \"element\": -1}");
              // switch(id){
              //   case 1:
              //   if(element==31){
              //     engine.setMessage("Player 1: Ressource LevelUp");
              //   } else {
              //     engine.setMessage("Player 1: Palace LevelUp");
              //   }
              //   break;
              //   case 2:
              //   if(element==31){
              //     engine.setMessage("Player 2: Ressource LevelUp");
              //   } else {
              //     engine.setMessage("Player 2: Palace LevelUp");
              //   }
              //   break;
              //   case 3:
              //   if(element==31){
              //     engine.setMessage("Player 3: Ressource LevelUp");
              //   } else {
              //     engine.setMessage("Player 3: Palace LevelUp");
              //   }
              //   break;
              //   default:break;
              // }
              // counter++;
            }
          }
          firstC = true;
          secondC = false;
          thirdC = false;
        }
        else if (element==30) {
          sf::Vector2i click2 = getClickButton(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],click2.x,click2.y,0,0};
          this->lastClicks=lastClick;

          Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
          int id = barrack->getIdBuilding();
          int shot = principalMap.getAllMaps().getEmpires()[id-1]->getShot();
          std::vector<std::vector<int>> matrix = principalMap.getAllMaps().getMapMatrix();
          if(shot==1){
            if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 256 && getLastClicks()[3]<=320){
              //engine.addCommand((unique_ptr<Command> (new LevelUp(getLastClicks()[0],getLastClicks()[1]))),5);
              command.push_back("{\"id\": 5, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":-1, \"y2\":-1, \"unit\": -1, \"element\": -1}");
              // switch(id){
              //   case 1:
              //   engine.setMessage("Player 1: Barrack LevelUp");
              //   break;
              //   case 2:
              //   engine.setMessage("Player 2: Barrack LevelUp");
              //   break;
              //   case 3:
              //   engine.setMessage("Player 3: Barrack LevelUp");
              //   break;
              //   default:break;
              // }
              // counter++;
            }
          }
          firstC = false;
          secondC = false;
          thirdC = true;
        }
      } else if(thirdC){
        Buildings* barrack =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[getLastClicks()[1]+25*getLastClicks()[0]].get();
        int id = barrack->getIdBuilding();
        if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 128 && getLastClicks()[3]<=192){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;
          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            //engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,1))),4);
            command.push_back("{\"id\": 4, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":"+to_string(click3.x)+", \"y2\":"+to_string(click3.y)+", \"unit\": 1, \"element\": -1}");
            // switch(id){
            //   case 1:
            //   engine.setMessage("Player 1: Arrow Created");
            //   break;
            //   case 2:
            //   engine.setMessage("Player 2: Arrow Created");
            //   break;
            //   case 3:
            //   engine.setMessage("Player 3: Arrow Created");
            //   break;
            //   default:break;
            // }
            // counter++;
          }
        }
        if (getLastClicks()[2]>= 96 && getLastClicks()[2]<=192 && getLastClicks()[3]>= 128 && getLastClicks()[3]<=192){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;

          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            //engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,2))),4);
            command.push_back("{\"id\": 4, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":"+to_string(click3.x)+", \"y2\":"+to_string(click3.y)+", \"unit\": 2, \"element\": -1}");
            // switch(id){
            //   case 1:
            //   engine.setMessage("Player 1: Decurion Created");
            //   break;
            //   case 2:
            //   engine.setMessage("Player 2: Decurion Created");
            //   break;
            //   case 3:
            //   engine.setMessage("Player 3: Decurion Created");
            //   break;
            //   default:break;
            // }
            // counter++;
          }
        }
        if (getLastClicks()[2]>= 0 && getLastClicks()[2]<=96 && getLastClicks()[3]>= 192 && getLastClicks()[3]<=256){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;

          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            //engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,4))),4);

            command.push_back("{\"id\": 4, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":"+to_string(click3.x)+", \"y2\":"+to_string(click3.y)+", \"unit\": 4, \"element\": -1}");
            // switch(id){
            //   case 1:
            //   engine.setMessage("Player 1: Catapult Created");
            //   break;
            //   case 2:
            //   engine.setMessage("Player 2: Catapult Created");
            //   break;
            //   case 3:
            //   engine.setMessage("Player 3: Catapult Created");
            //   break;
            //   default:break;
            // }
            // counter++;
          }
        }
        if (getLastClicks()[2]>= 96 && getLastClicks()[2]<=192 && getLastClicks()[3]>= 192 && getLastClicks()[3]<=256){
          sf::Vector2i click3 = getClick(window, event);
          std::vector<int> lastClick ={getLastClicks()[0],getLastClicks()[1],getLastClicks()[2],getLastClicks()[3],click3.x,click3.y};
          this->lastClicks=lastClick;

          if(principalMap.getAllMaps().getMapMatrix()[click3.x][click3.y]==2){
            //engine.addCommand((unique_ptr<Command> (new CreateUnit(getLastClicks()[0],getLastClicks()[1],click3.x,click3.y,3))),4);
            command.push_back("{\"id\": 4, \"x\":"+ to_string(getLastClicks()[0]) +", \"y\":"+to_string(getLastClicks()[1])+", \"x2\":"+to_string(click3.x)+", \"y2\":"+to_string(click3.y)+", \"unit\": 3, \"element\": -1}");
            // switch(id){
            //   case 1:
            //   engine.setMessage("Player 1: Cavalier Created");
            //   break;
            //   case 2:
            //   engine.setMessage("Player 2: Cavalier Created");
            //   break;
            //   case 3:
            //   engine.setMessage("Player 3: Cavalier Created");
            //   break;
            //   default:break;
            // }
            // counter++;
          }
        }

        firstC = true;
        secondC = false;
        thirdC = false;
      }
    }
  }
}


void RenderMap::startMenu(sf::RenderWindow& window, sf::Event& event, int& player){
  int counter =1;
  int stop=0;
  while(player==-1){
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
          stop=1;
          window.close();
      }
      if (counter==1){
        Layer startMenu("res/startMenu.png");
        startMenu.drawSprite(window);
        window.display();
        if((event.type == sf::Event::MouseButtonPressed)){
            sf::Vector2i click = getClickButton(window,event);
            if(click.x>=630 && click.x<= 985 && click.y>= 460 && click.y<=560){
              counter=2;
            }
            else if(click.x>=630 && click.x<= 985 && click.y>= 635 && click.y<=735){
              player=4;
            }
          }
        }
        else if (counter==2){
          Layer startMenu("res/startMenu2.png");
          startMenu.drawSprite(window);
          window.display();
          if((event.type == sf::Event::MouseButtonPressed)){
            sf::Vector2i click = getClickButton(window,event);
            if(click.x>=640 && click.x<= 950 && click.y>= 440 && click.y<=535){
              player=1;
            }
            else if (click.x>=640 && click.x<= 950 && click.y>= 580 && click.y<=675){
              player=2;
            }
            else if (click.x>=640 && click.x<= 950 && click.y>= 715 && click.y<=810){
              player=0;
            }
            else if (click.x>=90 && click.x<= 190 && click.y>= 760 && click.y<=820){
              counter=1;
            }
          }
        }
        else if(stop==1){
          break;
        }
      }
      if(stop==1){
        break;
      }
    }
  }


RenderMap::~RenderMap (){

}
