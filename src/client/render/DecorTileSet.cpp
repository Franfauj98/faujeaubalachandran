#include "DecorTileSet.h"
#include "state/Element.h"
#include "state/Decor.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

// Operations

DecorTileSet::DecorTileSet (){
  std::vector<Tile> d(9);
  Tile decor0(0,64,32);
  Tile decor1(1,64,32);
  Tile decor2(2,64,32);
  Tile decor3(3,64,32);
  Tile decor4(4,64,32);
  Tile decor5(5,64,32);
  Tile decor6(6,64,32);
  Tile decor7(7,64,32);
  Tile decor8(8,64,32);
  d[0]=decor0;
  d[1]=decor1;
  d[2]=decor2;
  d[3]=decor3;
  d[4]=decor4;
  d[5]=decor5;
  d[6]=decor6;
  d[7]=decor7;
  d[8]=decor8;
  this->decor=d;


}


const std::string DecorTileSet::getImageFile () const{
   const std::string file="res/terrain.png";
   return file;

}

const Tile DecorTileSet::getTile (const state::Decor& e) const{
  Tile tile;
  switch(e.getIdDecor()){
      case 0: tile=this->decor[0];
      break;
      case 1: tile=this->decor[1];
      break;
      case 2: tile=this->decor[2];
      break;
      case 3: tile=this->decor[3];
      break;
      case 4: tile=this->decor[4];
      break;
      case 5: tile=this->decor[5];
      break;
      case 6: tile=this->decor[6];
      break;
      case 7: tile=this->decor[7];
      break;
      case 8: tile=this->decor[8];
      break;
      case 9: tile=this->decor[0];
      break;


    }
    return tile;
  }


DecorTileSet::~DecorTileSet (){

}
