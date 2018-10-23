#include <iostream>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

#include "state.h"
#include "render.h"
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

    Tile tile;
    cout<<tile.getX()<<endl;
    cout<<tile.getY()<<endl;
    cout<<tile.getWidth()<<endl;
    cout<<tile.getHeight()<<endl;
    tile.setX(10);
    tile.setY(20);
    tile.setWidth(30);
    tile.setHeight(40);
    cout<<tile.getX()<<endl;
    cout<<tile.getY()<<endl;
    cout<<tile.getWidth()<<endl;
    cout<<tile.getHeight()<<endl;

    sf::RenderWindow window(sf::VideoMode(450, 450), "Tilemap");
    MapCreator map;
    const int tiles[] ={2,2,2,2,2,2,2,2,2,2,
                        2,2,2,2,2,2,2,2,2,2,
                        2,2,2,2,2,2,2,2,2,2,
                        2,2,2,2,0,0,2,2,2,2,
                        2,2,2,2,0,0,2,2,2,2,
                        2,2,2,2,2,2,2,2,2,2,
                        2,2,2,2,1,1,2,2,2,2,
                        2,2,2,2,1,1,2,2,2,2,
                        2,2,2,2,2,2,2,2,2,2,
                        2,2,2,2,2,2,2,2,2,2};
    map.loadTexture("res/terrain.png");
    map.initQuads(10);
    for (int x=0;x<10;x++){
      for(int y=0;y<10;y++){
        map.setSpriteLocation (10,x,y,0);
        map.setSpriteTexture(10,tiles,0,x,y);
      }
    }

    MapCreator building;
    const int bu[] ={6,6,6,6,6,6,6,6,6,6,
                     6,1,6,6,6,6,6,6,6,6,
                     6,6,6,6,6,6,6,0,6,6,
                     6,6,6,6,6,6,6,6,6,6,
                     6,6,6,6,6,6,6,6,6,6,
                     6,6,6,6,6,6,6,6,6,6,
                     6,6,6,6,6,6,6,6,6,6,
                     6,6,6,6,6,6,6,6,6,6,
                     6,6,3,6,6,6,6,6,3,6,
                     6,6,6,6,6,6,6,6,6,6};
    building.loadTexture("res/Buildings.png");
    building.initQuads(10);
    for (int x=0;x<10;x++){
      for(int y=0;y<10;y++){
        building.setSpriteLocation (10,x,y,0);
        building.setSpriteTexture(10,bu,0,x,y);
      }
    }

    MapCreator units;
    const int un[] ={16,16,3,16,16,16,16,16,16,16,
                     16,16,16,16,16,16,16,16,16,16,
                     16,16,16,16,16,16,16,16,16,16,
                     16,16,16,16,16,16,16,5,16,16,
                     16,16,16,16,16,16,16,16,16,16,
                     16,6,16,16,16,16,16,16,16,16,
                     16,16,16,16,16,16,16,16,16,16,
                     16,16,16,16,16,16,16,16,16,16,
                     16,16,16,16,16,9,16,16,16,16,
                     16,16,16,16,16,16,16,16,16,16};
    units.loadTexture("res/Units.png");
    units.initQuads(10);
    for (int x=0;x<10;x++){
      for(int y=0;y<10;y++){
        units.setSpriteLocation (10,x,y,0);
        units.setSpriteTexture(10,un,0,x,y);
      }
    }
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
        window.draw(building);
        window.draw(units);
        window.display();
    }

    return 0;
  }
  else {
    cout << "Please type 'hello' or 'state'" << endl;
  }


  return 0;
}
