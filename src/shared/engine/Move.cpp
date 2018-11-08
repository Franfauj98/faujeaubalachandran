#include "Move.h"
#include <iostream>
using namespace engine;
using namespace std;

Move::~Move (){

}

CommandTypeId Move::getTypeId () const{
  return CommandTypeId::MOVE;
}
void Move::execute(state::Observable& map, int x, int y, int x2, int y2){
  std::vector<std::vector<int>> mapMatrix = map.getAllMaps().getMapMatrix();
  std::vector<int> selectedMapId = map.getAllMaps().getSelectedMapId();
  if (selectedMapId[y2+25*x2]==9){
    map.notifyObserver(map,y+25*x,mapMatrix[x][y], 1,-1,y2+25*x2);
  }
}
