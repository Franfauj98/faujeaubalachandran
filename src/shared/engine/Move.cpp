#include "Move.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace std;
using namespace state;

Move::~Move (){

}

CommandTypeId Move::getTypeId () const{
  return CommandTypeId::MOVE;
}
bool Move::execute(state::Observable& map, int x, int y, int x2, int y2){
  std::vector<std::vector<int>> mapMatrix = this->map.getAllMaps().getMapMatrix();
  std::vector<int> selectedMapId = this->map.getAllMaps().getSelectedMapId();
  if (selectedMapId[this->y2+25*this->x2]==9 && mapMatrix[this->x2][this->y2]==2){
    this->map.notifyObserver(this->map,this->y+25*this->x,mapMatrix[this->x][this->y], 1,-1,this->y2+25*this->x2);
  } else{
    return false;
  }
  return true;
}
