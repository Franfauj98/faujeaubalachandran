#include "PalaceTest.h"

using namespace std;
using namespace state;

void PalaceTest(){



  cout << "-------------------------------------" << endl;
  cout << "TEST PALACE" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  BuildingCost palaceCost1(50,50);
  Position position1(2,5);
  Palace palace1(1, position1,1,HDV1, palaceCost1);
  cout << "Id Building: " << palace1.getIdBuilding() << endl;
  cout << "Position X: " << palace1.getPosition().getX() << endl;
  cout << "Position Y: " << palace1.getPosition().getY() << endl;
  cout << "IdTexture: " << palace1.getIdTexture() << endl;
  cout << "Wood Cost: " << palace1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace1.isPassable() << endl;
  BuildingCost palaceCost2(150,250);
  Position position2(5,2);
  palace1.setIdBuilding(10);
  palace1.setPosition(position2);
  palace1.setIdTexture(HDV2);
  palace1.setBuildingCost(palaceCost2);
  cout << endl;
  cout << "New Id Building: " << palace1.getIdBuilding() << endl;
  cout << "New Position X: " << palace1.getPosition().getX() << endl;
  cout << "New Position Y: " << palace1.getPosition().getY() << endl;
  cout << "New IdTexture: " << palace1.getIdTexture() << endl;
  cout << "New Wood Cost: " << palace1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << palace1.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << palace1.isPassable() << endl;
  cout << endl;
  BuildingCost palaceCost3(-50,150);
  Position position3(-2,5);
  Buildings palace2 (-1, position3,1,BARRACK, palaceCost3);
  cout << "Id Building: " << palace2.getIdBuilding() << endl;
  cout << "Position X: " << palace2.getPosition().getX() << endl;
  cout << "Position Y: " << palace2.getPosition().getY() << endl;
  cout << "IdTexture: " << palace2.getIdTexture() << endl;
  cout << "Wood Cost: " << palace2.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace2.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace2.isPassable() << endl;
  cout << endl;
  BuildingCost palaceCost4(-50,-50);
  Position position4(-5,-2);
  palace2.setIdBuilding(-10);
  palace2.setPosition(position4);
  palace2.setIdTexture(HDV3);
  palace2.setBuildingCost(palaceCost4);
  cout << endl;
  cout << "New Id Building: " << palace2.getIdBuilding() << endl;
  cout << "New Position X: " << palace2.getPosition().getX() << endl;
  cout << "New Position Y: " << palace2.getPosition().getY() << endl;
  cout << "New IdTexture: " << palace2.getIdTexture() << endl;
  cout << "New Wood Cost: " << palace2.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << palace2.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << palace2.isPassable() << endl;
  cout << endl;

  cout << "CONSTRUCTEUR AVEC TROIS ARGUMENTS" << endl;
  Position position5(20,50);
  Palace palace3(1, position5,2);
  cout << "Id Building: " << palace3.getIdBuilding() << endl;
  cout << "Position X: " << palace3.getPosition().getX() << endl;
  cout << "Position Y: " << palace3.getPosition().getY() << endl;
  cout << "IdTexture: " << palace3.getIdTexture() << endl;
  cout << "Wood Cost: " << palace3.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace3.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace3.isPassable() << endl;
  cout << endl;
  Position position6(-20,50);
  Palace palace4(-10, position6,-25);
  cout << "Id Building: " << palace4.getIdBuilding() << endl;
  cout << "Position X: " << palace4.getPosition().getX() << endl;
  cout << "Position Y: " << palace4.getPosition().getY() << endl;
  cout << "IdTexture: " << palace4.getIdTexture() << endl;
  cout << "Wood Cost: " << palace4.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace4.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace4.isPassable() << endl;
  cout << endl;

}
