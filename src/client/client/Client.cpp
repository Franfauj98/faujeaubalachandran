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
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <thread>
#include <json/json.h>

using namespace ai;
using namespace render;
using namespace state;
using namespace std;
using namespace engine;
using namespace client;

Client::Client (){
}

sf::Http::Request sendGet(std::string uri){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Get);
  request.setUri(uri);
  request.setHttpVersion(1, 0); // HTTP 1.0
  request.setField("Content-Type", "application/json; charset=utf-8");
  request.setBody("");
  return request;
}

sf::Http::Request sendPost(std::string uri, std::string body){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Post);
  request.setUri(uri);
  request.setHttpVersion(1, 1); // HTTP 1.0
  request.setField("Content-Type", "application/json; charset=utf-8");
  request.setBody(body);
  return request;
}

sf::Http::Request sendPut(std::string uri, std::string body){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Put);
  request.setUri(uri);
  request.setHttpVersion(1, 1); // HTTP 1.0
  request.setField("Content-Type", "application/json; charset=utf-8");
  request.setBody(body);
  return request;
}
// application/x-www-form-urlencoded

sf::Http::Request sendDelete(std::string uri){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Delete);
  request.setUri(uri);
  request.setHttpVersion(1, 1); // HTTP 1.0
  request.setField("Content-Type", "application/x-www-form-urlencoded");
  request.setBody("");
  return request;
}

void Client::connect (){
  sf::Http http;
  http.setHost("http://localhost",8080);

  Json::Value body;
  Json::Reader reader;

  sf::Http::Request request = sendGet("/player/");
  sf::Http::Response response = http.sendRequest(request);
  reader.parse(response.getBody(), body);
  std::cout << "begining : " << std::endl;
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;

  request = sendPut("/command", "{\"num\": 2, \"id\": 1, \"x\": 1, \"y\": 1, \"x2\": 1, \"y2\": 1, \"unit\": 1, \"element\": 1}");
  response = http.sendRequest(request);
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;
  request = sendPut("/command", "{\"num\": 3, \"id\": 1, \"x\": 1, \"y\": 1, \"x2\": 1, \"y2\": 1, \"unit\": 1, \"element\": 1}");
  response = http.sendRequest(request);
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;
  request = sendPut("/command", "{\"num\": 4, \"id\": 1, \"x\": 1, \"y\": 1, \"x2\": 1, \"y2\": 1, \"unit\": 1, \"element\": 1}");
  response = http.sendRequest(request);
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;
  reader.parse(response.getBody(), body);
  int idCommand = body["id"].asInt();


  request = sendPut("/player", "{\"name\": \"moi\", \"type\": 0}");
  response = http.sendRequest(request);
  reader.parse(response.getBody(), body);
  int idPlayer = body["id"].asInt();
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;
  std::cout << "id: " << idPlayer << std::endl;

  request = sendGet("/player/");
  response = http.sendRequest(request);
  std::cout << "Added to the game : " << std::endl;
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;

  cout << "Pressez <entrée> pour sortir" << endl;
  (void) getc(stdin);

  request = sendDelete("/player/"+to_string(idPlayer));
  response = http.sendRequest(request);

  request = sendGet("/player/");
  response = http.sendRequest(request);
  std::cout << "Deleted : " << std::endl;
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;

  request = sendPost("/command/"+to_string(idCommand), "{\"num\": 4, \"id\": 505, \"x\": 1, \"y\": 1, \"x2\": 1, \"y2\": 1, \"unit\": 1, \"element\": 1}");
  response = http.sendRequest(request);
  std::cout << "status: " << response.getStatus() << std::endl;
  std::cout << "body: " << response.getBody() << std::endl;


}

void Client::run (){
  int player=-1;
  sf::RenderWindow window(sf::VideoMode(1200, 800), "ROMAN'S WAR");
  window.setVerticalSyncEnabled(false);
// draw the layers
  window.clear();
  sf::Event event;
  sf::Music music;
  music.openFromFile("res/intro.ogg");
  music.setLoop(true);
  music.play();
  this->map.startMenu(window,event,player);
  music.stop();

  if(player!=-1){

    if(player==4){
      std::vector<int> aiPlayer;
      sf::Http http;
      http.setHost("http://localhost",8080);

      Json::Value body;
      Json::Reader reader;

      sf::Http::Request request = sendGet("/player/");
      sf::Http::Response response = http.sendRequest(request);
      reader.parse(response.getBody(), body);


      request = sendPut("/player", "{\"name\": \"player"+to_string(body["players"].size()+1)+"\", \"type\": 0}");
      response = http.sendRequest(request);
      reader.parse(response.getBody(), body);
      if(response.getStatus()==200){
        cout<<"not possible to play"<<endl;
      } else {
        int idPlayer = body["id"].asInt();
        usleep(2000000);

        request = sendGet("/player/");
        response = http.sendRequest(request);
        reader.parse(response.getBody(), body);
        switch (body["players"].size()) {
          case 1:{
            // request = sendPut("/player", "{\"name\": \"player"+to_string(body["players"].size()+1)+"\", \"type\": 1}");
            // response = http.sendRequest(request);
            // aiPlayer.push_back(response.getBody()["id"].asInt());
            // request = sendGet("/player/");
            // response = http.sendRequest(request);
            // reader.parse(response.getBody(), body);
            // request = sendPut("/player", "{\"name\": \"player"+to_string(body["players"].size()+1)+"\", \"type\": 1}");
            // response = http.sendRequest(request);
            // aiPlayer.push_back(response.getBody()["id"].asInt());
            // request = sendGet("/player/");
            // response = http.sendRequest(request);
            // reader.parse(response.getBody(), body);
            player=1;
            break;
            }
          case 2: {
            request = sendPut("/player", "{\"name\": \"player"+to_string(body["players"].size()+1)+"\", \"type\": 1}");
            response = http.sendRequest(request);
            reader.parse(response.getBody(), body);
            aiPlayer.push_back(body["id"].asInt());
            request = sendGet("/player/");
            response = http.sendRequest(request);
            reader.parse(response.getBody(), body);
            player=2;
            break;
          }
          default:break;
        }

          if(player!=1){

          std::unique_ptr<Observable> principalMap2 (new Observable(false,false));
          this->principalMap = move(principalMap2);


          this->map.update(*(this->principalMap),"","","","");
          this->map.drawMap(window);


          bool firstC;
          bool canPlay1;
          if(player==0){
            firstC = false;
            canPlay1=true;
          } else {
            firstC = true;
            canPlay1=false;
          }
          bool secondC = false;
          bool thirdC = false;

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

          //sf::Music music;
          music.openFromFile("res/music1.ogg");
          music.setLoop(true);
          music.play();

          thread th1(&Client::engineUpdating,this,ref(renderSignal),ref(id),ref(gold),ref(wood),ref(food),ref(text),ref(window),ref(stop));
          thread th2(&Client::aiUpdating,this,ref(counter),ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(controller),ref(window),ref(stop));
          thread th3(&Client::playerUpdating,this,ref(*(this->principalMap)), ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(palace1),ref(palace2),ref(palace3),ref(counter),ref(*empire1),ref(*empire2),ref(*empire3),ref(id),ref(idPalace),ref(stop),ref(controller),ref(player),ref(firstC),ref(secondC),ref(thirdC),ref(window));

            while (window.isOpen())
            {

            if(player==0){
              while (window.pollEvent(event))
              {
            // évènement "fermeture demandée" : on ferme la fenêtre
                if (event.type == sf::Event::Closed)
                    th1.join();
                    th2.join();
                    th3.join();
                    window.close();
                }
              }

              if(player==1 || player==2){
                this->map.handle(window, *(this->principalMap), this->engine, event,firstC,secondC,thirdC,counter);
              }
              if (stop==1){
                  Layer endGame("res/endgame.png");
                  endGame.drawSprite(window);
                  window.display();
                  usleep(10000000);
                  th1.join();
                  th2.join();
                  th3.join();
                  break;
                }
              if(renderSignal==1){
                this->m.lock();
                this->map.update(*(this->principalMap),gold,wood,food,text);
                this->map.drawMap(window);
                renderSignal=0;
                this->m.unlock();
              }
            }
          }
      }
    }

    if(player!=4){


      std::unique_ptr<Observable> principalMap2 (new Observable(false,false));
      this->principalMap = move(principalMap2);


      this->map.update(*(this->principalMap),"","","","");
      this->map.drawMap(window);

      bool firstC;
      bool canPlay1;
      if(player==0){
        firstC = false;
        canPlay1=true;
      } else {
        firstC = true;
        canPlay1=false;
      }
      bool secondC = false;
      bool thirdC = false;

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

      //sf::Music music;
      music.openFromFile("res/music1.ogg");
      music.setLoop(true);
      music.play();

      thread th1(&Client::engineUpdating,this,ref(renderSignal),ref(id),ref(gold),ref(wood),ref(food),ref(text),ref(window),ref(stop));
      thread th2(&Client::aiUpdating,this,ref(counter),ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(controller),ref(window),ref(stop));
      thread th3(&Client::playerUpdating,this,ref(*(this->principalMap)), ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(palace1),ref(palace2),ref(palace3),ref(counter),ref(*empire1),ref(*empire2),ref(*empire3),ref(id),ref(idPalace),ref(stop),ref(controller),ref(player),ref(firstC),ref(secondC),ref(thirdC),ref(window));

        while (window.isOpen())
        {

        if(player==0){
          while (window.pollEvent(event))
          {
        // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                th1.join();
                th2.join();
                th3.join();
                window.close();
            }
          }

          if(player==1 || player==2){
            this->map.handle(window, *(this->principalMap), this->engine, event,firstC,secondC,thirdC,counter);
          }
          if (stop==1){
              Layer endGame("res/endgame.png");
              endGame.drawSprite(window);
              window.display();
              usleep(10000000);
              th1.join();
              th2.join();
              th3.join();
              break;
            }
          if(renderSignal==1){
            this->m.lock();
            this->map.update(*(this->principalMap),gold,wood,food,text);
            this->map.drawMap(window);
            renderSignal=0;
            this->m.unlock();
          }
        }
    }
  }
}

void Client::aiUpdating (int& counter, bool& canPlay1, bool& canPlay2,bool& canPlay3,int& controller, sf::RenderWindow& window, int& stop){
  while(window.isOpen()){
    if(stop==1) break;
    this->m.lock();
    if (controller==2){
      if(canPlay1){
        this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay1, 1);
      } else if(canPlay2){
        this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay2, 2);
      } else if(canPlay3){
        this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay3, 3);
      }
      controller=1;
    }
    this->m.unlock();
  }
}

void Client::engineUpdating (int& renderSignal, int& id, string& gold, string& wood, string& food, string& text, sf::RenderWindow& window, int& stop){
  while(window.isOpen()){
    if(stop==1) break;
    this->m.lock();
    this->engine.execute(*(this->principalMap));
    Empire* empire = (this->principalMap)->getAllMaps().getEmpires()[id].get();
    gold= to_string(empire->getGoldRessource());
    wood= to_string(empire->getWoodRessource());
    food= to_string(empire->getFoodRessource());
    text =this->engine.getMessage();
    renderSignal=1;
    this->m.unlock();
  }
}

void Client::playerUpdating(Observable& principalMap, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2,
  bool& palace3, int& counter, Empire& empire1, Empire& empire2,Empire& empire3, int& id, int& idPalace,int& stop,int& controller,int player, bool& firstC, bool& secondC, bool& thirdC,sf::RenderWindow& window){
    while(window.isOpen()){
      if(stop==1) break;
      this->m.lock();
      if (controller==1){
        this->engine.run(principalMap, canPlay1,canPlay2,canPlay3,palace1,palace2,palace3,counter, empire1,empire2, empire3,id,idPalace, stop,player,firstC,secondC,thirdC);
        controller=2;
      }
      this->m.unlock();
    }
  }
