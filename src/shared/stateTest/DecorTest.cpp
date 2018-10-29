#include "DecorTest.h"

using namespace std;
using namespace state;

void DecorTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST DECOR" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTOR WITHOUT ARGUMENTS" << endl;
  Decor decor0;
  cout << "idDecor: " << decor0.getIdDecor() << endl;
  cout << "passable?: " << decor0.getPassable() << endl;
  cout << endl;

  cout << "SETTER" << endl;
  decor0.setPassable(false);
  decor0.setIdDecor(MOUNTAIN);
  cout << "idDecor: " << decor0.getIdDecor() << endl;
  cout << "passable?: " << decor0.getPassable() << endl;
  cout << endl;

  cout << "CONSTRUCTOR WITH ARGUMENTS" << endl;
  Position pos0(50,20);
  Decor decor1(SEA,pos0);
  cout << "idDecor: " << decor1.getIdDecor() << endl;
  cout << "passable?: " << decor1.getPassable() << endl;
  cout << "position X: " << decor1.getPosition().getX() << endl;
  cout << "position Y: " << decor1.getPosition().getY() << endl;
  cout << endl;

  cout << "CONSTRUCTOR WITH ARGUMENT OUTSIDE OF DOMAIN" << endl;
  Position pos1(-50,20);
  Decor decor2(SEA,pos1);
  cout << endl;

}
