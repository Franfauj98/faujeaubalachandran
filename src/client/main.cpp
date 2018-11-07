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
    Engine engine;
 }
  else {
    cout << "Please type 'hello' or 'state' or 'render'" << endl;
    Engine engine;
}

  return 0;
}
