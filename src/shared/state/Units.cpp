#include "Units.h"
#include <iostream>
using namespace state;

Units::Units () {
  Position p(0,0);
  setPosition(p);
  setIdUnits(0);
  setLife(0);
  setDamage(0);
  setStrikeRange(0);
  setMovingRange(0);
  setLevel(0);
  setIdTextureUnits(NONE_UNIT);
  UnitCost cost(0,0);
  setUnitCost(cost);
}

Units::Units (int idUnits, Position position, int life,
  int damage, int strikeRange, int movingRange,
  int level, IdTextureUnits idTextureUnits, UnitCost uniCost) {
  try{
    if(idUnits>=0 && life>=0 && life <=1000 && damage>=0 && damage <= 100 && strikeRange>=0 && strikeRange <= 10 && movingRange>=0 && movingRange<=5 && level>=0 && level<=5) {
      this->position = position;
      this->idUnits = idUnits;
      this->life = life;
      this->damage = damage;
      this->strikeRange = strikeRange;
      this->movingRange = movingRange;
      this->level = level;
      this->idTextureUnits=idTextureUnits;
      this->unitCost=unitCost;
    } else {
      UnitCost cost(0,0);
      this->idUnits = 0;
      this->life = 0;
      this->damage = 0;
      this->strikeRange = 0;
      this->movingRange = 0;
      this->level = 0;
      this->idTextureUnits=ARROW1;
      this->unitCost=cost;
      std::string message="idUnits must be positive\n";
      message += "life must be positive or be smaller than 1000\n";
      message += "damage must be positive or be smaller than 100\n";
      message += "strikeRange must be positive or be smaller than 10\n";
      message += "movingRange must be positive or be smaller than 5\n";
      message += "level must be positive and smaller than 5\n";

      throw std::string(message);
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

void Units::setLife (int life){
  try{
    if(life >= 0 && life <=1000){
      this->life = life;
    } else {
      this->life = 0;
      throw std::string("life must be positive  or be smaller than 1000");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

int Units::getLife() const{
  return this->life;
}

void Units::setDamage (const int damage){
  try{
    if(damage>=0 && damage<=100){
      this->damage = damage;
    } else {
      this->damage = 0;
      throw std::string("damage must be positive or be smaller than 100");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

int Units::getDamage() const{
  return this->damage;
}

void Units::setStrikeRange (const int strikeRange){
try{
    if(strikeRange >= 0 && strikeRange<=10){
      this->strikeRange = strikeRange;
    } else {
      this->strikeRange = 0;
      throw std::string("strikeRange must be positive or be smaller than 10");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

int Units::getStrikeRange() const{
  return this->strikeRange;
}

void Units::setMovingRange (const int movingRange){
  try{
    if(movingRange >= 0 && movingRange<=5){
      this->movingRange = movingRange;
    } else {
      this->movingRange = 0;
      throw std::string("movingRange must be positive or be smaller than 5");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

int Units::getMovingRange() const{
  return this->movingRange;
}

void Units::setLevel (const int level){
  try{
    if(level>=0 && level<=5){
      this->level = level;
    } else {
      this->level = 0;
      throw std::string("level must be positive or be smaller than 5");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

int Units::getLevel() const{
  return this->level;
}

IdTextureUnits Units::getIdTextureUnits () const{
  return this->idTextureUnits;
}

void Units::setIdTextureUnits (const IdTextureUnits idTextureUnits){
  this->idTextureUnits = idTextureUnits;
}

int Units::getIdUnits () const{
  return this->idUnits;
}

void Units::setIdUnits (const int idUnits){
  try{
    if(idUnits>=0){
      this->idUnits = idUnits;
    } else {
      this->idUnits = 0;
      throw std::string("idUnits must be positive");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
  }
}

UnitCost Units::getUnitCost () const{
  return this->unitCost;
}

void Units::setUnitCost (const UnitCost uniCost){
  this->unitCost=uniCost;
}

void Units::move (Position& p2, int moveNumber){
  if(moveAllowed(p2, moveNumber)) this->position=p2;
}

bool Units::moveAllowed (Position p2, int moveNumber){
  if(moveNumber>0 && p2.getX()>=0 && p2.getY()>=0 && (p2.getX()+moveNumber)<10000 && (p2.getY()+moveNumber)<10000){
    if(distance(this->position, p2) <= this -> movingRange){
      return true;
    }
    return false;
  } else {
    return false;
  }
}

void Units::attack (Units& unit2){
  if(attackAllowed(unit2)){
    const int tempLife = unit2.getLife()-this->damage;
    if(tempLife>0){
      unit2.setLife(tempLife);
    } else{
      unit2.setLife(0);
    }
  }
}

bool Units::attackAllowed (Units unit2){
  if(unit2.getLife() > 0){
    if(distance(this->position, unit2.getPosition()) <= this -> strikeRange){
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void Units::attackBuilding (Buildings& building){
  if(attackBuildingAllowed(building)){
    const int tempLife = building.getLife()-this->damage;
    if(tempLife>0){
      building.setLife(tempLife);
    } else{
      building.setLife(0);
    }
  }
}

bool Units::attackBuildingAllowed (Buildings building){
  if(building.getLife() > 0){
    if(distance(this->position, building.getPosition()) <= this -> strikeRange){
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool Units::isPassable(){
  return false;
}

Units::~Units () {}
