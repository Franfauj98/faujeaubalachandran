#include "BuildingCostTest.h"

using namespace std;
using namespace state;

void BuildingCostTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDING_COST" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR SANS ARGUMENTS" << endl;
  BuildingCost buildingCost;
  cout << "Gold Cost: " << buildingCost.getGold() << endl;
  cout << "Wood Cost: " << buildingCost.getWood() << endl;
  cout << endl;

  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  BuildingCost buildingCost2(50,50);
  cout << "Gold Cost: " << buildingCost2.getGold() << endl;
  cout << "Wood Cost: " << buildingCost2.getWood() << endl;

  cout << "SETTER AVEC PARAMETRES DANS DOMAINE DE DEF" << endl;
  buildingCost2.setGold(100);
  buildingCost2.setWood(200);
  cout << endl;
  cout << "New Gold Cost: " << buildingCost2.getGold() << endl;
  cout << "New Wood Cost: " << buildingCost2.getWood() << endl;
  cout << endl;

  cout << "SETTER AVEC PARAMETRES HORS DOMAINE DE DEF" << endl;
  buildingCost2.setGold(-100);
  buildingCost2.setWood(-200);
  cout << endl;

  cout << "CONSTRUCTEUR AVEC AVEC PARAMETRES HORS DOMAINE DE DEF" << endl;
  BuildingCost buildingCost3(-50,10000);
  cout << endl;


}
