#include "Cavalier.h"
using namespace state;

Cavalier::Cavalier () : Units() {
  Position p;
  setPosition(p);
  setIdUnits(1);
  setLife(0);
  setDamage(0);
  setStrikeRange(1);
  setMovingRange(1);
  setLevel(1);
  setIdTextureUnits(CAVALIER1);
  UnitCost cavalierCost(1,1);
  setUnitCost(cavalierCost);
}

Cavalier::Cavalier (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost cavalierCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, cavalierCost) {}

Cavalier::Cavalier (int level, Position p, int id){
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(25);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER1);
      UnitCost cavalierCost(50,50);
      setUnitCost(cavalierCost);
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(50);
      setDamage(40);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER2);
      UnitCost cavalierCost(100,100);
      setUnitCost(cavalierCost);
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(70);
      setDamage(50);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER3);
      UnitCost cavalierCost(150,150);
      setUnitCost(cavalierCost);
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(80);
      setDamage(55);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER4);
      UnitCost cavalierCost(200,200);
      setUnitCost(cavalierCost);
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(40);
      setDamage(25);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(CAVALIER1);
      UnitCost cavalierCost(50,50);
      setUnitCost(cavalierCost);
      break;}
  }
}

Cavalier::~Cavalier(){

}
