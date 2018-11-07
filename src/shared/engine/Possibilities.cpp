#include "Possibilities.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;

Possibilities::~Possibilities (){

}

CommandTypeId Possibilities::getTypeId () const{
  return CommandTypeId::POSSIBILITIES;
}
void Possibilities::execute (state::Observable& map,int x, int y, int element){
    std::vector<unique_ptr<state::Element>> selectedMap;
    for(int i = 0; i<map.getAllMaps().getSize(); i++){
      for(int j = 0; j<map.getAllMaps().getSize(); j++){
        Position p(i,j);
        selectedMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      }
    }
    Position pos(x,y);
    selectedMap[x+25*y]=move(unique_ptr<Element> (new Decor(SELECTED,pos)));
    if (element==10 || element==14 || element==18 || element==22){
      if (x+1>=0 && x+1<25){
        if(map.getAllMaps().getMapMatrix()[x+1][y]==2 || map.getAllMaps().getMapMatrix()[x+1][y]==9 ||
        map.getAllMaps().getMapMatrix()[x+1][y]==26 || map.getAllMaps().getMapMatrix()[x+1][y]==27 ||
        map.getAllMaps().getMapMatrix()[x+1][y]==28 || map.getAllMaps().getMapMatrix()[x+1][y]==29 ||
        map.getAllMaps().getMapMatrix()[x+1][y]==10 || map.getAllMaps().getMapMatrix()[x+1][y]==14 ||
        map.getAllMaps().getMapMatrix()[x+1][y]==16 || map.getAllMaps().getMapMatrix()[x+1][y]==22){
          Position pos2(x+1,y);
          selectedMap[x+1+25*y]=move(unique_ptr<Element> (new Decor(SELECTED,pos2)));
          cout<<map.getAllMaps().getMapMatrix()[x+1][y]<<endl;
        }
      }
      if (x-1>=0 && x-1<25){
        if(map.getAllMaps().getMapMatrix()[x-1][y]==2 || map.getAllMaps().getMapMatrix()[x-1][y]==9 ||
        map.getAllMaps().getMapMatrix()[x-1][y]==26 || map.getAllMaps().getMapMatrix()[x-1][y]==27 ||
        map.getAllMaps().getMapMatrix()[x-1][y]==28 || map.getAllMaps().getMapMatrix()[x-1][y]==29 ||
        map.getAllMaps().getMapMatrix()[x-1][y]==10 || map.getAllMaps().getMapMatrix()[x-1][y]==14 ||
        map.getAllMaps().getMapMatrix()[x-1][y]==16 || map.getAllMaps().getMapMatrix()[x-1][y]==22){
          Position pos3(x-1,y);
          selectedMap[x-1+25*y]=move(unique_ptr<Element> (new Decor(SELECTED,pos3)));
          cout<<map.getAllMaps().getMapMatrix()[x-1][y]<<endl;
        }
      }
      if (y+1>=0 && y+1<25){
        if(map.getAllMaps().getMapMatrix()[x][y+1]==2 || map.getAllMaps().getMapMatrix()[x][y+1]==9 ||
        map.getAllMaps().getMapMatrix()[x][y+1]==26 || map.getAllMaps().getMapMatrix()[x][y+1]==27 ||
        map.getAllMaps().getMapMatrix()[x][y+1]==28 || map.getAllMaps().getMapMatrix()[x][y+1]==29||
        map.getAllMaps().getMapMatrix()[x][y+1]==10 || map.getAllMaps().getMapMatrix()[x][y+1]==14 ||
        map.getAllMaps().getMapMatrix()[x][y+1]==16 || map.getAllMaps().getMapMatrix()[x][y+1]==22){
          Position pos4(x,y+1);
          selectedMap[x+25*(y+1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos4)));
          cout<<map.getAllMaps().getMapMatrix()[x][y+1]<<endl;
        }
      }
      if (y-1>=0 && y-1<25){
        if(map.getAllMaps().getMapMatrix()[x][y-1]==2 || map.getAllMaps().getMapMatrix()[x][y-1]==9 ||
        map.getAllMaps().getMapMatrix()[x][y-1]==26 || map.getAllMaps().getMapMatrix()[x][y-1]==27 ||
        map.getAllMaps().getMapMatrix()[x][y-1]==28 || map.getAllMaps().getMapMatrix()[x][y-1]==29||
        map.getAllMaps().getMapMatrix()[x][y-1]==10 || map.getAllMaps().getMapMatrix()[x][y-1]==14 ||
        map.getAllMaps().getMapMatrix()[x][y-1]==16 || map.getAllMaps().getMapMatrix()[x][y-1]==22){
          Position pos5(x,y-1);
          selectedMap[x+25*(y-1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos5)));
          cout<<map.getAllMaps().getMapMatrix()[x][y-1]<<endl;
        }
      }

    }
    map.getAllMaps().setSelectedMap(selectedMap);

}
