#include "MapCreatorTest.h"

using namespace std;
using namespace render;


void mapCreatorTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST MAPCREATOR" << endl;
  cout << "-------------------------------------" << endl;

  sf::RenderWindow window(sf::VideoMode(450, 450), "Tilemap");
  MapCreator map;
  vector <int> tiles={2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,1,1,1,2,2,2,
                      2,2,2,2,1,1,1,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,1,1,2,2,2,2,2,2,
                      2,2,1,1,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2};
  map.loadTexture("res/terrain.png");
  map.initQuads(10);
  for (int x=0;x<10;x++){
    for(int y=0;y<10;y++){
      map.setSpriteLocation (10,x,y);
      map.setSpriteTexture(10,tiles,x,y);
    }
  }

  MapCreator building;
  vector <int> bu ={0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,6,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,4,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,2,0,0,0,0,0,3,0,
                  0,0,0,0,0,0,0,0,0,0};
  building.loadTexture("res/Buildings.png");
  building.initQuads(10);
  for (int x=0;x<10;x++){
    for(int y=0;y<10;y++){
      building.setSpriteLocation (10,x,y);
      building.setSpriteTexture(10,bu,x,y);
    }
  }

  MapCreator units;
  vector <int> un ={14,0,0,0,0,0,0,0,0,4,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,6,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  9,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,};
  units.loadTexture("res/Units.png");
  units.initQuads(10);
  for (int x=0;x<10;x++){
    for(int y=0;y<10;y++){
      units.setSpriteLocation (10,x,y);
      units.setSpriteTexture(10,un,x,y);
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
    cout<<endl;
  }
