#include "Map.h"
#include "../state.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
// #include "../../extern/jsoncpp-1.8.0/json/json.h"
#include <json/json.h>

using namespace state;
using namespace std;

bool compare(int map[25][25],int positionX,int positionY,int rangeX,int rangeY, int elementTexture){
  bool boolean= true;
  for (int i=0;i<2*rangeX+1;i++){
    for (int j=0;j<2*rangeY+1;j++){
      if((positionX+i-rangeX)>=0 && (positionX+i-rangeX)<=24 && (positionY+j-rangeY)>=0 && (positionY+j-rangeY)<=24){
        if(map[positionX+i-rangeX][positionY+j-rangeY] == elementTexture){
          boolean =false;
        }
      }
      else {
         return false;
      }
    }
  }
  return boolean;
}

std::ofstream outputFileJSONToWrite;
std::ifstream inputFileJSONToRead;

void Map::beginRecord(){
  this->record = true;
}

void Map::beginReplay(){
  this->replay = true;
}

Map::Map(){}

void Map::constructMap(){
  srand(5);//);

  if(this->replay){
    inputFileJSONToRead.open("replay.json");
    if(inputFileJSONToRead.is_open()){
      Json::Value root;
      Json::Reader reader;
      reader.parse(inputFileJSONToRead, root);
      Json::Value map = root["map"];
      int x=0;
      int y=0;
      int mapTmp[25][25];
      for(int i = 0; i<(int)map.size(); i++){
        if(i%25==0&& i!=0) x++;
        if(y%25==0&& y!=0) y = 0;
        mapTmp[x][y]=map[i].asInt();
        y++;
      }
      vector <vector <int> > matrixcp(this->size,vector<int> (this->size,0));
      for (int i=0;i<this->size;i++){
        for (int j=0;j<this->size;j++){
          matrixcp[i][j]=mapTmp[i][j];
        }
      }
      this->mapMatrix = matrixcp;
      inputFileJSONToRead.close();
    }
  } else {
    // Create sea
    this->size=25;
    // decor wide in one direction
    int rangeX=1;
    int rangeY=1;
    int map[25][25];
    // map is a full array of grass at the beginning
    for (int i=0;i<this->size;i++){
      for (int j=0;j<this->size;j++){
        map[i][j]=2;
      }
    }

    int sizeBuilding = 1;
    int buildingRandx = 0; // avoid borders
    int buildingRandy = 0;
    for(int i = 0; i<3; i++){
      buildingRandx = rand() % (this->size-6)+3; // avoid borders
      buildingRandy = rand() % (this->size-6)+3;
      while( !(compare(map,buildingRandx,buildingRandy,sizeBuilding*5,sizeBuilding*5,26)))
      {
        buildingRandx = rand() % (this->size-6)+3;
        buildingRandy = rand() % (this->size-6)+3;
      }
      map[buildingRandx][buildingRandy-1] = 31;
      map[buildingRandx][buildingRandy] = 26;
      map[buildingRandx][buildingRandy+1] = 30;
    }

    // feeding of sea decor random array positions
    int seaRandx = 0;
    int seaRandy = 0;
    for(int i = 0; i < 3; i++){
      seaRandx = rand() % this->size;
      seaRandy = rand() % this->size;
      while(!(compare(map,seaRandx,seaRandy,rangeX,rangeY,26) && compare(map,seaRandx,seaRandy,rangeX,rangeY,30)
      && compare(map,seaRandx,seaRandy,rangeX,rangeY,31))){
        seaRandx = rand() % this->size;
        seaRandy = rand() % this->size;
      }
      for (int i=0;i<(2*rangeX+1);i++){
        for (int j=0;j<(2*rangeY+1);j++){
          map[seaRandx+i-rangeX][seaRandy+j-rangeY] = 1;
        }
      }
      map[seaRandx][seaRandy] = 6;
    }

    int woodRandx = 0;
    int woodRandy = 0;
    // feeding of wood decor random array positions
    for(int i = 0; i<3; i++){
      woodRandx = rand() % this->size;
      woodRandy = rand() % this->size;
      while(!(compare(map,woodRandx,woodRandy,rangeX,rangeY,1) && compare(map,woodRandx,woodRandy,rangeX,rangeY,26)
      && compare(map,woodRandx,woodRandy,rangeX,rangeY,30)&& compare(map,woodRandx,woodRandy,rangeX,rangeY,31))){
        woodRandx = rand() % this->size;
        woodRandy = rand() % this->size;
      }
      for (int i=0;i<2*rangeX+1;i++){
        for (int j=0;j<2*rangeY+1;j++){
          map[woodRandx+i-rangeX][woodRandy+j-rangeY] = 8;
        }
      }
    }
    int mountainRandx = 0;
    int mountainRandy = 0;
    // feeding of mountain decor random array positions
    for(int i = 0; i<3; i++){
      mountainRandx = rand() % this->size;
      mountainRandy = rand() % this->size;
      while( !(compare(map,mountainRandx,mountainRandy,rangeX,rangeY,1) && compare(map,mountainRandx,mountainRandy,rangeX,rangeY,8)
      && compare(map,mountainRandx,mountainRandy,rangeX,rangeY,26)&& compare(map,mountainRandx,mountainRandy,rangeX,rangeY,30)
      && compare(map,mountainRandx,mountainRandy,rangeX,rangeY,31))) {
        mountainRandx = rand() % this->size;
        mountainRandy = rand() % this->size;
      }
      for (int i=0;i<2*rangeX+1;i++){
        for (int j=0;j<2*rangeY+1;j++){
          map[mountainRandx+i-rangeX][mountainRandy+j-rangeY] = 3;
        }
      }
    }

    // feeding of building decor random array positions in few steps. A building cannot be on an other one

    int elementRandx = 0;
    int elementRandy = 0;
    int decorArray[] = {1,3,4,5,7,8};
    int decor = 0;
    for (int i=0;i<15;i++){
      elementRandx = rand () % this->size;
      elementRandy = rand () % this->size;
      decor = rand () % 6;
      while (map[elementRandx][elementRandy]!=2){
        elementRandx = rand () % this->size;
        elementRandy = rand () % this->size;
      }
      map[elementRandx][elementRandy]= decorArray[decor];
    }

    vector <vector <int> > matrix(this->size,vector<int> (this->size,0));
    for (int i=0;i<this->size;i++){
      for (int j=0;j<this->size;j++){
        matrix[i][j]=map[i][j];
      }
    }

    this->mapMatrix = matrix;

    if(this->record){
      outputFileJSONToWrite.open("replay.json");
      if(outputFileJSONToWrite.is_open()){
        std::string map = "{\"map\": [";
        for (int i=0;i<this->size;i++){
          for (int j=0;j<this->size;j++){
            if(i==24&&j==24) map += to_string(this->mapMatrix[i][j]);
            else map += to_string(this->mapMatrix[i][j])+", ";
          }
        }
        map+="],\n";
        outputFileJSONToWrite<<map;
        outputFileJSONToWrite.close();
      }
    }
  }

  //Map Init
  for(int i = 0; i<this->size; i++){
    for(int j = 0; j<this->size; j++){
      Position p(i,j);
      this->basicMap.push_back(unique_ptr<Element> (new Decor(GRASS,p)));
      this->decorMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
      this->buildingsMap.push_back(unique_ptr<Element> (new Buildings()));
      this->unitsMap.push_back(unique_ptr<Element> (new Units()));
      this->selectedMap.push_back(unique_ptr<Element> (new Decor(NONE_DECOR,p)));
    }
  }

  std::vector<int> statsMap(36,0);
  this->statsMap=statsMap;
 // Add decor to maps
  int basicChange=0;
  int decorChange=0;
  int buildingChange=0;

  int idPalace=1;
  int idBarrack=1;
  int idRessource=1;
  std::string name;

  for(int i = 0; i<this->size; i++){
    for(int j = 0; j<this->size; j++){
      Position p(i,j);
      switch(this->mapMatrix[i][j]){
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
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(REINDEER,p)));
        break;

        case 8:
        this->decorMap[decorChange] = move(unique_ptr<Element> (new Decor(TREE,p)));
        break;

        case 26: {
          this->buildingsMap[buildingChange] = move(unique_ptr<Element> (new Palace(idPalace,p,1)));
          name = "Player"+idPalace;
          Empires.push_back(unique_ptr<Empire> (new Empire(idPalace, name, 200, 200, 200, 3)));
          idPalace++;
          break;
        }

        case 30:
        this->buildingsMap[buildingChange] = move(unique_ptr<Element> (new Barrack(idBarrack,p,1)));
        idBarrack++;
        break;

        case 31:
        this->buildingsMap[buildingChange] = move(unique_ptr<Element> (new Ressource(idRessource,p,1)));
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
  std::vector<int> statsMapId(121,0);
  for (int i=5;i<11;i++){
    statsMapId[i]=i+22;
  }
  this->statsMap=statsMapId;
}

Map::~Map(){
}

void Map::addElement (std::vector<std::unique_ptr<Element>> vect, std::unique_ptr<Element> elt){
   vect.push_back(move(elt));
}

std::vector<unique_ptr<state::Element>>& Map::getBasicMap(){
  return this->basicMap;
}

std::vector<unique_ptr<state::Element>>& Map::getDecorMap(){
  return this->decorMap;
}

std::vector<unique_ptr<state::Element>>& Map::getUnitsMap(){
  return this->unitsMap;
}

std::vector<unique_ptr<state::Element>>& Map::getBuildingsMap(){
  return this->buildingsMap;
}

std::vector<int> Map::getBasicMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->basicMap.size(); i++){
    toReturn.push_back(((Decor *) this->basicMap[i].get())->getIdDecor());
  }
   return toReturn;
}

std::vector<int> Map::getDecorMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->decorMap.size(); i++){
    toReturn.push_back(((Decor *) this->decorMap[i].get())->getIdDecor());
  }
  return toReturn;
}

std::vector<int> Map::getUnitsMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->unitsMap.size(); i++){
    toReturn.push_back(((Units *) this->unitsMap[i].get())->getIdTextureUnits());
  }
  return toReturn;
}

std::vector<int> Map::getBuildingsMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->buildingsMap.size(); i++){
    toReturn.push_back(((Buildings *) this->buildingsMap[i].get())->getIdTexture());
  }
  return toReturn;
}

int Map::getSize () const{
  return this->size;
}

vector<vector<int> >& Map::getMapMatrix (){
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

void Map::addUnitsToMap (std::unique_ptr<Element>& unitsToMap, int& position){
  this->unitsMap[position] = move(unitsToMap);
}

void Map::deleteUnitsOnMap (unique_ptr<Element> unit){
  int pos = this->getPositionElement(move(unit));
  this->unitsMap[pos] = nullptr;
}

std::vector<int> Map::getStatsMap(){
  return this->statsMap;
}
std::vector<unique_ptr<state::Element>>& Map::getSelectedMap(){
  return this->selectedMap;
}

std::vector<int> Map::getSelectedMapId () {
  std::vector<int> toReturn;
  for(size_t i=0; i<this->selectedMap.size(); i++){
    toReturn.push_back(((Decor *) this->selectedMap[i].get())->getIdDecor());
  }
  return toReturn;
}

void Map::setStatsMap(std::vector<int>& statsMap){
  this->statsMap=statsMap;
}

void Map::setSelectedMap(std::vector<unique_ptr<state::Element>>& selectedMap){
  this->selectedMap=move(selectedMap);
}

std::vector<unique_ptr<state::Empire>>& Map::getEmpires(){
  return this->Empires;
}

void Map::setUnitsMap(std::vector<unique_ptr<state::Element>>& unitsMap){
  this->unitsMap=move(unitsMap);
}
