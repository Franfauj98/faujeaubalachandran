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
  // if (mapMatrix[x2][y2]==2){
  //
  //   for(int i =0; i<25;i++){
  //     for(int j =0; j<25;j++){
  //       cout<< mapMatrix[i][j]<<" ";
  //     }
  //     cout<<"\n";
  //   }
  //   cout<<"\n";
  //   cout<<"\n";
  std::vector<int> selectedMapId = map.getAllMaps().getSelectedMapId();
  cout<< "selectedMapId"<<selectedMapId[y2+25*x2]<<endl;
  if (selectedMapId[y2+25*x2]==9){
    map.notifyObserver(map,y+25*x,mapMatrix[x][y], 1,-1,y2+25*x2);
  }


    // std::vector<std::vector<int>> mapMatrix2 = map.getAllMaps().getMapMatrix();
    // for(int i =0; i<25;i++){
    //   for(int j =0; j<25;j++){
    //     cout<< mapMatrix2[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }

  //}

}
