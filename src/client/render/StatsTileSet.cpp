#include "StatsTileSet.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

// Operations

StatsTileSet::StatsTileSet (){
  std::vector<Tile> p(4);
  Tile level1(2,64,96);
  Tile level2(3,64,96);
  Tile level3(4,64,96);
  Tile level4(5,64,96);
  p[0]=level1;
  p[1]=level2;
  p[2]=level3;
  p[3]=level4;
  this->level=p;

  Tile life(1,64,96);
  this->life=life;

}


const std::string StatsTileSet::getImageFile () const{
   const std::string file="res/stats.png";
   return file;

}


StatsTileSet::~StatsTileSet (){

}
