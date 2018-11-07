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
    Units* units = (Units*) map.getAllMaps().getUnitsMap()[x+25*y].get();
    if (units->getLife()<=50*units->getLevel() && units->getLife()>3/4*50*units->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=1;
    }
    else if (units->getLife()<=3/4*50*units->getLevel() && units->getLife()>1/2*50*units->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=1;
      statsMap[3]=0;
    }
    else if (units->getLife()<=1/2*50*units->getLevel() && units->getLife()>1/4*50*units->getLevel()){
      statsMap[0]=1;
      statsMap[1]=1;
      statsMap[2]=0;
      statsMap[3]=0;
    }
    else if (units->getLife()<=1/4*50*units->getLevel() && units->getLife()>0){
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
    //cout<<units->getLife()<<endl;
    //cout<<units->getLevel()<<endl;
    // cout<<units->getDamage()<<endl;
  }
  else if (element==26 || element==27 || element==28 || element==30){
    Palace* palace = (Palace*) map.getAllMaps().getBuildingsMap()[x+25*y].get();
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
    //cout<<palace->getLife()<<endl;
    //cout<<palace->getLevel()<<endl;
  }
  else if (element==30){
    Barrack* barrack = (Barrack*) map.getAllMaps().getBuildingsMap()[x+25*y].get();
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

    //cout<<barrack->getLife()<<endl;
    //cout<<barrack->getLevel()<<endl;
    //cout<<barrack->getCapacity()<<endl;
    //cout<<barrack->getUnitsNumber()<<endl;

  }
  else if (element==31){
    Ressource* ressource = (Ressource*) map.getAllMaps().getBuildingsMap()[x+25*y].get();
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


    //cout<<ressource->getLife()<<endl;
    //cout<<ressource->getLevel()<<endl;
    //cout<<ressource->getProduction()<<endl;
  }

  else {
    map.getAllMaps().setStatsMap(statsMap);
  }
}
