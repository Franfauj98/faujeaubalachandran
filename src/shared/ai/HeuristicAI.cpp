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

// bool verif(Observable& principalMap, int x,int y, int id, int element){
//   bool verif=true;
//   if (element==1){
//     Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[y+25*x].get();
//     int idUnit=unit->getIdUnits();
//     if (idUnit==id){
//       verif=false;
//     } else {
//     verif=true;
//     }
//   }
//   else if (element==0){
//     Buildings* building =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[y+25*x].get();
//     int idBuilding=building->getIdBuilding();
//     if (idBuilding==id){
//       verif=false;
//     } else {
//       verif=true;
//     }
//   }
//   return verif;
// }

int dist(Position pos1, Position pos2){
  int absdiff, orddiff;
  absdiff = std::abs(pos1.getX() - pos2.getX());
  orddiff = std::abs(pos1.getY() - pos2.getY());
  return(absdiff+orddiff);
}

HeuristicAI::HeuristicAI (){}

/*
améliorer batiments dès qu'il peut: hdv caserne ressources OK
créer unités dès qu'il peut OK
choisir un empire et l'attaquer
envoyer toutes les unités ensemble: pour ca on choisit l'unité le plus loin de l'hdv adverse en distance puis A*
si en route unités adverse attaquer
attaquer hdv
choisir autre empire
*/

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
    std::cout << "/* NewTour */" << '\n';

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

    Position pos0(0,0);
    Arrow arrow(1,pos0,0);
    Decurion decurion(1,pos0,0);
    Catapult catapult(1,pos0,0);
    Cavalier cavalier(1,pos0,0);

    Ressource* ressource =(Ressource*) principalMap.getAllMaps().getBuildingsMap()[y1+25*x1].get();
    Palace* palace =(Palace*) principalMap.getAllMaps().getBuildingsMap()[y2+25*x2].get();
    Barrack* barrack =(Barrack*) principalMap.getAllMaps().getBuildingsMap()[y3+25*x3].get();
    int element;
    if(palace->getLevel() < 4 && palace->getBuildingCost().getWood()<empire->getWoodRessource() && palace->getBuildingCost().getGold()<empire->getGoldRessource()){
      std::cout << "LevelUp palace" << '\n';
      element=principalMap.getAllMaps().getMapMatrix()[x2][y2];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x2,y2))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x2,y2,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x2,y2,element)),3);
      usleep(2000000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x2,y2))),5);
      counter++;
      return;
    } else if(barrack->getLevel() < palace->getLevel() && barrack->getBuildingCost().getWood()<empire->getWoodRessource() && barrack->getBuildingCost().getGold()<empire->getGoldRessource()){
      std::cout << "LevelUp barrack" << '\n';
      int element=principalMap.getAllMaps().getMapMatrix()[x3][y3];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x3,y3))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x3,y3,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x2,y3,element)),3);
      usleep(2000000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x3,y3))),5);
      counter++;
      return;
    } else if(ressource->getLevel() < palace->getLevel() && ressource->getBuildingCost().getWood()<empire->getWoodRessource() && ressource->getBuildingCost().getGold()<empire->getGoldRessource()){
      std::cout << "LevelUp ressource" << '\n';
      int element=principalMap.getAllMaps().getMapMatrix()[x1][y1];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x1,y1))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x1,y1,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x1,y1,element)),3);
      usleep(2000000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x1,y1))),5);
      counter++;
      return;
    } else if (barrack->getUnitsNumber()<barrack->getCapacity() &&
    ((arrow.getUnitCost().getFood()<empire->getFoodRessource() && arrow.getUnitCost().getGold()<empire->getGoldRessource()) ||
      (decurion.getUnitCost().getFood()<empire->getFoodRessource() && decurion.getUnitCost().getGold()<empire->getGoldRessource()) ||
      (cavalier.getUnitCost().getFood()<empire->getFoodRessource() && cavalier.getUnitCost().getGold()<empire->getGoldRessource()) ||
      (catapult.getUnitCost().getFood()<empire->getFoodRessource() && catapult.getUnitCost().getGold()<empire->getGoldRessource())
    )
    ){
      std::cout << "CreateUnit" << '\n';
      std::vector<int> positions={y3,(x3+1),y3+1,(x3+1),y3+1,x3,y3+1,(x3-1),y3,(x3-1)};
      int pos=0;
      while (principalMap.getAllMaps().getMapMatrix()[positions[pos+1]][positions[pos]]!=2 && pos<10){
        pos +=2;
      }
      int y= positions[pos];
      int x=positions[pos+1];
      int unitChoice=rand() % 4+1;
      switch(unitChoice){
        case 1:
        if (arrow.getUnitCost().getFood()<empire->getFoodRessource() && arrow.getUnitCost().getGold()<empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,1))),4);
          usleep(2000000);
          counter++;
          std::cout << "arrow" << '\n';
          return;
        }
        break;
        case 2:
        if(decurion.getUnitCost().getFood()<empire->getFoodRessource() && decurion.getUnitCost().getGold()<empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,2))),4);
          usleep(2000000);
          counter++;
          std::cout << "decurion" << '\n';
          return;
        }
        break;
        case 3:
        if(cavalier.getUnitCost().getFood()<empire->getFoodRessource() && cavalier.getUnitCost().getGold()<empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,4))),4);
          usleep(2000000);
          counter++;
          std::cout << "cavalier" << '\n';
          return;
        }
        break;
        case 4:
        if(catapult.getUnitCost().getFood()<empire->getFoodRessource() && catapult.getUnitCost().getGold()<empire->getGoldRessource()){
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,3))),4);
          usleep(2000000);
          counter++;
          std::cout << "catapult" << '\n';
          return;
        }
        break;
        default : break;
      }
    } else {

      // select empire to Attack
      std::cout << "/* select empire to Attack */" << '\n';
      int toAttack = 0;

      Position posToAttack;

      int distance = 100000000;

      for(size_t i = 0; i < principalMap.getAllMaps().getBuildingsMap().size(); i++){
        Buildings* building = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
        if(building->getIdBuilding() == id && (building->getType()== 26 || building->getType()== 27 || building->getType()== 28 || building->getType()== 29)){
          for(size_t j = 0; j < principalMap.getAllMaps().getBuildingsMap().size(); j++){
            Buildings* building2 = (Buildings*) principalMap.getAllMaps().getBuildingsMap()[j].get();
            if(building2->getIdBuilding() != id && (building2->getType()== 26 || building2->getType()== 27 || building2->getType()== 28 || building2->getType()== 29)){
              if(building->distance(building->getPosition(), building2->getPosition()) < distance){
                distance = (building->distance(building->getPosition(), building2->getPosition()));
                toAttack = j;
                posToAttack = building2->getPosition();
              }
            }
          }
          break;
        }
      }
      std::cout << posToAttack.getX() << '\n';
      std::cout << posToAttack.getX() << '\n';
      std::cout << '\n';
      std::cout << '\n';

      int y4 = 0;
      int x4 =- 1;
      positionElement(x4, y4, toAttack);

      std::vector<int> units; //units index in unitMapMatrix
      std::vector<Position> unitsPosition; //units poition

      // parcourt le tableau pour voir s'il y a des unités et rentre leurs positions
      std::cout << "/* Recuperation position unités */" << '\n';
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
      int minimumDist = 1000000;
      int indexMinimumDist = 1000000;
      std::vector<int> distanceFromEmpireToAttack;
      std::cout << "/* Recuperation distance entre unités et empire à attaquer */" << '\n';
      for (size_t i=0;i<unitsPosition.size();i++){
        distanceFromEmpireToAttack.push_back(dist(unitsPosition[i], posToAttack));
        if(distanceFromEmpireToAttack[i]<minimumDist){
          minimumDist = distanceFromEmpireToAttack[i];
          indexMinimumDist = i;
        }
      }

      // select unit to attak if in range 3 .
      // for (size_t i=0;i<unitsPosition.size();i++){
      //   distanceFromEmpireToAttack.push_back(dist(unitsPosition[i], posToAttack));
      //   if(distanceFromEmpireToAttack[i]<minimumDist){
      //     minimumDist = distanceFromEmpireToAttack[i];
      //     indexMinimumDist = i;
      //   }
      // }

      int leftElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()-1][unitsPosition[indexMinimumDist].getY()];
      int rightElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()+1][unitsPosition[indexMinimumDist].getY()];
      int topElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()-1];
      int bottomElt = principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()+1];

      //go to the next empire and kill ennemies on its way
      int element=principalMap.getAllMaps().getMapMatrix()[unitsPosition[indexMinimumDist].getX()][unitsPosition[indexMinimumDist].getY()];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),element)),3);
      usleep(2000000);

      if(posToAttack.getY() < unitsPosition[indexMinimumDist].getY()){
        if(topElt == 2){
          std::cout << "/* Bouge y-1 */" << '\n';
          std::cout << unitsPosition[indexMinimumDist].getX() << '\n';
          std::cout << unitsPosition[indexMinimumDist].getY() << '\n';
          std::cout << '\n';
          std::cout << '\n';
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()-1))),6);
          usleep(2000000);
          counter++;
          return;
        // } else if(topElt == 10 || topElt == 14 || topElt == 18 || topElt == 22 || topElt == 26 || topElt == 27 || topElt == 28 || topElt == 29 ){
        //   std::cout << "/* Attack y-1 */" << '\n';
        //   engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()-1))),7);
        //   usleep(2000000);
        //   counter++;
        //   return;
        } else {
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()-1,unitsPosition[indexMinimumDist].getY()))),6);
          counter++;
          return;
        }//traiterObstacle !!
      } else if(posToAttack.getY() > unitsPosition[indexMinimumDist].getY()){
        if(bottomElt == 2){
          std::cout << "/* Bouge y+1 */" << '\n';
          std::cout << unitsPosition[indexMinimumDist].getX() << '\n';
          std::cout << unitsPosition[indexMinimumDist].getY() << '\n';
          std::cout << '\n';
          std::cout << '\n';
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()+1))),6);
          usleep(2000000);
          counter++;
          return;
        // } else if(bottomElt == 10 || bottomElt == 14 || bottomElt == 18 || bottomElt == 22 || bottomElt == 26 || bottomElt == 27 || bottomElt == 28 || bottomElt == 29 ){
        //   std::cout << "/* Attack y+1 */" << '\n';
        //   engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()+1))),7);
        //   usleep(2000000);
        //   counter++;
        //   return;
        } else {
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()-1,unitsPosition[indexMinimumDist].getY()))),6);
          counter++;
          return;
        }//traiterObstacle !!
      } else if(posToAttack.getX() < unitsPosition[indexMinimumDist].getX()){
        if(leftElt == 2){
          std::cout << "/* Bouge x-1 */" << '\n';
          std::cout << unitsPosition[indexMinimumDist].getX() << '\n';
          std::cout << unitsPosition[indexMinimumDist].getY() << '\n';
          std::cout << '\n';
          std::cout << '\n';

          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()-1,unitsPosition[indexMinimumDist].getY()))),6);
          usleep(2000000);
          counter++;
          return;
        // } else if(leftElt == 10 || leftElt == 14 || leftElt == 18 || leftElt == 22 || leftElt == 26 || leftElt == 27 || leftElt == 28 || leftElt == 29 ){
        //   std::cout << "/* Attack x-1 */" << '\n';
        //   engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()-1,unitsPosition[indexMinimumDist].getY()))),7);
        //   usleep(2000000);
        //   counter++;
        //   return;
        } else {
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()+1))),6);
          counter++;
          return;
        }//traiterObstacle !!
      } else if(posToAttack.getX() > unitsPosition[indexMinimumDist].getX()){
        if(rightElt == 2){
          std::cout << "/* Bouge x+1 */" << '\n';
          std::cout << unitsPosition[indexMinimumDist].getX() << '\n';
          std::cout << unitsPosition[indexMinimumDist].getY() << '\n';
          std::cout << '\n';
          std::cout << '\n';
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()+1,unitsPosition[indexMinimumDist].getY()))),6);
          usleep(2000000);
          counter++;
          return;
        // } else if(rightElt == 10 || rightElt == 14 || rightElt == 18 || rightElt == 22 || rightElt == 26 || rightElt == 27 || rightElt == 28 || rightElt == 29 ){
        //   std::cout << "/* Attack x+1 */" << '\n';
        //   engine.addCommand((unique_ptr<Command> (new Attack(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX()+1,unitsPosition[indexMinimumDist].getY()))),7);
        //   usleep(2000000);
        //   counter++;
        //   return;
        } else {
          engine.addCommand((unique_ptr<Command> (new Move(unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY(),unitsPosition[indexMinimumDist].getX(),unitsPosition[indexMinimumDist].getY()-1))),6);
          counter++;
          return;
        }//traiterObstacle !!
      }
    }
  }
}

    // // choix de l'unité
    // int unitChoice=rand() % (units.size());
    // int y = units[unitChoice]%25;
    // int x=-1;
    // for(int i = 0; i < (25*25); i++){
    //   if(i%25 == 0) x+=1;
    //   if(i==units[unitChoice]) break;
    // }
    // int element=principalMap.getAllMaps().getMapMatrix()[x][y];
    // engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x,y))),1);
    // engine.addCommand(unique_ptr<Command> (new Possibilities(x,y,element)),2);
    // engine.addCommand(unique_ptr<Command> (new PrintStats(x,y,element)),3);
    // usleep(2000000);
    // // choix positions possibles autour de l'unitéswitch
    // std::vector<int> positions;
    // Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[y+25*x].get();
    // int id=unit->getIdUnits();
    // std::vector<std::vector<int>> mapMatrix = principalMap.getAllMaps().getMapMatrix();
    //   if(mapMatrix[x+1][y]==2 || mapMatrix[x+1][y]==9
    //     || (mapMatrix[x+1][y]==26 && verif(principalMap, x+1, y,id, 0))
    //     || (mapMatrix[x+1][y]==27 && verif(principalMap, x+1, y,id, 0))
    //     || (mapMatrix[x+1][y]==28 && verif(principalMap, x+1, y,id, 0))
    //     || (mapMatrix[x+1][y]==29 && verif(principalMap, x+1, y,id, 0))
    //     || (mapMatrix[x+1][y]==10 && verif(principalMap, x+1, y,id, 1))
    //     || (mapMatrix[x+1][y]==14 && verif(principalMap, x+1, y,id, 1))
    //     || (mapMatrix[x+1][y]==18 && verif(principalMap, x+1, y,id, 1))
    //     || (mapMatrix[x+1][y]==22&& verif(principalMap, x+1, y,id, 1))){
    //
    //      positions.push_back(y);
    //      positions.push_back(x+1);
    //   }
    //
    //   if(mapMatrix[x-1][y]==2 || mapMatrix[x-1][y]==9
    //     || (mapMatrix[x-1][y]==26 && verif(principalMap, x-1, y,id, 0))
    //     || (mapMatrix[x-1][y]==27 && verif(principalMap, x-1, y,id, 0))
    //     || (mapMatrix[x-1][y]==28 && verif(principalMap, x-1, y,id, 0))
    //     || (mapMatrix[x-1][y]==29 && verif(principalMap, x-1, y,id, 0))
    //     || (mapMatrix[x-1][y]==10 && verif(principalMap, x-1, y,id, 1))
    //     || (mapMatrix[x-1][y]==14 && verif(principalMap, x-1, y,id, 1))
    //     || (mapMatrix[x-1][y]==16 && verif(principalMap, x-1, y,id, 1))
    //     || (mapMatrix[x-1][y]==22&& verif(principalMap, x-1, y,id, 1))){
    //       positions.push_back(y);
    //       positions.push_back(x-1);
    //   }
    //
    //
    //   if(mapMatrix[x][y+1]==2 || mapMatrix[x][y+1]==9
    //     || (mapMatrix[x][y+1]==26 && verif(principalMap, x, y+1,id, 0))
    //     || (mapMatrix[x][y+1]==27 && verif(principalMap, x, y+1,id, 0))
    //     || (mapMatrix[x][y+1]==28 && verif(principalMap, x, y+1,id, 0))
    //     || (mapMatrix[x][y+1]==29 && verif(principalMap, x, y+1,id, 0))
    //     || (mapMatrix[x][y+1]==10 && verif(principalMap, x, y+1,id, 1))
    //     || (mapMatrix[x][y+1]==14  && verif(principalMap, x, y+1,id, 1))
    //     || (mapMatrix[x][y+1]==18 && verif(principalMap, x, y+1,id, 1))
    //     || (mapMatrix[x][y+1]==22 && verif(principalMap, x, y+1,id, 1))){
    //       positions.push_back(y+1);
    //       positions.push_back(x);
    //   }
    //
    //   if(mapMatrix[x][y-1]==2 || mapMatrix[x][y-1]==9
    //     || (mapMatrix[x][y-1]==26 && verif(principalMap, x, y-1,id, 0))
    //     || (mapMatrix[x][y-1]==27 && verif(principalMap, x, y-1,id, 0))
    //     || (mapMatrix[x][y-1]==28 && verif(principalMap, x, y-1,id, 0))
    //     || (mapMatrix[x][y-1]==29 && verif(principalMap, x, y-1,id, 0))
    //     || (mapMatrix[x][y-1]==10 && verif(principalMap, x, y-1,id, 1))
    //     || (mapMatrix[x][y-1]==14 && verif(principalMap, x, y-1,id, 1))
    //     || (mapMatrix[x][y-1]==18 && verif(principalMap, x, y-1,id, 1))
    //     || (mapMatrix[x][y-1]==22 && verif(principalMap, x, y-1,id, 1))){
    //       positions.push_back(y-1);
    //       positions.push_back(x);
    //   }
    //
    // if (positions.size()>0){
    //   int pos=(rand()%(positions.size()/2))*2;
    //   // si herbe ou unité ou hdv
    //
    //   int y2= positions[pos];
    //   int x2= positions[pos+1];
    //   if (principalMap.getAllMaps().getMapMatrix()[x2][y2]==2){
    //     engine.addCommand((unique_ptr<Command> (new Move(x,y,x2,y2))),6);
    //     counter++;
    //   } else {
    //     engine.addCommand((unique_ptr<Command> (new Attack(x,y,x2,y2))),7);
    //     counter++;
    //     }
    //   } else {
    //     counter++;
    //   }
