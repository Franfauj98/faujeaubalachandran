#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;
using namespace std;

void BuildingsObserver::changeBuildings(Observable& mapToChange,
int position, int action, int unitToCreate, int position2){
  Map& map = mapToChange.getAllMaps();
  Buildings* build = (Buildings *)map.getBuildingsMap()[position].get();
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
        int unitsNumber = barrack->getUnitsNumber();
        unitsNumber++;
        if(unitsNumber <= barrack->getCapacity()){
          barrack->setUnitsNumber(unitsNumber);
          switch (unitToCreate){
            case 1:
            {
              std::unique_ptr<Element> arrow_ptr(new Arrow(level,*pos2,barrack->getIdBuilding()));
              map.addUnitsToMap(arrow_ptr, position2);
              map.getMapMatrix()[x2][y2] = 14;
              Units* currentUnit = (Units*) map.getUnitsMap()[x2*25 + y2].get();
              std::vector<state::Position> unitPos;
              Position pos0(0,0);
              Position pos(x2,y2);
              unitPos.push_back(pos0);
              unitPos.push_back(pos0);
              unitPos.push_back(pos);
              currentUnit->setCanMove(unitPos);
              break;
            }
            case 2:
            {
              std::unique_ptr<Element> decurion_ptr(new Decurion(level,*pos2,barrack->getIdBuilding()));
              map.addUnitsToMap(decurion_ptr, position2);
              map.getMapMatrix()[x2][y2] = 10;
              Units* currentUnit = (Units*) map.getUnitsMap()[x2*25 + y2].get();
              std::vector<state::Position> unitPos;
              Position pos0(0,0);
              Position pos(x2,y2);
              unitPos.push_back(pos0);
              unitPos.push_back(pos0);
              unitPos.push_back(pos);
              currentUnit->setCanMove(unitPos);
              break;
            }
            case 3:
            {
              std::unique_ptr<Element> catapult_ptr(new Catapult(level,*pos2,barrack->getIdBuilding()));
              map.addUnitsToMap(catapult_ptr, position2);
              map.getMapMatrix()[x2][y2] = 22;
              Units* currentUnit = (Units*) map.getUnitsMap()[x2*25 + y2].get();
              std::vector<state::Position> unitPos;
              Position pos0(0,0);
              Position pos(x2,y2);
              unitPos.push_back(pos0);
              unitPos.push_back(pos0);
              unitPos.push_back(pos);
              currentUnit->setCanMove(unitPos);
              break;
            }
            case 4:
            {
              std::unique_ptr<Element> cavalier_ptr(new Cavalier(level,*pos2,barrack->getIdBuilding()));
              map.addUnitsToMap(cavalier_ptr, position2);
              map.getMapMatrix()[x2][y2] = 18;
              Units* currentUnit = (Units*) map.getUnitsMap()[x2*25 + y2].get();
              std::vector<state::Position> unitPos;
              Position pos0(0,0);
              Position pos(x2,y2);
              unitPos.push_back(pos0);
              unitPos.push_back(pos0);
              unitPos.push_back(pos);
              currentUnit->setCanMove(unitPos);
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
