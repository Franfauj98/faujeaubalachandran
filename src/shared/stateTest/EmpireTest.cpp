#include "EmpireTest.h"

using namespace std;
using namespace state;

void EmpireTest(){



  cout << "-------------------------------------" << endl;
  cout << "TEST EMPIRE" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR PAR DEFAUT" << endl;
  Empire empire0;
  cout << "idEmpire: " << empire0.getId() << endl;
  cout << "Name: " << empire0.getName() << endl;
  cout << "EmpireLevel: " << empire0.getEmpireLevel() << endl;
  cout << "GoldRessource: " << empire0.getGoldRessource() << endl;
  cout << "WoodRessource: " << empire0.getWoodRessource() << endl;
  cout << "FoodRessource: " << empire0.getFoodRessource() << endl;
  std::vector<Position> pos=empire0.getPosition();
  for (unsigned int i=0;i<pos.size();i++ ){
    cout << "Position X: " << pos[i].getX() << endl;
    cout << "Position Y: " << pos[i].getY() << endl;
  }

  cout << endl;

//     cout << "SETTER AVEC PARAMETRES DANS LE DOMAINE DE DEF" << endl;
//     Position pos0(50,25);
//     BuildingCost buildingCost0(200,100);
//     building0.setIdBuilding(10);
//     building0.setPosition(pos0);
//     building0.setIdTexture(HDV1);
//     building0.setBuildingCost(buildingCost0);
//     building0.setLife(500);
//     cout << "New Id Building: " << building0.getIdBuilding() << endl;
//     cout << "New Position X: " << building0.getPosition().getX() << endl;
//     cout << "New Position Y: " << building0.getPosition().getY() << endl;
//     cout << "New IdTexture: " << building0.getIdTexture() << endl;
//     cout << "New Wood Cost: " << building0.getBuildingCost().getWood() << endl;
//     cout << "New Gold Cost: " << building0.getBuildingCost().getGold() << endl;
//     cout << "New Life: " << building0.getLife() << endl;
//     cout << endl;
//
//     cout << "SETTER AVEC PARAMETRES HORS DOMAINE DE DEF" << endl;
//     Position pos1(-50,25);
//     BuildingCost buildingCost1(200000,-100);
//     building0.setIdBuilding(-10);
//     building0.setPosition(pos1);
//     building0.setIdTexture(HDV1);
//     building0.setBuildingCost(buildingCost1);
//     building0.setLife(50000);
//     cout << endl;
//
//     cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
//     BuildingCost buildingCost2(50,50);
//     Position pos2(2,5);
//     Buildings building1(1, pos2,1,BARRACK, buildingCost2);
//     cout << "Id Building: " << building1.getIdBuilding() << endl;
//     cout << "Position X: " << building1.getPosition().getX() << endl;
//     cout << "Position Y: " << building1.getPosition().getY() << endl;
//     cout << "IdTexture: " << building1.getIdTexture() << endl;
//     cout << "Wood Cost: " << building1.getBuildingCost().getWood() << endl;
//     cout << "Gold Cost: " << building1.getBuildingCost().getGold() << endl;
//     cout << "Passable ?: " << building1.isPassable() << endl;
//     cout << "Life: " << building1.getLife() << endl;
//     cout << endl;
//
//     cout << "CONSTRUCTEUR AVEC ARGUMENTS HORS DOMAINE DE DEF" << endl;
//     BuildingCost buildingCost3(50,50000);
//     Position pos3(-2,5);
//     Buildings building2(1, pos3,1,BARRACK, buildingCost3);
//     cout << endl;
//
//
}
