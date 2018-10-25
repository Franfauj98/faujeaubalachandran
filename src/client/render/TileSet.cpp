#include "TileSet.h"
#include "state.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;


TileSet::~TileSet(){

}

int TileSet::getCellWidth () const{
  return 64;

}

int TileSet::getCellHeight () const{
  return 32;
}
