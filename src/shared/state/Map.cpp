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

bool comparePosition(int elementRandX1, int elementRandY1, int elementRandX2, int elementRandY2){
  if (((elementRandX1 != elementRandX2 || elementRandX1 != elementRandY2) && distance(elementRandX1, elementRandY1, elementRandX2, elementRandY2) > 6)) {
    return true;
  } else {
    return false;
  }
}

Map::Map(){
// Create sea
  srand(time(NULL));

// decor wide
  int sizeSea = 2;
  int sizeMountain = 2;
  int sizeWood = 2;

// array which contain radom locations for decors
  int listSeaPosition[3][2];
  int listWoodPosition[3][2];
  int listMountainPosition[3][2];
  int listBuildingsPosition[3][2];

// feeding of sea decor random array positions
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      int seaRand = rand() % size;
      listSeaPosition[i][j] = seaRand;
    }
  }

// feeding of wood decor random array positions
  for(int i = 0; i<3; i++){
    int woodRandx = rand() % size;
    int woodRandy = rand() % size;
    while( !( comparePosition(woodRandx, woodRandy, listSeaPosition[0][0], listSeaPosition[0][1]) && comparePosition(woodRandx, woodRandy, listSeaPosition[1][0], listSeaPosition[1][1])
    && comparePosition(woodRandx, woodRandy, listSeaPosition[2][0], listSeaPosition[2][1]))){
      woodRandx = rand() % size;
      woodRandy = rand() % size;
    }
    listWoodPosition[i][0] = woodRandx;
    listWoodPosition[i][1] = woodRandy;
  }

// feeding of mountain decor random array positions
  for(int i = 0; i<3; i++){
    int mountainRandx = rand() % size;
    int mountainRandy = rand() % size;
    while( !( comparePosition(mountainRandx, mountainRandy, listSeaPosition[0][0], listSeaPosition[0][1]) && comparePosition(mountainRandx, mountainRandy, listSeaPosition[1][0], listSeaPosition[1][1]) &&
    comparePosition(mountainRandx, mountainRandy, listSeaPosition[2][0], listSeaPosition[2][1]) && comparePosition(mountainRandx, mountainRandy, listWoodPosition[0][0], listWoodPosition[0][1]) &&
    comparePosition(mountainRandx, mountainRandy, listWoodPosition[1][0], listWoodPosition[1][1]) && comparePosition(mountainRandx, mountainRandy, listWoodPosition[2][0], listWoodPosition[2][1]) )) {
      mountainRandx = rand() % size;
      mountainRandy = rand() % size;
    }
    listMountainPosition[i][0] = mountainRandx;
    listMountainPosition[i][1] = mountainRandy;
  }

// feeding of building decor random array positions in few steps. A building cannot be on an other one
  int buildingRandx = rand() % size;
  int buildingRandy = rand() % size;
  while( !( comparePosition(buildingRandx, buildingRandy, listSeaPosition[0][0], listSeaPosition[0][1]) && comparePosition(buildingRandx, buildingRandy, listSeaPosition[1][0], listSeaPosition[1][1]) &&
  comparePosition(buildingRandx, buildingRandy, listSeaPosition[2][0], listSeaPosition[2][1]) && comparePosition(buildingRandx, buildingRandy, listWoodPosition[0][0], listWoodPosition[0][1]) &&
  comparePosition(buildingRandx, buildingRandy, listWoodPosition[1][0], listWoodPosition[1][1]) && comparePosition(buildingRandx, buildingRandy, listWoodPosition[2][0], listWoodPosition[2][1]) &&
  comparePosition(buildingRandx, buildingRandy, listMountainPosition[0][0], listMountainPosition[0][1]) && comparePosition(buildingRandx, buildingRandy, listMountainPosition[1][0], listMountainPosition[1][1]) &&
  comparePosition(buildingRandx, buildingRandy, listMountainPosition[2][0], listMountainPosition[2][1]) && (buildingRandx%this->size > 3) && (buildingRandy%this->size > 3) &&
  (buildingRandx%this->size < (this->size-3)) && (buildingRandy%this->size < (this->size-3) )) ){
    buildingRandx = rand() % size;
    buildingRandy = rand() % size;
  }
  listBuildingsPosition[0][0] = buildingRandx;
  listBuildingsPosition[0][1] = buildingRandy;

  buildingRandx = rand() % size;
  buildingRandy = rand() % size;
  while( !( comparePosition(buildingRandx, buildingRandy, listSeaPosition[0][0], listSeaPosition[0][1]) && comparePosition(buildingRandx, buildingRandy, listSeaPosition[1][0], listSeaPosition[1][1]) &&
  comparePosition(buildingRandx, buildingRandy, listSeaPosition[2][0], listSeaPosition[2][1]) && comparePosition(buildingRandx, buildingRandy, listWoodPosition[0][0], listWoodPosition[0][1]) &&
  comparePosition(buildingRandx, buildingRandy, listWoodPosition[1][0], listWoodPosition[1][1]) && comparePosition(buildingRandx, buildingRandy, listWoodPosition[2][0], listWoodPosition[2][1]) &&
  comparePosition(buildingRandx, buildingRandy, listMountainPosition[0][0], listMountainPosition[0][1]) && comparePosition(buildingRandx, buildingRandy, listMountainPosition[1][0], listMountainPosition[1][1]) &&
  comparePosition(buildingRandx, buildingRandy, listMountainPosition[2][0], listMountainPosition[2][1]) && comparePosition(buildingRandx, buildingRandy, listBuildingsPosition[0][0], listBuildingsPosition[0][1]) &&
  (buildingRandx%this->size > 3) && (buildingRandy%this->size > 3) && (buildingRandx%this->size < (this->size-3)) && (buildingRandy%this->size < (this->size-3)) ) ){
    buildingRandx = rand() % size;
    buildingRandy = rand() % size;
  }
  listBuildingsPosition[1][0] = buildingRandx;
  listBuildingsPosition[1][1] = buildingRandy;

  buildingRandx = rand() % size;
  buildingRandy = rand() % size;
  while( !( comparePosition(buildingRandx, buildingRandy, listSeaPosition[0][0], listSeaPosition[0][1]) && comparePosition(buildingRandx, buildingRandy, listSeaPosition[1][0], listSeaPosition[1][1]) &&
  comparePosition(buildingRandx, buildingRandy, listSeaPosition[2][0], listSeaPosition[2][1]) && comparePosition(buildingRandx, buildingRandy, listWoodPosition[0][0], listWoodPosition[0][1]) &&
  comparePosition(buildingRandx, buildingRandy, listWoodPosition[1][0], listWoodPosition[1][1]) && comparePosition(buildingRandx, buildingRandy, listWoodPosition[2][0], listWoodPosition[2][1]) &&
  comparePosition(buildingRandx, buildingRandy, listMountainPosition[0][0], listMountainPosition[0][1]) && comparePosition(buildingRandx, buildingRandy, listMountainPosition[1][0], listMountainPosition[1][1]) &&
  comparePosition(buildingRandx, buildingRandy, listMountainPosition[2][0], listMountainPosition[2][1]) && comparePosition(buildingRandx, buildingRandy, listBuildingsPosition[0][0], listBuildingsPosition[0][1]) &&
  comparePosition(buildingRandx, buildingRandy, listBuildingsPosition[1][0], listBuildingsPosition[1][1]) && (buildingRandx%this->size > 3) && (buildingRandy%this->size > 3) &&
  (buildingRandx%this->size < (this->size-3)) && (buildingRandy%this->size < (this->size-3)) ) ){
    buildingRandx = rand() % size;
    buildingRandy = rand() % size;
  }
  listBuildingsPosition[2][0] = buildingRandx;
  listBuildingsPosition[2][1] = buildingRandy;

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
  std::vector<int> toReturn;
  for(size_t i=0; i<this->basicMap.size(); i++){
    Decor* d = (Decor *) this->basicMap[i].get();
    toReturn.push_back(d->getIdDecor());
  }
  return toReturn;
}

std::vector<int> Map::getDecorMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->decorMap.size(); i++){
    Decor* d = (Decor *) this->decorMap[i].get();
    toReturn.push_back(d->getIdDecor());
  }
  return toReturn;
}

std::vector<int> Map::getUnitsMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->unitsMap.size(); i++){
    Units* d = (Units *) this->unitsMap[i].get();
    toReturn.push_back(d->getIdTextureUnits());
  }
  return toReturn;
}

std::vector<int> Map::getBuildingsMapId () {
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
  for(size_t i = 0; i<this->unitsMap.size(); i++){
    if(elt.get()==this->unitsMap[i].get()){
      pos = i;
      break;
    }
  }
  return pos;
}

void Map::addUnitsToMap (std::unique_ptr<Units> unitsToMap, int position){
  this->unitsMap[position] = move(unitsToMap);  
}

void Map::deleteUnitsOnMap (unique_ptr<Element> unit){
  int pos = this->getPositionElement(move(unit));
  this->unitsMap[pos] = nullptr;
}
