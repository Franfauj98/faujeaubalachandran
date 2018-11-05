#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void BuildingsObserver::changeBuildings(std::unique_ptr<Element> buildings,
Observable& mapToChange,
int position, int action, int unitToCreate){
  // std::vector<std::unique_ptr<Element>> const& map = mapToChange.getAllMaps().getBuildingsMap();
  Buildings* build = ((Buildings *) buildings.get());
  std::cout << "BuildingsObserver" << std::endl;
  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }
  std::cout << "posx : " << x << std::endl;
  std::cout << "posy : " << y << std::endl;
  Position* pos1 = new Position(x,y);

  switch(action){

    case 1:
    {
      int level = build->getLevel();
      std::cout << level << std::endl;
      std::cout << "levelUp" << std::endl;
      build->setLevel(++level);
      level = build->getLevel();
      std::cout << level << std::endl;
      break;
    }

    case 2:
    {
      Map& map = mapToChange.getAllMaps();
      // Barrack* barrack = ((Barrack *) build);
      switch (unitToCreate){
        case 1:
        {
          // Arrow* arrow = barrack->createArrow(2, *pos1, 1);
          std::unique_ptr<Element> arrow_ptr(new Arrow(2,*pos1,1));
          // barrack->destructArrow(arrow);
          map.addUnitsToMap(arrow_ptr, position);
          break;
        }
        case 2:
        {
          std::unique_ptr<Element> decurion_ptr(new Decurion(2,*pos1,1));
          map.addUnitsToMap(decurion_ptr, position);
          break;
        }
        case 3:
        {
          std::unique_ptr<Element> catapult_ptr(new Catapult(2,*pos1,1));
          map.addUnitsToMap(catapult_ptr, position);
          break;
        }
        case 4:
        {
          std::unique_ptr<Element> cavalier_ptr(new Cavalier(2,*pos1,1));
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
