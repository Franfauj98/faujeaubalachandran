#include "Empire.h"
#include "Barrack.h"
#include "Palace.h"
#include "Ressource.h"
#include <iostream>
using namespace state;

Empire::Empire(){
  this->idEmpire=0;
  this->name="none";
  this->empireLevel=0;
  this->life=0;
  this->goldRessource=0;
  this->woodRessource=0;
  this->foodRessource=0;
  std::vector<Position> position(1);
  Position pos0(0,0);
  position[0]=pos0;
  this->position=position;
  this->barrack=new Barrack();
  this->ressource=new Ressource();
  this->palace=new Palace();
}

Empire::Empire (int id, std::string name, int empireLevel, int life, int goldRessource, int woodRessource, int foodRessource, std::vector<Position> position, Barrack* barrack,
  Ressource* ressource, Palace* palace){
  try{
    bool a;
    unsigned int count =0;
    for (unsigned int i=0;i<position.size();i++){
      if (position[i].getX()>=0 && position[i].getY()>=0 && position[i].getX()<=10000 &&position[i].getY()<=10000){
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
      this->barrack=barrack;
      this->palace=palace;
      this->ressource=ressource;
    } else {
      this->idEmpire=0;
      this->name="none";
      this->empireLevel=0;
      this->life=0;
      this->goldRessource=0;
      this->woodRessource=0;
      this->foodRessource=0;
      Position pos0(0,0);
      std::vector<Position> pos;
      for (unsigned int i=0;i<pos.size();i++){
        pos[i]=pos0;
      }
      setPosition(pos);
      Barrack* barrack0 = new Barrack();
      Palace* palace0 = new Palace();
      Ressource* ressource0 = new Ressource();
      this->barrack=barrack0;
      this->palace=palace0;
      this->ressource=ressource0;
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

Barrack* Empire::getBarrack () const{
  return this->barrack;
}
void Empire::setBarrack (Barrack* barrack){
  this->barrack=barrack;
}

Palace* Empire::getPalace () const{
  return this->palace;
}
void Empire::setPalace (Palace* palace){
  this->palace=palace;
}

Ressource* Empire::getRessource () const{
  return this->ressource;
}
void Empire::setRessource (Ressource* ressource){
  this->ressource=ressource;
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
