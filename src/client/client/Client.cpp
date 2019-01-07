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
  Empire* empire1 = (this->principalMap)->getAllMaps().getEmpires()[0].get();
  Empire* empire2 = (this->principalMap)->getAllMaps().getEmpires()[1].get();
  Empire* empire3 = (this->principalMap)->getAllMaps().getEmpires()[2].get();

  int id = 0;
  int idPalace=1;
  string gold= "";
  string wood= "";
  string food= "";

  while (window.isOpen())
  {
    thread th1(&Client::engineUpdated,this);
    thread th2(&Client::engineUpdating,this,ref(counter),ref(canPlay1),ref(canPlay2),ref(canPlay3));
    this->renderMutex.lock();
    sf::Event event;
    while (window.pollEvent(event))
    {
  // évènement "fermeture demandée" : on ferme la fenêtre
    if (event.type == sf::Event::Closed)
        window.close();
    }

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
        break;
      }
      else {
        counter=0;
      }

    }

    Empire* empire = (this->principalMap)->getAllMaps().getEmpires()[id].get();
    gold= to_string(empire->getGoldRessource());
    wood= to_string(empire->getWoodRessource());
    food= to_string(empire->getFoodRessource());
    this->map.update(*(this->principalMap),gold,wood,food,"");
    this->map.drawMap(window);
    this->renderMutex.unlock();
    th1.join();
    th2.join();
  }

}

 void Client::engineUpdating (int& counter, bool& canPlay1, bool& canPlay2,bool& canPlay3){
   this->renderMutex.lock();
   if(canPlay1){
     this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay1, 1);
   } else if(canPlay2){
     this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay2, 2);
   } else if(canPlay3){
     this->heuristic.run(this->engine,*(this->principalMap),counter,canPlay3, 3);
   }
   this->renderMutex.unlock();
 }

void Client::engineUpdated (){
  this->renderMutex.lock();
  this->engine.execute(*(this->principalMap));
  this->renderMutex.unlock();
}
