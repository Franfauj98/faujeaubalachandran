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
void PrintStats::execute (state::Observable& map, int x, int y, int element){
  std::vector<int> statsMap(36,0);

  if (element==10 || element==14 || element==18 || element==22){
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

  //  map.getAllMaps().setStatsMap(statsMap);
  }
  else if (element==26 || element==27 || element==28 || element==29){
    Palace* palace = (Palace*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
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

    if (element==26 || element==27 || element==28){
      statsMap[12]=24;
      statsMap[13]=25;
      statsMap[14]=26;
    }
    //map.getAllMaps().setStatsMap(statsMap);
  }
  else if (element==30){
    Barrack* barrack = (Barrack*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
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

      case 6:
      statsMap[9]=8;
      break;

      default:
      break;
    }
    for (int i=12;i<27;i++){
      statsMap[i]=i;
    }
  //  map.getAllMaps().setStatsMap(statsMap);

  }
  else if (element==31){
    Ressource* ressource = (Ressource*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
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
    map.getAllMaps().setStatsMap(statsMap);

}
