#include "BuildingCostTest.h"

using namespace std;
using namespace state;

void BuildingCostTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDING_COST" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTOR WITHOUT ARGUMENTS" << endl;
  BuildingCost buildingCost;
  cout << "Gold Cost: " << buildingCost.getGold() << endl;
  cout << "Wood Cost: " << buildingCost.getWood() << endl;
  cout << endl;

  cout << "CONSTRUCTOR WITH ALL ARGUMENTS" << endl;
  BuildingCost buildingCost2(50,50);
  cout << "Gold Cost: " << buildingCost2.getGold() << endl;
  cout << "Wood Cost: " << buildingCost2.getWood() << endl;

  cout << "SETTER WITH PARAMETERS INSIDE OF DEF" << endl;
  buildingCost2.setGold(100);
  buildingCost2.setWood(200);
  cout << endl;
  cout << "New Gold Cost: " << buildingCost2.getGold() << endl;
  cout << "New Wood Cost: " << buildingCost2.getWood() << endl;
  cout << endl;

  cout << "SETTER WITH PARAMETERS OUTSIDE OF DEF" << endl;
  buildingCost2.setGold(-100);
  buildingCost2.setWood(-200);
  cout << endl;

  cout << "CONSTRUCTEUR WITH ALL ARGUMENTS OUTSIDE OF DEF" << endl;
  BuildingCost buildingCost3(-50,10000);
  cout << endl;


}
