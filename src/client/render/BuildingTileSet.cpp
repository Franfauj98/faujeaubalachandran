#include "BuildingTileSet.h"
#include "state/Element.h"
#include "state/Buildings.h"
#include "state/Palace.h"
#include "state/Barrack.h"
#include "state/Ressource.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

// Operations

BuildingTileSet::BuildingTileSet (){
  std::vector<Tile> p(4);
  Tile palace1(1,64,32);
  Tile palace2(2,64,32);
  Tile palace3(3,64,32);
  Tile palace4(4,64,32);
  p[0]=palace1;
  p[1]=palace2;
  p[2]=palace3;
  p[3]=palace4;
  this->palace=p;

  std::vector<Tile> b(1);
  Tile barrackAll(5,64,32);
  b[0]=barrackAll;
  this->barrack=b;

  std::vector<Tile> r(3);
  Tile ressource1(6,64,32);
  Tile ressource2(7,64,32);
  Tile ressource3(8,64,32);
  r[0]=ressource1;
  r[1]=ressource2;
  r[2]=ressource3;
  this->ressource=r;
}


const std::string BuildingTileSet::getImageFile () const{
   const std::string file="res/Buildings.png";
   return file;

}

const Tile BuildingTileSet::getTile (const state::Buildings& e) const{
  Tile tile;
  switch(e.getType()){
      case 5: tile=this->barrack[0];
      break;
      case 6:
            switch (e.getLevel()){
              case 1: tile=this->palace[0];
              break;
              case 2:tile=this->palace[1];
              break;
              case 3:tile=this->palace[2];
              break;
              case 4:tile=this->palace[3];
             break;
          }
      break;
      case 7: tile=this->ressource[0];
      break;
    }
    return tile;
  }


BuildingTileSet::~BuildingTileSet (){

}
