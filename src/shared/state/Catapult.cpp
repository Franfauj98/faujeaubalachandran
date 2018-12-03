#include "Catapult.h"
using namespace state;

Catapult::Catapult () : Units() {
  Position p(0,0);
  setPosition(p);
  setIdUnits(0);
  setLife(0);
  setDamage(0);
  setStrikeRange(0);
  setMovingRange(0);
  setLevel(0);
  setIdTextureUnits(CATAPULT2);
  UnitCost catapultCost(0,0);
  this->type = 22;
  setUnitCost(catapultCost);
}

Catapult::Catapult (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost catapultCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, catapultCost,0) {}

Catapult::Catapult (int level, Position p, int id){
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(20);
      setDamage(40);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT2);
      UnitCost catapultCost(50,50);
      setUnitCost(catapultCost);
      this->type = 22;
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(30);
      setDamage(60);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT2);
      UnitCost catapultCost(100,100);
      setUnitCost(catapultCost);
      this->type = 22;
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(80);
      setStrikeRange(5);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT2);
      UnitCost catapultCost(150,150);
      setUnitCost(catapultCost);
      this->type = 22;
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(50);
      setDamage(100);
      setStrikeRange(5);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT2);
      UnitCost catapultCost(200,200);
      setUnitCost(catapultCost);
      this->type = 22;
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(5);
      setDamage(50);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(CATAPULT2);
      UnitCost catapultCost(50,50);
      setUnitCost(catapultCost);
      this->type = 22;
      break;}
  }
}

Catapult::~Catapult(){
}
