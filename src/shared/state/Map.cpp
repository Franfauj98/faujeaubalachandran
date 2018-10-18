#include "Map.h"
#include <iostream>
using namespace state;
using namespace std;

Map::Map(){}
Map::~Map(){
  for(size_t i = 0; i<this->playingMap.size();i++){
    delete this->playingMap[i];
  }
}

void Map::addElement (Element* elt){
   this->playingMap.push_back(elt);
}

std::vector<Element*> Map::getMap() const{
  return this->playingMap;
}

void Map::deleteElement (int pos){
  this->playingMap[pos] = nullptr;
}

int Map::getPositionElement (Element* elt){
  int pos = -1;
  for(size_t i = 0; i<this->playingMap.size(); i++){
    if(elt==this->playingMap[i]){
      pos = i;
      break;
    }
  }
  return pos;
}
