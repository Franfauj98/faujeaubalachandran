#include <iostream>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

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
<<<<<<< HEAD
    sf::RenderWindow window(sf::VideoMode(1024, 256), "Tilemap");

   const int level[] =
   {
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
      3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  };
  const int level2[] =
  {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 };
   // on crée la tilemap avec le niveau précédemment défini
   TileMap map;
   if (!map.load("res/terrain.png", sf::Vector2u(64, 32), level, 16, 8))
       return -1;
   TileMap map2;
   if (!map2.load("res/terrain.png", sf::Vector2u(64, 32), level2, 16, 8))
       return -1;

   // on fait tourner la boucle principale
   while (window.isOpen())
   {
       // on gère les évènements
       sf::Event event;
       while (window.pollEvent(event))
       {
           if(event.type == sf::Event::Closed)
               window.close();
       }

       // on dessine le niveau
       window.clear();
       window.draw(map);
       window.draw(map2);
       window.display();
   }
=======
>>>>>>> 6f072af02330b8c4f9859e4356fdf4ecd05baaa5

    tileTest();
    mapCreatorTest();
  
  }
  else {
    cout << "Please type 'hello' or 'state'" << endl;
  }


  return 0;
}
