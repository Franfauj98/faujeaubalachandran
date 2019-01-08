#include "Client.h"
#include "state.h"
#include "ai.h"
#include "engine.h"
#include "render.h"
#include <iostream>
#include "string.h"
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<thread>
using namespace ai;
using namespace render;
using namespace state;
using namespace std;
using namespace engine;
using namespace client;

Client::Client (){
}

void Client::run (){
  std::unique_ptr<Observable> principalMap2 (new Observable(false,false));
  this->principalMap = move(principalMap2);
  sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
  window.setVerticalSyncEnabled(false);
// draw the layers
  window.clear();

  this->map.update(*(this->principalMap),"","","","");
  this->map.drawMap(window);

  bool canPlay1 = true;
  bool canPlay2 = false;
  bool canPlay3 = false;
  bool palace1=false;
  bool palace2=false;
  bool palace3=false;


  int counter=0;
  int stop=0;
  Empire* empire1 = (this->principalMap)->getAllMaps().getEmpires()[0].get();
  Empire* empire2 = (this->principalMap)->getAllMaps().getEmpires()[1].get();
  Empire* empire3 = (this->principalMap)->getAllMaps().getEmpires()[2].get();

  int id = 0;
  int idPalace=1;
  string gold= "";
  string wood= "";
  string food= "";
  string text= "";
  int controller=1;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
  // évènement "fermeture demandée" : on ferme la fenêtre
    if (event.type == sf::Event::Closed)
        window.close();
    }
    thread th1(&Client::engineUpdating,this,ref(controller));
    thread th2(&Client::aiUpdating,this,ref(counter),ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(controller));
    thread th3(&Client::playerUpdating,this,ref(*(this->principalMap)), ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(palace1),ref(palace2),ref(palace3),ref(counter),ref(*empire1),ref(*empire2),ref(*empire3),ref(id),ref(idPalace),ref(gold),ref(wood),ref(food),ref(text),ref(stop),ref(controller));
    if(controller==4){
      this->m.lock();
        if (stop==1){
          Layer endGame("res/endgame.png");
          endGame.drawSprite(window);
          window.display();
          usleep(10000000);
          break;
        }
      this->map.update(*(this->principalMap),gold,wood,food,text);
      this->map.drawMap(window);
      this->m.unlock();
      controller=1;
    }

    th1.join();
    th2.join();
    th3.join();
  }

}

 void Client::aiUpdating (int& counter, bool& canPlay1, bool& canPlay2,bool& canPlay3,int& controller){
   if (controller==1){
     this->m.lock();
     if(canPlay1){
       this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay1, 1);
     } else if(canPlay2){
       this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay2, 2);
     } else if(canPlay3){
       this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay3, 3);
     }
     this->m.unlock();
     controller=2;
   }

 }

void Client::engineUpdating (int& controller){
  if (controller==3){
    this->m.lock();
    this->engine.execute(*(this->principalMap));
    this->m.unlock();
    controller=4;
  }

}

void Client::playerUpdating(Observable& principalMap, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2,
  bool& palace3, int& counter, Empire& empire1, Empire& empire2,Empire& empire3, int& id, int& idPalace, string& gold,
  string& wood,string& food,string& text, int& stop,int& controller){
    if (controller==2){
      this->m.lock();
      this->engine.run(principalMap, canPlay1,canPlay2,canPlay3,palace1,palace2,palace3,counter, empire1,empire2, empire3,id,idPalace,gold,wood,food,text, stop);
      this->m.unlock();
      controller=3;
    }

}
