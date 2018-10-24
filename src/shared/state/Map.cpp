#include "Map.h"
#include <iostream>
#include "../state.h"
using namespace state;
using namespace std;

// int woodRand = rand() % sizeMap;
// int mountainRand = rand() % sizeMap;
// while( ((woodRand>(seaRand-sizeSea-1)) && (woodRand<(seaRand+sizeSea+1))) || ((woodRand>(mountainRand-sizeMountain-1)) && (woodRand<(mountainRand+sizeMountain+1)))) woodRand = rand() % sizeMap;
// listWoodPosition[i][j] = woodRand;
// while( ((mountainRand>(seaRand-sizeSea-1)) && (mountainRand<(seaRand+sizeSea+1))) || ((mountainRand>(woodRand-sizeWood-1)) && (mountainRand<(woodRand+sizeWood+1))) ) mountainRand = rand() % sizeMap;
// listMountainPosition[i][j] = mountainRand;

Map::Map(){

// Create sea

  int sizeMap = 40;
  int sizeSea = 2;
  int sizeMountain = 2;
  int sizeWood = 2;

  int listSeaPosition[3][2];
  int listWoodPosition[3][2];
  int listMountainPosition[3][2];
  int listBuildingsPosition[3][2];

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      int seaRand = rand() % sizeMap;
      listSeaPosition[i][j] = seaRand;
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      bool test = true;
      int woodRand = rand() % sizeMap;
      while(test){
        for(int k = 0; k < 3; k++){
          if( ((woodRand>(*listSeaPosition[k]-sizeSea-1)) && (woodRand<(*listSeaPosition[k]+sizeSea+1))) ){
            woodRand = rand() % sizeMap;
            break;
          } else if (k==2){
            test = false;
          }
        }
      }
      listWoodPosition[i][j] = woodRand;
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      bool test = true;
      int mountainRand = rand() % sizeMap;
      while(test){
        for(int k = 0; k < 3; k++){
          if( ((mountainRand>(*listSeaPosition[k]-sizeSea-1)) && (mountainRand<(*listSeaPosition[k]+sizeSea+1))) || ((mountainRand>(*listWoodPosition[k]-sizeWood-1)) && (mountainRand<(*listWoodPosition[k]+sizeWood+1))) ){
            mountainRand = rand() % sizeMap;
            break;
          } else if (k==2){
            test = false;
          }
        }
      }
      listMountainPosition[i][j] = mountainRand;
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      bool test = true;
      int buildingRand = rand() % sizeMap;
      while(test){
        for(int k = 0; k < 3; k++){
          if( ((buildingRand>(*listSeaPosition[k]-sizeSea-1)) && (buildingRand<(*listSeaPosition[k]+sizeSea+1))) ||
          ((buildingRand>(*listWoodPosition[k]-sizeWood-1)) && (buildingRand<(*listWoodPosition[k]+sizeWood+1))) ||
          ((buildingRand>(*listMountainPosition[k]-sizeMountain-1)) && (buildingRand<(*listMountainPosition[k]+sizeMountain+1))) ){
            buildingRand = rand() % sizeMap;
            break;
          } else if (k==2){
            test = false;
          }
        }
      }
      listBuildingsPosition[i][j] = buildingRand;
    }
  }

  for(int i = 0; i < 3; i++){
    cout << "x  : " << listSeaPosition[i][0] << " y  : " << listSeaPosition[i][1] << endl;
    cout << "x  : " << listWoodPosition[i][0] << " y  : " << listWoodPosition[i][1] << endl;
    cout << "x  : " << listMountainPosition[i][0] << " y  : " << listMountainPosition[i][1] << endl;
  }

//Map Init
  for(int i = 0; i<sizeMap; i++){
    for(int j = 0; j<sizeMap; j++){
      Position p(i,j);
      this->basicMap.push_back(unique_ptr<Element> (new Decor(HERBE,p)));
      this->decorMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      this->buildingsMap.push_back(unique_ptr<Element> (new Buildings()));
      this->unitsMap.push_back(unique_ptr<Element> (new Units()));
    }
  }

// Add decor to maps
  int toChange=0;

  for(int i = 0; i<sizeMap; i++){
    for(int j = 0; j<sizeMap; j++){
      if( ((i>(listSeaPosition[0][0]-sizeSea) && i<(listSeaPosition[0][0]+sizeSea))&&(j>(listSeaPosition[0][1]-sizeSea) && j<(listSeaPosition[0][1]+sizeSea))) ||
      ((i>(listSeaPosition[1][0]-sizeSea) && i<(listSeaPosition[1][0]+sizeSea))&&(j>(listSeaPosition[1][1]-sizeSea) && j<(listSeaPosition[1][1]+sizeSea))) ||
      ((i>(listSeaPosition[2][0]-sizeSea) && i<(listSeaPosition[2][0]+sizeSea))&&(j>(listSeaPosition[2][1]-sizeSea) && j<(listSeaPosition[2][1]+sizeSea))) ){
        Position p(i,j);
        // this->basicMap[toChange] = move(unique_ptr<Element> (new Decor(EAU,p)));
        this->decorMap[toChange] = move(unique_ptr<Element> (new Decor(EAU,p)));
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
        Position p(i,j);
        this->buildingsMap[toChange-1] = move(unique_ptr<Element> (new Ressource(1,p,2)));
        this->buildingsMap[toChange] = move(unique_ptr<Element> (new Palace(1,p,2)));
        this->buildingsMap[toChange+1] = move(unique_ptr<Element> (new Barrack(1,p,2)));
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
