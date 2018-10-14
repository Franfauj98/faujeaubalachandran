#include "Arrow.h"
#include <iostream>
using namespace state;

Arrow::Arrow () : Units() {}

Arrow::Arrow (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost arrowCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, arrowCost) {}

Arrow::Arrow (int level, Position p, int id) : Units() {
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(400);
      setDamage(100);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW1);
      UnitCost arrowCost(50,50);
      setUnitCost(arrowCost);
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(500);
      setDamage(200);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW2);
      UnitCost arrowCost(100,100);
      setUnitCost(arrowCost);
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(600);
      setDamage(300);
      setStrikeRange(3);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW3);
      UnitCost arrowCost(150,150);
      setUnitCost(arrowCost);
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(700);
      setDamage(400);
      setStrikeRange(3);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW4);
      UnitCost arrowCost(200,200);
      setUnitCost(arrowCost);
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(400);
      setDamage(100);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(ARROW1);
      UnitCost arrowCost(50,50);
      setUnitCost(arrowCost);
      break;}
  }
}

Arrow::~Arrow(){
}
