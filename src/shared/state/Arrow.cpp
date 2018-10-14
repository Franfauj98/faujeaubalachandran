#include "Arrow.h"
#include <iostream>
using namespace state;

Arrow::Arrow () : Units() {}

Arrow::Arrow (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Arrow::Arrow (int level, Position p, int id) : Units() {
  switch(level){
    case 1 :
      setPosition(p);
      setIdUnits(id);
      setLife(400);
      setDamage(100);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW1);
      break;
    case 2 :
      setPosition(p);
      setIdUnits(id);
      setLife(500);
      setDamage(200);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW2);
      break;
    case 3 :
      setPosition(p);
      setIdUnits(id);
      setLife(600);
      setDamage(300);
      setStrikeRange(3);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW3);
      break;
    case 4 :
      setPosition(p);
      setIdUnits(id);
      setLife(700);
      setDamage(400);
      setStrikeRange(3);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW4);
      break;
    default :
      setPosition(p);
      setIdUnits(id);
      setLife(400);
      setDamage(100);
      setStrikeRange(2);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(ARROW1);
      break;
  }
}

Arrow::~Arrow(){
}
