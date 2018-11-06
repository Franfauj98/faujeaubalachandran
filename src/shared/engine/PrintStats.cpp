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
  if (element==10 || element==14 || element==18 || element==22){
    Units* units = (Units*) map.getAllMaps().getUnitsMap()[x+25*y].get();
    cout<<units->getLife()<<endl;
    cout<<units->getLevel()<<endl;
    cout<<units->getDamage()<<endl;
  }
  else if (element==26 || element==27 || element==28 || element==30){
    Palace* palace = (Palace*) map.getAllMaps().getBuildingsMap()[x+25*y].get();
    cout<<palace->getLife()<<endl;
    cout<<palace->getLevel()<<endl;
  }
  else if (element==30){
    Barrack* barrack = (Barrack*) map.getAllMaps().getBuildingsMap()[x+25*y].get();
    cout<<barrack->getLife()<<endl;
    cout<<barrack->getLevel()<<endl;
    cout<<barrack->getCapacity()<<endl;
    cout<<barrack->getUnitsNumber()<<endl;

  }
  else if (element==31){
    Ressource* ressource = (Ressource*) map.getAllMaps().getBuildingsMap()[x+25*y].get();
    cout<<ressource->getLife()<<endl;
    cout<<ressource->getLevel()<<endl;
    cout<<ressource->getProduction()<<endl;
  }
}
