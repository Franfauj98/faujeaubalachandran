#include "Empire.h"
#include "Barrack.h"
#include "Palace.h"
#include "Ressource.h"
#include <iostream>
using namespace state;
using namespace std;

Empire::Empire(){
  this->idEmpire=0;
  this->name="none";
  this->empireLevel=0;
  this->life=0;
  this->goldRessource=0;
  this->woodRessource=0;
  this->foodRessource=0;
  this->shot=3;
  std::vector<Position> position(1);
  Position pos0(0,0);
  position[0]=pos0;
  this->position=position;
  this->barrack=std::unique_ptr<Barrack> (new Barrack());
  this->ressource=std::unique_ptr<Ressource> (new Ressource());
  this->palace=std::unique_ptr<Palace> (new Palace());
}

Empire::Empire (int id, std::string name, int empireLevel, int life, int goldRessource, int woodRessource, int foodRessource, std::vector<Position> position, std::unique_ptr<Barrack>& barrack,
  std::unique_ptr<Ressource>& ressource, std::unique_ptr<Palace>& palace, int shot){
  try{
    bool a;
    unsigned int count =0;
    for (unsigned int i=0;i<position.size();i++){
      if (position[i].getX()>=0 && position[i].getY()>=0 && position[i].getX()<=25 &&position[i].getY()<=25){
        count +=1;
      }
    }
    if(count==position.size()) {
      a=true;
    }
    if (idEmpire>=0 && empireLevel>=0 && empireLevel<5 && life>=0 && life<=1000 &&goldRessource>=0 &&
    woodRessource>=0 && foodRessource>=0 && a==true){
      this->idEmpire=id;
      this->name=name;
      this->empireLevel=empireLevel;
      this->life=life;
      this->goldRessource=goldRessource;
      this->woodRessource=woodRessource;
      this->foodRessource=foodRessource;
      this->position=position;
      this->barrack = move(barrack);
      this->palace= move(palace);
      this->ressource= move(ressource);
      this->shot=shot;
    } else {
      this->idEmpire=0;
      this->name="none";
      this->empireLevel=0;
      this->life=0;
      this->goldRessource=0;
      this->woodRessource=0;
      this->foodRessource=0;
      this->shot=shot;
      Position pos0(0,0);
      std::vector<Position> pos;
      for (unsigned int i=0;i<pos.size();i++){
        pos[i]=pos0;
      }
      setPosition(pos);
      this->barrack=std::unique_ptr<Barrack> (new Barrack());
      this->palace=std::unique_ptr<Palace> (new Palace());
      this->ressource=std::unique_ptr<Ressource> (new Ressource());
      std::string message="idEmpire must be positive";
      message+='\n';
      message+="empireLevel must be positive or smaller than 5";
      message+='\n';
      message+="life must be positive and smaller than 1000";
      message+='\n';
      message+="goldRessource must be positive";
      message+='\n';
      message+="woodRessource must be positive";
      message+='\n';
      message+="foodRessource must be positive";
      message+='\n';
      message+="position vector must be positive or be on the map ";
      message+='\n';
      throw std::string(message);
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}
int Empire::getId () const{
  return this->idEmpire;
}

void Empire::setName (const std::string name){
  this->name=name;
}

std::string Empire::getName () const{
  return this->name;
}
void Empire::setEmpireLevel (const int level){
  try{
    if(level>=0 && level<5){
      this->empireLevel=level;
    } else {
      this->empireLevel=0;
      throw std::string("empireLevel must be positive or smaller than 5");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

int Empire::getEmpireLevel () const{
  return this->empireLevel;

}
void Empire::setLife (const int life){
  try{
    if(life>=0 && life<=1000){
      this->life=life;
    } else {
      this->life=0;
      throw std::string("life must be positive or smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}
int Empire::getLife () const{
  return this->life;
}
int Empire::getGoldRessource () const{
  return this->goldRessource;
}
void Empire::setGoldRessource (const int gold){
  try{
    if(goldRessource>=0){
      this->goldRessource=gold;
    } else {
      this->goldRessource=0;
      throw std::string("goldRessource must be positive");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}
int Empire::getWoodRessource () const{
  return this->woodRessource;
}
void Empire::setWoodRessource (const int wood){
  try{
    if(woodRessource>=0){
      this->woodRessource=wood;
    } else {
      this->woodRessource=0;
      throw std::string("woodRessource must be positive");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}
int Empire::getFoodRessource () const{
  return this->foodRessource;
}
void Empire::setFoodRessource (const int food){
  try{
    if(foodRessource>=0){
      this->foodRessource=food;
    } else {
      this->foodRessource=0;
      throw std::string("foodRessource must be positive");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}
std::vector<Position> Empire::getPosition () const{
  return this->position;
}

void Empire::setPosition (const std::vector<Position> postion){
  try{
    unsigned int count =0;
    for (unsigned int i=0;i<position.size();i++){
      if (position[i].getX()>=0 && position[i].getY()>=0 &&position[i].getX()<10000 &&position[i].getY()<10000){
        count +=1;
      }
    }
    if(count==position.size()) {
    this->position=position;
    } else {
        Position pos0(0,0);
        std::vector<Position> pos;
        for (unsigned int i=0;i<pos.size();i++){
          pos[i]=pos0;
        }
        this->position=pos;
        throw std::string("position vector must be positive or be on the map");

      }
    } catch (std::string error){
      std::cerr << error << std::endl;
      }
}

std::unique_ptr<Barrack>& Empire::getBarrack (){
  return this->barrack;
}

void Empire::setBarrack (std::unique_ptr<Barrack>& barrack){
  this->barrack=move(barrack);
}

std::unique_ptr<Palace>& Empire::getPalace (){
  return this->palace;
}
void Empire::setPalace (std::unique_ptr<Palace>& palace){
  this->palace=move(palace);
}

std::unique_ptr<Ressource>& Empire::getRessource (){
  return this->ressource;
}

void Empire::setRessource (std::unique_ptr<Ressource>& ressource){
  this->ressource=move(ressource);
}

int Empire::getShot(){
  return this->shot;
}

void Empire::setShot(int shot){
  try{
    if(shot>=0) this->shot=shot;
    else throw std::string("shot must be positive or null");
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

Empire::~Empire (){

}
