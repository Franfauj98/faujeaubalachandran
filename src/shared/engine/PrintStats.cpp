#include "PrintStats.h"
#include "state.h"
#include <iostream>
using namespace state;
using namespace engine;
using namespace std;

PrintStats::~PrintStats(){

}
PrintStats::PrintStats(int x, int y, int element){
  this->x = x;
  this->y = y;
  this->element = element;
}

int PrintStats::getX() const{
  return this->x;
}
int PrintStats::getY() const{
  return this->y;
}
int PrintStats::getElement() const{
  return this->element;
}

CommandTypeId PrintStats::getTypeId () const{
  return CommandTypeId::PRINTSTATS;
}
void PrintStats::execute (state::Observable& map){
  std::vector<int> statsMap(121,0);
  for (int i=5;i<11;i++){
    statsMap[i]=i+22;
  }
  if (this->element==10 || this->element==14 || this->element==18 || this->element==22){
    Units* units = (Units*) map.getAllMaps().getUnitsMap()[y+25*x].get();
    if (units->getLife()>=40){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=1;
    }
    else if (units->getLife()>=30&&units->getLife()<40){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=0;
    }
    else if (units->getLife()>=20&&units->getLife()<30){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=0;
      statsMap[3]=0;
    }
    else if (units->getLife()>=10&&units->getLife()<20){
      statsMap[0]=1;
      statsMap[1]=0;
      statsMap[2]=0;
      statsMap[3]=0;
    }

    switch(units->getLevel()){
      case 1:
      statsMap[11]=3;
      break;

      case 2:
      statsMap[11]=4;
      break;

      case 3:
      statsMap[11]=5;
      break;

      case 4:
      statsMap[11]=6;
      break;

      default:
      break;
    }
  }
  else if (this->element==26 || this->element==27 || this->element==28 || this->element==29){
    Palace* palace = (Palace*) map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
    if (palace->getLife()<=200 && palace->getLife()>150){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=1;
    }
    else if (palace->getLife()<=150 && palace->getLife()>100){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=0;
    }
    else if (palace->getLife()<=100 && palace->getLife()>50){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=0;
      statsMap[3]=0;
    }
    else if (palace->getLife()<=50 && palace->getLife()>=0){
      statsMap[0]=1;
      statsMap[1]=0;
      statsMap[2]=0;
      statsMap[3]=0;
    }

    switch(palace->getLevel()){
      case 1:
      statsMap[11]=3;
      break;

      case 2:
      statsMap[11]=4;
      break;

      case 3:
      statsMap[11]=5;
      break;

      case 4:
      statsMap[11]=6;
      break;

      default:
      break;
    }

    if (this->element==26 || this->element==27 || this->element==28){
      statsMap[22]=24;
      statsMap[23]=25;
      statsMap[24]=26;
    }


  }
  else if (this->element==30){
    Barrack* barrack = (Barrack*) map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
    switch(barrack->getLevel()){
      case 1:
      statsMap[0]=3;
      break;

      case 2:
      statsMap[0]=4;
      break;

      case 3:
      statsMap[0]=5;
      break;

      case 4:
      statsMap[0]=6;
      break;

      default:
      break;

    }

    switch(barrack->getUnitsNumber()){

      case 0:
      statsMap[11]=2;
      break;

      case 1:
      statsMap[11]=3;
      break;

      case 2:
      statsMap[11]=4;
      break;

      case 3:
      statsMap[11]=5;
      break;

      case 4:
      statsMap[11]=6;
      break;

      case 5:
      statsMap[11]=7;
      break;

      case 6:
      statsMap[11]=8;
      break;

      default:
      break;
    }

    switch(barrack->getCapacity()){
      case 1:
      statsMap[14]=3;
      break;

      case 2:
      statsMap[14]=4;
      break;

      case 4:
      statsMap[14]=6;
      break;

      case 5:
      statsMap[14]=7;
      break;

      case 6:
      statsMap[14]=8;
      break;

      default:
      break;
    }
    if (barrack->getLevel()<4){
      for (int i=22;i<28;i++){
        statsMap[i]=i-10;
      }
      for (int i=33;i<39;i++){
        statsMap[i]=i-15;
      }
      for (int i=44;i<47;i++){
        statsMap[i]=i-20;
      }
    } else {
      for (int i=22;i<34;i++){
        statsMap[i]=i-10;
      }
      for (int i=33;i<36;i++){
        statsMap[i]=i-15;
      }
    }
  }

  else if (this->element==31){
    Ressource* ressource = (Ressource*) map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
    switch(ressource->getLevel()){
      case 1:
      statsMap[0]=3;
      break;

      case 2:
      statsMap[0]=4;
      break;

      case 3:
      statsMap[0]=5;
      break;

      case 4:
      statsMap[0]=6;
      break;

      default:
      break;
    }

    switch(ressource->getProduction()){
      case 50:
      statsMap[11]=7;
      statsMap[12]=2;
      break;

      case 100:
      statsMap[11]=3;
      statsMap[12]=2;
      statsMap[13]=2;
      break;

      case 150:
      statsMap[11]=3;
      statsMap[12]=7;
      statsMap[13]=2;
      break;

      case 200:
      statsMap[11]=4;
      statsMap[12]=2;
      statsMap[13]=2;
      break;

      default:
      break;
    }
    if (ressource->getLevel()<4){
      statsMap[22]=24;
      statsMap[23]=25;
      statsMap[24]=26;
    }
  }
    map.getAllMaps().setStatsMap(statsMap);
}
