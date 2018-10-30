#include "Map.h"
#include <iostream>
#include "../state.h"
#include <time.h>
using namespace state;
using namespace std;

bool compare(int map[25][25],int positionX,int positionY,int rangeX,int rangeY, int elementTexture){
  bool boolean= true;
  for (int i=0;i<2*rangeX+1;i++){
    for (int j=0;j<2*rangeY+1;j++){
      if(map[positionX+i-rangeX][positionY+j-rangeY] == elementTexture){
        boolean =false;
      }
    }
  }
  return boolean;
}

Map::Map(){
// Create sea
  srand(time(NULL));

// decor wide in one direction
  int sizeSea = 1;
  int sizeMountain = 1;
  int sizeWood = 1;
  int sizeBuilding = 1;

 //vector< vector<int> > map(this->size,vector<int> (this->size,2)); //replace by size
 int map[25][25];
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      map[i][j]=2;
    }
  }
  // for (int i=0;i<size;i++){
  //   for (int j=0;j<size;j++){
  //     cout<< map[i][j] << " ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  // cout<<endl;

  for(int i = 0; i<3; i++){
    int buildingRandx = rand() % (size-6)+3; // avoid borders
    int buildingRandy = rand() % (size-6)+3;
    while( !(compare(map,buildingRandx,buildingRandy,sizeBuilding*3,sizeBuilding*3,26)))
     {
        buildingRandx = rand() % (size-6)+3;
        buildingRandy = rand() % (size-6)+3;
    }
        map[buildingRandx][buildingRandy-1] = 31;
        map[buildingRandx][buildingRandy] = 26;
        map[buildingRandx][buildingRandy+1] = 30;
    }

// feeding of sea decor random array positions
  for(int i = 0; i < 3; i++){
      int seaRandx = rand() % size;
      int seaRandy = rand() % size;
      while(!(compare(map,seaRandx,seaRandy,sizeSea,sizeSea,26) && compare(map,seaRandx,seaRandy,sizeSea,sizeSea,30)
      && compare(map,seaRandx,seaRandy,sizeSea,sizeSea,31) )){
        seaRandx = rand() % size;
        seaRandy = rand() % size;
      }
      for (int i=0;i<2*sizeSea+1;i++){
        for (int j=0;j<2*sizeSea+1;j++){
          map[seaRandx+i-sizeSea][seaRandy+j-sizeSea] = 1;
        }
      }
      map[seaRandx][seaRandy] = 6;
  }

// feeding of wood decor random array positions
  for(int i = 0; i<3; i++){
    int woodRandx = rand() % size;
    int woodRandy = rand() % size;
    while(!(compare(map,woodRandx,woodRandy,sizeWood,sizeWood,1) && compare(map,woodRandx,woodRandy,sizeWood,sizeWood,26)
         && compare(map,woodRandx,woodRandy,sizeWood,sizeWood,30)&& compare(map,woodRandx,woodRandy,sizeWood,sizeWood,31))){
      woodRandx = rand() % size;
      woodRandy = rand() % size;
    }
    for (int i=0;i<2*sizeWood+1;i++){
      for (int j=0;j<2*sizeWood+1;j++){
        map[woodRandx+i-sizeWood][woodRandy+j-sizeWood] = 8;
    }
  }
}


// feeding of mountain decor random array positions
  for(int i = 0; i<3; i++){
    int mountainRandx = rand() % size;
    int mountainRandy = rand() % size;
    while( !(compare(map,mountainRandx,mountainRandy,sizeMountain,sizeMountain,1) && compare(map,mountainRandx,mountainRandy,sizeMountain,sizeMountain,8)
           && compare(map,mountainRandx,mountainRandy,sizeMountain,sizeMountain,26)&& compare(map,mountainRandx,mountainRandy,sizeMountain,sizeMountain,30)
           && compare(map,mountainRandx,mountainRandy,sizeMountain,sizeMountain,31))) {
      mountainRandx = rand() % size;
      mountainRandy = rand() % size;
    }
    for (int i=0;i<2*sizeMountain+1;i++){
      for (int j=0;j<2*sizeMountain+1;j++){
        map[mountainRandx+i-sizeMountain][mountainRandy+j-sizeMountain] = 3;
    }
  }
}

// feeding of building decor random array positions in few steps. A building cannot be on an other one


for (int i=0;i<15;i++){
  int elementRandx = rand () % size;
  int elementRandy = rand () % size;
  int decorArray[] = {1,3,4,5,7,8};
  int decor = rand () % 6;
  while (map[elementRandx][elementRandy]!=2){
    elementRandx = rand () % size;
    elementRandy = rand () % size;
  }
  map[elementRandx][elementRandy]= decorArray[decor];
}

  // for (int i=0;i<size;i++){
  //   for (int j=0;j<size;j++){
  //     cout<< map[i][j] << " ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  // cout<<endl;

  vector <vector <int> > matrix(25,vector<int> (25,0));
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      matrix[i][j]=map[i][j];
    }
  }

  this->mapMatrix = matrix;
cout << "coucou1"<<endl;
//Map Init
  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      Position p(i,j);
      this->basicMap.push_back(unique_ptr<Element> (new Decor(GRASS,p)));
      this->decorMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      this->buildingsMap.push_back(unique_ptr<Element> (new Buildings()));
      this->unitsMap.push_back(unique_ptr<Element> (new Units()));
    }
  }
 cout << "coucou2"<<endl;
// Add decor to maps
  int basicChange=0;
  int decorChange=0;
  int buildingChange=0;

 int idPalace=1;
 int idBarrack=1;
 int idRessource=1;

  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      Position p(i,j);
      switch(map[i][j]){
        case 1:
        this->basicMap[basicChange] = move(unique_ptr<Element> (new Decor(SEA,p)));
        break;

        case 3:
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(MOUNTAIN,p)));
        break;

        case 4:
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(HORSE,p)));
        break;

        case 5:
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(CHICKEN,p)));
        break;

        case 6:
        this->basicMap[basicChange] = move(unique_ptr<Element> (new Decor(SEA,p)));
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(FISH,p)));
        break;

        case 7:
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(RENNE,p)));
        break;

        case 8:
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(TREE,p)));
        break;

        case 26:
        this->buildingsMap[buildingChange] = move(unique_ptr<Element> (new Palace(idPalace,p,2)));
        idPalace++;
        break;

        case 30:
        this->buildingsMap[buildingChange] = move(unique_ptr<Element> (new Barrack(idBarrack,p,2)));
        idBarrack++;
        break;

        case 31:
        this->buildingsMap[buildingChange] = move(unique_ptr<Element> (new Ressource(idRessource,p,2)));
        idRessource++;
        break;
        default:
        break;
      }
      basicChange++;
      decorChange++;
      buildingChange++;
    }
  }
   cout << "coucou3"<<endl;
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
//   size_t i=0;
//   while (i<toReturn.size()){
//     int count =0;
//     while (count<25){
//       cout<< toReturn[i] << " ";
//       count++;
//       i++;
//     }
//     cout<<endl;
//   }
//   cout<<endl;
//   cout<<endl;
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

vector<vector<int> > Map::getMapMatrix () const{
  return this->mapMatrix;
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
