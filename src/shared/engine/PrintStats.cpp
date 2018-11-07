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
  cout<< "element" << endl;
  cout<< element << endl;

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
    }

    map.getAllMaps().setStatsMap(statsMap);
  }
  else if (element==26 || element==27 || element==28 || element==29){
    Palace* palace = (Palace*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
    if (palace->getLife()<=50*palace->getLevel() && palace->getLife()>3/4*50*palace->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=1;
    }
    else if (palace->getLife()<=3/4*50*palace->getLevel() && palace->getLife()>1/2*50*palace->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=0;
    }
    else if (palace->getLife()<=1/2*50*palace->getLevel() && palace->getLife()>1/4*50*palace->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=0;
      statsMap[3]=0;
    }
    else if (palace->getLife()<=1/4*50*palace->getLevel() && palace->getLife()>0){
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
    }

    if (element==26 || element==27 || element==28){
      statsMap[12]=16;

    }
    map.getAllMaps().setStatsMap(statsMap);
  }
  else if (element==30){
    Barrack* barrack = (Barrack*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
    if (barrack->getLife()<=50*barrack->getLevel() && barrack->getLife()>3/4*50*barrack->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=1;
    }
    else if (barrack->getLife()<=3/4*50*barrack->getLevel() && barrack->getLife()>1/2*50*barrack->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=0;
    }
    else if (barrack->getLife()<=1/2*50*barrack->getLevel() && barrack->getLife()>1/4*50*barrack->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=0;
      statsMap[3]=0;
    }
    else if (barrack->getLife()<=1/4*50*barrack->getLevel() && barrack->getLife()>0){
      statsMap[0]=1;
      statsMap[1]=0;
      statsMap[2]=0;
      statsMap[3]=0;
    }

    switch(barrack->getLevel()){
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
    }
    switch(barrack->getUnitsNumber()){
      case 1:
      statsMap[8]=3;
      break;

      case 2:
      statsMap[8]=4;
      break;

      case 3:
      statsMap[8]=5;
      break;

      case 4:
      statsMap[8]=6;
      break;

      case 5:
      statsMap[8]=7;
      break;

      case 6:
      statsMap[8]=8;
      break;
    }

    switch(barrack->getCapacity()){
      case 1:
      statsMap[10]=3;
      break;

      case 2:
      statsMap[10]=4;
      break;

      case 4:
      statsMap[10]=6;
      break;

      case 6:
      statsMap[10]=8;
      break;
    }
    statsMap[12]=12;
    statsMap[15]=13;
    statsMap[18]=14;
    statsMap[21]=15;
    statsMap[24]=16;

    map.getAllMaps().setStatsMap(statsMap);

  }
  else if (element==31){
    Ressource* ressource = (Ressource*) map.getAllMaps().getBuildingsMap()[y+25*x].get();
    if (ressource->getLife()<=50*ressource->getLevel() && ressource->getLife()>3/4*50*ressource->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=1;
    }
    else if (ressource->getLife()<=3/4*50*ressource->getLevel() && ressource->getLife()>1/2*50*ressource->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=0;
    }
    else if (ressource->getLife()<=1/2*50*ressource->getLevel() && ressource->getLife()>1/4*50*ressource->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=0;
      statsMap[3]=0;
    }
    else if (ressource->getLife()<=1/4*50*ressource->getLevel() && ressource->getLife()>0){
      statsMap[0]=1;
      statsMap[1]=0;
      statsMap[2]=0;
      statsMap[3]=0;
    }

    switch(ressource->getLevel()){
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
    }

    switch(ressource->getProduction()){
      case 2:
      statsMap[12]=4;
      break;

      case 4:
      statsMap[12]=6;
      break;

      case 6:
      statsMap[12]=8;
      break;

      case 8:
      statsMap[12]=10;
      break;
    }
    if (ressource->getLevel()<4){
      statsMap[18]=16;
    }
  }

  else {
    map.getAllMaps().setStatsMap(statsMap);
  }
}
