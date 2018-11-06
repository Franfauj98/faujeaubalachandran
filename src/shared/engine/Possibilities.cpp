#include "Possibilities.h"
#include <iostream>
using namespace engine;
using namespace std;

Possibilities::~Possibilities (){

}

CommandTypeId Possibilities::getTypeId () const{
  return CommandTypeId::POSSIBILITIES;
}
// void Possibilities::execute (state::Observable& map,int x, int y, int element){
//   switch(element){
//     case 10:
//     std::vector<unique_ptr<state::Element>> selectedMap;
//     for(int i = 0; i<map.getAllMaps().getSize(); i++){
//       for(int j = 0; j<map.getAllMaps().getSize(); j++){
//         Position p(i,j);
//         selectedMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
//       }
//     }
//     Position pos(x,y);
//     selectedMap[x+25*y]=new Decor(SELECTED,pos);
//     // selectedMap[x+25*y]=1;
//     // selected
//     break;
//   }
// }
