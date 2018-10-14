#include "Decurion.h"
using namespace state;

Decurion::Decurion () : Units() {}

Decurion::Decurion (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Decurion::Decurion (int level, Position p, int id){
  switch(level){
    case 1 :
      setPosition(p);
      setIdUnits(id);
      setLife(600);
      setDamage(150);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION1);
      break;
    case 2 :
      setPosition(p);
      setIdUnits(id);
      setLife(700);
      setDamage(200);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION2);
      break;
    case 3 :
      setPosition(p);
      setIdUnits(id);
      setLife(800);
      setDamage(250);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION3);
      break;
    case 4 :
      setPosition(p);
      setIdUnits(id);
      setLife(900);
      setDamage(300);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION4);
      break;
    default :
      setPosition(p);
      setIdUnits(id);
      setLife(600);
      setDamage(150);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(DECURION1);
      break;
  }
}

Decurion::~Decurion(){

}
