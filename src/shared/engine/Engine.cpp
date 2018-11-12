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
        double yy=(double) event.mouseButton.y/32.0;
        double xx=(double) (event.mouseButton.x-800)/64.0;

        Y= floor(yy+xx);
        X= floor(yy-xx);

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
  map.update(principalMap);

  sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
  window.setVerticalSyncEnabled(false);
// draw the layers
  window.clear();

  drawMap(window,map);
  int element, element2 = 0;
  while (window.isOpen())
  {
    int counter=0;
    while (counter<9){
      //std::vector<std::unique_ptr<state::Empire> > Emp;

      if (counter>=0 && counter <=2){
        principalMap.getAllMaps().getEmpires()[0]->setShot(1);
        principalMap.getAllMaps().getEmpires()[1]->setShot(0);
        principalMap.getAllMaps().getEmpires()[2]->setShot(0);
      }
      else if (counter>=3 && counter <=5){
        principalMap.getAllMaps().getEmpires()[0]->setShot(0);
        principalMap.getAllMaps().getEmpires()[1]->setShot(1);
        principalMap.getAllMaps().getEmpires()[2]->setShot(0);
      }
      else if (counter>=6 && counter <=8){
        principalMap.getAllMaps().getEmpires()[0]->setShot(0);
        principalMap.getAllMaps().getEmpires()[1]->setShot(0);
        principalMap.getAllMaps().getEmpires()[2]->setShot(1);
      }
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
      counter++;
    }
    if(element2==10||element2==14||element2==18||element2==22||element2==26||element2==27||element2==28||element2==29){
      at.execute(principalMap, click.x, click.y, click2.x, click2.y);
      counter++;
    }
  }
  else if ((element==26||element==27||element==28||element==29||element==31)) {
    LevelUp lu;
    sf::Vector2i click2 = getClickButton(window, map);
    if (click2.x>= 0 && click2.x<=96 && click2.y>= 128 && click2.y<=192){
      lu.execute(principalMap,click.x,click.y);
      counter++;
    }
  }
  else if (element==30) {
    LevelUp lu;
    CreateUnit cu;
    sf::Vector2i click2 = getClickButton(window, map);
    if (click2.x>= 0 && click2.x<=96 && click2.y>= 256 && click2.y<=320){
      lu.execute(principalMap,click.x,click.y);
      counter++;
    }
    if (click2.x>= 0 && click2.x<=96 && click2.y>= 128 && click2.y<=192){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,1);
      counter++;
    }
    if (click2.x>= 96 && click2.x<=192 && click2.y>= 128 && click2.y<=192){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,2);
      counter++;
    }
    if (click2.x>= 0 && click2.x<=128 && click2.y>= 192 && click2.y<=256){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,4);
      counter++;
    }
    if (click2.x>= 96 && click2.x<=192 && click2.y>= 192 && click2.y<=256){
      sf::Vector2i click3 = getClick(window, map);
      map.update(principalMap);
      drawMap(window,map);
      cu.execute(principalMap,click.x,click.y,click3.x,click3.y,3);
      counter++;
    }

  }
  map.update(principalMap);
  drawMap(window,map);
  }

}

}

Engine::~Engine (){

}
