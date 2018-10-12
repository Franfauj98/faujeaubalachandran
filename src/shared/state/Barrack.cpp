#include "Barrack.h"
#include "Units.h"
#include "Arrow.h"
#include "Cavalier.h"
#include "Decurion.h"
#include "Catapult.h"
using namespace state;

Barrack::Barrack():Buildings(){

}

Barrack::Barrack(int capacity, int id, Position position, int level, IdTexture idTexture):Buildings(id,position,level,idTexture){
  this->capacity=capacity;

}

int Barrack::getCapacity() const{
  return this->capacity;
}

void Barrack::setCapacity(int capacity){
  this->capacity=capacity;
}

int Barrack::getUnitsNumber() const{
  return this->unitsNumber;
}

void Barrack::setUnitsNumber(int unitsNumber){
  this->unitsNumber=unitsNumber;
}

// Arrow Barrack::createArrow(int level,Position position, int id){
//   if (this->unitsNumber<this->capacity){
//
//     if (level==1) {
//       Arrow arrow1(1,position,id);
//       return arrow1;
//     }
//     else {
//       Arrow arrow();
//       return arrow;
//     }
//   }
//   else {
//     Arrow arrow();
//     return arrow;
//   }
// }

/*void Barrack::createCavalier (int level, Position position, int id){
  if (level==1) {
    Cavalier cavalier1(1,id, position,50,10,2,1,CAVALIER1);
  }
  else if (level==2) {
    Cavalier cavalier2(2,id,position,50,10,2,1,CAVALIER2);
  }
  else if (level==3) {
    Cavalier cavalier3(3,id,position,50,10,2,1,CAVALIER3);
  }
  else if (level==4) {
    Cavalier cavalier4(4,id,position,50,10,2,1,CAVALIER4);
  }
}

void Barrack::createDecurion (int level, Position position, int id){
  if (level==1) {
    Decurion decurion1(1,id, position,50,10,2,1,DECURION1);
  }
  else if (level==2) {
    Decurion decurion2(2,id,position,50,10,2,1,DECURION2);
  }
  else if (level==3) {
    Decurion decurion3(3,id,position,50,10,2,1,DECURION3);
  }
  else if (level==4) {
    Decurion decurion4(4,id,position,50,10,2,1,DECURION4);
  }
}

void Barrack::createCatapult (int level, Position position, int id){
  if (level==1) {
    Catapult catapult1(1,id, position,50,10,2,1,CATAPULT1);
  }
  else if (level==2) {
    Catapult catapult2(2,id,position,50,10,2,1,CATAPULT2);
  }
  else if (level==3) {
    Catapult catapult3(3,id,position,50,10,2,1,CATAPULT3);
  }
  else if (level==4) {
    Catapult catapult4(4,id,position,50,10,2,1,CATAPULT4);
  }
}*/

Barrack::~Barrack(){

}
