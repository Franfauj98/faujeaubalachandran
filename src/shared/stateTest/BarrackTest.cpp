#include "BarrackTest.h"

using namespace std;
using namespace state;

void BarackTest(){



  cout << "-------------------------------------" << endl;
  cout << "TEST BARRACK" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  BuildingCost barrackCost1(50,50);
  Position position1(2,5);
  Barrack barrack1(1, position1,1,BARRACK, barrackCost1);
  cout << "Id Building: " << barrack1.getIdBuilding() << endl;
  cout << "Position X: " << barrack1.getPosition().getX() << endl;
  cout << "Position Y: " << barrack1.getPosition().getY() << endl;
  cout << "IdTexture: " << barrack1.getIdTexture() << endl;
  cout << "Wood Cost: " << barrack1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << barrack1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << barrack1.isPassable() << endl;
  BuildingCost barrackCost2(150,250);
  Position position2(5,2);
  barrack1.setIdBuilding(10);
  barrack1.setPosition(position2);
  barrack1.setBuildingCost(barrackCost2);
  cout << endl;
  cout << "New Id Building: " << barrack1.getIdBuilding() << endl;
  cout << "New Position X: " << barrack1.getPosition().getX() << endl;
  cout << "New Position Y: " << barrack1.getPosition().getY() << endl;
  cout << "New Wood Cost: " << barrack1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << barrack1.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << barrack1.isPassable() << endl;
  cout << endl;
  BuildingCost barrackCost3(-50,150);
  Position position3(-2,5);
  Barrack barrack2 (-1, position3,1,BARRACK, barrackCost3);
  cout << "Id Building: " << barrack2.getIdBuilding() << endl;
  cout << "Position X: " << barrack2.getPosition().getX() << endl;
  cout << "Position Y: " << barrack2.getPosition().getY() << endl;
  cout << "IdTexture: " << barrack2.getIdTexture() << endl;
  cout << "Wood Cost: " << barrack2.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << barrack2.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << barrack2.isPassable() << endl;
  cout << endl;
  BuildingCost barrackCost4(-50,-50);
  Position position4(-5,-2);
  barrack2.setIdBuilding(-10);
  barrack2.setPosition(position4);
  barrack2.setBuildingCost(barrackCost4);
  cout << endl;
  cout << "New Id Building: " << barrack2.getIdBuilding() << endl;
  cout << "New Position X: " << palace2.getPosition().getX() << endl;
  cout << "New Position Y: " << palace2.getPosition().getY() << endl;
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
