#include "Cavalier.h"
using namespace state;

std::vector<state::Position> poscav;

Cavalier::Cavalier () : Units() {
  Position p(0,0);
  setPosition(p);
  setIdUnits(0);
  setLife(0);
  setDamage(0);
  setStrikeRange(0);
  setMovingRange(0);
  setLevel(0);
  setIdTextureUnits(CAVALIER2);
  UnitCost cavalierCost(0,0);
  setUnitCost(cavalierCost);
  this->type = 18;
}

Cavalier::Cavalier (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost cavalierCost) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits, cavalierCost,poscav) {}

Cavalier::Cavalier (int level, Position p, int id): Units(){
  switch(level){
    case 1 :{
      setPosition(p);
      setIdUnits(id);
      setLife(60);
      setDamage(15);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER2);
      UnitCost cavalierCost(50,50);
      setUnitCost(cavalierCost);
      this->type = 18;
      break;}
    case 2 :{
      setPosition(p);
      setIdUnits(id);
      setLife(70);
      setDamage(20);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER2);
      UnitCost cavalierCost(100,100);
      setUnitCost(cavalierCost);
      this->type = 18;
      break;}
    case 3 :{
      setPosition(p);
      setIdUnits(id);
      setLife(80);
      setDamage(25);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER2);
      UnitCost cavalierCost(150,150);
      setUnitCost(cavalierCost);
      this->type = 18;
      break;}
    case 4 :{
      setPosition(p);
      setIdUnits(id);
      setLife(90);
      setDamage(30);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(level);
      setIdTextureUnits(CAVALIER2);
      UnitCost cavalierCost(200,200);
      setUnitCost(cavalierCost);
      this->type = 18;
      break;}
    default :{
      setPosition(p);
      setIdUnits(id);
      setLife(60);
      setDamage(15);
      setStrikeRange(1);
      setMovingRange(1);
      setLevel(1);
      setIdTextureUnits(CAVALIER2);
      UnitCost cavalierCost(50,50);
      setUnitCost(cavalierCost);
      this->type = 18;
      break;}
  }
}

Cavalier::~Cavalier(){

}
