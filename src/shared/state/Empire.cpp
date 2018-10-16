#include "Empire.h"
#include "Barrack.h"
#include "Palace.h"
#include "Ressource.h"
using namespace state;


Empire::Empire(){

}

Empire::Empire (int id, std::string name, int empireLevel, int life, int goldRessource, int woodRessource, int foodRessource, std::vector<Position> position, Barrack* barrack,
  Ressource* ressource, Palace* palace){
  this->idEmpire=id;
  this->name=name;
  this->empireLevel=empireLevel;
  this->life=life;
  this->goldRessource=goldRessource;
  this->woodRessource=woodRessource;
  this->foodRessource=foodRessource;
  this->position=position;
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
  if(level>0){
    this->empireLevel=level;
  }
  else {
    this->empireLevel=0;
  }
}

int Empire::getEmpireLevel () const{
  return this->empireLevel;

}
void Empire::setLife (int life){
  if(life>0){
    this->life=life;
  }
  else {
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
  if(goldRessource>0){
    this->goldRessource=gold;
  }
  else {
    this->goldRessource=0;
  }
}
int Empire::getWoodRessource () const{
  return this->woodRessource;
}
void Empire::setWoodRessource (int wood){
  if(woodRessource>0){
    this->woodRessource=wood;
  }
  else {
    this->woodRessource=0;
  }
}
int Empire::getFoodRessource () const{
  return this->foodRessource;
}
void Empire::setFoodRessource (int food){
  if(foodRessource>0){
    this->foodRessource=food;
  }
  else{
    this->foodRessource=0;
  }
}
std::vector<Position> Empire::getPosition () const{
  return this->position;
}
void Empire::setPosition (std::vector<Position> postion){
  this->position=position;
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
