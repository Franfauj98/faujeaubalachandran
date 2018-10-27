#include "UnitCostTest.h"

using namespace std;
using namespace state;

void UnitCostTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST UNIT_COST" << endl;
  cout << "-------------------------------------" << endl;

  cout << "DEFAULT CONSTRUCTOR" << endl;
  UnitCost unitCost;
  cout << "Gold Cost: " << unitCost.getGold() << endl;
  cout << "Food Cost: " << unitCost.getFood() << endl;
  cout << endl;

  cout << "CONSTRUCTOR WITH ALL ARGUMENTS" << endl;
  UnitCost unitCost2(50,50);
  cout << "Gold Cost: " << unitCost2.getGold() << endl;
  cout << "Food Cost: " << unitCost2.getFood() << endl;
  unitCost2.setGold(100);
  unitCost2.setFood(200);
  cout << endl;
  cout << "New Gold Cost: " << unitCost2.getGold() << endl;
  cout << "New Food Cost: " << unitCost2.getFood() << endl;
  cout<<endl;
  UnitCost unitCost3(50,-50);
  cout << "Gold Cost: " << unitCost3.getGold() << endl;
  cout << "Food Cost: " << unitCost3.getFood() << endl;
  unitCost3.setGold(-100);
  unitCost3.setFood(-200);
  cout << endl;
  cout << "New Gold Cost: " << unitCost3.getGold() << endl;
  cout << "New Food Cost: " << unitCost3.getFood() << endl;
}
