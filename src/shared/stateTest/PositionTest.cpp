#include "PositionTest.h"

using namespace state;
using namespace std;

void positionTest() {
  cout << "-------------------------------------" << endl;
  cout << "TEST POSITION : " << endl;
  cout << "-------------------------------------" << endl;

  Position pos2(1,2);
  Position pos1;
  Position pos3(-1,0);

  cout << "CONSTRUCTEUR PAR DEFAULT DE POSITION : " << endl;
  cout << "abscisse : " << pos1.getX() << endl;
  cout << "ordonnee : " << pos1.getY() << endl;

  cout << "CONSTRUCTEUR AVEC ARGUMENTS : " << endl;
  cout << "abscisse : " << pos2.getX() << endl;
  cout << "ordonnee : " << pos2.getY() << endl;

}
