#include "Empire.h"
#include "Barrack.h"
#include "Palace.h"
#include "Ressource.h"
#include <iostream>
using namespace state;


Empire::Empire(){

}

Empire::Empire (int id, std::string name, int empireLevel, int life, int goldRessource, int woodRessource, int foodRessource, std::vector<Position> position, Barrack* barrack,
  Ressource* ressource, Palace* palace){
  if (idEmpire>=0){
    this->idEmpire=id;
  }else{
    std::cerr<<"idEmpire must be positive"<<std::endl;
    this->idEmpire=0;
  }
  this->name=name;
  if (empireLevel>=0){
    this->empireLevel=empireLevel;
  }else{
    std::cerr<<"empireLevel must be positive"<<std::endl;
    this->empireLevel=0;
  }
  if (life>=0){
    this->life=life;
  }else{
    std::cerr<<"life must be positive"<<std::endl;
    this->life=0;
  }
  if (goldRessource>=0){
    this->goldRessource=goldRessource;
  }else{
    std::cerr<<"goldRessource must be positive"<<std::endl;
    this->goldRessource=0;
  }
  if (woodRessource>=0){
    this->woodRessource=woodRessource;
  }else{
    std::cerr<<"woodRessource must be positive"<<std::endl;
    this->woodRessource=0;
  }
  if (foodRessource>=0){
    this->foodRessource=foodRessource;
  }else{
    std::cerr<<"foodRessource must be positive"<<std::endl;
    this->foodRessource=0;
  }
  int count =0;
  for (int i=0;i<position.size();i++){
    if (position[i].getX()>=0 && position[i].getY()>=0){
      count +=1;
    }
  }
    if(count==position.size()) {
      this->position=position;
    }
    else{
      std::cerr<<"position vector must be positive"<<std::endl;
      Position pos0(0,0);
      std::vector<Position> pos;
      for (int i=0;i<pos.size();i++){
        pos[i]=pos0;
      }
      this->position=pos;
    }

  this->barrack=barrack;
  this->palace=palace;
  this->ressource=ressource;

}
int Empire::getId () const{
  return this->idEmpire;
}

void Empire::setName (std::string name){
  this->name=name;
}

std::string Empire::getName () const{
  return this->name;
}
void Empire::setEmpireLevel (int level){
  if(level>=0){
    this->empireLevel=level;
  }
  else {
    std::cerr<<"empireLevel must be positive"<<std::endl;
    this->empireLevel=0;
  }
}

int Empire::getEmpireLevel () const{
  return this->empireLevel;

}
void Empire::setLife (int life){
  if(life>=0){
    this->life=life;
  }
  else {
    std::cerr<<"life must be positive"<<std::endl;
    this->life=0;
  }
}
int Empire::getLife () const{
  return this->life;
}
int Empire::getGoldRessource () const{
  return this->goldRessource;
}
void Empire::setGoldRessource (int gold){
  if(goldRessource>=0){
    this->goldRessource=gold;
  }
  else {
    std::cerr<<"goldRessource must be positive"<<std::endl;
    this->goldRessource=0;
  }
}
int Empire::getWoodRessource () const{
  return this->woodRessource;
}
void Empire::setWoodRessource (int wood){
  if(woodRessource>=0){
    this->woodRessource=wood;
  }
  else {
    std::cerr<<"woodRessource must be positive"<<std::endl;
    this->woodRessource=0;
  }
}
int Empire::getFoodRessource () const{
  return this->foodRessource;
}
void Empire::setFoodRessource (int food){
  if(foodRessource>=0){
    this->foodRessource=food;
  }
  else{
    std::cerr<<"foodRessource must be positive"<<std::endl;
    this->foodRessource=0;
  }
}
std::vector<Position> Empire::getPosition () const{
  return this->position;
}
void Empire::setPosition (std::vector<Position> postion){
  int count =0;
  for (int i=0;i<position.size();i++){
    if (position[i].getX()>=0 && position[i].getY()>=0){
      count +=1;
    }
  }
    if(count==position.size()) {
      this->position=position;
    }
    else{
      std::cerr<<"position vector must be positive"<<std::endl;
      Position pos0(0,0);
      std::vector<Position> pos;
      for (int i=0;i<pos.size();i++){
        pos[i]=pos0;
      }
      this->position=pos;
    }
}
Barrack* Empire::createBarrack(Barrack* barrack, int id,Position position, int level){
  barrack=new Barrack(id,position,level);
  return barrack;
}

Palace* Empire::createPalace(Palace* palace, int id,Position position, int level){
  palace=new Palace(id,position,level);
  return palace;
}
Ressource* Empire::createRessource(Ressource* ressource, int id,Position position, int level){
  ressource=new Ressource(id,position,level);
  return ressource;
}

void Empire::destructBarrack(Barrack* barrack){
  delete barrack;
}

void Empire::destructPalace(Palace* palace){
  delete palace;
}

void Empire::destructRessource(Ressource* ressource){
  delete ressource;
}

Empire::~Empire (){

}
