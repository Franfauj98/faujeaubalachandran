#include <iostream>
#include <cmath>
#include "string.h"
#include <unistd.h>
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"
#include "renderTest.h"
#include "stateTest.h"


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;


int main(int argc,char* argv[])
{

  if (argv[1] &&!strcmp(argv[1],"hello")){
    cout << "Bonjour le monde!" << endl;
  } else if (argv[1] &&!strcmp(argv[1],"state")) {
    positionTest();
    UnitCostTest();
    unitsTest();
    arrowTest();
    catapultTest();
    cavalierTest();
    decurionTest();
    DecorTest();
    BuildingCostTest();
    BuildingsTest();
    PalaceTest();
    BarrackTest();
    EmpireTest();
    RessourceTest();
    mapTest();

  } else if (argv[1] &&!strcmp(argv[1],"render")) {

    //tileTest();
    //tileSetTest();
    //layerTest();
  //   RenderMap map;
  //   sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
  //   window.setVerticalSyncEnabled(false);
  //
  //   while (window.isOpen())
  //   {
  // // manage the events
  //   sf::Event event;
  //   while (window.pollEvent(event))
  //   {
  //     if(event.type == sf::Event::Closed){
  //     window.close();
  //     }
  //   }
  //
  // // draw the layers
  //   window.clear();
  //
  //   map.getBackground()->drawSprite(window);
  //   window.draw(map.getBasicMap());
  //   window.draw(map.getDecorMap());
  //   window.draw(map.getBuildingMap());
  //   window.draw(map.getStatsMap());
  //
  //   window.display();
  //   }
  //   cout<<"relaunch the render to get a new map"<<endl;

  }
  else if (argv[1] &&!strcmp(argv[1],"engine")) {
    cout << "Click on the map to play" << endl;
    cout << "Create unit : clik on barrack and then on one button (A, D, CV, CT) then click on a position next to the barrack " << endl;
    cout << "Move unit : clik on the unit and then on one brighted tile" << endl;
    cout << "Attack unit : move next to a unit and clik on the other unit brighted" << endl;
    cout << "Attack palace : move next to a palace and clik on the palace" << endl;
    //Engine engine;

    Observable principalMap;
    RenderMap map;
    Engine engine;

    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
    window.setVerticalSyncEnabled(false);
  // draw the layers
    window.clear();

    map.update(principalMap,"","","","");
    map.drawMap(window);

    sf::Event event;

    bool firstC = true;
    bool secondC = false;
    bool thirdC = false;

    int counter=0;
    Empire* empire1 = principalMap.getAllMaps().getEmpires()[0].get();
    Empire* empire2 = principalMap.getAllMaps().getEmpires()[1].get();
    Empire* empire3 = principalMap.getAllMaps().getEmpires()[2].get();

    int id = 0;

    string gold= "";
    string wood= "";
    string food= "";

    while (window.isOpen())
    {
      if (counter>=0 && counter <=2){
        empire1->setShot(1);
        empire2->setShot(0);
        empire3->setShot(0);
        id = 0;
      }
      else if (counter>=3 && counter <=5){
        empire1->setShot(0);
        empire2->setShot(1);
        empire3->setShot(0);
        id = 1;
      }
      else if (counter>=6 && counter <=8){
        empire1->setShot(0);
        empire2->setShot(0);
        empire3->setShot(1);
        id = 2;
      }

      if(counter==9){
        empire1->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        empire2->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        empire3->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        counter=0;
        empire1->setShot(1);
        empire2->setShot(0);
        empire3->setShot(0);
        id = 0;
      }

      map.handle(window, principalMap, engine, event,firstC,secondC,thirdC,counter);

      engine.execute(principalMap);

      Empire* empire = principalMap.getAllMaps().getEmpires()[id].get();
      gold= to_string(empire->getGoldRessource());
      wood= to_string(empire->getWoodRessource());
      food= to_string(empire->getFoodRessource());
      map.update(principalMap,gold,wood,food,"");
      map.drawMap(window);
    }
  } else if (argv[1] &&!strcmp(argv[1],"random_ai")) {
    Observable principalMap;
    RenderMap map;
    Engine engine;
    RandomAI ia1;
    RandomAI ia2;
    RandomAI ia3;

    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
    window.setVerticalSyncEnabled(false);
  // draw the layers
    window.clear();

    map.update(principalMap,"","","","");
    map.drawMap(window);

    bool canPlay1 = true;
    bool canPlay2 = false;
    bool canPlay3 = false;

    int counter=0;
    Empire* empire1 = principalMap.getAllMaps().getEmpires()[0].get();
    Empire* empire2 = principalMap.getAllMaps().getEmpires()[1].get();
    Empire* empire3 = principalMap.getAllMaps().getEmpires()[2].get();

    int id = 0;

    string gold= "";
    string wood= "";
    string food= "";

    while (window.isOpen())
    {

      sf::Event event;
      while (window.pollEvent(event))
      {
    // évènement "fermeture demandée" : on ferme la fenêtre
      if (event.type == sf::Event::Closed)
          window.close();
      }
      if (counter>=0 && counter <=2){
        empire1->setShot(1);
        empire2->setShot(0);
        empire3->setShot(0);
        id = 0;
        canPlay1 = true;
        canPlay2 = false;
        canPlay3 = false;
        ia1.run(engine,principalMap,counter, canPlay1,1);
      }
      else if (counter>=3 && counter <=5){
        empire1->setShot(0);
        empire2->setShot(1);
        empire3->setShot(0);
        id = 1;
        canPlay2 = true;
        canPlay1 = false;
        canPlay3 = false;
        ia2.run(engine,principalMap,counter, canPlay2,2);
      }
      else if (counter>=6 && counter <=8){
        empire1->setShot(0);
        empire2->setShot(0);
        empire3->setShot(1);
        id = 2;
        canPlay3 = true;
        canPlay2 = false;
        canPlay1 = false;
        ia3.run(engine,principalMap,counter, canPlay3,3);
      }

      if(counter==9){
        empire1->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        empire2->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        empire3->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        counter=0;
        empire1->setShot(1);
        empire2->setShot(0);
        empire3->setShot(0);
        canPlay1 = true;
        canPlay2 = false;
        canPlay3 = false;
        id = 0;
      }

      engine.execute(principalMap);

      Empire* empire = principalMap.getAllMaps().getEmpires()[id].get();
      gold= to_string(empire->getGoldRessource());
      wood= to_string(empire->getWoodRessource());
      food= to_string(empire->getFoodRessource());
      map.update(principalMap,gold,wood,food,"");
      map.drawMap(window);
  }
} else if (argv[1] &&!strcmp(argv[1],"heuristic_ai")) {
  Observable principalMap;
  RenderMap map;
  Engine engine;
  HeuristicAI ia1;
  HeuristicAI ia2;
  HeuristicAI ia3;

  sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
  window.setVerticalSyncEnabled(false);
// draw the layers
  window.clear();

  map.update(principalMap,"","","","");
  map.drawMap(window);

  bool canPlay1 = true;
  bool canPlay2 = false;
  bool canPlay3 = false;
  bool palace1=false;
  bool palace2=false;
  bool palace3=false;
  std::vector<int> canMove1 = {0, 0, 0 ,0, 0 ,0, 0 ,0};
  std::vector<int> canMove2 = {0, 0, 0 ,0, 0 ,0, 0 ,0};
  std::vector<int> canMove3 = {0, 0, 0 ,0, 0 ,0, 0 ,0};

  int counter=0;
  Empire* empire1 = principalMap.getAllMaps().getEmpires()[0].get();
  Empire* empire2 = principalMap.getAllMaps().getEmpires()[1].get();
  Empire* empire3 = principalMap.getAllMaps().getEmpires()[2].get();

  int id = 0;
  int idPalace=1;
  string gold= "";
  string wood= "";
  string food= "";

  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
  // évènement "fermeture demandée" : on ferme la fenêtre
    if (event.type == sf::Event::Closed)
        window.close();
    }

    if (counter>=0 && counter <=2){
      id = 0;
      idPalace=1;
      for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> (principalMap.getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace1=true;
            break;
          } else {
            palace1=false;
          }
        }
      }
      if (palace1){
        empire1->setShot(1);
        empire2->setShot(0);
        empire3->setShot(0);

        canPlay1 = true;
        canPlay2 = false;
        canPlay3 = false;
        ia1.run(engine,principalMap,counter, canPlay1, 1, canMove1);
      } else {
        counter=3;
      }

    }
    else if (counter>=3 && counter <=5){
      id = 1;
      idPalace=2;
      for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> (principalMap.getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace2=true;
            break;
          } else {
            palace2=false;
          }
        }
      }
      if (palace2){
        empire1->setShot(0);
        empire2->setShot(1);
        empire3->setShot(0);

        canPlay1 = false;
        canPlay2 = true;
        canPlay3 = false;
        ia1.run(engine,principalMap,counter, canPlay2, 2, canMove2);
      } else {
        counter=6;
      }
    }
    else if (counter>=6 && counter <=8){
      id = 2;
      idPalace=3;
      for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> (principalMap.getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace3=true;
            break;
          } else {
            palace3=false;
          }
        }
      }
      if (palace3){
        empire1->setShot(0);
        empire2->setShot(0);
        empire3->setShot(1);

        canPlay1 = false;
        canPlay2 = false;
        canPlay3 = true;
        ia1.run(engine,principalMap,counter, canPlay3, 3, canMove3);
      } else {
        counter=9;
      }
    }

    if(counter==9){
      idPalace = 1;
      for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> (principalMap.getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace1=true;
            break;
          } else {
            palace1=false;
          }
        }
      }
      idPalace = 2;

      for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> (principalMap.getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace2=true;
            break;
          } else {
            palace2=false;
          }
        }
      }
      idPalace = 3;

      for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> (principalMap.getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace3=true;
            break;
          } else {
            palace3=false;
          }
        }
      }
      if (palace1){
        empire1->updateRessource(principalMap.getAllMaps().getBuildingsMap());

      }
      if (palace2){
        empire2->updateRessource(principalMap.getAllMaps().getBuildingsMap());
      }
      if (palace3){
        empire3->updateRessource(principalMap.getAllMaps().getBuildingsMap());
      }

      if ((palace1==true && palace2==false && palace3==false) || (palace1==false && palace2==true && palace3==false) || (palace1==false && palace2==false && palace3==true)){
        Layer endGame("res/endgame.png");
        endGame.drawSprite(window);
        window.display();
        usleep(10000000);
        break;
      }
      else {
        counter=0;
        // canPlay1 = true;
        // canPlay2 = false;
        // canPlay3 = false;
        // id = 0;
        // idPalace=1;
      }

    }

    engine.execute(principalMap);

    Empire* empire = principalMap.getAllMaps().getEmpires()[id].get();
    gold= to_string(empire->getGoldRessource());
    wood= to_string(empire->getWoodRessource());
    food= to_string(empire->getFoodRessource());
    map.update(principalMap,gold,wood,food,"");
    map.drawMap(window);
  }
} else {
    cout << "Please type 'hello' or 'state' or 'render' or 'engine'" << endl;
    Engine engine;
  }

  return 0;
}
