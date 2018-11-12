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
    int id,shot;
    if (element==10 || element==14 || element==18 || element==22){
      Units* unit =(Units*) map.getAllMaps().getUnitsMap()[y+25*x].get();
      id= unit->getIdUnits();
      shot = map.getAllMaps().getEmpires()[id-1]->getShot();
    }
    else if (element==26 || element==27 || element==28 || element==29){
      Palace* building =(Palace*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
      id = building->getIdBuilding();
      shot = map.getAllMaps().getEmpires()[id-1]->getShot();
    }
    else if (element ==30){
      Barrack* building =(Barrack*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
      id = building->getIdBuilding();
      shot = map.getAllMaps().getEmpires()[id-1]->getShot();
    }
    else if (element==31){
      Ressource* building =(Ressource*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
      id = building->getIdBuilding();
      shot = map.getAllMaps().getEmpires()[id-1]->getShot();
    }
    else {
      Position pos(x,y);
      selectedMap[y+25*x]=move(unique_ptr<Element> (new Decor(SELECTED,pos)));
    }


    if (shot==1){

    Position pos(x,y);
    selectedMap[y+25*x]=move(unique_ptr<Element> (new Decor(SELECTED,pos)));
    std::vector<std::vector<int>> mapMatrix = map.getAllMaps().getMapMatrix();
    if (element==10 || element==14 || element==18 || element==22){

      if (x+1>=0 && x+1<25){
        if(mapMatrix[x+1][y]==2 || mapMatrix[x+1][y]==9 ||
          mapMatrix[x+1][y]==26 || mapMatrix[x+1][y]==27 ||
          mapMatrix[x+1][y]==28 || mapMatrix[x+1][y]==29 ||
          mapMatrix[x+1][y]==10 || mapMatrix[x+1][y]==14 ||
          mapMatrix[x+1][y]==18 || mapMatrix[x+1][y]==22){
          Position pos2(x+1,y);
          selectedMap[y+25*(x+1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos2)));
        }
      }
      if (x-1>=0 && x-1<25){
        if(mapMatrix[x-1][y]==2 || mapMatrix[x-1][y]==9 ||
          mapMatrix[x-1][y]==26 || mapMatrix[x-1][y]==27 ||
          mapMatrix[x-1][y]==28 || mapMatrix[x-1][y]==29 ||
          mapMatrix[x-1][y]==10 || mapMatrix[x-1][y]==14 ||
          mapMatrix[x-1][y]==16 || mapMatrix[x-1][y]==22){
          Position pos3(x-1,y);
          selectedMap[y+25*(x-1)]=move(unique_ptr<Element> (new Decor(SELECTED,pos3)));
        }
      }
      if (y+1>=0 && y+1<25){
        if(mapMatrix[x][y+1]==2 || mapMatrix[x][y+1]==9 ||
        mapMatrix[x][y+1]==26 || mapMatrix[x][y+1]==27 ||
        mapMatrix[x][y+1]==28 || mapMatrix[x][y+1]==29||
        mapMatrix[x][y+1]==10 || mapMatrix[x][y+1]==14 ||
        mapMatrix[x][y+1]==18 || mapMatrix[x][y+1]==22){
          Position pos4(x,y+1);
          selectedMap[y+1+25*(x)]=move(unique_ptr<Element> (new Decor(SELECTED,pos4)));
        }
      }

      if (y-1>=0 && y-1<25){
        if(mapMatrix[x][y-1]==2 || mapMatrix[x][y-1]==9 ||
        mapMatrix[x][y-1]==26 || mapMatrix[x][y-1]==27 ||
        mapMatrix[x][y-1]==28 || mapMatrix[x][y-1]==29||
        mapMatrix[x][y-1]==10 || mapMatrix[x][y-1]==14 ||
        mapMatrix[x][y-1]==18 || mapMatrix[x][y-1]==22){
          Position pos5(x,y-1);
          selectedMap[y-1+25*(x)]=move(unique_ptr<Element> (new Decor(SELECTED,pos5)));
        }
      }

    }
    map.getAllMaps().setSelectedMap(selectedMap);
}
}
