#include "LayerTest.h"

using namespace std;
using namespace render;


void layerTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST LAYER" << endl;
  cout << "-------------------------------------" << endl;

  sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");

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
  Layer map("res/map.png", 10, tiles,1);

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
  Layer building("res/Buildings.png", 10, bu,1);

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
  Layer units("res/Units.png", 10, un,1);

  while (window.isOpen())
  {

  sf::Event event;
  while (window.pollEvent(event))
  {
    if(event.type == sf::Event::Closed)
    window.close();
  }


  window.clear();
  window.draw(map);
  window.draw(building);
  window.draw(units);
  window.display();
  }
    cout<<endl;
  }
