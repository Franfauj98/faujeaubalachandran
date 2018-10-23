#include "Map.h"
#include <iostream>
#include "../state.h"
using namespace state;
using namespace std;

Map::Map(){

// Create sea
  int list[3][2];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      list[i][j] = rand() % 40;
    }
  }
  cout<<list[0][0]<<endl;
  cout<<list[0][1]<<endl;
  cout<<list[1][0]<<endl;
  cout<<list[1][1]<<endl;
  cout<<list[2][0]<<endl;
  cout<<list[2][1]<<endl;

  for(int i = 0; i<40; i++){
    for(int j = 0; j<40; j++){
      if( ((i>(list[0][0]-5) && i<(list[0][0]+5))&&(j>(list[0][1]-5) && j<(list[0][1]+5))) ||
      ((i>(list[1][0]-5) && i<(list[1][0]+5))&&(j>(list[1][1]-5) && j<(list[1][1]+5))) ||
      ((i>(list[2][0]-5) && i<(list[2][0]+5))&&(j>(list[2][1]-5) && j<(list[2][1]+5))) ){
        Position p(i,j);
        this->basicMap.push_back(unique_ptr<Element> (new Decor(EAU,p)));
      } else {
        Position p(i,j);
        this->basicMap.push_back(unique_ptr<Element> (new Decor(HERBE,p)));
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

std::vector<unique_ptr<state::Element>> const& Map::getMap(){
  return this->basicMap;
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
