#include "Catapult.h"
using namespace state;

Catapult::Catapult () : Units() {}

Catapult::Catapult (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Catapult::Catapult (int level, Position p, int id){
  switch(level){
    case 1 :
      setPosition(p);
      setIdUnits(id);
      setLife(3000);
      setDamage(50);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT1);
      break;
    case 2 :
      Units(id, p, 4000, 50, 4, 1, level, CATAPULT2);
      setPosition(p);
      setIdUnits(id);
      setLife(4000);
      setDamage(70);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT2);
      break;
    case 3 :
      setPosition(p);
      setIdUnits(id);
      setLife(5000);
      setDamage(90);
      setStrikeRange(5);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT3);
      break;
    case 4 :
      setPosition(p);
      setIdUnits(id);
      setLife(6000);
      setDamage(110);
      setStrikeRange(5);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT4);
      break;
    default :
      setPosition(p);
      setIdUnits(id);
      setLife(3000);
      setDamage(50);
      setStrikeRange(4);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CATAPULT1);
      break;
  }
}

Catapult::~Catapult(){
}
