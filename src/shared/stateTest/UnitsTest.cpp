#include "UnitsTest.h"

using namespace state;
using namespace std;

void unitsTest() {
  cout << "-------------------------------------" << endl;
  cout << "TEST UNITS" << endl;
  cout << "-------------------------------------" << endl;
  Position pos1(1,2);
  Units unit(1, pos1, 1000, 100, 2, 1, 4, CAVALIER1);
  cout << "Life : " << unit.getLife() << endl;
  cout << "position x : " << unit.getPosition().getX() << endl;
  cout << "position y : " << unit.getPosition().getY() << endl;
  cout << "damage : " << unit.getDamage() << endl;
  cout << "strikeRange : " << unit.getStrikeRange() << endl;
  cout << "movingRange : " << unit.getMovingRange() << endl;
  cout << "level : " << unit.getLevel() << endl;
  cout << "idUnits : " << unit.getIdUnits() << endl;
  cout << "idTextureUnits : " << unit.getIdTextureUnits() << endl;
  unit.setLife(3000);
  cout << "Life : " << unit.getLife() << endl;

}
