#include <iostream>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "state.h"
#include "render.h"
#include "renderTest.h"
#include "stateTest.h"


using namespace std;
using namespace state;
using namespace render;

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
    renderMap map;
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
    window.setVerticalSyncEnabled(false);

    while (window.isOpen())
    {
  // omanage the events
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      window.close();
    }

  // draw the layers
    window.clear();

    map.getBackground()->drawSprite(window);
    window.draw(map.getBasicMap());
    window.draw(map.getDecorMap());
    window.draw(map.getBuildingMap());
    window.draw(map.getStatsMap());
    //Layer menu1("res/helvetica.ttf", "Stats:", 14, sf::Color::White, 80, 20);
    // MenuLayer menu1("res/helvetica.ttf", "Stats:", 14, sf::Color::White, 80, 50);
    //MenuLayer menu2("res/helvetica.ttf", "Level:", 14, sf::Color::White, 80, 70);
    //MenuLayer menu3("res/helvetica.ttf", "Life:", 14, sf::Color::White, 80, 90);
    //MenuLayer menu4("res/helvetica.ttf", "Damage:", 14, sf::Color::White, 80, 110);
    //menu1.drawText(window);




    window.display();
    }
    cout<<"relaunch the render to get a new map"<<endl;

  }
  else {
    cout << "Please type 'hello' or 'state' or 'render'" << endl;

  }

  return 0;
}
