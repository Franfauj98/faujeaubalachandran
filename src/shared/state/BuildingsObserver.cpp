#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void BuildingsObserver::changeBuildings(Observable& mapToChange,
int position, int action, int unitToCreate, int position2){
  Map& map = mapToChange.getAllMaps();
  Buildings* build = (Buildings *)map.getBuildingsMap()[position].get();
  std::cout << "BuildingsObserver" << std::endl;
  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }
  Position* pos1 = new Position(x,y);
  int level = build->getLevel();

  switch(action){

    case 1:
    {
      std::cout << level << std::endl;
      std::cout << "levelUp" << std::endl;
      build->setLevel(++level);
      level = build->getLevel();
      std::cout << level << std::endl;
      break;
    }

    case 2:
    {
      switch (unitToCreate){
        case 1:
        {
          // std::unique_ptr<Element> arrow_ptr = barrack->createArrow(2, *pos1, 1);
          std::unique_ptr<Element> arrow_ptr(new Arrow(level,*pos1,1));
          // barrack->destructArrow(arrow);
          map.addUnitsToMap(arrow_ptr, position);
          break;
        }
        case 2:
        {
          std::unique_ptr<Element> decurion_ptr(new Decurion(level,*pos1,1));
          map.addUnitsToMap(decurion_ptr, position);
          break;
        }
        case 3:
        {
          std::unique_ptr<Element> catapult_ptr(new Catapult(level,*pos1,1));
          map.addUnitsToMap(catapult_ptr, position);
          break;
        }
        case 4:
        {
          std::unique_ptr<Element> cavalier_ptr(new Cavalier(level,*pos1,1));
          map.addUnitsToMap(cavalier_ptr, position);
          break;
        }
        default: break;
      }
      break;
    }

    default:
    break;
  }

}
