#include "Palace.h"
#include<iostream>
using namespace state;


Palace::Palace():Buildings() {

}

Palace::Palace(int id, Position position, int level, BuildingCost palaceCost,IdTexture idTexture,int life):Buildings(id,position,level,idTexture,palaceCost,life) {

}

Palace::Palace (int id, Position position, int level) : Buildings() {
  switch(level){
    case 1 :{
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(HDV1);
      BuildingCost palaceCost(50,50);
      setBuildingCost(palaceCost);
      setLife(200);

      break;}
    case 2 :{
      setIdBuilding(id);
      setPosition(position);
      setLevel(2);
      setIdTexture(HDV2);
      BuildingCost palaceCost(100,100);
      setBuildingCost(palaceCost);
      setLife(400);
      break;}
    case 3 :{
      setIdBuilding(id);
      setPosition(position);
      setLevel(3);
      setIdTexture(HDV3);
      BuildingCost palaceCost(150,150);
      setBuildingCost(palaceCost);
      setLife(600);
      break;}
    case 4 :{
      setIdBuilding(id);
      setPosition(position);
      setLevel(4);
      setIdTexture(HDV4);
      BuildingCost palaceCost(200,200);
      setBuildingCost(palaceCost);
      setLife(800);
      break;}
    default :{
      setIdBuilding(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(HDV1);
      BuildingCost palaceCost(50,50);
      setBuildingCost(palaceCost);
      setLife(200);
      break;}
  }
}

Palace::~Palace(){

}
