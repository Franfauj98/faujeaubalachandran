#include "DeepAI.h"
#include "AStar.hpp"
#include "../engine.h"
#include "../state.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace ai;
using namespace engine;
using namespace state;
using namespace std;
using namespace AStar;


//find the distance between 2 positions
int distDeepAi(Position pos1, Position pos2){
  int absdiff, orddiff;
  absdiff = std::abs(pos1.getX() - pos2.getX());
  orddiff = std::abs(pos1.getY() - pos2.getY());
  return(absdiff+orddiff);
}

//Verify if there is at least one unit in the map of id : id
bool verifUnitsDeepAi(Observable& principalMap,int id){
  bool verif=false;
  for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
    Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
    int idUnit=unit->getIdUnits();
    if (idUnit==id){
      verif=true;
      break;
    }
  }
  return verif;
}

//Verify if the ID of the (x,y) element is the same as the current element one
bool verifPossDeepAi(Observable& principalMap, int x,int y, int id, int element){
  bool verif=true;
  if (element==1){
    Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[y+25*x].get();
    int idUnit=unit->getIdUnits();
    if (idUnit==id){
      verif=false;
    } else {
      verif=true;
    }
  }
  else if (element==0){
    Buildings* building =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[y+25*x].get();
    int idBuilding=building->getIdBuilding();
    if (idBuilding==id){
      verif=false;
    } else {
      verif=true;
    }
  }
  return verif;
}

//verify if the (x,y) unit id is the same as the current empire playing id
bool idUnitsDeepAi(Observable& principalMap, int id,int x, int y){
    Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[y+25*x].get();
    int idUnit=unit->getIdUnits();
    if (idUnit!=id){
      return true;
    }
    else {
      return false;
    }
}

//compare 2 positions
bool posCompDeepAi(Position pos1, Position pos2){
  if (pos1.getX()==pos2.getX() && pos1.getY()==pos2.getY()){
    return false;
  }
  else {
    return true;
  }
}


//recover the element position in an inline array
void positionElementDeepAi(int& x, int& y, int position){
  y = position%25;
  x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }
}


DeepAI::DeepAI (){}


bool levelUp(engine::Engine& engine, Observable& principalMap, int& counter, int id){
  std::vector<int> buildings;
  for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
    Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
    int idBuilding=building->getIdBuilding();
    if (idBuilding==id){
      buildings.push_back(i);
    }
  }

  Empire* empire=principalMap.getAllMaps().getEmpires()[0].get();
  for (int i=1;i<3;i++){
    if (principalMap.getAllMaps().getEmpires()[i].get()->getId()==id){
      empire=principalMap.getAllMaps().getEmpires()[i].get();
    }
  }

  int y1 = 0;
  int x1 = -1;
  positionElementDeepAi(x1, y1, buildings[0]);

  int y2 = 0;
  int x2 = -1;
  positionElementDeepAi(x2, y2, buildings[1]);

  int y3 = 0;
  int x3=-1;
  positionElementDeepAi(x3, y3, buildings[2]);

  Ressource* ressource = (Ressource*) principalMap.getAllMaps().getBuildingsMap()[y1+25*x1].get();
  Palace* palace = (Palace*) principalMap.getAllMaps().getBuildingsMap()[y2+25*x2].get();
  Barrack* barrack = (Barrack*) principalMap.getAllMaps().getBuildingsMap()[y3+25*x3].get();

  int element;
  if(palace->getLevel() < 4 && palace->getBuildingCost().getWood()<=empire->getWoodRessource() && palace->getBuildingCost().getGold()<=empire->getGoldRessource()){
    std::cout << "LevelUp palace" << '\n';
    element=principalMap.getAllMaps().getMapMatrix()[x2][y2];
    engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x2,y2))),1);
    engine.addCommand(unique_ptr<Command> (new Possibilities(x2,y2,element)),2);
    engine.addCommand(unique_ptr<Command> (new PrintStats(x2,y2,element)),3);
    engine.addCommand((unique_ptr<Command> (new LevelUp(x2,y2))),5);
    return true;
    //level up of the barrack if possible
  } else if(barrack->getLevel() < palace->getLevel() && barrack->getBuildingCost().getWood()<=empire->getWoodRessource() && barrack->getBuildingCost().getGold()<=empire->getGoldRessource()){
    std::cout << "LevelUp barrack" << '\n';
    int element=principalMap.getAllMaps().getMapMatrix()[x3][y3];
    engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x3,y3))),1);
    engine.addCommand(unique_ptr<Command> (new Possibilities(x3,y3,element)),2);
    engine.addCommand(unique_ptr<Command> (new PrintStats(x3,y3,element)),3);
    engine.addCommand((unique_ptr<Command> (new LevelUp(x3,y3))),5);
    return true;
    //level up of the ressource if possible
  } else if(ressource->getLevel() < palace->getLevel() && ressource->getBuildingCost().getWood()<=empire->getWoodRessource() && ressource->getBuildingCost().getGold()<=empire->getGoldRessource()){
    std::cout << "LevelUp ressource" << '\n';
    int element=principalMap.getAllMaps().getMapMatrix()[x1][y1];
    engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x1,y1))),1);
    engine.addCommand(unique_ptr<Command> (new Possibilities(x1,y1,element)),2);
    engine.addCommand(unique_ptr<Command> (new PrintStats(x1,y1,element)),3);
    engine.addCommand((unique_ptr<Command> (new LevelUp(x1,y1))),5);
    return true;
  }
  return false;
}



bool createUnit(engine::Engine& engine, Observable& principalMap, int& counter, int id){
  std::vector<int> buildings;

  for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
    Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
    int idBuilding=building->getIdBuilding();
    if (idBuilding==id){
      buildings.push_back(i);
    }
  }

  Empire* empire=principalMap.getAllMaps().getEmpires()[0].get();
  for (int i=1;i<3;i++){
    if (principalMap.getAllMaps().getEmpires()[i].get()->getId()==id){
      empire=principalMap.getAllMaps().getEmpires()[i].get();
    }
  }

  int y3 = 0;
  int x3=-1;
  positionElementDeepAi(x3, y3, buildings[2]);

  Barrack* barrack = (Barrack*) principalMap.getAllMaps().getBuildingsMap()[y3+25*x3].get();
  int levelUnit = barrack->getLevel();

  std::vector<int> arrowCost = {50,100,150,200};
  std::vector<int> decurionCost = {50,100,150,200};
  std::vector<int> catapultCost = {50,100,150,200};
  std::vector<int> cavalierCost = {50,100,150,200};

  if (barrack->getUnitsNumber()<barrack->getCapacity() &&
  ((arrowCost[levelUnit-1]<=empire->getFoodRessource() && arrowCost[levelUnit-1]<=empire->getGoldRessource()) ||
    (decurionCost[levelUnit-1]<=empire->getFoodRessource() && decurionCost[levelUnit-1]<=empire->getGoldRessource()) ||
    (cavalierCost[levelUnit-1]<=empire->getFoodRessource() && cavalierCost[levelUnit-1]<=empire->getGoldRessource()) ||
    (catapultCost[levelUnit-1]<=empire->getFoodRessource() && catapultCost[levelUnit-1]<=empire->getGoldRessource())
  )
  ){

    int element=principalMap.getAllMaps().getMapMatrix()[x3][y3];
    engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x3,y3))),1);
    engine.addCommand(unique_ptr<Command> (new Possibilities(x3,y3,element)),2);
    engine.addCommand(unique_ptr<Command> (new PrintStats(x3,y3,element)),3);
    std::vector<int> positions={y3,(x3+1),y3+1,(x3+1),y3+1,x3,y3+1,(x3-1),y3,(x3-1)};

    int pos=0;
    while (principalMap.getAllMaps().getMapMatrix()[positions[pos+1]][positions[pos]]!=2 && pos<10){
      pos +=2;
    }
    int y= positions[pos];
    int x=positions[pos+1];
    //random choice of the unit to create
    int unitChoice=rand() % 4+1;
    switch(unitChoice){
      case 1:
      if (arrowCost[levelUnit-1]<=empire->getFoodRessource() && arrowCost[levelUnit-1]<=empire->getGoldRessource()){
        std::cout << "CreateArrow" << '\n';
        engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,1))),4);
        return true;
      }
      break;
      case 2:
      if(decurionCost[levelUnit-1]<=empire->getFoodRessource() && decurionCost[levelUnit-1]<=empire->getGoldRessource()){
        std::cout << "CreateDecurion" << '\n';
        engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,2))),4);
        return true;
      }
      break;
      case 3:
      if(cavalierCost[levelUnit-1]<=empire->getFoodRessource() && cavalierCost[levelUnit-1]<=empire->getGoldRessource()){
        std::cout << "CreateCavalier" << '\n';
        engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,4))),4);
        return true;
      }
      break;
      case 4:
      if(catapultCost[levelUnit-1]<=empire->getFoodRessource() && catapultCost[levelUnit-1]<=empire->getGoldRessource()){
        std::cout << "CreateCatapult" << '\n';
        engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,3))),4);
        return true;
      }
      break;
      default : break;
    }
  }
  return false;

}

std::vector<int> attackAvailable(Observable& principalMap, int id){
  std::vector<int> toAttackNow;
  if (verifUnitsDeepAi(principalMap,id)){

    Position posToAttack;
    int distance = 10000000;
    for(size_t i = 0; i < principalMap.getAllMaps().getBuildingsMap().size(); i++){
      Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
      if(building->getIdBuilding() == id && (building->getType()== 26 || building->getType()== 27 || building->getType()== 28 || building->getType()== 29)){
        for(size_t j = 0; j < principalMap.getAllMaps().getBuildingsMap().size(); j++){
          Buildings* building2 = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[j].get();
          if(building2->getIdBuilding() != id && building2->getIdBuilding() != 0 && (building2->getType()== 26 || building2->getType()== 27 || building2->getType()== 28 || building2->getType()== 29)){
            if(building->distance(building->getPosition(), building2->getPosition()) < distance){
              distance = (building->distance(building->getPosition(), building2->getPosition()));
              posToAttack = building2->getPosition();
            }
          }
        }
        break;
      }
    }

    std::vector<int> units; //units index in unitMapMatrix
    std::vector<Position> unitsPosition; //units poition

    for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
      Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
      int idUnit=unit->getIdUnits();
      if (idUnit==id){
        units.push_back(i);
        unitsPosition.push_back(unit->getPosition());
      }
    }
    //units de l'empire

    //distance Unit -> EmpireToAttack
    int minimumDist=100000;
    int indexMinimumDist=-1;
    std::vector<int> distanceFromEmpireToAttack;
    for (size_t i=0;i<unitsPosition.size();i++){
      distanceFromEmpireToAttack.push_back(distDeepAi(unitsPosition[i], posToAttack));
      if(distanceFromEmpireToAttack[i]<minimumDist){
        minimumDist = distanceFromEmpireToAttack[i];
        indexMinimumDist = i;
      }
    }
    if (minimumDist>3){
      for (size_t i=0;i<units.size();i++){
        int xu=0; int yu=0;
        positionElementDeepAi(xu, yu, units[i]);
        if (((principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 22) && idUnitsDeepAi(principalMap,id,xu+1,yu) && xu+1>=0 && xu+1<=24) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 22) && idUnitsDeepAi(principalMap,id,xu-1,yu) && xu-1>=0 && xu-1<=24) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 22 ) && idUnitsDeepAi(principalMap,id,xu,yu+1) && yu+1>=0 && yu+1<=24)||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 22) && idUnitsDeepAi(principalMap,id,xu,yu-1) && yu-1>=0 && yu-1<=24)
          ){
            indexMinimumDist=i;
            break;
          }
          else {
            indexMinimumDist=rand() % (distanceFromEmpireToAttack.size());
          }
      }
    }

    int leftElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()+1][unitsPosition[indexMinimumDist].getY()];
    int rightElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()-1][unitsPosition[indexMinimumDist].getY()];
    int topElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()-1];
    int bottomElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()+1];

    //go to the next empire and kill ennemies on its way
    int element=principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()];

    Units* currentUnit = (Units*) principalMap.getAllMaps().getUnitsMap()[unitsPosition[indexMinimumDist].getX()*25 + (unitsPosition[indexMinimumDist].getY())].get();

    Units* unitToAttackt = dynamic_cast<Units*> (principalMap.getAllMaps().getUnitsMap()[unitsPosition[indexMinimumDist].getX()*25 + (unitsPosition[indexMinimumDist].getY()-1)].get());
    Buildings* buildToAttackt = dynamic_cast<Buildings*> (principalMap.getAllMaps().getBuildingsMap()[unitsPosition[indexMinimumDist].getX()*25 + (unitsPosition[indexMinimumDist].getY()-1)].get());
    Buildings* buildToAttackb = dynamic_cast<Buildings*> (principalMap.getAllMaps().getBuildingsMap()[unitsPosition[indexMinimumDist].getX()*25 + (unitsPosition[indexMinimumDist].getY()+1)].get());
    Units* unitToAttackb = dynamic_cast<Units*> (principalMap.getAllMaps().getUnitsMap()[unitsPosition[indexMinimumDist].getX()*25 + (unitsPosition[indexMinimumDist].getY()+1)].get());
    Buildings* buildToAttackl = dynamic_cast<Buildings*> (principalMap.getAllMaps().getBuildingsMap()[(unitsPosition[indexMinimumDist].getX()+1)*25 + (unitsPosition[indexMinimumDist].getY())].get());
    Units* unitToAttackl = dynamic_cast<Units*> (principalMap.getAllMaps().getUnitsMap()[(unitsPosition[indexMinimumDist].getX()+1)*25 + (unitsPosition[indexMinimumDist].getY())].get());
    Buildings* buildToAttackr = dynamic_cast<Buildings*> (principalMap.getAllMaps().getBuildingsMap()[(unitsPosition[indexMinimumDist].getX()-1)*25 + (unitsPosition[indexMinimumDist].getY())].get());
    Units* unitToAttackr = dynamic_cast<Units*> (principalMap.getAllMaps().getUnitsMap()[(unitsPosition[indexMinimumDist].getX()-1)*25 + (unitsPosition[indexMinimumDist].getY())].get());

    if (((topElt == 26 || topElt == 27 || topElt == 28 || topElt == 29) && (currentUnit->getIdUnits() != buildToAttackt->getIdBuilding())) ||
      ( (topElt == 10 || topElt == 14 || topElt == 18 || topElt == 22) && currentUnit->getIdUnits() != unitToAttackt->getIdUnits() )){
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY()-1);
      toAttackNow.push_back(element);
      return toAttackNow;
    }
    else if(( (bottomElt == 26 || bottomElt == 27 || bottomElt == 28 || bottomElt == 29) && (currentUnit->getIdUnits() != buildToAttackb->getIdBuilding())) ||
      ( (bottomElt == 10 || bottomElt == 14 || bottomElt == 18 || bottomElt == 22) && currentUnit->getIdUnits() != unitToAttackb->getIdUnits() )){
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY()+1);
      toAttackNow.push_back(element);
      return toAttackNow;
    }
    else if(( (leftElt == 26 || leftElt == 27 || leftElt == 28 || leftElt == 29) && (currentUnit->getIdUnits() != buildToAttackl->getIdBuilding())) ||
      ( (leftElt == 10 || leftElt == 14 || leftElt == 18 || leftElt == 22) && currentUnit->getIdUnits() != unitToAttackl->getIdUnits() )){
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX()+1);
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY());
      toAttackNow.push_back(element);
      return toAttackNow;
    }
    else if(( (rightElt == 26 || rightElt == 27 || rightElt == 28 || rightElt == 29) && (currentUnit->getIdUnits() != buildToAttackr->getIdBuilding())) ||
      ( (rightElt == 10 || rightElt == 14 || rightElt == 18 || rightElt == 22) && currentUnit->getIdUnits() != unitToAttackr->getIdUnits() )  ){
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY());
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getX()-1);
      toAttackNow.push_back(unitsPosition[indexMinimumDist].getY());
      toAttackNow.push_back(element);
      return toAttackNow;
    }
  }
  return toAttackNow;
}

bool attack(engine::Engine& engine, Observable& principalMap, int& counter, int id){
  std::vector<int> v = attackAvailable(principalMap, id);
  if(v.size()>0){
    std::cout << "Attack" << '\n';
    engine.addCommand(unique_ptr<Command> (new CaseIdentifier(v[0],v[1])),1);
    engine.addCommand(unique_ptr<Command> (new Possibilities(v[0],v[1],v[4])),2);
    engine.addCommand(unique_ptr<Command> (new PrintStats(v[0],v[1],v[4])),3);
    engine.addCommand(unique_ptr<Command> (new Attack(v[0],v[1],v[2],v[3])),7);
    return true;
  } else {
    return false;
  }
}


bool moveToGetCloser(Observable& principalMap, int id){
  if (verifUnitsDeepAi(principalMap,id)){
    // select empire to Attack
    Position posToAttack;
    int distance = 10000000;
    for(size_t i = 0; i < principalMap.getAllMaps().getBuildingsMap().size(); i++){
      Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
      if(building->getIdBuilding() == id && (building->getType()== 26 || building->getType()== 27 || building->getType()== 28 || building->getType()== 29)){
        for(size_t j = 0; j < principalMap.getAllMaps().getBuildingsMap().size(); j++){
          Buildings* building2 = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[j].get();
          if(building2->getIdBuilding() != id && building2->getIdBuilding() != 0 && (building2->getType()== 26 || building2->getType()== 27 || building2->getType()== 28 || building2->getType()== 29)){
            if(building->distance(building->getPosition(), building2->getPosition()) < distance){
              distance = (building->distance(building->getPosition(), building2->getPosition()));
              posToAttack = building2->getPosition();
            }
          }
        }
        break;
      }
    }

    std::vector<int> units; //units index in unitMapMatrix
    std::vector<Position> unitsPosition; //units poition

    for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
      Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
      int idUnit=unit->getIdUnits();
      if (idUnit==id){
        units.push_back(i);
        unitsPosition.push_back(unit->getPosition());
      }
    }
    //units de l'empire

    //distance Unit -> EmpireToAttack
    int minimumDist=100000;
    int indexMinimumDist=-1;
    std::vector<int> distanceFromEmpireToAttack;
    for (size_t i=0;i<unitsPosition.size();i++){
      distanceFromEmpireToAttack.push_back(distDeepAi(unitsPosition[i], posToAttack));
      if(distanceFromEmpireToAttack[i]<minimumDist){
        minimumDist = distanceFromEmpireToAttack[i];
        indexMinimumDist = i;
      }
    }
    if (minimumDist>3){
      for (size_t i=0;i<units.size();i++){
        int xu=0; int yu=0;
        positionElementDeepAi(xu, yu, units[i]);
        if (((principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 22) && idUnitsDeepAi(principalMap,id,xu+1,yu) && xu+1>=0 && xu+1<=24) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 22) && idUnitsDeepAi(principalMap,id,xu-1,yu) && xu-1>=0 && xu-1<=24) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 22 ) && idUnitsDeepAi(principalMap,id,xu,yu+1) && yu+1>=0 && yu+1<=24)||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 22) && idUnitsDeepAi(principalMap,id,xu,yu-1) && yu-1>=0 && yu-1<=24)
          ){
            indexMinimumDist=i;
            break;
          }
          else {
            indexMinimumDist=rand() % (distanceFromEmpireToAttack.size());
          }
      }
    }

    std::vector<int> unitsE; //units index in unitMapMatrix
    std::vector<Position> unitsPositionE; //units poition

    for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
      Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
      int idUnit=unit->getIdUnits();
      if (idUnit!=id&&idUnit!=0){
        unitsE.push_back(i);
        unitsPositionE.push_back(unit->getPosition());
      }
    }

    if(unitsPositionE.size()>0){
      int minimumDistE=100000;
      int indexMinimumDistE=-1;
      std::vector<int> distanceFromUnitToAttack;
      for (size_t i=0;i<unitsPositionE.size();i++){
        distanceFromUnitToAttack.push_back(distDeepAi(unitsPosition[indexMinimumDist], unitsPositionE[i]));
        if(distanceFromUnitToAttack[i]<minimumDistE){
          minimumDistE = distanceFromUnitToAttack[i];
          indexMinimumDistE = i;
        }
      }
      if(indexMinimumDistE>=0){
        if (distanceFromUnitToAttack[indexMinimumDistE]<=3){
          posToAttack=unitsPositionE[indexMinimumDistE];
          return true;
        }
      }
    }
    return false;
  }
  return false;
}


std::vector<int> moveAvailable(Observable& principalMap, int id){
  std::vector<int> toMoveNow;

  if (verifUnitsDeepAi(principalMap,id)){
    // select empire to Attack
    Position posToAttack;
    int distance = 10000000;
    for(size_t i = 0; i < principalMap.getAllMaps().getBuildingsMap().size(); i++){
      Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
      if(building->getIdBuilding() == id && (building->getType()== 26 || building->getType()== 27 || building->getType()== 28 || building->getType()== 29)){
        for(size_t j = 0; j < principalMap.getAllMaps().getBuildingsMap().size(); j++){
          Buildings* building2 = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[j].get();
          if(building2->getIdBuilding() != id && building2->getIdBuilding() != 0 && (building2->getType()== 26 || building2->getType()== 27 || building2->getType()== 28 || building2->getType()== 29)){
            if(building->distance(building->getPosition(), building2->getPosition()) < distance){
              distance = (building->distance(building->getPosition(), building2->getPosition()));
              posToAttack = building2->getPosition();
            }
          }
        }
        break;
      }
    }

    std::vector<int> units; //units index in unitMapMatrix
    std::vector<Position> unitsPosition; //units poition

    for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
      Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
      int idUnit=unit->getIdUnits();
      if (idUnit==id){
        units.push_back(i);
        unitsPosition.push_back(unit->getPosition());
      }
    }
    //units de l'empire

    //distance Unit -> EmpireToAttack
    int minimumDist=100000;
    int indexMinimumDist=-1;
    std::vector<int> distanceFromEmpireToAttack;
    for (size_t i=0;i<unitsPosition.size();i++){
      distanceFromEmpireToAttack.push_back(distDeepAi(unitsPosition[i], posToAttack));
      if(distanceFromEmpireToAttack[i]<minimumDist){
        minimumDist = distanceFromEmpireToAttack[i];
        indexMinimumDist = i;
      }
    }
    if (minimumDist>3){
      for (size_t i=0;i<units.size();i++){
        int xu=0; int yu=0;
        positionElementDeepAi(xu, yu, units[i]);
        if (((principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 22) && idUnitsDeepAi(principalMap,id,xu+1,yu) && xu+1>=0 && xu+1<=24) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 22) && idUnitsDeepAi(principalMap,id,xu-1,yu) && xu-1>=0 && xu-1<=24) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 22 ) && idUnitsDeepAi(principalMap,id,xu,yu+1) && yu+1>=0 && yu+1<=24)||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 22) && idUnitsDeepAi(principalMap,id,xu,yu-1) && yu-1>=0 && yu-1<=24)
          ){
            indexMinimumDist=i;
            break;
          }
          else {
            indexMinimumDist=rand() % (distanceFromEmpireToAttack.size());
          }
      }
    }

    std::vector<int> unitsE; //units index in unitMapMatrix
    std::vector<Position> unitsPositionE; //units poition

    for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
      Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
      int idUnit=unit->getIdUnits();
      if (idUnit!=id&&idUnit!=0){
        unitsE.push_back(i);
        unitsPositionE.push_back(unit->getPosition());
      }
    }

    if(unitsPositionE.size()>0){
      int minimumDistE=100000;
      int indexMinimumDistE=-1;
      std::vector<int> distanceFromUnitToAttack;
      for (size_t i=0;i<unitsPositionE.size();i++){
        distanceFromUnitToAttack.push_back(distDeepAi(unitsPosition[indexMinimumDist], unitsPositionE[i]));
        if(distanceFromUnitToAttack[i]<minimumDistE){
          minimumDistE = distanceFromUnitToAttack[i];
          indexMinimumDistE = i;
        }
      }
      if(indexMinimumDistE>=0){
        if (distanceFromUnitToAttack[indexMinimumDistE]<=3){
          posToAttack=unitsPositionE[indexMinimumDistE];
        }
      }
    }

    int element=principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()];


/////////////////////////////////////////////// ASTAR ////////////////////////////////////////////////
/////////////////////////////////////////////// ASTAR ////////////////////////////////////////////////
/////////////////////////////////////////////// ASTAR ////////////////////////////////////////////////
    AStar::Generator generator;
    // Set 2d map size.
    generator.setWorldSize({principalMap.getAllMaps().getSize(), principalMap.getAllMaps().getSize()});
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    generator.setHeuristic(AStar::Heuristic::manhattan);
    generator.setDiagonalMovement(false);

    std::vector<std::vector<int> > mapMatrix = principalMap.getAllMaps().getMapMatrix();
    for (int i =0 ; i<principalMap.getAllMaps().getSize(); i++ ){
      for (int j = 0 ; j<principalMap.getAllMaps().getSize(); j++){
        if(mapMatrix[i][j]!=2)
        {
            Vec2i collision;
            collision.x = i;
            collision.y = j;
            generator.addCollision(collision);
        }
      }
    }

    Vec2i initial,target;
    initial.x = unitsPosition[indexMinimumDist].getX();
    initial.y = unitsPosition[indexMinimumDist].getY();

    if(posToAttack.getX()>= unitsPosition[indexMinimumDist].getX()){
      target.x = posToAttack.getX()-1;
    } else {
      target.x = posToAttack.getX()+1;
    }

    target.y = posToAttack.getY();
    auto path = generator.findPath(initial,target);

    auto nextTile = path[path.size()-2];
    generator.clearCollisions();
    // std::cout << "unitsPosition : (" << unitsPosition[indexMinimumDist].getX() << "," << unitsPosition[indexMinimumDist].getY() << ")" << endl;
    // std::cout << "nextTile : (" << nextTile.x << "," << nextTile.y << ")" << endl;

    if(nextTile.x > 0 && nextTile.x < 25 && nextTile.y > 0 && nextTile.y < 25){
      toMoveNow.push_back(unitsPosition[indexMinimumDist].getX());
      toMoveNow.push_back(unitsPosition[indexMinimumDist].getY());
      toMoveNow.push_back(nextTile.x);
      toMoveNow.push_back(nextTile.y);
      toMoveNow.push_back(element);
    }
  }
  return toMoveNow;
}


bool move(engine::Engine& engine, Observable& principalMap, int& counter, int id){
  std::vector<int> v = moveAvailable(principalMap, id);
  if(v.size()>0){

    // std::cout << "posInit : (" << v[0] << "," << v[1] << ")" << '\n';
    // std::cout << "posToGo : (" << v[2] << "," << v[3] << ")" << '\n';
    engine.addCommand(unique_ptr<Command> (new CaseIdentifier(v[0],v[1])),1);
    engine.addCommand(unique_ptr<Command> (new Possibilities(v[0],v[1],v[4])),2);
    engine.addCommand(unique_ptr<Command> (new PrintStats(v[0],v[1],v[4])),3);
    engine.addCommand(unique_ptr<Command> (new Move(v[0],v[1],v[2],v[3])),6);
    std::cout << "Move" << '\n';
    return true;
  } else {
    return false;
  }
}


bool ennemyNextToPalace(Observable& principalMap, int id){

  Position posPalace;

  for(size_t i = 0; i < principalMap.getAllMaps().getBuildingsMap().size(); i++){
    Buildings* build = (Buildings *) principalMap.getAllMaps().getBuildingsMap()[i].get();
    if(build->getIdBuilding()==id && ( build->getType()== 26 || build->getType()== 27 || build->getType()== 28 || build->getType()== 29 ) ){
      posPalace = build->getPosition();
    }
  }

  for(size_t i = 0; i < principalMap.getAllMaps().getUnitsMap().size(); i++){
    Units* unit = (Units *) principalMap.getAllMaps().getUnitsMap()[i].get();
    if(unit->getIdUnits()!=id && ( unit->getType()== 10 || unit->getType()== 14 || unit->getType()== 18 || unit->getType()== 22 ) ){
      if(distDeepAi(posPalace, unit->getPosition())<=3){
        return true;
      }
    }
  }
  return false;
}


//Here is our heuristic behaviour function :
//it should process the gameState to update the weights for each situation

std::vector<int> weightUpdate(Observable& principalMap, int id){
  int moveWeight;
  int attackWeight;
  int createUnitWeight;
  int levelUpWeight;
  std::vector<int> toReturn;

  if(attackAvailable(principalMap, id).size() > 0){
    //if a unit/palace is next to you : Attack it, then the others weights are low
    moveWeight = 10;
    attackWeight = 40;
    createUnitWeight = 20; //Maybe not Possible
    levelUpWeight = 30; //Maybe not Possible
  } else if(moveToGetCloser(principalMap, id)){
    //if a unit/palace is in a range of 3 next to you : Move to it, then the others weights are low
    moveWeight = 40;
    attackWeight = -1; //Not Possible to attack here ==> branch to be cut
    createUnitWeight = 20; //Maybe not Possible
    levelUpWeight = 30; //Maybe not Possible
  } else if(ennemyNextToPalace(principalMap, id)){
    //if an ennemy is in a range of 3 next to your palace : create a unit if it is possible, then the others weights are low
    moveWeight = 20;
    attackWeight = -1; //Not Possible to attack here ==> branch to be cut
    createUnitWeight = 40; //Maybe not Possible
    levelUpWeight = 30; //Maybe not Possible
  } else {
    // Basic weight are given by :
    moveWeight = 20; //Maybe not Possible
    attackWeight = -1; //Not Possible to attack here ==> branch to be cut
    createUnitWeight = 30; //Maybe not Possible
    levelUpWeight = 40; //Maybe not Possible
    // This is better to LevelUp, then to CreateUnit, then to Attack, then to Move
  }

  //Cost of units according to level
  std::vector<int> unitCost = {50,100,150,200};
  std::vector<int> buildingCost = {100,200,300,400};

  Empire* empire=principalMap.getAllMaps().getEmpires()[0].get();
  for (int i=1;i<3;i++){
    if (principalMap.getAllMaps().getEmpires()[i].get()->getId()==id){
      empire=principalMap.getAllMaps().getEmpires()[i].get();
    }
  }

  int food = empire->getFoodRessource();
  int wood = empire->getWoodRessource();
  int gold = empire->getGoldRessource();

  std::vector<int> buildingsLevel;

  for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
    Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
    int idBuilding=building->getIdBuilding();
    if (idBuilding==id){
      buildingsLevel.push_back(building->getLevel());
    }
  }

  if(food < unitCost[buildingsLevel[2]-1] || gold < unitCost[buildingsLevel[2]-1]){
    createUnitWeight = -1;
  }

  int min = 100000;
  for(int i=0; i<3; i++){
    if(buildingsLevel[i]<min) min = i;
  }

  if(wood < buildingCost[buildingsLevel[min]-1] || gold < unitCost[buildingsLevel[min]-1]){
    levelUpWeight = -1;
  }

  if(!verifUnitsDeepAi(principalMap,id)) moveWeight = -1;

//watch monney levelUp create

  // if all of the previous heuristic are false, then use the basic weights
  toReturn.push_back(levelUpWeight);
  toReturn.push_back(createUnitWeight);
  toReturn.push_back(attackWeight);
  toReturn.push_back(moveWeight);
  return toReturn;
}

//When we create the binary tree of all our actions we must cut the branches which cannot be processed.
//For exemple : No money ==> no levelUp or Unit creation

////////////////////////////////////////////////////////////
/////////////////////////  MIN  ////////////////////////////
////////////////////////////////////////////////////////////

std::vector<int> min(std::vector<int> array, size_t begin, size_t end){
  int min = 10000000;
  int index = 0;
  std::vector<int> toReturn;
  for(size_t i = begin; i < end; i++){
    if(array[i]<min && array[i]>0){
      min = array[i];
      index = i;
    }
  }
  if(min == 10000000) min = 0;
  toReturn.push_back(min);
  toReturn.push_back(index - begin);
  return toReturn;
}

////////////////////////////////////////////////////////////
/////////////////////////  MAX  ////////////////////////////
////////////////////////////////////////////////////////////

std::vector<int> max(std::vector<int> array, size_t begin, size_t end){
  int max = 0;
  int index = 0;
  std::vector<int> toReturn;
  for(size_t i = begin; i < end; i++){
    if(array[i]>max){
      max = array[i];
      index = i;
    }
  }
  toReturn.push_back(max);
  toReturn.push_back(index - begin + 1);
  return toReturn;
}

////////////////////////////////////////////////////////////
/////////////////////////  MIN-MAX  ////////////////////////
////////////////////////////////////////////////////////////

bool performAction(engine::Engine& engine, Observable& principalMap, int& counter, bool& canPlay, int id, int i){
  std::vector<int> empireWeights;
  empireWeights = weightUpdate(principalMap, id);
  switch (i) {
    case 4: {
      if(empireWeights[i-1] != -1){
        if(move(engine, principalMap, counter, id)){
          engine.execute(principalMap);
          return true;
        } else {
          return false;
        }
      }
      break;
    }
    case 3: {
      if(empireWeights[i-1] != -1){
        if(attack(engine, principalMap, counter, id)){
          engine.execute(principalMap);
          return true;
        } else {
          return false;
        }
      }
      break;
    }
    case 2: {
      if(empireWeights[i-1] != -1){
        if(createUnit(engine, principalMap, counter, id)){
          engine.execute(principalMap);
          return true;
        } else {
          return false;
        }
      }
      break;
    }
    case 1: {
      if(empireWeights[i-1] != -1){
        if(levelUp(engine, principalMap, counter, id)){
          engine.execute(principalMap);
          return true;
        } else {
          return false;
        }
      }
      break;
    }
    default : break;
  }
  return false;
}

std::vector<int> minMax(engine::Engine& engine, Observable& principalMap, int& counter, bool& canPlay, int id){

  std::vector<int> state2;
  std::vector<int> state3;
  std::vector<int> state4;
  std::vector<int> action2; //save the actionID associated to the weight
  std::vector<int> action3; //save the actionID associated to the weight
  std::vector<int> action4; //save the actionID associated to the weight

  std::vector<int> empire3Weights;

  int id1, id2, id3;

  if(id == 1){
    id1 = 1;
    id2 = 2;
    id3 = 3;
  } else if(id == 2){
    id1 = 2;
    id2 = 3;
    id3 = 1;
  } else{
    id1 = 3;
    id2 = 1;
    id3 = 2;
  }

  std::vector<int> toAdd;

  for (size_t i = 1; i < 5; i++) {                              //currentEmpire
    if(performAction(engine, principalMap, counter, canPlay, id1, i)){

      for (size_t j = 1; j < 5; j++) {
        if(performAction(engine, principalMap, counter, canPlay, id2, j)){

          for (size_t k = 1; k < 5; k++) {
            if(performAction(engine, principalMap, counter, canPlay, id3, k)){
              empire3Weights = weightUpdate(principalMap, id3);
              toAdd = min(empire3Weights, 0, empire3Weights.size());
              action4.push_back(toAdd[1]+1);
              state4.push_back(toAdd[0]);
              engine.rollback(principalMap);
            } else {
              action4.push_back(k);
              state4.push_back(-1);
            }
          }
          toAdd = min(state4, state4.size()-4, state4.size());
          state3.push_back(toAdd[0]);
          action3.push_back(toAdd[1]+1);
          engine.rollback(principalMap);
        } else {
          action3.push_back(j);
          state3.push_back(-1);
        }
      }
      toAdd = min(state3, state3.size()-4, state3.size());
      state2.push_back(toAdd[0]);
      action2.push_back(toAdd[1]+1);
      engine.rollback(principalMap);
    } else {
      action2.push_back(i);
      state2.push_back(-1);
    }
  }
  toAdd = max(state2, 0, 4);

  // int actionToPerform = toAdd[1];  // 4 --> levelup   3 --> createUnit   1 --> move   2 --> attack

  return toAdd;

}


void DeepAI::run (engine::Engine& engine, Observable& principalMap, int& counter, bool& canPlay, int id){
  srand(time(NULL));
  std::cout << "/* NewTour */" << '\n';
  std::vector<int> minmax = minMax(engine, principalMap, counter, canPlay, id);
  if(minmax[1]==1){
    counter++;
    if(levelUp(engine, principalMap, counter, id)){
      return;
    }
  } else if(minmax[1]==2){
    counter++;
    if(createUnit(engine, principalMap, counter, id)){
      return;
    }
  } else if(minmax[1]==3){
    counter++;
    if(attack(engine, principalMap, counter, id)){
      return;
    }
  } else if(minmax[1]==4){
    counter++;
    if(move(engine, principalMap, counter, id)){
      return;
    }
  } else {
    counter++;
    std::cout << "don't play" << '\n';
    return;
  }
}
