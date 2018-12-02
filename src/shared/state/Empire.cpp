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
  this->goldRessource=0;
  this->woodRessource=0;
  this->foodRessource=0;
  this->shot=0;
}

Empire::Empire (int id, std::string name, int goldRessource, int woodRessource, int foodRessource, int shot){
  try{
    if (id>=0 &&goldRessource>=0 && woodRessource>=0 && foodRessource>=0){
      this->idEmpire=id;
      this->name=name;
      this->goldRessource=goldRessource;
      this->woodRessource=woodRessource;
      this->foodRessource=foodRessource;
      this->shot=shot;
    } else {
      this->idEmpire=0;
      this->name="none";
      this->goldRessource=0;
      this->woodRessource=0;
      this->foodRessource=0;
      this->shot=shot;
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

void Empire::updateRessource(std::vector<std::unique_ptr<Element>>& buildingsMap){
  // Buildings* build;
  Ressource* ress;
  for(size_t i = 0; i < buildingsMap.size(); i++){
    Buildings* build = (Buildings *)(buildingsMap[i].get());
    if(build->getType() == 31 && build->getIdBuilding()==this->idEmpire){
      ress = (Ressource *) build;
      this->foodRessource+=ress->getProduction();
      this->goldRessource+=ress->getProduction();
      this->woodRessource+=ress->getProduction();
    }
  }
}

Empire::~Empire (){

}
