#include "Map.h"
#include <iostream>
#include "../state.h"
#include <time.h>
using namespace state;
using namespace std;

int distance(int x1, int y1, int x2, int y2){
  int absDiff = abs(x1-x2);
  int ordDiff = abs(y1-y2);
  return absDiff+ordDiff;
}

Map::Map(){

// Create sea
  srand(time(NULL));

  int sizeSea = 2;
  int sizeMountain = 2;
  int sizeWood = 2;

  int listSeaPosition[3][2];
  int listWoodPosition[3][2];
  int listMountainPosition[3][2];
  int listBuildingsPosition[3][2];

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      int seaRand = rand() % size;
      listSeaPosition[i][j] = seaRand;
    }
  }

  for(int i = 0; i<3; i++){
    int woodRandx = rand() % size;
    int woodRandy = rand() % size;
    while( !((woodRandx != listSeaPosition[i][0] || woodRandy != listSeaPosition[i][1]) && distance(woodRandx, woodRandy, listSeaPosition[i][0], listSeaPosition[i][1]) > 6) ){
      woodRandx = rand() % size;
      woodRandy = rand() % size;
    }
    listWoodPosition[i][0] = woodRandx;
    listWoodPosition[i][1] = woodRandy;
  }

  for(int i = 0; i<3; i++){
    int mountainRandx = rand() % size;
    int mountainRandy = rand() % size;
    while( !( ((mountainRandx != listSeaPosition[i][0] || mountainRandy != listSeaPosition[i][1]) && distance(mountainRandx, mountainRandy, listSeaPosition[i][0], listSeaPosition[i][1]) > 6) &&
    ((mountainRandx != listWoodPosition[i][0] || mountainRandy != listWoodPosition[i][1]) && distance(mountainRandx, mountainRandy, listWoodPosition[i][0], listWoodPosition[i][1]) > 6) )){
      mountainRandx = rand() % size;
      mountainRandy = rand() % size;
    }
    listMountainPosition[i][0] = mountainRandx;
    listMountainPosition[i][1] = mountainRandy;
  }

  for(int i = 0; i<3; i++){
    int buildingRandx = rand() % size;
    int buildingRandy = rand() % size;
    while( !( ((buildingRandx != listSeaPosition[i][0] || buildingRandy != listSeaPosition[i][1]) && distance(buildingRandx, buildingRandy, listSeaPosition[i][0], listSeaPosition[i][1]) > 6) &&
    ((buildingRandx != listWoodPosition[i][0] || buildingRandy != listWoodPosition[i][1]) && distance(buildingRandx, buildingRandy, listWoodPosition[i][0], listWoodPosition[i][1]) > 6) &&
    ((buildingRandx != listMountainPosition[i][0] || buildingRandy != listMountainPosition[i][1]) && distance(buildingRandx, buildingRandy, listMountainPosition[i][0], listMountainPosition[i][1]) > 6)
      && (buildingRandx%this->size > 3) && (buildingRandy%this->size > 3) && (buildingRandx%this->size < (this->size-3)) && (buildingRandy%this->size < (this->size-3)) )){
      buildingRandx = rand() % size;
      buildingRandy = rand() % size;
    }
    listBuildingsPosition[i][0] = buildingRandx;
    listBuildingsPosition[i][1] = buildingRandy;
  }

  for(int i = 0; i < 3; i++){
    cout << "x  : " << listSeaPosition[i][0] << " y  : " << listSeaPosition[i][1] << endl;
    cout << "x  : " << listWoodPosition[i][0] << " y  : " << listWoodPosition[i][1] << endl;
    cout << "x  : " << listMountainPosition[i][0] << " y  : " << listMountainPosition[i][1] << endl;
  }

//Map Init
  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      Position p(i,j);
      this->basicMap.push_back(unique_ptr<Element> (new Decor(HERBE,p)));
      this->decorMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      this->buildingsMap.push_back(unique_ptr<Element> (new Buildings()));
      this->unitsMap.push_back(unique_ptr<Element> (new Units()));
    }
  }

// Add decor to maps
  int toChange=0;

  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      if( ((i>(listSeaPosition[0][0]-sizeSea) && i<(listSeaPosition[0][0]+sizeSea))&&(j>(listSeaPosition[0][1]-sizeSea) && j<(listSeaPosition[0][1]+sizeSea))) ||
      ((i>(listSeaPosition[1][0]-sizeSea) && i<(listSeaPosition[1][0]+sizeSea))&&(j>(listSeaPosition[1][1]-sizeSea) && j<(listSeaPosition[1][1]+sizeSea))) ||
      ((i>(listSeaPosition[2][0]-sizeSea) && i<(listSeaPosition[2][0]+sizeSea))&&(j>(listSeaPosition[2][1]-sizeSea) && j<(listSeaPosition[2][1]+sizeSea))) ){
        Position p(i,j);
        // this->basicMap[toChange] = move(unique_ptr<Element> (new Decor(EAU,p)));
        this->basicMap[toChange] = move(unique_ptr<Element> (new Decor(EAU,p)));
        if((i==listSeaPosition[0][0]&&j==listSeaPosition[0][1]) || (i==listSeaPosition[1][0]&&j==listSeaPosition[1][1]) || (i==listSeaPosition[2][0]&&j==listSeaPosition[2][1])){
          this->decorMap[toChange] = move(unique_ptr<Element> (new Decor(POISSON,p)));
        }
      } else if( ((i>(listWoodPosition[0][0]-sizeWood) && i<(listWoodPosition[0][0]+sizeWood))&&(j>(listWoodPosition[0][1]-sizeWood) && j<(listWoodPosition[0][1]+sizeWood))) ||
      ((i>(listWoodPosition[1][0]-sizeWood) && i<(listWoodPosition[1][0]+sizeWood))&&(j>(listWoodPosition[1][1]-sizeWood) && j<(listWoodPosition[1][1]+sizeWood))) ||
      ((i>(listWoodPosition[2][0]-sizeWood) && i<(listWoodPosition[2][0]+sizeWood))&&(j>(listWoodPosition[2][1]-sizeWood) && j<(listWoodPosition[2][1]+sizeWood))) ){
        Position p(i,j);
        this->decorMap[toChange] = move(unique_ptr<Element> (new Decor(ARBRE,p)));
      } else if( ((i>(listMountainPosition[0][0]-sizeMountain) && i<(listMountainPosition[0][0]+sizeMountain))&&(j>(listMountainPosition[0][1]-sizeMountain) && j<(listMountainPosition[0][1]+sizeMountain))) ||
      ((i>(listMountainPosition[1][0]-sizeMountain) && i<(listMountainPosition[1][0]+sizeMountain))&&(j>(listMountainPosition[1][1]-sizeMountain) && j<(listMountainPosition[1][1]+sizeMountain))) ||
      ((i>(listMountainPosition[2][0]-sizeMountain) && i<(listMountainPosition[2][0]+sizeMountain))&&(j>(listMountainPosition[2][1]-sizeMountain) && j<(listMountainPosition[2][1]+sizeMountain))) ){
        Position p(i,j);
        this->decorMap[toChange] = move(unique_ptr<Element> (new Decor(MONTAGNE,p)));
      } else if( (i==listBuildingsPosition[0][0] && j==listBuildingsPosition[0][1]) || (i==listBuildingsPosition[0][0] && j==listBuildingsPosition[0][1]) || (i==listBuildingsPosition[0][0] && j==listBuildingsPosition[0][1]) ||
        (i==listBuildingsPosition[1][0] && j==listBuildingsPosition[1][1]) || (i==listBuildingsPosition[1][0] && j==listBuildingsPosition[1][1]) || (i==listBuildingsPosition[1][0] && j==listBuildingsPosition[1][1]) ||
        (i==listBuildingsPosition[2][0] && j==listBuildingsPosition[2][1]) || (i==listBuildingsPosition[2][0] && j==listBuildingsPosition[2][1]) || (i==listBuildingsPosition[2][0] && j==listBuildingsPosition[2][1]) ){
        Position p1(i,j-1);
        Position p2(i,j);
        Position p3(i,j+2);
        this->buildingsMap[toChange-1] = move(unique_ptr<Element> (new Ressource(1,p1,2)));
        this->buildingsMap[toChange] = move(unique_ptr<Element> (new Palace(1,p2,2)));
        this->buildingsMap[toChange+1] = move(unique_ptr<Element> (new Barrack(1,p3,2)));
      }
      toChange++;
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

std::vector<unique_ptr<state::Element>> const& Map::getBasicMap(){
  return this->basicMap;
}

std::vector<unique_ptr<state::Element>> const& Map::getDecorMap(){
  return this->decorMap;
}

std::vector<unique_ptr<state::Element>> const& Map::getUnitsMap(){
  return this->unitsMap;
}

std::vector<unique_ptr<state::Element>> const& Map::getBuildingsMap(){
  return this->buildingsMap;
}

std::vector<int> Map::getBasicMapId () {
  // std::vector<std::unique_ptr<Element>> const &basic = this->basicMap;
  std::vector<int> toReturn;
  for(size_t i=0; i<this->basicMap.size(); i++){
    Decor* d = (Decor *) this->basicMap[i].get();
    toReturn.push_back(d->getIdDecor());
  }
  return toReturn;
}

std::vector<int> Map::getDecorMapId () {
  // std::vector<std::unique_ptr<Element>> const &basic = this->decorMap.getDecorMap();
  std::vector<int> toReturn;
  for(size_t i=0; i<this->decorMap.size(); i++){
    Decor* d = (Decor *) this->decorMap[i].get();
    toReturn.push_back(d->getIdDecor());
  }
  return toReturn;
}

std::vector<int> Map::getUnitsMapId () {
  // std::vector<std::unique_ptr<Element>> const &basic = this->unitsMap.getDecorMap();
  std::vector<int> toReturn;
  for(size_t i=0; i<this->unitsMap.size(); i++){
    Units* d = (Units *) this->unitsMap[i].get();
    toReturn.push_back(d->getIdTextureUnits());
  }
  return toReturn;
}

std::vector<int> Map::getBuildingsMapId () {
  // std::vector<std::unique_ptr<Element>> const &basic = this->buildingsMap.getDecorMap();
  std::vector<int> toReturn;
  for(size_t i=0; i<this->buildingsMap.size(); i++){
    Buildings* d = (Buildings *) this->buildingsMap[i].get();
    toReturn.push_back(d->getIdTexture());
  }
  return toReturn;
}

int Map::getSize () const{
  return this->size;
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
