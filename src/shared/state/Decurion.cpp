#include "Decurion.h"
using namespace state;

Decurion::Decurion () : Units() {}

Decurion::Decurion (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost decurionCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, decurionCost) {}

Decurion::Decurion (int level, Position p, int id){
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(600);
      setDamage(150);
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
      setLife(700);
      setDamage(200);
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
      setLife(800);
      setDamage(250);
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
      setLife(900);
      setDamage(300);
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
      setLife(600);
      setDamage(150);
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
