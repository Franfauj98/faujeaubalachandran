#include "UnitsTileSet.h"
#include "state/Element.h"
#include "state/Units.h"
#include "state/Arrow.h"
#include "state/Decurion.h"
#include "state/Cavalier.h"
#include "state/Catapult.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

// Operations

UnitsTileSet::UnitsTileSet (){
  Tile arrow(6,64,32);
  Tile decurion(2,64,32);
  Tile cavalier(10,64,32);
  Tile catapult(14,64,32);
  std::vector<Tile> a(1);
  std::vector<Tile> d(1);
  std::vector<Tile> c(1);
  std::vector<Tile> e(1);
  a[0]=arrow;
  d[0]=decurion;
  c[0]=cavalier;
  e[0]=catapult;
  this->arrow=a;
  this->decurion=d;
  this->cavalier=c;
  this->catapult=e;

}


const std::string UnitsTileSet::getImageFile () const{
   const std::string file="res/Units.png";
   return file;

}

const Tile UnitsTileSet::getTile (const state::Units& e) const{
  Tile tile;
  switch(e.getType()){
      case 1: tile=this->arrow[0];
      break;
      case 2: tile=this->decurion[0];
      break;
      case 3: tile=this->cavalier[0];
      break;
      case 4: tile=this->catapult[0];
      break;
    }
    return tile;
  }


UnitsTileSet::~UnitsTileSet (){

}
