#include "Client.h"
#include "state.h"
#include "ai.h"
#include "engine.h"
#include "render.h"
#include <iostream>
#include "string.h"
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include <SFML/Network.hpp>
#include<thread>
using namespace ai;
using namespace render;
using namespace state;
using namespace std;
using namespace engine;
using namespace client;

Client::Client (){
}

void Client::connect (){
  sf::Http http;
  http.setHost("http://localhost",8080);

  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Get);
  request.setUri("/player/1");
  request.setHttpVersion(1, 0); // HTTP 1.0
  request.setField("From", "me");
  request.setField("Content-Type", "application/json; charset=utf-8");
  request.setBody("");

  sf::Http::Response response = http.sendRequest(request);
  std::cout << "begining : " << std::endl;
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;

  sf::Http::Request requestPut;
  requestPut.setMethod(sf::Http::Request::Put);
  requestPut.setUri("/player");
  requestPut.setHttpVersion(1, 1); // HTTP 1.0
  requestPut.setField("From", "me");
  requestPut.setField("Content-Type", "application/x-www-form-urlencoded");
  requestPut.setBody("{\"name\": \"moi\", \"type\": 0}");
  response = http.sendRequest(requestPut);

  sf::Http::Request requestGetAfterAdd;
  requestGetAfterAdd.setMethod(sf::Http::Request::Get);
  requestGetAfterAdd.setUri("/player/1");
  requestGetAfterAdd.setHttpVersion(1, 0); // HTTP 1.0
  requestGetAfterAdd.setField("From", "me");
  requestGetAfterAdd.setField("Content-Type", "application/json; charset=utf-8");
  requestGetAfterAdd.setBody("");
  response = http.sendRequest(requestGetAfterAdd);

  std::cout << "Added to the game : " << std::endl;
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;

  cout << "Pressez <entrée> pour sortir" << endl;
  (void) getc(stdin);

  sf::Http::Request requestDelete;
  requestDelete.setMethod(sf::Http::Request::Delete);
  requestDelete.setUri("/player/2");
  requestDelete.setHttpVersion(1, 1); // HTTP 1.0
  requestDelete.setField("From", "me");
  requestDelete.setField("Content-Type", "application/x-www-form-urlencoded");
  requestDelete.setBody("");
  response = http.sendRequest(requestDelete);

  sf::Http::Request requestGetAfterDelete;
  requestGetAfterDelete.setMethod(sf::Http::Request::Get);
  requestGetAfterDelete.setUri("/player/2");
  requestGetAfterDelete.setHttpVersion(1, 0); // HTTP 1.0
  requestGetAfterDelete.setField("From", "me");
  requestGetAfterDelete.setField("Content-Type", "application/json; charset=utf-8");
  requestGetAfterDelete.setBody("");
  response = http.sendRequest(requestGetAfterDelete);

  std::cout << "Deleted : " << std::endl;
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;
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
  int renderSignal=0;

  sf::Music music;
  music.openFromFile("res/music1.ogg");
  music.setLoop(true);
  music.play();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
  // évènement "fermeture demandée" : on ferme la fenêtre
    if (event.type == sf::Event::Closed)
        window.close();
    }
    thread th1(&Client::engineUpdating,this,ref(renderSignal),ref(id),ref(gold),ref(wood),ref(food),ref(text));
    thread th2(&Client::aiUpdating,this,ref(counter),ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(controller));
    thread th3(&Client::playerUpdating,this,ref(*(this->principalMap)), ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(palace1),ref(palace2),ref(palace3),ref(counter),ref(*empire1),ref(*empire2),ref(*empire3),ref(id),ref(idPalace),ref(stop),ref(controller));
      if (stop==1){
          Layer endGame("res/endgame.png");
          endGame.drawSprite(window);
          window.display();
          usleep(10000000);
          break;
        }
      if(renderSignal==1){
        this->map.update(*(this->principalMap),gold,wood,food,text);
        this->map.drawMap(window);
        renderSignal=0;
      }

    th1.join();
    th2.join();
    th3.join();
  }

}

 void Client::aiUpdating (int& counter, bool& canPlay1, bool& canPlay2,bool& canPlay3,int& controller){
   if (controller==2){
     this->m.lock();
     if(canPlay1){
       this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay1, 1);
     } else if(canPlay2){
       this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay2, 2);
     } else if(canPlay3){
       this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay3, 3);
     }
     this->m.unlock();
     controller=1;
   }

 }

void Client::engineUpdating (int& renderSignal, int& id, string& gold, string& wood, string& food, string& text){
    this->engine.execute(*(this->principalMap));
    Empire* empire = (this->principalMap)->getAllMaps().getEmpires()[id].get();
    gold= to_string(empire->getGoldRessource());
    wood= to_string(empire->getWoodRessource());
    food= to_string(empire->getFoodRessource());
    text =this->engine.getMessage();
    renderSignal=1;

}

void Client::playerUpdating(Observable& principalMap, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2,
  bool& palace3, int& counter, Empire& empire1, Empire& empire2,Empire& empire3, int& id, int& idPalace,int& stop,int& controller){
    if (controller==1){
      this->m.lock();
      this->engine.run(principalMap, canPlay1,canPlay2,canPlay3,palace1,palace2,palace3,counter, empire1,empire2, empire3,id,idPalace, stop);
      this->m.unlock();
      controller=2;
    }
}
