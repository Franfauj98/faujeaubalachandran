#include "BuildingsTest.h"

using namespace std;
using namespace state;

void BuildingsTest(){



  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDING" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  BuildingCost buildingCost1(50,50);
  Position position1(2,5);
  Buildings building1 (1, position1,1,BARRACK, buildingCost1);
  cout << "Id Building: " << building1.getIdBuilding() << endl;
  cout << "Position X: " << building1.getPosition().getX() << endl;
  cout << "Position Y: " << building1.getPosition().getY() << endl;
  cout << "IdTexture: " << building1.getIdTexture() << endl;
  cout << "Wood Cost: " << building1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << building1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << building1.isPassable() << endl;
  BuildingCost buildingCost2(150,250);
  Position position2(5,2);
  building1.setIdBuilding(10);
  building1.setPosition(position2);
  building1.setIdTexture(HDV1);
  building1.setBuildingCost(buildingCost2);
  cout << endl;
  cout << "New Id Building: " << building1.getIdBuilding() << endl;
  cout << "New Position X: " << building1.getPosition().getX() << endl;
  cout << "New Position Y: " << building1.getPosition().getY() << endl;
  cout << "New IdTexture: " << building1.getIdTexture() << endl;
  cout << "New Wood Cost: " << building1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << building1.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << building1.isPassable() << endl;
  cout << endl;
  BuildingCost buildingCost3(-50,150);
  Position position3(-2,5);
  Buildings building3 (-1, position3,1,BARRACK, buildingCost3);
  cout << "Id Building: " << building1.getIdBuilding() << endl;
  cout << "Position X: " << building1.getPosition().getX() << endl;
  cout << "Position Y: " << building1.getPosition().getY() << endl;
  cout << "IdTexture: " << building1.getIdTexture() << endl;
  cout << "Wood Cost: " << building1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << building1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << building1.isPassable() << endl;
  cout << endl;
  BuildingCost buildingCost4(-50,-50);
  Position position4(-5,-2);
  building1.setIdBuilding(-10);
  building1.setPosition(position4);
  building1.setIdTexture(HDV1);
  building1.setBuildingCost(buildingCost4);
  cout << endl;
  cout << "New Id Building: " << building1.getIdBuilding() << endl;
  cout << "New Position X: " << building1.getPosition().getX() << endl;
  cout << "New Position Y: " << building1.getPosition().getY() << endl;
  cout << "New IdTexture: " << building1.getIdTexture() << endl;
  cout << "New Wood Cost: " << building1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << building1.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << building1.isPassable() << endl;

}
