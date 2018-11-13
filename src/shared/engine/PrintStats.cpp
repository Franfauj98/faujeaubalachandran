#include "PrintStats.h"
#include "state.h"
#include <iostream>
using namespace state;
using namespace engine;
using namespace std;

PrintStats::~PrintStats (){

}

CommandTypeId PrintStats::getTypeId () const{
  return CommandTypeId::PRINTSTATS;
}
void PrintStats::execute (){
  std::vector<int> statsMap(36,0);
  if (this->element==10 || this->element==14 || this->element==18 || this->element==22){
    Units* units = (Units*) this->map.getAllMaps().getUnitsMap()[this->y+25*this->x].get();
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
      statsMap[6]=3;
      break;

      case 2:
      statsMap[6]=4;
      break;

      case 3:
      statsMap[6]=5;
      break;

      case 4:
      statsMap[6]=6;
      break;

      default:
      break;
    }
  }
  else if (this->element==26 || this->element==27 || this->element==28 || this->element==29){
    Palace* palace = (Palace*) this->map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
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
    else if (palace->getLife()<=50 && palace->getLife()>0){
      statsMap[0]=1;
      statsMap[1]=0;
      statsMap[2]=0;
      statsMap[3]=0;
    }

    switch(palace->getLevel()){
      case 1:
      statsMap[6]=3;
      break;

      case 2:
      statsMap[6]=4;
      break;

      case 3:
      statsMap[6]=5;
      break;

      case 4:
      statsMap[6]=6;
      break;

      default:
      break;
    }

    if (this->element==26 || this->element==27 || this->element==28){
      statsMap[12]=24;
      statsMap[13]=25;
      statsMap[14]=26;
    }
    for (int i=18;i<24;i++){
      statsMap[i]=i+9;
    }

  }
  else if (this->element==30){
    Barrack* barrack = (Barrack*) this->map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
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
      statsMap[6]=2;
      break;

      case 1:
      statsMap[6]=3;
      break;

      case 2:
      statsMap[6]=4;
      break;

      case 3:
      statsMap[6]=5;
      break;

      case 4:
      statsMap[6]=6;
      break;

      case 5:
      statsMap[6]=7;
      break;

      case 6:
      statsMap[6]=8;
      break;

      default:
      break;
    }

    switch(barrack->getCapacity()){
      case 1:
      statsMap[9]=3;
      break;

      case 2:
      statsMap[9]=4;
      break;

      case 4:
      statsMap[9]=6;
      break;

      case 5:
      statsMap[9]=7;
      break;

      case 6:
      statsMap[9]=8;
      break;

      default:
      break;
    }
    if (barrack->getLevel()<4){
      for (int i=12;i<27;i++){
        statsMap[i]=i;
      }
    } else {
      for (int i=12;i<24;i++){
        statsMap[i]=i;
      }
    }
  }

  else if (element==31){
    Ressource* ressource = (Ressource*) this->map.getAllMaps().getBuildingsMap()[this->y+25*this->x].get();
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
      case 2:
      statsMap[6]=4;
      break;

      case 4:
      statsMap[6]=6;
      break;

      case 6:
      statsMap[6]=8;
      break;

      case 8:
      statsMap[6]=10;
      break;

      default:
      break;
    }
    if (ressource->getLevel()<4){
      statsMap[12]=24;
      statsMap[13]=25;
      statsMap[14]=26;
    }
  }
    this->map.getAllMaps().setStatsMap(statsMap);
}
