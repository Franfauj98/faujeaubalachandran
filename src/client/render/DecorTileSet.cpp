#include "DecorTileSet.h"
#include "state/Element.h"
#include "state/Decor.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;

// Operations

DecorTileSet::DecorTileSet (){
  std::vector<Tile> d(4);
  Tile palace1(1,64,32);
  Tile palace2(2,64,32);
  Tile palace3(3,64,32);
  Tile palace4(4,64,32);
  p[0]=palace1;
  p[1]=palace2;
  p[2]=palace3;
  p[3]=palace4;
  this->palace=p;


}

int DecorTileSet::getCellWidth () const{
  return 64;

}

int DecorTileSet::getCellHeight () const{
  return 32;
}

const std::string DecorTileSet::getImageFile () const{
   const std::string file="res/Buildings.png";
   return file;

}

const Tile DecorTileSet::getTile (const state::Element& e) const{
  Tile tile;
  switch(e.getType()){
      case 5: tile=this->barrack[0];
      break;
      case 6:
            switch (e.getLevel()){
              case 1: tile=this->palace[0];
              break;
              case 2:tile=this->palace[1];/
              break;
              case 3:tile=this->palace[2];
              break;
              case 4:tile=this->palace[3];
             break;
          }
      case 7: tile=this->ressource[0];
      break;
    }
    return tile;
  }


DecorTileSet::~DecorTileSet (){

}
