#include <iostream>
#include <cmath>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "renderTest.h"
#include "stateTest.h"


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

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
    map.update(principalMap,"","","","");

    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
    window.setVerticalSyncEnabled(false);
  // draw the layers
    window.clear();

    map.drawMap(window);
    sf::Event event;
    while (window.isOpen())
    {
      int counter=0;
      Empire* empire1 = principalMap.getAllMaps().getEmpires()[0].get();
      Empire* empire2 = principalMap.getAllMaps().getEmpires()[1].get();
      Empire* empire3 = principalMap.getAllMaps().getEmpires()[2].get();
      while (counter<9 && window.isOpen()){

        if (counter>=0 && counter <=2){
          empire1->setShot(1);
          empire2->setShot(0);
          empire3->setShot(0);
        }
        else if (counter>=3 && counter <=5){
          empire1->setShot(0);
          empire2->setShot(1);
          empire3->setShot(0);
        }
        else if (counter>=6 && counter <=8){
          empire1->setShot(0);
          empire2->setShot(0);
          empire3->setShot(1);
        }
        if(counter==8){
          empire1->updateRessource(principalMap.getAllMaps().getBuildingsMap());
          empire2->updateRessource(principalMap.getAllMaps().getBuildingsMap());
          empire3->updateRessource(principalMap.getAllMaps().getBuildingsMap());
        }

        while (window.waitEvent(event)&&(event.type == sf::Event::MouseButtonPressed)){
          map.handle(window, principalMap, engine, event,true,false,false);
          engine.execute(principalMap);
          engine.execute(principalMap);
          engine.execute(principalMap);
          cout<<"x"<<map.getLastClicks()[0]<<endl;
          cout<<"y"<<map.getLastClicks()[1]<<endl;
          int element = principalMap.getAllMaps().getMapMatrix()[map.getLastClicks()[0]][map.getLastClicks()[1]];
          if (element==26 || element==27 || element==28 || element==29 || element==30 || element==31 ){
            Buildings* building =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[map.getLastClicks()[1]+25*map.getLastClicks()[0]].get();
            int id = building->getIdBuilding();
            Empire* empire = principalMap.getAllMaps().getEmpires()[id-1].get();
            string gold= to_string(empire->getGoldRessource());
            string wood= to_string(empire->getWoodRessource());
            string food= to_string(empire->getFoodRessource());
            map.update(principalMap,gold,wood,food,"");
            } else {
              map.update(principalMap,"","","","");
            }

            map.drawMap(window);

          if (element==10||element==14||element==18||element==22) {
            map.handle(window, principalMap, engine, event, false, true,false);
            for(unsigned int i=0;i<engine.getCommandListId().size();i++){
              engine.execute(principalMap);
              counter++;
              map.update(principalMap,"","","","");
              map.drawMap(window);
            }
          }
          else if ((element==26||element==27||element==28||element==29||element==31)) {
            map.handle(window, principalMap, engine, event, false, true,false);
            for(unsigned int i=0;i<engine.getCommandListId().size();i++){
              engine.execute(principalMap);
              counter++;
              map.update(principalMap,"","","","");
              map.drawMap(window);
            }
          }

          else if (element==30) {
            map.handle(window, principalMap, engine, event, false, true,false);
            for(unsigned int i=0;i<engine.getCommandListId().size();i++){
              engine.execute(principalMap);
              counter++;
              map.update(principalMap,"","","","");
              map.drawMap(window);
            }

            map.handle(window, principalMap, engine, event, false, false, true);
            for(unsigned int i=0;i<engine.getCommandListId().size();i++){
              engine.execute(principalMap);
              counter++;
              map.update(principalMap,"","","","");
              map.drawMap(window);
            }
        }
      }
    }
  }
}
  else {
    cout << "Please type 'hello' or 'state' or 'render' or 'engine'" << endl;
    Engine engine;
}

  return 0;
}
