#include "BuildingsTest.h"

using namespace std;
using namespace state;

void BuildingsTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDING" << endl;
  cout << "-------------------------------------" << endl;

    cout << "DEFAULT CONSTRUCTOR" << endl;
    Buildings building0;
    cout << "Id Building: " << building0.getIdBuilding() << endl;
    cout << "Position X: " << building0.getPosition().getX() << endl;
    cout << "Position Y: " << building0.getPosition().getY() << endl;
    cout << "IdTexture: " << building0.getIdTexture() << endl;
    cout << "Wood Cost: " << building0.getBuildingCost().getWood() << endl;
    cout << "Gold Cost: " << building0.getBuildingCost().getGold() << endl;
    cout << "Passable ?: " << building0.isPassable() << endl;
    cout << "Life: " << building0.getLife() << endl;
    cout << endl;

    cout << "SETTER WITH ALL PARAMETERS INSIDE OF DEF" << endl;
    Position pos0(50,25);
    BuildingCost buildingCost0(200,100);
    building0.setIdBuilding(10);
    building0.setPosition(pos0);
    building0.setIdTexture(HDV1);
    building0.setBuildingCost(buildingCost0);
    building0.setLife(500);
    cout << "New Id Building: " << building0.getIdBuilding() << endl;
    cout << "New Position X: " << building0.getPosition().getX() << endl;
    cout << "New Position Y: " << building0.getPosition().getY() << endl;
    cout << "New IdTexture: " << building0.getIdTexture() << endl;
    cout << "New Wood Cost: " << building0.getBuildingCost().getWood() << endl;
    cout << "New Gold Cost: " << building0.getBuildingCost().getGold() << endl;
    cout << "New Life: " << building0.getLife() << endl;
    cout << endl;

    cout << "SETTER WITH PARAMETERS OUTSIDE OF DEF" << endl;
    Position pos1(-50,25);
    BuildingCost buildingCost1(200000,-100);
    building0.setIdBuilding(-10);
    building0.setPosition(pos1);
    building0.setIdTexture(HDV1);
    building0.setBuildingCost(buildingCost1);
    building0.setLife(50000);
    cout << endl;

    cout << "CONSTRUCTOR WITH ALL ARGUMENTS" << endl;
    BuildingCost buildingCost2(50,50);
    Position pos2(2,5);
    Buildings building1(1, pos2,1,BARRACK, buildingCost2);
    cout << "Id Building: " << building1.getIdBuilding() << endl;
    cout << "Position X: " << building1.getPosition().getX() << endl;
    cout << "Position Y: " << building1.getPosition().getY() << endl;
    cout << "IdTexture: " << building1.getIdTexture() << endl;
    cout << "Wood Cost: " << building1.getBuildingCost().getWood() << endl;
    cout << "Gold Cost: " << building1.getBuildingCost().getGold() << endl;
    cout << "Passable ?: " << building1.isPassable() << endl;
    cout << "Life: " << building1.getLife() << endl;
    cout << endl;

    cout << "CONSTRUCTOR WITH ARGUMENTS OUTSIDE OF DEF" << endl;
    BuildingCost buildingCost3(50,50000);
    Position pos3(-2,5);
    Buildings building2(1, pos3,1,BARRACK, buildingCost3);
    cout << endl;

}
