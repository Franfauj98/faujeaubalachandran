#include "MapTest.h"

using namespace std;
using namespace state;

void mapTest(){
  cout << "-------------------------------------" << endl;
  cout << "TEST MAP" << endl;
  cout << "-------------------------------------" << endl;

  Map map;

  Position p(1,2);
  Position p2(3,4);

  Arrow* arrow = new Arrow(2,p2,2);
  Arrow* arrow2 = new Arrow(3,p,3);
  Arrow* arrow3 = new Arrow(3,p,3);
  cout << "Life : " << arrow->getLife() << endl;
  map.addElement(arrow);
  map.addElement(arrow2);
  map.addElement(arrow3);

  Arrow* arr = (Arrow *)map.getMap()[0];
  cout << arr->getLife() << endl;

  map.deleteElement(1);

  cout << "POSITION OF ARROW 1" << endl;
  cout << map.getPositionElement(arrow) << endl;

}
