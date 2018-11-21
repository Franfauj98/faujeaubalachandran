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

void HeuristicAI::run (engine::Engine& engine, Observable& principalMap, int& counter, bool& canPlay, int id){
  if(canPlay){
    srand(time(NULL));
    std::vector<int> buildings;
    for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMap().size();i++){
        Buildings* building =(Buildings*) principalMap.getAllMaps().getBuildingsMap()[i].get();
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

    int y1 = buildings[0]%25;
    int x1=-1;
    for(int i = 0; i < (25*25); i++){
      if(i%25 == 0) x1+=1;
      if(i==buildings[0]) break;
    }
    int y2 = buildings[1]%25;
    int x2=-1;
    for(int i = 0; i < (25*25); i++){
      if(i%25 == 0) x2+=1;
      if(i==buildings[1]) break;
    }
    int y3 = buildings[2]%25;
    int x3=-1;
    for(int i = 0; i < (25*25); i++){
      if(i%25 == 0) x3+=1;
      if(i==buildings[2]) break;
    }
    Ressource* ressource =(Ressource*) principalMap.getAllMaps().getBuildingsMap()[y1+25*x1].get();
    Palace* palace =(Palace*) principalMap.getAllMaps().getBuildingsMap()[y2+25*x2].get();
    Barrack* barrack =(Barrack*) principalMap.getAllMaps().getBuildingsMap()[y3+25*x3].get();
    int element;
    if(palace->getLevel()<4 && palace->getBuildingCost().getWood()<empire->getWoodRessource() && palace->getBuildingCost().getGold()<empire->getGoldRessource()){
      element=principalMap.getAllMaps().getMapMatrix()[x2][y2];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x2,y2))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x2,y2,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x2,y2,element)),3);
      usleep(2000000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x2,y2))),5);
      counter++;
      return;
    }
    else if(barrack->getLevel()<4 && barrack->getBuildingCost().getWood()<empire->getWoodRessource() && barrack->getBuildingCost().getGold()<empire->getGoldRessource()){
      int element=principalMap.getAllMaps().getMapMatrix()[x3][y3];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x3,y3))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x3,y3,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x2,y3,element)),3);
      usleep(2000000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x3,y3))),5);
      counter++;
      return;
    }
    else if(ressource->getLevel()<4 && ressource->getBuildingCost().getWood()<empire->getWoodRessource() && ressource->getBuildingCost().getGold()<empire->getGoldRessource()){
      int element=principalMap.getAllMaps().getMapMatrix()[x1][y1];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x1,y1))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x1,y1,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x1,y1,element)),3);
      usleep(2000000);
      engine.addCommand((unique_ptr<Command> (new LevelUp(x1,y1))),5);
      counter++;
      return;
    }
    else if (barrack->getUnitsNumber()<barrack->getCapacity()){
      Position pos0(0,0);
      Arrow arrow(1,pos0,0);
      Decurion decurion(1,pos0,0);
      Catapult catapult(1,pos0,0);
      Cavalier cavalier(1,pos0,0);

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
            counter++;
            return;
          }
          break;
        case 2:
          if(decurion.getUnitCost().getFood()<empire->getFoodRessource() && decurion.getUnitCost().getGold()<empire->getGoldRessource()){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,2))),4);
            counter++;
            return;
          }
          break;
        case 3:
          if(cavalier.getUnitCost().getFood()<empire->getFoodRessource() && cavalier.getUnitCost().getGold()<empire->getGoldRessource()){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,4))),4);
            counter++;
            return;
          }
          break;
        case 4:
          if(catapult.getUnitCost().getFood()<empire->getFoodRessource() && catapult.getUnitCost().getGold()<empire->getGoldRessource()){
            engine.addCommand((unique_ptr<Command> (new CreateUnit(x3,y3,x,y,3))),4);
            counter++;
            return;
          }
          break;
        }
    }
  }
}

    // std::vector<int> units;
    // // parcourt le tableau pour voir s'il y a des unités et rentre kleurs positions
    // for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMap().size();i++){
    //   Units* unit =(Units*) principalMap.getAllMaps().getUnitsMap()[i].get();
    //   int idUnit=unit->getIdUnits();
    //   if (idUnit==id){
    //     units.push_back(i);
    //   }
    // }
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
