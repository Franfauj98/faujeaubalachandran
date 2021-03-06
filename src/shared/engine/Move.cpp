#include "Move.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace std;
using namespace state;

Move::~Move (){

}

Move::Move (int x, int y, int x2, int y2){
  this->x = x;
  this->y = y;
  this->x2 = x2;
  this->y2 = y2;
}

int Move::getX() const{
  return this->x;
}
int Move::getY() const{
  return this->y;
}
int Move::getX2() const{
  return this->x2;
}
int Move::getY2() const{
  return this->y2;
}

CommandTypeId Move::getTypeId () const{
  return CommandTypeId::MOVE;
}
void Move::execute(state::Observable& map){
  std::vector<std::vector<int>> mapMatrix = map.getAllMaps().getMapMatrix();
  std::vector<int> selectedMapId = map.getAllMaps().getSelectedMapId();
  if (selectedMapId[this->y2+25*this->x2]==9 && mapMatrix[this->x2][this->y2]==2){
    map.notifyObserver(map,this->y+25*this->x,mapMatrix[this->x][this->y], 1,-1,this->y2+25*this->x2);
  }
}

void Move::rollback(state::Observable& map){
  std::vector<std::vector<int>> mapMatrix = map.getAllMaps().getMapMatrix();
  map.notifyObserverPrev(map,this->y+25*this->x,mapMatrix[this->x2][this->y2], 1,-1,this->y2+25*this->x2);

}
