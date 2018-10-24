#include "Map.h"
#include <iostream>
#include "../state.h"
using namespace state;
using namespace std;

Map::Map(){

// Create sea

  int size = 40;

  int list[3][2];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      list[i][j] = rand() % size;
    }
  }

  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      if( ((i>(list[0][0]-5) && i<(list[0][0]+5))&&(j>(list[0][1]-5) && j<(list[0][1]+5))) ||
      ((i>(list[1][0]-5) && i<(list[1][0]+5))&&(j>(list[1][1]-5) && j<(list[1][1]+5))) ||
      ((i>(list[2][0]-5) && i<(list[2][0]+5))&&(j>(list[2][1]-5) && j<(list[2][1]+5))) ){
        Position p(i,j);
        this->basicMap.push_back(unique_ptr<Element> (new Decor(EAU,p)));
        if((i==list[0][0]&&j==list[0][1]) || (i==list[1][0]&&j==list[1][1]) || (i==list[2][0]&&j==list[2][1])){
          this->decorMap.push_back(unique_ptr<Element> (new Decor(POISSON,p)));
        } else {
          this->decorMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
        }
      } else {
        Position p(i,j);
        this->basicMap.push_back(unique_ptr<Element> (new Decor(HERBE,p)));
        this->decorMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      }
    }
  }

}

Map::~Map(){
  // for(size_t i = 0; i<this->playingMap.size();i++){
  //   delete this->playingMap[i];
  // }
}

void Map::addElement (std::vector<std::unique_ptr<Element>> vect, std::unique_ptr<Element> elt){
   vect.push_back(move(elt));
}

std::vector<unique_ptr<state::Element>> const& Map::getBasicMap(){
  return this->basicMap;
}

std::vector<unique_ptr<state::Element>> const& Map::getDecorMap(){
  return this->decorMap;
}

std::vector<unique_ptr<state::Element>> const& Map::getUnitsMap(){
  return this->unitsMap;
}

std::vector<unique_ptr<state::Element>> const& Map::getBuildingsMap(){
  return this->buildingsMap;
}

void Map::deleteElement (int pos){
  this->basicMap[pos] = nullptr;
}

int Map::getPositionElement (std::unique_ptr<Element> elt){
  int pos = -1;
  for(size_t i = 0; i<this->basicMap.size(); i++){
    if(elt.get()==this->basicMap[i].get()){
      pos = i;
      break;
    }
  }
  return pos;
}
