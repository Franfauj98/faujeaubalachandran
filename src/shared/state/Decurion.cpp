#include "Decurion.h"
using namespace state;

Decurion::Decurion () : Units() {
  Position p(0,0);
  setPosition(p);
  setIdUnits(0);
  setLife(0);
  setDamage(0);
  setStrikeRange(0);
  setMovingRange(0);
  setLevel(0);
  setIdTextureUnits(DECURION1);
  UnitCost decurionCost(0,0);
  setUnitCost(decurionCost);
}

Decurion::Decurion (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost decurionCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, decurionCost) {}

Decurion::Decurion (int level, Position p, int id){
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(30);
      setDamage(30);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION1);
      UnitCost decurionCost(50,50);
      setUnitCost(decurionCost);
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(40);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION2);
      UnitCost decurionCost(100,100);
      setUnitCost(decurionCost);
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(50);
      setDamage(50);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION3);
      UnitCost decurionCost(150,150);
      setUnitCost(decurionCost);
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(60);
      setDamage(55);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION4);
      UnitCost decurionCost(200,200);
      setUnitCost(decurionCost);
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(20);
      setDamage(20);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(DECURION1);
      UnitCost decurionCost(50,50);
      setUnitCost(decurionCost);
      break;}
  }
}

Decurion::~Decurion(){

}
