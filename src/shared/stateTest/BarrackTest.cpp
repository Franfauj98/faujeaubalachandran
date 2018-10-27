#include "BarrackTest.h"
#include "ArrowTest.h"
#include "CatapultTest.h"
#include "DecurionTest.h"
#include "CavalierTest.h"
using namespace std;
using namespace state;

void BarrackTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST BARRACK" << endl;
  cout << "-------------------------------------" << endl;

  cout << "Default Constructor" << endl;
  Barrack barrack0;
  cout << "Id Building: " << barrack0.getIdBuilding() << endl;
  cout << "Position X: " << barrack0.getPosition().getX() << endl;
  cout << "Position Y: " << barrack0.getPosition().getY() << endl;
  cout << "IdTexture: " << barrack0.getIdTexture() << endl;
  cout << "Wood Cost: " << barrack0.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << barrack0.getBuildingCost().getGold() << endl;
  cout << "Passable?: " << barrack0.isPassable() << endl;
  cout << "Capacity: " << barrack0.getCapacity() << endl;
  cout << "UnitsNumber: " << barrack0.getUnitsNumber() << endl;
  cout << endl;

  cout << "SETTER PARAMETERS IN DEF DOMAIN" << endl;
  BuildingCost buildingCost0(200,150);
  Position pos0(5,10);
  barrack0.setIdBuilding(1);
  barrack0.setPosition(pos0);
  barrack0.setIdTexture(BARRACK);
  barrack0.setBuildingCost(buildingCost0);
  barrack0.isPassable();
  barrack0.setCapacity(10);
  barrack0.setUnitsNumber(8);
  cout << "New Id Building: " << barrack0.getIdBuilding() << endl;
  cout << "New Position X: " << barrack0.getPosition().getX() << endl;
  cout << "New Position Y: " << barrack0.getPosition().getY() << endl;
  cout << "New IdTexture: " << barrack0.getIdTexture() << endl;
  cout << "New Wood Cost: " << barrack0.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << barrack0.getBuildingCost().getGold() << endl;
  cout << "New Passable?: " << barrack0.isPassable() << endl;
  cout << "New Capacity: " << barrack0.getCapacity() << endl;
  cout << "New UnitsNumber: " << barrack0.getUnitsNumber() << endl;
  cout << endl;

  cout << "CONSTRUCTOR WITH 7 ARGUMENTS" << endl;
  BuildingCost barrackCost1(50,50);
  Position position1(2,5);
  Barrack barrack1(10,1, position1,1, barrackCost1);
  cout << "Id Building: " << barrack1.getIdBuilding() << endl;
  cout << "Position X: " << barrack1.getPosition().getX() << endl;
  cout << "Position Y: " << barrack1.getPosition().getY() << endl;
  cout << "IdTexture: " << barrack1.getIdTexture() << endl;
  cout << "Wood Cost: " << barrack1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << barrack1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << barrack1.isPassable() << endl;
  cout << "Capacity: " << barrack1.getCapacity() << endl;
  cout << "UnitsNumber: " << barrack1.getUnitsNumber() << endl;
  cout << endl;

  cout << "SETTER PARAMETERS OUTSIDE OF DEF" << endl;
  BuildingCost barrackCost2(-150,250);
  Position position2(5,-2);
  barrack1.setIdBuilding(-10);
  barrack1.setPosition(position2);
  barrack1.setBuildingCost(barrackCost2);
  barrack1.setCapacity(-10);
  barrack1.setUnitsNumber(-8);
  cout << "New Id Building: " << barrack1.getIdBuilding() << endl;
  cout << "New Position X: " << barrack1.getPosition().getX() << endl;
  cout << "New Position Y: " << barrack1.getPosition().getY() << endl;
  cout << "New Wood Cost: " << barrack1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << barrack1.getBuildingCost().getGold() << endl;
  cout << "New Capacity: " << barrack1.getCapacity() << endl;
  cout << "New UnitsNumber: " << barrack1.getUnitsNumber() << endl;
  cout << endl;


  cout << "CONSTRUCTOR WITH THREE ARGUMENTS" << endl;
  Position position3(20,50);
  Barrack barrack2(1, position3,2);
  cout << "Id Building: " << barrack2.getIdBuilding() << endl;
  cout << "Position X: " << barrack2.getPosition().getX() << endl;
  cout << "Position Y: " << barrack2.getPosition().getY() << endl;
  cout << "IdTexture: " << barrack2.getIdTexture() << endl;
  cout << "Wood Cost: " << barrack2.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << barrack2.getBuildingCost().getGold() << endl;
  cout << "Passable?: " << barrack2.isPassable() << endl;
  cout << "Capacity: " << barrack2.getCapacity() << endl;
  cout << "UnitsNumber: " << barrack2.getUnitsNumber() << endl;
  cout << endl;

  cout << "SETTER PARAMETERS OUTSIDE OF DEF" << endl;
  BuildingCost barrackCost3(15000,100000);
  Position position4(20000,40000);
  barrack2.setIdBuilding(1);
  barrack2.setPosition(position4);
  barrack2.setBuildingCost(barrackCost3);
  barrack2.setCapacity(6);
  barrack2.setUnitsNumber(8);
  cout << "New Id Building: " << barrack2.getIdBuilding() << endl;
  cout << "New Position X: " << barrack2.getPosition().getX() << endl;
  cout << "New Position Y: " << barrack2.getPosition().getY() << endl;
  cout << "New Wood Cost: " << barrack2.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << barrack2.getBuildingCost().getGold() << endl;
  cout << "New Capacity: " << barrack2.getCapacity() << endl;
  cout << "New UnitsNumber: " << barrack2.getUnitsNumber() << endl;
  cout << endl;

  cout << "CONSTRUCTOR WITH 7 NEGATIVE PARAMETERS" << endl;
  Position position5(-20,50);
  Barrack barrack3(5,1, position3,-2,barrackCost3);
  cout << endl;

  cout << "ARROW CREATION" << endl;
  Position posArrow(10,10);
  Arrow* arrow=barrack0.createArrow(1,posArrow,1);
  cout << "Arrow X position:" << arrow->getPosition().getX() << endl;
  cout << "Arrow Y position:" << arrow->getPosition().getY() << endl;
  cout << "Arrow id:" << arrow->getIdUnits() << endl;
  cout << "Arrow level:" << arrow->getLevel() << endl;
  cout << "Arrow life:" << arrow->getLife() << endl;
  cout << endl;

  cout << "CAVALIER CREATION" << endl;
  Position posCavalier(20,20);
  Cavalier* cavalier=barrack0.createCavalier(2,posCavalier,2);
  cout << "Cavalier X position:" << cavalier->getPosition().getX() << endl;
  cout << "Cavalier Y position:" << cavalier->getPosition().getY() << endl;
  cout << "Cavalier id:" << cavalier->getIdUnits() << endl;
  cout << "Cavalier level:" << cavalier->getLevel() << endl;
  cout << "Cavalier life:" << cavalier->getLife() << endl;
  cout << endl;

  cout << "DECURION CREATION" << endl;
  Position posDecurion(30,30);
  Decurion* decurion=barrack0.createDecurion(3,posArrow,3);
  cout << "Decurion X position:" << decurion->getPosition().getX() << endl;
  cout << "Decurion Y position:" << decurion->getPosition().getY() << endl;
  cout << "Decurion id:" << decurion->getIdUnits() << endl;
  cout << "Decurion level:" << decurion->getLevel() << endl;
  cout << "Decurion life:" << decurion->getLife() << endl;
  cout << endl;

  cout << "CATAPULT CREATION" << endl;
  Position posCatapult(40,40);
  Catapult* catapult=barrack0.createCatapult(1,posArrow,1);
  cout << "Catapult X position:" << catapult->getPosition().getX() << endl;
  cout << "Catapult Y position:" << catapult->getPosition().getY() << endl;
  cout << "Catapult id:" << catapult->getIdUnits() << endl;
  cout << "Catapult level:" << catapult->getLevel() << endl;
  cout << "Catapult life:" << catapult->getLife() << endl;
  cout << endl;

  cout << "DESTRUCTIONS" << endl;
  barrack0.destructArrow(arrow);
  barrack0.destructCavalier(cavalier);
  barrack0.destructCatapult(catapult);
  barrack0.destructDecurion(decurion);
  cout << endl;

}
