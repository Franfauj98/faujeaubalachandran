#include "Map.h"
#include <iostream>
using namespace state;
using namespace std;

Map::Map(){}
Map::~Map(){
  // for(size_t i = 0; i<this->playingMap.size();i++){
  //   delete this->playingMap[i];
  // }
}

void Map::addElement (Element* elt){
   this->playingMap.push_back(unique_ptr<Element>(elt));
}

std::vector<unique_ptr<state::Element>> const& Map::getMap(){
  return this->playingMap;
}

void Map::deleteElement (int pos){
  this->playingMap[pos] = nullptr;
}

int Map::getPositionElement (Element* elt){
  int pos = -1;
  for(size_t i = 0; i<this->playingMap.size(); i++){
    if(elt==this->playingMap[i].get()){
      pos = i;
      break;
    }
  }
  return pos;
}
