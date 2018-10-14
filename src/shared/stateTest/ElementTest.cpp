#include "ElementTest.h"

using namespace state;
using namespace std;

void elementTest() {
  Position pos2(1,2);
  Position pos1;

  cout << "-------------------------------------" << endl;
  cout << "TEST ELEMENT" << endl;
  cout << "-------------------------------------" << endl;

  Element elt(pos1);

  cout << "Position x : " << elt.getPosition().getX() << endl;
  cout << "Position y : " << elt.getPosition().getY() << endl;

  cout << "Change position from pos1 to pos 2" << endl;
  elt.setPosition(pos2);
  cout << "Position x : " << elt.getPosition().getX() << endl;
  cout << "Position y : " << elt.getPosition().getY() << endl;

}
