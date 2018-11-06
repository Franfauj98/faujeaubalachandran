#include <iostream>
#include <cmath>
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
  // manage the events
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed){
      window.close();
      }
    }

  // draw the layers
    window.clear();

    map.getBackground()->drawSprite(window);
    window.draw(map.getBasicMap());
    window.draw(map.getDecorMap());
    window.draw(map.getBuildingMap());
    window.draw(map.getStatsMap());

    window.display();
    }
    cout<<"relaunch the render to get a new map"<<endl;

  }
  else if (argv[1] &&!strcmp(argv[1],"engine")) {
   renderMap map;
   sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
   window.setVerticalSyncEnabled(false);

   while (window.isOpen())
   {
 // manage the events
   sf::Event event;
   while (window.pollEvent(event))
   {
     if(event.type == sf::Event::Closed){
     window.close();
     }
    if (event.type == sf::Event::MouseButtonPressed)
     {
         if (event.mouseButton.button == sf::Mouse::Left)
         {
           std::cout << "the right button was pressed" << std::endl;
           // std::cout << "mouse x: " << event.mouseButton.x << std::endl;
           // std::cout << "mouse y: " << event.mouseButton.y << std::endl;
           int y=(int) floor((event.mouseButton.x-800-2*event.mouseButton.y)/(-64));
           int x=(int) floor(event.mouseButton.y/16-(event.mouseButton.x-800-2*event.mouseButton.y)/(-64));
           // std::cout << "x: " << x<< std::endl;
           // std::cout << "y: " << y << std::endl;
           int X=0;
           int Y=0;
           for (int rangeX=0;rangeX<3;rangeX++){
             for (int rangeY=0;rangeY<3;rangeY++){
               sf::Vertex* quad = &map.getDecorMap().getQuads()[(x+rangeX-1 + (y+rangeY-1) * 25) * 4];
               // std::cout << "q1 x: " << quad[1].position.x<< std::endl;
               // std::cout << "q3 x: " << quad[3].position.x<< std::endl;
               // std::cout << "q2 y: " << quad[2].position.y<< std::endl;
               // std::cout << "q0 y: " << quad[0].position.y<< std::endl;

               if(quad[1].position.x-event.mouseButton.x<45 && event.mouseButton.x-quad[3].position.x<45 &&
               quad[2].position.y-event.mouseButton.y<20 && event.mouseButton.y-quad[0].position.y<20){
                 X=x+rangeX-1;
                 Y=y+rangeY-1;
               }
             }
           }
           std::cout << "X: " << X << std::endl;
           std::cout << "Y: " << Y << std::endl;
         }
     }

   }

 // draw the layers
   window.clear();

   map.getBackground()->drawSprite(window);
   window.draw(map.getBasicMap());
   window.draw(map.getDecorMap());
   window.draw(map.getBuildingMap());
   window.draw(map.getStatsMap());

   window.display();
   }
   cout<<"relaunch the render to get a new map"<<endl;

 }
  else {
    cout << "Please type 'hello' or 'state' or 'render'" << endl;
}

  return 0;
}
