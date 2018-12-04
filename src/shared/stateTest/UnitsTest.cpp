#include "UnitsTest.h"

using namespace state;
using namespace std;

void unitsTest() {
  cout << "-------------------------------------" << endl;
  cout << "TEST UNITS" << endl;
  cout << "-------------------------------------" << endl;
  Position pos1(1,2);
  UnitCost unitCost(50,50);
  cout << "INSTANCIATION OF UNITS WITH INVALID ARGUMENTS" << endl;
  std::vector<state::Position> post;
  Units unit(-1, pos1, -1000, -100, -2, -1, -4, CAVALIER1,unitCost,post);
  Units unit2(1, pos1, 1000, 100, 2, 1, 4, CAVALIER1,unitCost,post);
  cout << "setLife WITH INVALID ARGUMENTS" << endl;
  unit2.setLife(-1);
  cout << "setLevel WITH INVALID ARGUMENTS" << endl;
  unit2.setLevel(-1);
  cout << "setDamage WITH INVALID ARGUMENTS" << endl;
  unit2.setDamage(-1);
  cout << "setIdUnits WITH INVALID ARGUMENTS" << endl;
  unit2.setIdUnits(-1);
  cout << "setMovingRange WITH INVALID ARGUMENTS" << endl;
  unit2.setMovingRange(-1);
  cout << "setStrikeRange WITH INVALID ARGUMENTS" << endl;
  unit2.setStrikeRange(-1);
}
