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

    //tileTest();
    //ileSetTest();
    //mapCreatorTest();
    Layer layer;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Tilemap");
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
    window.draw(layer.getBasicMap());
    window.draw(layer.getDecorMap());
    window.draw(layer.getBuildingMap());
    window.display();
    }


  }
  else {
    cout << "Please type 'hello' or 'state'" << endl;
  }


  return 0;
}
