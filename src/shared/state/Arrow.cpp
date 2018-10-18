#include "Arrow.h"
#include <iostream>
using namespace state;

Arrow::Arrow () : Units() {
  Position p;
  setPosition(p);
  setIdUnits(1);
  setLife(0);
  setDamage(0);
  setStrikeRange(1);
  setMovingRange(1);
  setLevel(1);
  setIdTextureUnits(ARROW1);
  UnitCost arrowCost(1,1);
  setUnitCost(arrowCost);
}

Arrow::Arrow (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost arrowCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, arrowCost) {}

Arrow::Arrow (int level, Position p, int id) : Units() {
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(10);
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
      setLife(50);
      setDamage(20);
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
      setLife(60);
      setDamage(30);
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
      setLife(70);
      setDamage(40);
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
      setLife(40);
      setDamage(10);
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
