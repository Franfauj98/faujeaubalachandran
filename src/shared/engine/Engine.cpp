#include "Engine.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <cmath>
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;
using namespace render;



Engine::Engine (){
  Observable principalMap; // to put in engine
  renderMap map;
  CreateUnit cu1;
  cu1.execute(principalMap,0,0,1);
  map.update(principalMap);
  int X=0;
  int Y=0;
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
          X=0;
          Y=0;
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
        break;
    }

  }
  CaseIdentifier cs;
  Possibilities ps;
  PrintStats pst;
  CreateUnit cu;
  ps.execute(principalMap,X,Y,cs.execute(principalMap,X,Y));
  pst.execute(principalMap,X,Y,cs.execute(principalMap,X,Y));
  map.update(principalMap);

// draw the layers
  window.clear();

  map.getBackground()->drawSprite(window);
  window.draw(map.getBasicMap());
  window.draw(map.getSelectedMap());
  window.draw(map.getDecorMap());
  window.draw(map.getBuildingMap());
  window.draw(map.getUnitMap());
  window.draw(map.getStatsMap());

  window.display();
  }

}

Engine::~Engine (){

}
const state::Map& Engine::getMap () const{

}
void Engine::addCommand (int priority, Command* command){

}
void Engine::update (){

}
