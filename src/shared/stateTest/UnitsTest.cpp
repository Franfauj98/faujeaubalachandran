#include "UnitsTest.h"

using namespace state;
using namespace std;

void unitsTest() {
  cout << "-------------------------------------" << endl;
  cout << "TEST UNITS" << endl;
  cout << "-------------------------------------" << endl;
  Position pos1(1,2);
  UnitCost unitCost(50,50);
  cout << "INSTANCIATION DE UNIT AVEC DES ARGUMENTS INVALIDES" << endl;
  Units unit(-1, pos1, -1000, -100, -2, -1, -4, CAVALIER1,unitCost);
  Units unit2(1, pos1, 1000, 100, 2, 1, 4, CAVALIER1,unitCost);
  cout << "TEST DE setLife AVEC ARGUMENT INVALIDE" << endl;
  unit2.setLife(-1);
  cout << "TEST DE setLevel AVEC ARGUMENT INVALIDE" << endl;
  unit2.setLevel(-1);
  cout << "TEST DE setDamage AVEC ARGUMENT INVALIDE" << endl;
  unit2.setDamage(-1);
  cout << "TEST DE setIdUnits AVEC ARGUMENT INVALIDE" << endl;
  unit2.setIdUnits(-1);
  cout << "TEST D&E setMovingRange AVEC ARGUMENT INVALIDE" << endl;
  unit2.setMovingRange(-1);
  cout << "TEST DE setStrikeRange AVEC ARGUMENT INVALIDE" << endl;
  unit2.setStrikeRange(-1);
}
