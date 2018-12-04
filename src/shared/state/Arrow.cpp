#include "Arrow.h"
#include <iostream>
using namespace state;

std::vector<state::Position> pos;

Arrow::Arrow () : Units() {
  Position p(0,0);
  setPosition(p);
  setIdUnits(0);
  setLife(0);
  setDamage(0);
  setStrikeRange(0);
  setMovingRange(0);
  setLevel(0);
  setIdTextureUnits(ARROW2);
  UnitCost arrowCost(0,0);
  setUnitCost(arrowCost);
  this->type = 14;
}

Arrow::Arrow (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost arrowCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, arrowCost,pos) {}

Arrow::Arrow (int level, Position p, int id) : Units() {
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(20);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW2);
      UnitCost arrowCost(50,50);
      setUnitCost(arrowCost);
      this->type = 14;
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(50);
      setDamage(25);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW2);
      UnitCost arrowCost(100,100);
      setUnitCost(arrowCost);
      this->type = 14;
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(60);
      setDamage(30);
      setStrikeRange(3);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW2);
      UnitCost arrowCost(150,150);
      setUnitCost(arrowCost);
      this->type = 14;
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(70);
      setDamage(35);
      setStrikeRange(3);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW2);
      UnitCost arrowCost(200,200);
      setUnitCost(arrowCost);
      this->type = 14;
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(20);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(ARROW2);
      UnitCost arrowCost(50,50);
      setUnitCost(arrowCost);
      this->type = 14;
      break;}
  }
}

Arrow::~Arrow(){
}
