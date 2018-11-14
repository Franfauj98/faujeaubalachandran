#include "RandomAI.h"
#include "../engine.h"
#include "../state.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace ai;
using namespace engine;
using namespace state;
using namespace std;

RandomAI::RandomAI (){}

void RandomAI::run (engine::Engine& engine, Observable& principalMap, int& counter, bool& canPlay, int id){
  if(canPlay){
    srand(time(NULL));
    int elementChoice=0;
    std::vector<int> units;
    // parcourt le tableau pour voir s'il y a des unités et rentre kleurs positions
    for (unsigned int i=0;i<principalMap.getAllMaps().getUnitsMapId().size();i++){
      if (principalMap.getAllMaps().getUnitsMapId()[i]==id){
        units.push_back(i);
      }
    }

    // rentre les positions des batiments
    std::vector<int> buildings;
    for (unsigned int i=0;i<principalMap.getAllMaps().getBuildingsMapId().size();i++){
      if (principalMap.getAllMaps().getBuildingsMapId()[i]==id){
        buildings.push_back(i);
      }
    }
    // s'il y a des unités on choisit entre 0 et 1
    if (units.size()>0){
      elementChoice=rand() % 2+1;
    } else {
      elementChoice=1;
    }

    // choix des bâtiments
    if (elementChoice==1){
      // on choisit le batiment
      int buildingChoice=rand() % (3);
      // on récupère ses coordonnées
      int y = buildings[buildingChoice]%25;
      int x=-1;
      for(int i = 0; i < (25*25); i++){
        if(i%25 == 0) x+=1;
        if(i==buildings[buildingChoice]) break;
      }
      std::cout << x << '\n';
      std::cout << y << '\n';
      // on fait les troix commandes
      int element=principalMap.getAllMaps().getMapMatrix()[x][y];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x,y))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x,y,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x,y,element)),3);
      usleep(3000000);

      // si c'est une caserne
      if (buildingChoice==2){
        // on choisit une commande parmi ()
        switch (rand() % 5){
          case 0:{
            // on prend des positions autour de caserne et on tire au sort une qui a de l'herbe
          std::vector<int> positions={y+25*(x+1),y+1+25*(x+1),y+1+25*x,y+1+25*(x-1),y+25*(x-1)};
          int pos=0;
          while (principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=2 && pos<5){
            pos +=1;
          }
          int y2= positions[pos]%25;
          int x2=-1;
          for(int i = 0; i < (25*25); i++){
            if(i%25 == 0) x2+=1;
            if(i==positions[pos]) break;
          }
          std::cout << x << '\n';
          std::cout << y << '\n';
          std::cout << x2 << '\n';
          std::cout << y2 << '\n';
          std::cout << "creatuUnit" << '\n';
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x,y,x2,y2,1))),4);
          counter++;
          break;
        }
          case 1:{
          std::vector<int> positions={y+25*(x+1),y+1+25*(x+1),y+1+25*x,y+1+25*(x-1),y+25*(x-1)};
          int pos=0;
          while (principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=2 && pos<5){
            pos +=1;
          }
          int y2= positions[pos]%25;
          int x2=-1;
          for(int i = 0; i < (25*25); i++){
            if(i%25 == 0) x2+=1;
            if(i==positions[pos]) break;
          }
          std::cout << x << '\n';
          std::cout << y << '\n';
          std::cout << x2 << '\n';
          std::cout << y2 << '\n';
          std::cout << "creatuUnit" << '\n';
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x,y,x2,y2,2))),4);
          counter++;
          break;
        }
          case 2:{
          std::vector<int> positions={y+25*(x+1),y+1+25*(x+1),y+1+25*x,y+1+25*(x-1),y+25*(x-1)};
          int pos=0;
          while (principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=2 && pos<5){
            pos +=1;
          }
          int y2= positions[pos]%25;
          int x2=-1;
          for(int i = 0; i < (25*25); i++){
            if(i%25 == 0) x2+=1;
            if(i==positions[pos]) break;
          }
          std::cout << x << '\n';
          std::cout << y << '\n';
          std::cout << x2 << '\n';
          std::cout << y2 << '\n';
          std::cout << "creatuUnit" << '\n';
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x,y,x2,y2,3))),4);
          counter++;
          break;
        }
          case 3:{
          std::vector<int> positions={y+25*(x+1),y+1+25*(x+1),y+1+25*x,y+1+25*(x-1),y+25*(x-1)};
          int pos=0;
          while (principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=2 && pos<5){
            pos +=1;
          }
          int y2= positions[pos]%25;
          int x2=-1;
          for(int i = 0; i < (25*25); i++){
            if(i%25 == 0) x2+=1;
            if(i==positions[pos]) break;
          }
          std::cout << x << '\n';
          std::cout << y << '\n';
          std::cout << x2 << '\n';
          std::cout << y2 << '\n';
          std::cout << "creatuUnit" << '\n';
          engine.addCommand((unique_ptr<Command> (new CreateUnit(x,y,x2,y2,4))),4);
          counter++;
          break;
        }
          case 4:
          std::cout << "Levelup" << '\n';
          engine.addCommand((unique_ptr<Command> (new LevelUp(x,y))),5);
          counter++;
          break;
          default:
          break;
        }
        // si hdv ou ressource on levelUp
      }else{
        std::cout << "levelUp" << '\n';
        engine.addCommand((unique_ptr<Command> (new LevelUp(x,y))),5);
        counter++;
      }
 // si unités
    } else {
      // choix de l'unité
      int unitChoice=rand() % (units.size());
      int y = units[unitChoice]%25;
      int x=-1;
      for(int i = 0; i < (25*25); i++){
        if(i%25 == 0) x+=1;
        if(i==units[unitChoice]) break;
      }
      int element=principalMap.getAllMaps().getMapMatrix()[x][y];
      engine.addCommand((unique_ptr<Command> (new CaseIdentifier(x,y))),1);
      engine.addCommand(unique_ptr<Command> (new Possibilities(x,y,element)),2);
      engine.addCommand(unique_ptr<Command> (new PrintStats(x,y,element)),3);
      usleep(3000000);
      // choix positions possibles autour de l'unitéswitch
      std::vector<int> positions={y+25*(x+1),y+1+25*x,y-1+25*x,y+25*(x-1)};
      int pos=0;
      // si herbe ou unité ou hdv
      while ((principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=2
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=10
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=14
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=18
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=22
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=26
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=27
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=28
      || principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]!=29)
      && pos<4){
        pos +=1;
      }
      int y2= positions[pos]%25;
      int x2=-1;
      for(int i = 0; i < (25*25); i++){
        if(i%25 == 0) x2+=1;
        if(i==positions[pos]) break;
      }
      if (principalMap.getAllMaps().getBuildingsMapId()[positions[pos]]==2){
        std::cout << "move" << '\n';
        engine.addCommand((unique_ptr<Command> (new Move(x,y,x2,y2))),6);
        counter++;
      }
      else{
        std::cout << "Attack" << '\n';
        engine.addCommand((unique_ptr<Command> (new Attack(x,y,x2,y2))),7);
        counter++;
      }
    }


  }

}
