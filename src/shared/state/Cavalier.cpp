#include "Cavalier.h"
using namespace state;

Cavalier::Cavalier () : Units() {}

Cavalier::Cavalier (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Cavalier::Cavalier (int level, Position p, int id){
  switch(level){
    case 1 :
      setPosition(p);
      setIdUnits(id);
      setLife(1000);
      setDamage(180);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER1);
      break;
    case 2 :
      setPosition(p);
      setIdUnits(id);
      setLife(1500);
      setDamage(230);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER2);
      break;
    case 3 :
      setPosition(p);
      setIdUnits(id);
      setLife(2000);
      setDamage(300);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER3);
      break;
    case 4 :
      setPosition(p);
      setIdUnits(id);
      setLife(2500);
      setDamage(350);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER4);
      break;
    default :
      setPosition(p);
      setIdUnits(id);
      setLife(1000);
      setDamage(180);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER1);
      break;
  }
}

Cavalier::~Cavalier(){

}
