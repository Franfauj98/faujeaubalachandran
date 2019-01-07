#include "Client.h"
#include "state.h"
#include "ai.h"
#include "engine.h"
#include "render.h"
#include <iostream>
#include "string.h"
#include <unistd.h>
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<thread>
using namespace ai;
using namespace render;
using namespace state;
using namespace std;
using namespace engine;
using namespace client;



// engine::Engine engine;
// ai::HeuristicAI ai;
// state::Observable principalMap;
// render::RenderMap map;
  //   // Operations

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
  //std::vector<int> canMove1 = {0, 0, 0 ,0, 0 ,0, 0 ,0};
  // std::vector<int> canMove2 = {0, 0, 0 ,0, 0 ,0, 0 ,0};
  // std::vector<int> canMove3 = {0, 0, 0 ,0, 0 ,0, 0 ,0};

  int counter=0;
  Empire* empire1 = (this->principalMap)->getAllMaps().getEmpires()[0].get();
  Empire* empire2 = (this->principalMap)->getAllMaps().getEmpires()[1].get();
  Empire* empire3 = (this->principalMap)->getAllMaps().getEmpires()[2].get();

  int id = 0;
  int idPalace=1;
  string gold= "";
  string wood= "";
  string food= "";

  int stop=0;

  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
  // évènement "fermeture demandée" : on ferme la fenêtre
    if (event.type == sf::Event::Closed)
        window.close();
    }
    thread th1(&Client::engineUpdating,this,ref(window),ref(canPlay1),ref(canPlay2),ref(canPlay3),ref(palace1),ref(palace2),ref(palace3),ref(counter),ref(id), ref(idPalace),ref(gold), ref(wood), ref(food), ref(empire1),ref(empire2),ref(empire3),ref(stop));
    thread th2(&Client::engineUpdated,this);
    th1.join();
    th2.join();
    //engineUpdating (window,canPlay1,canPlay2,canPlay3,palace1,palace2,palace3,counter,id, idPalace,gold, wood, food, empire1,empire2,empire3,stop);
   if(stop==1){
     break;
   }
  }

}


void Client::engineUpdating (sf::RenderWindow& window, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2, bool& palace3, int& counter, int& id, int& idPalace, string& gold, string& wood, string& food, state::Empire* empire1, state::Empire* empire2, state::Empire* empire3, int& stop){
  std::unique_lock<std::mutex> lock(this->renderMutex);
  //this->renderMutex.lock();
  if (counter>=0 && counter <=2){
    id = 0;
    idPalace=1;
    for (unsigned int i=0;i<(this->principalMap)->getAllMaps().getBuildingsMap().size();i++){
      Palace* building = dynamic_cast<Palace*> ((this->principalMap)->getAllMaps().getBuildingsMap()[i].get());
      if (building!=nullptr){
        int idBuilding=building->getIdBuilding();
        if (idBuilding==idPalace){
          palace1=true;
          break;
        } else {
          palace1=false;
        }
      }
    }
    if (palace1){
      empire1->setShot(1);
      empire2->setShot(0);
      empire3->setShot(0);

      canPlay1 = true;
      canPlay2 = false;
      canPlay3 = false;
      getHeuristic().run(this->engine,*(this->principalMap),counter, canPlay1, 1);
    } else {
      counter=3;
    }

  }
  else if (counter>=3 && counter <=5){
    id = 1;
    idPalace=2;
    for (unsigned int i=0;i<(this->principalMap)->getAllMaps().getBuildingsMap().size();i++){
      Palace* building = dynamic_cast<Palace*> ((this->principalMap)->getAllMaps().getBuildingsMap()[i].get());
      if (building!=nullptr){
        int idBuilding=building->getIdBuilding();
        if (idBuilding==idPalace){
          palace2=true;
          break;
        } else {
          palace2=false;
        }
      }
    }
    if (palace2){
      empire1->setShot(0);
      empire2->setShot(1);
      empire3->setShot(0);

      canPlay1 = false;
      canPlay2 = true;
      canPlay3 = false;
      getHeuristic().run(this->engine,*(this->principalMap),counter, canPlay2, 2);
    } else {
      counter=6;
    }
  }
  else if (counter>=6 && counter <=8){
    id = 2;
    idPalace=3;
    for (unsigned int i=0;i<(this->principalMap)->getAllMaps().getBuildingsMap().size();i++){
      Palace* building = dynamic_cast<Palace*> ((this->principalMap)->getAllMaps().getBuildingsMap()[i].get());
      if (building!=nullptr){
        int idBuilding=building->getIdBuilding();
        if (idBuilding==idPalace){
          palace3=true;
          break;
        } else {
          palace3=false;
        }
      }
    }
    if (palace3){
      empire1->setShot(0);
      empire2->setShot(0);
      empire3->setShot(1);

      canPlay1 = false;
      canPlay2 = false;
      canPlay3 = true;
      getHeuristic().run(this->engine,*(this->principalMap),counter, canPlay3, 3);
    } else {
      counter=9;
    }
  }

  if(counter==9){
    idPalace = 1;
    for (unsigned int i=0;i<(this->principalMap)->getAllMaps().getBuildingsMap().size();i++){
      Palace* building = dynamic_cast<Palace*> ((this->principalMap)->getAllMaps().getBuildingsMap()[i].get());
      if (building!=nullptr){
        int idBuilding=building->getIdBuilding();
        if (idBuilding==idPalace){
          palace1=true;
          break;
        } else {
          palace1=false;
        }
      }
    }
    idPalace = 2;

    for (unsigned int i=0;i<(this->principalMap)->getAllMaps().getBuildingsMap().size();i++){
      Palace* building = dynamic_cast<Palace*> ((this->principalMap)->getAllMaps().getBuildingsMap()[i].get());
      if (building!=nullptr){
        int idBuilding=building->getIdBuilding();
        if (idBuilding==idPalace){
          palace2=true;
          break;
        } else {
          palace2=false;
        }
      }
    }
    idPalace = 3;

    for (unsigned int i=0;i<(this->principalMap)->getAllMaps().getBuildingsMap().size();i++){
      Palace* building = dynamic_cast<Palace*> ((this->principalMap)->getAllMaps().getBuildingsMap()[i].get());
      if (building!=nullptr){
        int idBuilding=building->getIdBuilding();
        if (idBuilding==idPalace){
          palace3=true;
          break;
        } else {
          palace3=false;
        }
      }
    }
    if (palace1){
      empire1->updateRessource((this->principalMap)->getAllMaps().getBuildingsMap());

    }
    if (palace2){
      empire2->updateRessource((this->principalMap)->getAllMaps().getBuildingsMap());
    }
    if (palace3){
      empire3->updateRessource((this->principalMap)->getAllMaps().getBuildingsMap());
    }

    if ((palace1==true && palace2==false && palace3==false) || (palace1==false && palace2==true && palace3==false) || (palace1==false && palace2==false && palace3==true)){
      Layer endGame("res/endgame.png");
      endGame.drawSprite(window);
      window.display();
      usleep(10000000);
      stop=1;
      //break;
    }
    else {
      counter=0;
      // canPlay1 = true;
      // canPlay2 = false;
      // canPlay3 = false;
      // id = 0;
      // idPalace=1;
    }

  }

//  engineUpdated ();
  this->renderCV.notify_one();
  std::unique_lock<std::mutex> lock2(this->engineMutex);
  this->engineCV.wait(lock2);
  Empire* empire = (this->principalMap)->getAllMaps().getEmpires()[id].get();
  gold= to_string(empire->getGoldRessource());
  wood= to_string(empire->getWoodRessource());
  food= to_string(empire->getFoodRessource());
  this->map.update(*(this->principalMap),gold,wood,food,"");
  this->map.drawMap(window);

  //this->renderMutex.unlock();
}


void Client::engineUpdated (){
  //this->engineMutex.lock();
  std::unique_lock<std::mutex> lock(this->renderMutex);
  this->renderCV.wait(lock);
  std::unique_lock<std::mutex> lock2(this->engineMutex);
  this->engine.execute(*(this->principalMap));
  this->engineCV.notify_one(lock2);
  //this->engineMutex.unlock();
}

ai::HeuristicAI Client::getHeuristic(){
    return this->heuristic;
}
