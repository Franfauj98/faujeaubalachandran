#include "RessourceTest.h"

using namespace std;
using namespace state;

void RessourceTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST RESSOURCE" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR PAR DEFAUT" << endl;
  Ressource ressource0;
  cout << "Id Building: " << ressource0.getIdBuilding() << endl;
  cout << "Position X: " << ressource0.getPosition().getX() << endl;
  cout << "Position Y: " << ressource0.getPosition().getY() << endl;
  cout << "IdTexture: " << ressource0.getIdTexture() << endl;
  cout << "Wood Cost: " << ressource0.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << ressource0.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << ressource0.isPassable() << endl;
  cout << "Level: " << ressource0.getLevel() << endl;
  cout << "Life: " << ressource0.getLife() << endl;
  cout << "Production: " << ressource0.getProduction() << endl;


  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS DANS DOMAINE DEF" << endl;
  BuildingCost ressourceCost1(50,50);
  Position position1(2,5);
  Ressource ressource1(5,1, position1,1, ressourceCost1,RESSOURCE);
  cout << "Id Building: " << ressource1.getIdBuilding() << endl;
  cout << "Position X: " << ressource1.getPosition().getX() << endl;
  cout << "Position Y: " << ressource1.getPosition().getY() << endl;
  cout << "IdTexture: " << ressource1.getIdTexture() << endl;
  cout << "Wood Cost: " << ressource1.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << ressource1.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << ressource1.isPassable() << endl;
  cout << "Level: " << ressource1.getLevel() << endl;
  cout << "Life: " << ressource1.getLife() << endl;
  cout << "Production: " << ressource1.getProduction() << endl;

  cout << "SETTER AVEC TOUS LES ARGUMENTS DANS DOMAINE DEF" << endl;
  BuildingCost ressourceCost2(150,250);
  Position position2(5,2);
  ressource1.setIdBuilding(10);
  ressource1.setPosition(position2);
  ressource1.setIdTexture(RESSOURCE);
  ressource1.setBuildingCost(ressourceCost2);
  ressource1.setLife(500);
  ressource1.setLevel(4);
  ressource1.setProduction(5);
  cout << endl;
  cout << "New Id Building: " << ressource1.getIdBuilding() << endl;
  cout << "New Position X: " << ressource1.getPosition().getX() << endl;
  cout << "New Position Y: " << ressource1.getPosition().getY() << endl;
  cout << "New IdTexture: " << ressource1.getIdTexture() << endl;
  cout << "New Wood Cost: " << ressource1.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << ressource1.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << ressource1.isPassable() << endl;
  cout << "Level: " << ressource1.getLevel() << endl;
  cout << "Life: " << ressource1.getLife() << endl;
  cout << "Production: " << ressource1.getProduction() << endl;
  cout << endl;

  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS HORS DOMAINE DEF" << endl;
  BuildingCost ressourceCost3(-50,150);
  Position position3(-2,5);
  Ressource ressource2(5000,-1, position3,1,ressourceCost3,RESSOURCE);
  cout << "Id Building: " << ressource2.getIdBuilding() << endl;
  cout << "Position X: " << ressource2.getPosition().getX() << endl;
  cout << "Position Y: " << ressource2.getPosition().getY() << endl;
  cout << "IdTexture: " << ressource2.getIdTexture() << endl;
  cout << "Wood Cost: " << ressource2.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << ressource2.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << ressource2.isPassable() << endl;
  cout << "Level: " << ressource2.getLevel() << endl;
  cout << "Life: " << ressource2.getLife() << endl;
  cout << "Production: " << ressource2.getProduction() << endl;
  cout << endl;

  cout << "SETTERS AVEC TOUS LES ARGUMENTS HORS DOMAINE DEF" << endl;
  BuildingCost ressourceCost4(-50,-50);
  Position position4(-5,-2);
  ressource2.setIdBuilding(-10);
  ressource2.setPosition(position4);
  ressource2.setIdTexture(RESSOURCE);
  cout << endl;
  cout << "New Id Building: " << ressource2.getIdBuilding() << endl;
  cout << "New Position X: " << ressource2.getPosition().getX() << endl;
  cout << "New Position Y: " << ressource2.getPosition().getY() << endl;
  cout << "New IdTexture: " << ressource2.getIdTexture() << endl;
  cout << "New Wood Cost: " << ressource2.getBuildingCost().getWood() << endl;
  cout << "New Gold Cost: " << ressource2.getBuildingCost().getGold() << endl;
  cout << "New Passable ?: " << ressource2.isPassable() << endl;
  cout << "Production: " << ressource2.getProduction() << endl;
  cout << endl;

  cout << "CONSTRUCTEUR AVEC TROIS ARGUMENTS" << endl;
  Position position5(20,50);
  Ressource ressource3(1, position5,2);
  cout << "Id Building: " << ressource3.getIdBuilding() << endl;
  cout << "Position X: " << ressource3.getPosition().getX() << endl;
  cout << "Position Y: " << ressource3.getPosition().getY() << endl;
  cout << "IdTexture: " << ressource3.getIdTexture() << endl;
  cout << "Wood Cost: " << ressource3.getBuildingCost().getWood() << endl;
  cout << "Gold Cost: " << ressource3.getBuildingCost().getGold() << endl;
  cout << "Passable ?: " << ressource3.isPassable() << endl;
  cout << "Level: " << ressource3.getLevel() << endl;
  cout << "Life: " << ressource3.getLife() << endl;
  cout << "Production: " << ressource3.getProduction() << endl;
  cout << endl;
}
