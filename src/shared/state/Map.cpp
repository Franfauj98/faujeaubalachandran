#include "Map.h"
#include <iostream>
using namespace state;
using namespace std;

Map::Map(){}
Map::~Map(){}

void Map::addElement (std::unique_ptr<Element*> elt){
   this->playingMap.push_back(std::move(elt));
}

std::vector<std::unique_ptr<Element*>> const& Map::getMap() const{
  return this->playingMap;
}

void Map::deleteElement (int pos){
  this->playingMap[pos] = nullptr;
}

int Map::getPositionElement (std::unique_ptr<Element*> elt){
  int pos = -1;
  for(size_t i = 0; i<this->playingMap.size(); i++){
    if(elt==this->playingMap[i]){
      pos = i;
      break;
    }
  }
  return pos;
}
