#include "PalaceTest.h"

using namespace std;
using namespace state;

void PalaceTest(){



  cout << "-------------------------------------" << endl;
  cout << "TEST PALACE" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR PAR DEFAUT" << endl;
  Palace palace0;
  cout << "Id Building: " << palace0.getIdBuilding() << endl;
  cout << "Position X: " << palace0.getPosition().getX() << endl;
  cout << "Position Y: " << palace0.getPosition().getY() << endl;
  cout << "IdTexture: " << palace0.getIdTexture() << endl;
  cout << "Wood Cost: " << palace0.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace0.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace0.isPassable() << endl;
  cout << "Level: " << palace0.getLevel() << endl;
  cout << "Life: " << palace0.getLife() << endl;


  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS DANS DOMAINE DEF" << endl;
  BuildingCost palaceCost1(50,50);
  Position position1(2,5);
  Palace palace1(1, position1,1, palaceCost1,HDV1,200);
  cout << "Id Building: " << palace1.getIdBuilding() << endl;
  cout << "Position X: " << palace1.getPosition().getX() << endl;
  cout << "Position Y: " << palace1.getPosition().getY() << endl;
  cout << "IdTexture: " << palace1.getIdTexture() << endl;
  cout << "Wood Cost: " << palace1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace1.isPassable() << endl;
  cout << "Level: " << palace1.getLevel() << endl;
  cout << "Life: " << palace1.getLife() << endl;

  cout << "SETTER AVEC TOUS LES ARGUMENTS DANS DOMAINE DEF" << endl;
  BuildingCost palaceCost2(150,250);
  Position position2(5,2);
  palace1.setIdBuilding(10);
  palace1.setPosition(position2);
  palace1.setIdTexture(HDV2);
  palace1.setBuildingCost(palaceCost2);
  palace1.setLife(500);
  palace1.setLevel(4);
  cout << endl;
  cout << "New Id Building: " << palace1.getIdBuilding() << endl;
  cout << "New Position X: " << palace1.getPosition().getX() << endl;
  cout << "New Position Y: " << palace1.getPosition().getY() << endl;
  cout << "New IdTexture: " << palace1.getIdTexture() << endl;
  cout << "New Wood Cost: " << palace1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << palace1.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << palace1.isPassable() << endl;
  cout << "Level: " << palace1.getLevel() << endl;
  cout << "Life: " << palace1.getLife() << endl;
  cout << endl;

  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS HORS DOMAINE DEF" << endl;
  BuildingCost palaceCost3(-50,150);
  Position position3(-2,5);
  Buildings palace2 (-1, position3,1,HDV2, palaceCost3);
  cout << "Id Building: " << palace2.getIdBuilding() << endl;
  cout << "Position X: " << palace2.getPosition().getX() << endl;
  cout << "Position Y: " << palace2.getPosition().getY() << endl;
  cout << "IdTexture: " << palace2.getIdTexture() << endl;
  cout << "Wood Cost: " << palace2.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << palace2.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << palace2.isPassable() << endl;
  cout << "Level: " << palace2.getLevel() << endl;
  cout << "Life: " << palace2.getLife() << endl;
  cout << endl;

  cout << "SETTERS AVEC TOUS LES ARGUMENTS HORS DOMAINE DEF" << endl;
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
  cout << "Level: " << palace3.getLevel() << endl;
  cout << "Life: " << palace3.getLife() << endl;
  cout << endl;


}
