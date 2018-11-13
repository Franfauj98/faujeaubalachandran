#include "Possibilities.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;

Possibilities::~Possibilities (){

}

Possibilities::Possibilities (int x, int y, int element){
  this->x = x;
  this->y = y;
  this->element = element;
}


CommandTypeId Possibilities::getTypeId () const{
  return CommandTypeId::POSSIBILITIES;
}
void Possibilities::execute (){
    std::vector<unique_ptr<state::Element>> selectedMap;
    for(int i = 0; i<this->map.getAllMaps().getSize(); i++){
      for(int j = 0; j<this->map.getAllMaps().getSize(); j++){
        Position p(i,j);
        selectedMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      }
    }
    Position pos(this->x,this->y);
    selectedMap[this->y+25*this->x]=move(unique_ptr<Element> (new Decor(SELECTED,pos)));
    std::vector<std::vector<int>> mapMatrix = this->map.getAllMaps().getMapMatrix();
    if (this->element==10 || this->element==14 || this->element==18 || this->element==22){

      if (this->x+1>=0 && this->x+1<25){
        if(mapMatrix[this->x+1][this->y]==2 || mapMatrix[this->x+1][this->y]==9 ||
          mapMatrix[this->x+1][this->y]==26 || mapMatrix[this->x+1][this->y]==27 ||
          mapMatrix[this->x+1][this->y]==28 || mapMatrix[this->x+1][this->y]==29 ||
          mapMatrix[this->x+1][this->y]==10 || mapMatrix[this->x+1][this->y]==14 ||
          mapMatrix[this->x+1][this->y]==18 || mapMatrix[this->x+1][this->y]==22){
          Position pos2(this->x+1,this->y);
          selectedMap[this->y+25*(this->x+1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos2)));
        }
      }
      if (this->x-1>=0 && this->x-1<25){
        if(mapMatrix[this->x-1][this->y]==2 || mapMatrix[this->x-1][this->y]==9 ||
          mapMatrix[this->x-1][this->y]==26 || mapMatrix[this->x-1][this->y]==27 ||
          mapMatrix[this->x-1][this->y]==28 || mapMatrix[this->x-1][this->y]==29 ||
          mapMatrix[this->x-1][this->y]==10 || mapMatrix[this->x-1][this->y]==14 ||
          mapMatrix[this->x-1][this->y]==16 || mapMatrix[this->x-1][this->y]==22){
          Position pos3(this->x-1,this->y);
          selectedMap[this->y+25*(this->x-1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos3)));
        }
      }
      if (this->y+1>=0 && this->y+1<25){
        if(mapMatrix[this->x][y+1]==2 || mapMatrix[this->x][this->y+1]==9 ||
        mapMatrix[this->x][this->y+1]==26 || mapMatrix[this->x][this->y+1]==27 ||
        mapMatrix[this->x][this->y+1]==28 || mapMatrix[this->x][this->y+1]==29||
        mapMatrix[this->x][this->y+1]==10 || mapMatrix[this->x][this->y+1]==14 ||
        mapMatrix[this->x][this->y+1]==18 || mapMatrix[this->x][this->y+1]==22){
          Position pos4(this->x,this->y+1);
          selectedMap[this->y+1+25*(this->x)]=move(unique_ptr<Element> (new Decor(SELECTED,pos4)));
        }
      }

      if (this->y-1>=0 && this->y-1<25){
        if(mapMatrix[this->x][this->y-1]==2 || mapMatrix[this->x][y-1]==9 ||
        mapMatrix[this->x][this->y-1]==26 || mapMatrix[this->x][y-1]==27 ||
        mapMatrix[this->x][this->y-1]==28 || mapMatrix[this->x][y-1]==29||
        mapMatrix[this->x][this->y-1]==10 || mapMatrix[this->x][y-1]==14 ||
        mapMatrix[this->x][this->y-1]==18 || mapMatrix[this->x][y-1]==22){
          Position pos5(this->x,this->y-1);
          selectedMap[this->y-1+25*(this->x)]=move(unique_ptr<Element> (new Decor(SELECTED,pos5)));
        }
      }

    }
    this->map.getAllMaps().setSelectedMap(selectedMap);
}
