#include "Possibilities.h"
#include "state.h"
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;


bool verification(Observable& principalMap, int x,int y, int id, int element){
  bool verif=true;
  if (element==1){
    Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[y+25*x].get();
    int idUnit=unit->getIdUnits();
    if (idUnit==id){
      verif=false;
    } else {
    verif=true;
    }
  }
  else if (element==0){
    Buildings* building =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[y+25*x].get();
    int idBuilding=building->getIdBuilding();
    if (idBuilding==id){
      verif=false;
    } else {
      verif=true;
    }
  }
  return verif;
}


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
void Possibilities::execute (state::Observable& map){
    std::vector<unique_ptr<state::Element>> selectedMap;
    for(int i = 0; i<map.getAllMaps().getSize(); i++){
      for(int j = 0; j<map.getAllMaps().getSize(); j++){
        Position p(i,j);
        selectedMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      }
    }
    // cout<<"posX:"<<this->x<<" posY:"<<this->y<<endl;
    Position pos(this->x,this->y);
    selectedMap[this->y+25*this->x]=move(unique_ptr<Element> (new Decor(SELECTED,pos)));
    std::vector<std::vector<int>> mapMatrix = map.getAllMaps().getMapMatrix();
    if (this->element==10 || this->element==14 || this->element==18 || this->element==22){
      Units* unit =(Units*) map.getAllMaps().getUnitsMap()[this->y+25*this->x].get();
      int id=unit->getIdUnits();
      if (this->x+1>=0 && this->x+1<25){
        if(mapMatrix[this->x+1][this->y]==2 || mapMatrix[this->x+1][this->y]==9
          || (mapMatrix[this->x+1][this->y]==26 && verification(map, this->x+1, this->y,id, 0))
          || (mapMatrix[this->x+1][this->y]==27 && verification(map, this->x+1, this->y,id, 0))
          || (mapMatrix[this->x+1][this->y]==28 && verification(map, this->x+1, this->y,id, 0))
          || (mapMatrix[this->x+1][this->y]==29 && verification(map, this->x+1, this->y,id, 0))
          || (mapMatrix[this->x+1][this->y]==10 && verification(map, this->x+1, this->y,id, 1))
          || (mapMatrix[this->x+1][this->y]==14 && verification(map, this->x+1, this->y,id, 1))
          || (mapMatrix[this->x+1][this->y]==18 && verification(map, this->x+1, this->y,id, 1))
          || (mapMatrix[this->x+1][this->y]==22&& verification(map, this->x+1, this->y,id, 1))){
          Position pos2(this->x+1,this->y);
          selectedMap[this->y+25*(this->x+1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos2)));
        }
      }
      if (this->x-1>=0 && this->x-1<25){
        if(mapMatrix[this->x-1][this->y]==2 || mapMatrix[this->x-1][this->y]==9
          || (mapMatrix[this->x-1][this->y]==26 && verification(map, this->x-1, this->y,id, 0))
          || (mapMatrix[this->x-1][this->y]==27 && verification(map, this->x-1, this->y,id, 0))
          || (mapMatrix[this->x-1][this->y]==28 && verification(map, this->x-1, this->y,id, 0))
          || (mapMatrix[this->x-1][this->y]==29 && verification(map, this->x-1, this->y,id, 0))
          || (mapMatrix[this->x-1][this->y]==10 && verification(map, this->x-1, this->y,id, 1))
          || (mapMatrix[this->x-1][this->y]==14 && verification(map, this->x-1, this->y,id, 1))
          || (mapMatrix[this->x-1][this->y]==16 && verification(map, this->x-1, this->y,id, 1))
          || (mapMatrix[this->x-1][this->y]==22&& verification(map, this->x-1, this->y,id, 1))){
          Position pos3(this->x-1,this->y);
          selectedMap[this->y+25*(this->x-1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos3)));
        }
      }
      if (this->y+1>=0 && this->y+1<25){
        if(mapMatrix[this->x][y+1]==2 || mapMatrix[this->x][this->y+1]==9
          || (mapMatrix[this->x][this->y+1]==26 && verification(map, this->x, this->y+1,id, 0))
          || (mapMatrix[this->x][this->y+1]==27 && verification(map, this->x, this->y+1,id, 0))
          || (mapMatrix[this->x][this->y+1]==28 && verification(map, this->x, this->y+1,id, 0))
          || (mapMatrix[this->x][this->y+1]==29 && verification(map, this->x, this->y+1,id, 0))
          || (mapMatrix[this->x][this->y+1]==10 && verification(map, this->x, this->y+1,id, 1))
          || (mapMatrix[this->x][this->y+1]==14  && verification(map, this->x, this->y+1,id, 1))
          || (mapMatrix[this->x][this->y+1]==18 && verification(map, this->x, this->y+1,id, 1))
          || (mapMatrix[this->x][this->y+1]==22 && verification(map, this->x, this->y+1,id, 1))){
          Position pos4(this->x,this->y+1);
          selectedMap[this->y+1+25*(this->x)]=move(unique_ptr<Element> (new Decor(SELECTED,pos4)));
        }
      }

      if (this->y-1>=0 && this->y-1<25){
        if(mapMatrix[this->x][this->y-1]==2 || mapMatrix[this->x][y-1]==9
          || (mapMatrix[this->x][this->y-1]==26 && verification(map, this->x, this->y-1,id, 0))
          || (mapMatrix[this->x][y-1]==27 && verification(map, this->x, this->y-1,id, 0))
          || (mapMatrix[this->x][this->y-1]==28 && verification(map, this->x, this->y-1,id, 0))
          || (mapMatrix[this->x][y-1]==29 && verification(map, this->x, this->y-1,id, 0))
          || (mapMatrix[this->x][this->y-1]==10 && verification(map, this->x, this->y-1,id, 1))
          || (mapMatrix[this->x][y-1]==14 && verification(map, this->x, this->y-1,id, 1))
          || (mapMatrix[this->x][this->y-1]==18 && verification(map, this->x, this->y-1,id, 1))
          || (mapMatrix[this->x][y-1]==22 && verification(map, this->x, this->y-1,id, 1))){
          Position pos5(this->x,this->y-1);
          selectedMap[this->y-1+25*(this->x)]=move(unique_ptr<Element> (new Decor(SELECTED,pos5)));
        }
      }

    }
    map.getAllMaps().setSelectedMap(selectedMap);
}
