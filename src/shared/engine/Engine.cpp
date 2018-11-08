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

sf::Vector2i getClick(sf::RenderWindow& window, RenderMap& map){
  // manage the events
  int X=0;
  int Y=0;
  sf::Event event;
  while (window.waitEvent(event))
  {
    if(event.type == sf::Event::Closed){
    window.close();
    }
   if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
      {
        std::cout << "the right button was pressed" << std::endl;
        // int y=(int) floor((event.mouseButton.x-800-2*event.mouseButton.y)/(-64));
        // int x=(int) floor(event.mouseButton.y/16-(event.mouseButton.x-800-2*event.mouseButton.y)/(-64));
        // X=0;
        // Y=0;
        // for (int rangeX=0;rangeX<3;rangeX++){
        //   for (int rangeY=0;rangeY<3;rangeY++){
        //     sf::Vertex* quad = &map.getDecorMap().getQuads()[(x+rangeX-1 + (y+rangeY-1) * 25) * 4];
        //     if(quad[1].position.x-event.mouseButton.x<45 && event.mouseButton.x-quad[3].position.x<45 &&
        //     quad[2].position.y-event.mouseButton.y<20 && event.mouseButton.y-quad[0].position.y<20){
        //       Y=x+rangeX-1;
        //       X=y+rangeY-1;
        //     }
        //   }
        // }
        double yy=(double) event.mouseButton.y/32.0;
        double xx=(double) (event.mouseButton.x-800)/64.0;

        std::cout << "x: " << event.mouseButton.x<< std::endl;
        std::cout << "y: " << event.mouseButton.y << std::endl;
        std::cout << "yy: " << yy<< std::endl;
        std::cout << "xx: " <<xx<< std::endl;
        Y= floor(yy+xx);
        X= floor(yy-xx);
        std::cout << "X: " << X << std::endl;
        std::cout << "Y: " << Y << std::endl;

      }
      break;
    }
  }
  sf::Vector2i click(X,Y);
  return click;
}

sf::Vector2i getClickButton(sf::RenderWindow& window, RenderMap& map){
  // manage the events
  int X=0;
  int Y=0;
  sf::Event event;
  while (window.waitEvent(event))
  {
    if(event.type == sf::Event::Closed){
    window.close();
    }
   if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
      {
        std::cout << "the click button was pressed" << std::endl;

        X=event.mouseButton.x;
        Y=event.mouseButton.y;
        std::cout << "X: " << X << std::endl;
        std::cout << "Y: " << Y << std::endl;

      }
      break;
    }
  }
  sf::Vector2i click(X,Y);
  return click;
}

void drawMap(sf::RenderWindow& window, RenderMap& map){
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

Engine::Engine (){
  Observable principalMap; // to put in engine
  RenderMap map;
  CreateUnit cu1;
  cu1.execute(principalMap,10,10,10,10,1);
  cu1.execute(principalMap,12,12,12,12,3);
  map.update(principalMap);

  sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
  window.setVerticalSyncEnabled(false);
// draw the layers
  window.clear();

  drawMap(window,map);
  int element, element2 = 0;
  while (window.isOpen())
  {
    sf::Vector2i click = getClick(window, map);

    CaseIdentifier cs;
    Possibilities ps;
    PrintStats pst;
    CreateUnit cu;
    element = cs.execute(principalMap,click.x,click.y);
    ps.execute(principalMap,click.x,click.y,element);
    pst.execute(principalMap,click.x,click.y,element);
    map.update(principalMap);

    drawMap(window,map);

  if (element==10||element==14||element==18||element==22) {
    Move mv;
    Attack at;
    sf::Vector2i click2 = getClick(window, map);

    CaseIdentifier cs2;
    element2 = cs2.execute(principalMap,click2.x,click2.y);
    if(element2==2){
      mv.execute(principalMap, click.x, click.y, click2.x, click2.y);
    }
    if(element2==10||element2==14||element2==18||element2==22||element2==26||element2==27||element2==28||element2==29){
      at.execute(principalMap, click.x, click.y, click2.x, click2.y);
    }
  }
  else if ((element==26||element==27||element==28||element==29||element==31)) {
    LevelUp lu;
    sf::Vector2i click2 = getClickButton(window, map);
    if (click2.x>= 0 && click2.x<=96 && click2.y>= 128 && click2.y<=192){
      lu.execute(principalMap,click.x,click.y);
    }
  }
  else if (element==30) {
    LevelUp lu;
    CreateUnit cu;
    sf::Vector2i click2 = getClickButton(window, map);
    if (click2.x>= 0 && click2.x<=96 && click2.y>= 256 && click2.y<=320){
      lu.execute(principalMap,click.x,click.y);
    }
    if (click2.x>= 0 && click2.x<=96 && click2.y>= 128 && click2.y<=192){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,1);
    }
    if (click2.x>= 96 && click2.x<=192 && click2.y>= 128 && click2.y<=192){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,2);
    }
    if (click2.x>= 0 && click2.x<=128 && click2.y>= 192 && click2.y<=256){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,4);
    }
    if (click2.x>= 96 && click2.x<=192 && click2.y>= 192 && click2.y<=256){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,3);
    }

  }
  map.update(principalMap);
  drawMap(window,map);
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
