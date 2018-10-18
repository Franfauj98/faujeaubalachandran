#include "EmpireTest.h"
#include "BarrackTest.h"
#include "PalaceTest.h"
#include "RessourceTest.h"

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
  Barrack* empireBarrack0=empire0.getBarrack();
  cout<< "Barrack X position:" << empireBarrack0->getPosition().getX() << endl;
  cout<< "Barrack Y position:" << empireBarrack0->getPosition().getY() << endl;
  cout<< "Barrack level:" << empireBarrack0->getLevel() << endl;
  cout<< "Barrack life:" << empireBarrack0->getLife() << endl;
  cout << endl;

  Palace* empirePalace0=empire0.getPalace();
  cout<< "Palace X position:" << empirePalace0->getPosition().getX() << endl;
  cout<< "Palace Y position:" << empirePalace0->getPosition().getY() << endl;
  cout<< "Palace level:" << empirePalace0->getLevel() << endl;
  cout<< "Palace life:" << empirePalace0->getLife() << endl;
  cout << endl;

  Ressource* empireRessource0=empire0.getRessource();
  cout<< "Ressource X position:" << empireRessource0->getPosition().getX() << endl;
  cout<< "Ressource Y position:" << empireRessource0->getPosition().getY() << endl;
  cout<< "Ressource level:" << empireRessource0->getLevel() << endl;
  cout<< "Ressource life:" << empireRessource0->getLife() << endl;
  cout << endl;

  cout << "SETTER AVEC PARAMETRES DANS LE DOMAINE DE DEF" << endl;

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
  Barrack* empireBarrack0=empire0.getBarrack();
  cout<< "Barrack X position:" << empireBarrack0->getPosition().getX() << endl;
  cout<< "Barrack Y position:" << empireBarrack0->getPosition().getY() << endl;
  cout<< "Barrack level:" << empireBarrack0->getLevel() << endl;
  cout<< "Barrack life:" << empireBarrack0->getLife() << endl;
  cout << endl;

  Palace* empirePalace0=empire0.getPalace();
  cout<< "Palace X position:" << empirePalace0->getPosition().getX() << endl;
  cout<< "Palace Y position:" << empirePalace0->getPosition().getY() << endl;
  cout<< "Palace level:" << empirePalace0->getLevel() << endl;
  cout<< "Palace life:" << empirePalace0->getLife() << endl;
  cout << endl;

  Ressource* empireRessource0=empire0.getRessource();
  cout<< "Ressource X position:" << empireRessource0->getPosition().getX() << endl;
  cout<< "Ressource Y position:" << empireRessource0->getPosition().getY() << endl;
  cout<< "Ressource level:" << empireRessource0->getLevel() << endl;
  cout<< "Ressource life:" << empireRessource0->getLife() << endl;
  cout << endl;
  
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
