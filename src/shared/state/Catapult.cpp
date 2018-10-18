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
  setIdTextureUnits(CATAPULT1);
  UnitCost catapultCost(0,0);
  setUnitCost(catapultCost);
}

Catapult::Catapult (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost catapultCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, catapultCost) {}

Catapult::Catapult (int level, Position p, int id){
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(50);
      setDamage(5);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT1);
      UnitCost catapultCost(50,50);
      setUnitCost(catapultCost);
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(60);
      setDamage(10);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT2);
      UnitCost catapultCost(100,100);
      setUnitCost(catapultCost);
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(70);
      setDamage(15);
      setStrikeRange(5);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT3);
      UnitCost catapultCost(150,150);
      setUnitCost(catapultCost);
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(80);
      setDamage(20);
      setStrikeRange(5);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT4);
      UnitCost catapultCost(200,200);
      setUnitCost(catapultCost);
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(5);
      setDamage(50);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(CATAPULT1);
      UnitCost catapultCost(50,50);
      setUnitCost(catapultCost);
      break;}
  }
}

Catapult::~Catapult(){
}
