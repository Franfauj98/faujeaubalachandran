#include "Palace.h"
using namespace state;

Palace::Palace():Buildings() {

}

Palace::Palace(int id, Position position, int level, IdTexture idTexture, BuildingCost palaceCost):Buildings(id,position,level,idTexture,palaceCost) {

}

Palace::Palace (int id, Position position, int level) : Buildings() {
  switch(level){
    case 1 :{
      setId(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(HDV1);
      BuildingCost palaceCost(50,50);
      setBuildingCost(palaceCost);

      break;}
    case 2 :{
      setId(id);
      setPosition(position);
      setLevel(2);
      setIdTexture(HDV2);
      BuildingCost palaceCost(100,100);
      setBuildingCost(palaceCost);
      break;}
    case 3 :{
      setId(id);
      setPosition(position);
      setLevel(3);
      setIdTexture(HDV3);
      BuildingCost palaceCost(150,150);
      setBuildingCost(palaceCost);
      break;}
    case 4 :{
      setId(id);
      setPosition(position);
      setLevel(4);
      setIdTexture(HDV4);
      BuildingCost palaceCost(200,200);
      setBuildingCost(palaceCost);
      break;}
    default :{
      setId(id);
      setPosition(position);
      setLevel(1);
      setIdTexture(HDV1);
      BuildingCost palaceCost(50,50);
      setBuildingCost(palaceCost);
      break;}
  }
}

Palace::~Palace(){

}
