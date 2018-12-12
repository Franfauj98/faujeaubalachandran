#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;
using namespace std;

void UnitsObserver::changeUnits(Observable& mapToChange,
int position, int action, int position2){
  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }

  int y2 = position2%25;
  int x2=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x2+=1;
    if(i==position2) break;
  }
  Position* pos2 = new Position(x2,y2);
  int unitLife=0;
  Map& map = mapToChange.getAllMaps();
  Units* unitToChange = (Units *)map.getUnitsMap()[position].get();
  Units* unitToChange2 = (Units *)map.getUnitsMap()[position2].get();
  int idUnit=unitToChange2->getIdUnits();
  Buildings* buildingToAttack = (Buildings *)map.getBuildingsMap()[position2].get();
  std::vector<std::vector<int>>& mapMatrix = map.getMapMatrix();
  switch(action){
    case 1: //move
    {
      unitToChange->move(*pos2, 1);
      std::unique_ptr<Element> tmp = std::move(map.getUnitsMap()[position]);
      std::unique_ptr<Element> wideUnit(new Units());
      map.addUnitsToMap(tmp, position2);
      map.addUnitsToMap(wideUnit, position);
      mapMatrix[x][y] = 2;
      mapMatrix[x2][y2] = unitToChange->getType();
      break;
    }
    case 2: //attackUnit
    {
      unitToChange->attack(*unitToChange2);
      if (unitToChange2->getLife()<=unitToChange->getDamage()){
        Units* uni1 = (Units *)map.getUnitsMap()[position2].get();
        Units uni=*(uni1);
        switch(uni.getType()){
          case 10:{
          std::unique_ptr<Units> unitToChange2bis =move(unique_ptr<Units>(new Decurion()));
          *unitToChange2bis= uni;
          std::vector<std::unique_ptr<Units>> re= move(mapToChange.getRessurectionUnits());
          re.push_back(std::move(unitToChange2bis));
          Units* unitToChange3bis = (Units *)re.back().get();
          mapToChange.setRessurectionUnits(re);
          std::vector<int> reId= mapToChange.getRessurectionId();
          reId.push_back(0);
          mapToChange.setRessurectionId(reId);
          break;}
          case 14:{
          std::unique_ptr<Units> unitToChange2bis =move(unique_ptr<Units>(new Arrow()));
          *unitToChange2bis= uni;
          std::vector<std::unique_ptr<Units>> re= move(mapToChange.getRessurectionUnits());
          re.push_back(std::move(unitToChange2bis));
          Units* unitToChange3bis = (Units *)re.back().get();
          mapToChange.setRessurectionUnits(re);
          std::vector<int> reId= mapToChange.getRessurectionId();
          reId.push_back(0);
          mapToChange.setRessurectionId(reId);
          break;}
          case 18:{
          std::unique_ptr<Units> unitToChange2bis =move(unique_ptr<Units>(new Cavalier()));
          *unitToChange2bis= uni;
          std::vector<std::unique_ptr<Units>> re= move(mapToChange.getRessurectionUnits());
          re.push_back(std::move(unitToChange2bis));
          Units* unitToChange3bis = (Units *)re.back().get();
          mapToChange.setRessurectionUnits(re);
          std::vector<int> reId= mapToChange.getRessurectionId();
          reId.push_back(0);
          mapToChange.setRessurectionId(reId);
          break;}
          case 22:{
          std::unique_ptr<Units> unitToChange2bis = move(unique_ptr<Units>(new Catapult()));
          *unitToChange2bis= uni;
          std::vector<std::unique_ptr<Units>> re= move(mapToChange.getRessurectionUnits());
          re.push_back(std::move(unitToChange2bis));
          Units* unitToChange3bis = (Units *)re.back().get();
          mapToChange.setRessurectionUnits(re);
          std::vector<int> reId= mapToChange.getRessurectionId();
          reId.push_back(0);
          mapToChange.setRessurectionId(reId);
          break;}
        }

      }
      if(unitToChange2->getLife()==0){

        map.getUnitsMap()[position2] = std::move(std::unique_ptr<Element> (new Units()));
        mapMatrix[x2][y2] = 2;
        std::vector<int> buildings;

        for (unsigned int i=0;i<map.getBuildingsMap().size();i++){
          Buildings* building = (Buildings*) map.getBuildingsMap()[i].get();
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idUnit){
            buildings.push_back(i);
          }
        }
        Barrack* barrack =(Barrack*) map.getBuildingsMap()[buildings[2]].get();
        barrack->setUnitsNumber(barrack->getUnitsNumber()-1);
        }
        break;
      }

    case 3: //attackBuilding
    {

      unitToChange->attackBuilding(*buildingToAttack);
      if (buildingToAttack->getLife()<=unitToChange->getDamage()){
        Buildings* palace = (Buildings *)map.getBuildingsMap()[position2].get();
        Buildings palace1=*(palace);
        std::unique_ptr<Buildings> palace2 =move(unique_ptr<Buildings>(new Palace()));
        *palace2= palace1;
        Buildings* ressource = (Buildings *)map.getBuildingsMap()[position2-1].get();
        Buildings ressource1=*(ressource);
        std::unique_ptr<Buildings> ressource2 =move(unique_ptr<Buildings>(new Ressource()));
        *ressource2= ressource1;
        Buildings* barrack = (Buildings *)map.getBuildingsMap()[position2+1].get();
        Buildings barrack1=*(barrack);
        std::unique_ptr<Buildings> barrack2 =move(unique_ptr<Buildings>(new Barrack()));
        *barrack2= barrack1;
        std::vector<std::unique_ptr<Buildings>> re= move(mapToChange.getRessurectionPalace());
        re.push_back(std::move(palace2));
        re.push_back(std::move(ressource2));
        re.push_back(std::move(barrack2));
        mapToChange.setRessurectionPalace(re);
        std::vector<int> reId= mapToChange.getRessurectionId();
        reId.push_back(1);
        mapToChange.setRessurectionId(reId);
      }
      if(buildingToAttack->getLife()==0){
        int id=buildingToAttack->getIdBuilding();
        map.getBuildingsMap()[position2] = std::move(std::unique_ptr<Element> (new Buildings()));
        map.getBuildingsMap()[position2+1] = std::move(std::unique_ptr<Element> (new Buildings()));
        map.getBuildingsMap()[position2-1] = std::move(std::unique_ptr<Element> (new Buildings()));
        mapMatrix[x2][y2] = 2;
        mapMatrix[x2][y2+1] = 2;
        mapMatrix[x2][y2-1] = 2;

        // parcourt le tableau pour voir s'il y a des unités et rentre leurs positions
        for (unsigned int i=0;i<map.getUnitsMap().size();i++){
          Units* unit =(Units*) map.getUnitsMap()[i].get();
          int idUnit=unit->getIdUnits();
          if (idUnit==id){
            map.getUnitsMap()[i] = std::move(std::unique_ptr<Element> (new Units()));
          }
        }
      }
      break;
    }
    default: break;
  }
}

void UnitsObserver::changeUnitsPrev(Observable& mapToChange,
int position, int action, int position2){
  int y = position%25;
  int x=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x+=1;
    if(i==position) break;
  }

  int y2 = position2%25;
  int x2=-1;
  for(int i = 0; i < (25*25); i++){
    if(i%25 == 0) x2+=1;
    if(i==position2) break;
  }
  Position* pos2 = new Position(x2,y2);
  Position* pos = new Position(x,y);
  Map& map = mapToChange.getAllMaps();
  Units* unitToChange = (Units *)map.getUnitsMap()[position].get();
  Units* unitToChange2 = (Units *)map.getUnitsMap()[position2].get();


  Buildings* buildingToAttack = (Buildings *)map.getBuildingsMap()[position2].get();
  std::vector<std::vector<int>>& mapMatrix = map.getMapMatrix();
  switch(action){
    case 1: //move
    {
      unitToChange2->move(*pos, 1);
      std::unique_ptr<Element> tmp = std::move(map.getUnitsMap()[position2]);
      std::unique_ptr<Element> wideUnit(new Units());
      map.addUnitsToMap(tmp, position);
      map.addUnitsToMap(wideUnit, position2);
      mapMatrix[x][y] = unitToChange2->getType();
      mapMatrix[x2][y2] = 2;
      break;
    }

    case 2: //attackUnit
    {

      if(unitToChange2->getLife()>0){
        unitToChange2->setLife(unitToChange2->getLife()+unitToChange->getDamage());
      } else if (buildingToAttack->getLife()>0){
        buildingToAttack->setLife(buildingToAttack->getLife()+unitToChange->getDamage());
      }
      else {
        std::vector<int> reId=mapToChange.getRessurectionId();
        if (reId.back()==0){
          std::vector<std::unique_ptr<Units>> re= move(mapToChange.getRessurectionUnits());
          map.getUnitsMap()[position2] = std::move(re.back());
          re.pop_back();
          reId.pop_back();
          mapToChange.setRessurectionUnits(re);
          mapToChange.setRessurectionId(reId);
          mapMatrix[x2][y2] = map.getUnitsMap()[position2]->getType();
          std::vector<int> buildings;
          unitToChange2 = (Units *)map.getUnitsMap()[position2].get();
          int idUnit=unitToChange2->getIdUnits();
          for (unsigned int i=0;i<map.getBuildingsMap().size();i++){
            Buildings* building = (Buildings*) map.getBuildingsMap()[i].get();
            int idBuilding=building->getIdBuilding();
            if (idBuilding==idUnit){
              buildings.push_back(i);
            }
          }
          Barrack* barrack =(Barrack*) map.getBuildingsMap()[buildings[2]].get();
          barrack->setUnitsNumber(barrack->getUnitsNumber()+1);
        }
        else {
          std::vector<std::unique_ptr<Buildings>> re= move(mapToChange.getRessurectionPalace());
          map.getBuildingsMap()[position2+1] = std::move(re.back());
          re.pop_back();
          map.getBuildingsMap()[position2-1] = std::move(re.back());
          re.pop_back();
          map.getBuildingsMap()[position2] = std::move(re.back());
          re.pop_back();
          reId.pop_back();
          mapToChange.setRessurectionPalace(re);
          mapToChange.setRessurectionId(reId);
          mapMatrix[x2][y2] = map.getUnitsMap()[position2]->getType();
          mapMatrix[x2][y2-1] = map.getUnitsMap()[position2-1]->getType();
          mapMatrix[x2][y2+1] = map.getUnitsMap()[position2+1]->getType();
              // int id=buildingToAttack->getIdBuilding();
              //
              // map.getBuildingsMap()[position2+1] = std::move(std::unique_ptr<Element> (new Buildings()));
              // map.getBuildingsMap()[position2-1] = std::move(std::unique_ptr<Element> (new Buildings()));
              // mapMatrix[x2][y2] = 2;
              // mapMatrix[x2][y2+1] = 2;
              // mapMatrix[x2][y2-1] = 2;
              //
              // // parcourt le tableau pour voir s'il y a des unités et rentre leurs positions
              // for (unsigned int i=0;i<map.getUnitsMap().size();i++){
              //   Units* unit =(Units*) map.getUnitsMap()[i].get();
              //   int idUnit=unit->getIdUnits();
              //   if (idUnit==id){
              //     map.getUnitsMap()[i] = std::move(std::unique_ptr<Element> (new Units()));
        }
        }
        break;
      }

    default: break;
  }


}
