#include "HeuristicAI.h"
#include "../engine.h"
#include "../state.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace ai;
using namespace engine;
using namespace state;
using namespace std;

//find the distance between 2 positions
int dist(Position pos1, Position pos2){
  int absdiff, orddiff;
  absdiff = std::abs(pos1.getX() - pos2.getX());
  orddiff = std::abs(pos1.getY() - pos2.getY());
  return(absdiff+orddiff);
}

//Verify if there is at least one unit in the map of id : id
bool verifUnits(Observable& principalMap,int id){
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
bool verifPoss(Observable& principalMap, int x,int y, int id, int element){
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

//compare 2 positions
bool posComp(Position pos1, Position pos2){
  if (pos1.getX()==pos2.getX() && pos1.getY()==pos2.getY()){
    return false;
  }
  else {
    return true;
  }
}

//verify if the (x,y) unit id is the same as the current empire playing id
bool idUnits(Observable& principalMap, int id,int x, int y){
    Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[y+25*x].get();
    int idUnit=unit->getIdUnits();
    if (idUnit!=id){
      return true;
    }
    else {
      return false;
    }
}

HeuristicAI::HeuristicAI (){}

//recover the element position in an inline array
void positionElement(int& x, int& y, int position){
  y = position%25;
  x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }
}

void HeuristicAI::run (engine::Engine& engine, Observable& principalMap, int& counter, bool& canPlay, int id){
  if(canPlay){
    srand(time(NULL));
    // std::cout << "/* NewTour */" << '\n';

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
    positionElement(x1, y1, buildings[0]);

    int y2 = 0;
    int x2 = -1;
    positionElement(x2, y2, buildings[1]);

    int y3 = 0;
    int x3=-1;
    positionElement(x3, y3, buildings[2]);

    std::vector<int> arrowCost = {50,100,150,200};
    std::vector<int> decurionCost = {50,100,150,200};
    std::vector<int> catapultCost = {50,100,150,200};
    std::vector<int> cavalierCost = {50,100,150,200};

    Ressource* ressource = (Ressource*) principalMap.getAllMaps().getBuildingsMap()[y1+25*x1].get();
    Palace* palace = (Palace*) principalMap.getAllMaps().getBuildingsMap()[y2+25*x2].get();
    Barrack* barrack = (Barrack*) principalMap.getAllMaps().getBuildingsMap()[y3+25*x3].get();
    int levelUnit = barrack->getLevel();

    int element;
    //level up of the palace if possible
    if(palace->getLevel() < 4 && palace->getBuildingCost().getWood()<=empire->getWoodRessource() && palace->getBuildingCost().getGold()<=empire->getGoldRessource()){
      // std::cout << "LevelUp palace" << '\n';
      element=principalMap.getAllMaps().getMapMatrix()[x2][y2];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x2,y2))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x2,y2,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x2,y2,element)),3);
      usleep(500000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x2,y2))),5);
      counter++;
      return;
      //level up of the barrack if possible
    } else if(barrack->getLevel() < palace->getLevel() && barrack->getBuildingCost().getWood()<=empire->getWoodRessource() && barrack->getBuildingCost().getGold()<=empire->getGoldRessource()){
      // std::cout << "LevelUp barrack" << '\n';
      int element=principalMap.getAllMaps().getMapMatrix()[x3][y3];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x3,y3))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x3,y3,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x3,y3,element)),3);
      usleep(500000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x3,y3))),5);
      counter++;
      return;
      //level up of the ressource if possible
    } else if(ressource->getLevel() < palace->getLevel() && ressource->getBuildingCost().getWood()<=empire->getWoodRessource() && ressource->getBuildingCost().getGold()<=empire->getGoldRessource()){
      // std::cout << "LevelUp ressource" << '\n';
      int element=principalMap.getAllMaps().getMapMatrix()[x1][y1];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x1,y1))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x1,y1,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x1,y1,element)),3);
      usleep(500000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x1,y1))),5);
      counter++;
      return;
      //CreateUnit if enough space in barrack and enough ressource
    } else if (barrack->getUnitsNumber()<barrack->getCapacity() &&
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
      usleep(500000);
      // std::cout << "CreateUnit" << '\n';
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
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,1))),4);
          usleep(500000);
          counter++;
          return;
        }
        break;
        case 2:
        if(decurionCost[levelUnit-1]<=empire->getFoodRessource() && decurionCost[levelUnit-1]<=empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,2))),4);
          usleep(500000);
          counter++;
          return;
        }
        break;
        case 3:
        if(cavalierCost[levelUnit-1]<=empire->getFoodRessource() && cavalierCost[levelUnit-1]<=empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,4))),4);
          usleep(500000);
          counter++;
          return;
        }
        break;
        case 4:
        if(catapultCost[levelUnit-1]<=empire->getFoodRessource() && catapultCost[levelUnit-1]<=empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,3))),4);
          usleep(500000);
          counter++;
          return;
        }
        break;
        default : break;
      }
    } else if (verifUnits(principalMap,id)){

      // select empire to Attack

      Position posToAttack;

      int distance = 100000000;

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
      int minimumDist=1000000;
      int indexMinimumDist=-1;
      std::vector<int> distanceFromEmpireToAttack;
      for (size_t i=0;i<unitsPosition.size();i++){
        distanceFromEmpireToAttack.push_back(dist(unitsPosition[i], posToAttack));
        if(distanceFromEmpireToAttack[i]<minimumDist){
          minimumDist = distanceFromEmpireToAttack[i];
          indexMinimumDist = i;
        }
      }

      if (minimumDist>3){
        for (size_t i=0;i<units.size();i++){
          int xu=0; int yu=0;
          positionElement(xu, yu, units[i]);
          if(xu+1>=0 && xu+1<=24 && xu-1>=0 && xu-1<=24 && yu+1>=0 && yu+1<=24 && yu-1>=0 && yu-1<=24){
            if (((principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu+1][yu] == 22) && idUnits(principalMap,id,xu+1,yu)) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 10 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 14 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 18 || principalMap.getAllMaps().getMapMatrix()[xu-1][yu] == 22) && idUnits(principalMap,id,xu-1,yu)) ||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu+1] == 22 ) && idUnits(principalMap,id,xu,yu+1))||
            ((principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 10 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 14 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 18 || principalMap.getAllMaps().getMapMatrix()[xu][yu-1] == 22) && idUnits(principalMap,id,xu,yu-1))
            ){
              indexMinimumDist=i;
              break;
            } else {
              indexMinimumDist=rand() % (units.size());
            }
          }
        }
      }

      std::vector<int> unitsE; //units index in unitMapMatrix
      std::vector<Position> unitsPositionE; //units poition

      for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
        Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
        int idUnit=unit->getIdUnits();
        if (idUnit!=id && idUnit!=0){
          unitsE.push_back(i);
          unitsPositionE.push_back(unit->getPosition());
        }
      }

      if(unitsPositionE.size()>0){
        int minimumDistE=1000000;
        int indexMinimumDistE=-1;
        std::vector<int> distanceFromUnitToAttack;
        for (size_t i=0;i<unitsPositionE.size();i++){
          distanceFromUnitToAttack.push_back(dist(unitsPosition[indexMinimumDist], unitsPositionE[i]));
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
        engine.addCommand((unique_ptr<Command> (new CaseIdentifier(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()))),1);
        engine.addCommand(unique_ptr<Command> (new Possibilities(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),2);
        engine.addCommand(unique_ptr<Command> (new PrintStats(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),3);
        engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()-1))),7);
        usleep(500000);
        counter++;
        return;
      }
      else if(( (bottomElt == 26 || bottomElt == 27 || bottomElt == 28 || bottomElt == 29) && (currentUnit->getIdUnits() != buildToAttackb->getIdBuilding())) ||
        ( (bottomElt == 10 || bottomElt == 14 || bottomElt == 18 || bottomElt == 22) && currentUnit->getIdUnits() != unitToAttackb->getIdUnits() )){
        engine.addCommand((unique_ptr<Command> (new CaseIdentifier(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()))),1);
        engine.addCommand(unique_ptr<Command> (new Possibilities(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),2);
        engine.addCommand(unique_ptr<Command> (new PrintStats(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),3);
        engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()+1))),7);
        usleep(500000);
        counter++;
        return;
      }
      else if(( (leftElt == 26 || leftElt == 27 || leftElt == 28 || leftElt == 29) && (currentUnit->getIdUnits() != buildToAttackl->getIdBuilding())) ||
        ( (leftElt == 10 || leftElt == 14 || leftElt == 18 || leftElt == 22) && currentUnit->getIdUnits() != unitToAttackl->getIdUnits() )){
        engine.addCommand((unique_ptr<Command> (new CaseIdentifier(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()))),1);
        engine.addCommand(unique_ptr<Command> (new Possibilities(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),2);
        engine.addCommand(unique_ptr<Command> (new PrintStats(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),3);
        usleep(500000);
        engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()+1,unitsPosition[indexMinimumDist].getY()))),7);
        usleep(500000);
        counter++;
        return;
      }
      else if(( (rightElt == 26 || rightElt == 27 || rightElt == 28 || rightElt == 29) && (currentUnit->getIdUnits() != buildToAttackr->getIdBuilding())) ||
        ( (rightElt == 10 || rightElt == 14 || rightElt == 18 || rightElt == 22) && currentUnit->getIdUnits() != unitToAttackr->getIdUnits() )  ){
        engine.addCommand((unique_ptr<Command> (new CaseIdentifier(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()))),1);
        engine.addCommand(unique_ptr<Command> (new Possibilities(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),2);
        engine.addCommand(unique_ptr<Command> (new PrintStats(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),3);
        usleep(500000);
        engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()-1,unitsPosition[indexMinimumDist].getY()))),7);
        usleep(500000);
        counter++;
        return;
      }
      std::vector<state::Position> possibilitiesPos;
      if(leftElt==2){
        Position pos2(unitsPosition[indexMinimumDist].getX()+1,unitsPosition[indexMinimumDist].getY());
        if (posComp(pos2,currentUnit->getCanMove()[0]) && posComp(pos2,currentUnit->getCanMove()[1]) && posComp(pos2,currentUnit->getCanMove()[2])){
          possibilitiesPos.push_back(pos2);
        }
      }
      if(rightElt==2){
        Position pos3(unitsPosition[indexMinimumDist].getX()-1,unitsPosition[indexMinimumDist].getY());
        if (posComp(pos3,currentUnit->getCanMove()[0]) && posComp(pos3,currentUnit->getCanMove()[1]) && posComp(pos3,currentUnit->getCanMove()[2])){
          possibilitiesPos.push_back(pos3);
        }
      }
      if(bottomElt==2){
        Position pos4(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()+1);
        if (posComp(pos4,currentUnit->getCanMove()[0]) && posComp(pos4,currentUnit->getCanMove()[1]) && posComp(pos4,currentUnit->getCanMove()[2])){
          possibilitiesPos.push_back(pos4);
        }
      }
      if(topElt==2){
        Position pos5(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()-1);
        if (posComp(pos5,currentUnit->getCanMove()[0]) && posComp(pos5,currentUnit->getCanMove()[1]) && posComp(pos5,currentUnit->getCanMove()[2])){
          possibilitiesPos.push_back(pos5);
        }
      }
      int minimumDistG=1000000;
      int indexMinimumDistG=-1;
      std::vector<int> distanceFromGToAttack;
      for (size_t i=0;i<possibilitiesPos.size();i++){
        distanceFromGToAttack.push_back(dist(possibilitiesPos[i], posToAttack));
        if(distanceFromGToAttack[i]<minimumDistG){
          minimumDistG = distanceFromGToAttack[i];
          indexMinimumDistG = i;
        } else if (distanceFromGToAttack[i]==minimumDistG){
          if (rand() %2 ==1){
            minimumDistG = distanceFromGToAttack[i];
            indexMinimumDistG = i;
          }
        }
      }

      if (indexMinimumDistG>=0){
        engine.addCommand((unique_ptr<Command> (new CaseIdentifier(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()))),1);
        engine.addCommand(unique_ptr<Command> (new Possibilities(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),2);
        engine.addCommand(unique_ptr<Command> (new PrintStats(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),3);
        engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),possibilitiesPos[indexMinimumDistG].getX(),possibilitiesPos[indexMinimumDistG].getY()))),6);
        usleep(500000);
        std::vector<state::Position> unitPos;
        Position possPos(possibilitiesPos[indexMinimumDistG].getX(),possibilitiesPos[indexMinimumDistG].getY());
        unitPos.push_back(currentUnit->getCanMove()[1]);
        unitPos.push_back(currentUnit->getCanMove()[2]);
        unitPos.push_back(possPos);
        currentUnit->setCanMove(unitPos);
        counter++;
        return;
      } else {
        counter++;
        return;
      }
    }
    counter++;
    return;
  }
}
