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

  int y2 = position2%25;
  int x2=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x2+=1;
    if(i==position2) break;
  }
  Position* pos2 = new Position(x2,y2);

  int level = build->getLevel();

  switch(action){

    case 1:
    {
      build->setLevel(++level);
      level = build->getLevel();
      std::cout<< "Type" <<std::endl;
      std::cout<< build->getIdTexture() <<std::endl;
      switch(build->getIdTexture()){
        case 1: {
          build->setIdTexture(IdTexture::HDV2);
          break;
        }
        case 2: {
          build->setIdTexture(IdTexture::HDV3);
          break;
        }
        case 3: {
          build->setIdTexture(IdTexture::HDV4);
          break;
        }
        default: {
          break;
        }
      }
      break;
    }

    case 2:
    {
        Barrack* barrack = (Barrack *)map.getBuildingsMap()[position].get();
        int barrackid = map.getBuildingsMapId()[position];
        int unitsNumber = barrack->getUnitsNumber();
        unitsNumber++;
        std::cout<< "UnitsNumber"<<std::endl;
        std::cout<< unitsNumber <<std::endl;
        std::cout<< "barrackid " << barrackid <<std::endl;
        std::cout<< "barrack->getIdTexture() " << barrack->getIdTexture() <<std::endl;
        std::cout<< "barrack->getCapacity() " << barrack->getCapacity() <<std::endl;
        if(unitsNumber <= barrack->getCapacity()){
          std::cout<< "coucou"<<std::endl;
          barrack->setUnitsNumber(unitsNumber);
          switch (unitToCreate){
            case 1:
            {
              // std::unique_ptr<Element> arrow_ptr = barrack->createArrow(2, *pos1, 1);
              std::unique_ptr<Element> arrow_ptr(new Arrow(level,*pos2,1));
              // barrack->destructArrow(arrow);
              map.addUnitsToMap(arrow_ptr, position2);
              map.getMapMatrix()[x][y] = 14;
              break;
            }
            case 2:
            {
              std::unique_ptr<Element> decurion_ptr(new Decurion(level,*pos2,1));
              map.addUnitsToMap(decurion_ptr, position2);
              map.getMapMatrix()[x][y] = 10;
              break;
            }
            case 3:
            {
              std::unique_ptr<Element> catapult_ptr(new Catapult(level,*pos2,1));
              map.addUnitsToMap(catapult_ptr, position2);
              map.getMapMatrix()[x][y] = 22;
              break;
            }
            case 4:
            {
              std::unique_ptr<Element> cavalier_ptr(new Cavalier(level,*pos2,1));
              map.addUnitsToMap(cavalier_ptr, position2);
              map.getMapMatrix()[x][y] = 18;
              break;
            }
            default: break;
          }

      }
      break;
    }

    default:
    break;
  }

}
