#include "PositionTest.h"

using namespace state;
using namespace std;

void positionTest() {
  cout << "-------------------------------------" << endl;
  cout << "TEST POSITION : " << endl;
  cout << "-------------------------------------" << endl;

  Position pos2(1,2);
  Position pos1;
  Position pos3(-2,-2);

  cout << "CONSTRUCTEUR PAR DEFAULT DE POSITION : " << endl;
  cout << "abscisse : " << pos1.getX() << endl;
  cout << "ordonnee : " << pos1.getY() << endl;

  cout << "CONSTRUCTEUR AVEC ARGUMENTS NEGATIFS: " << endl;
  cout << "abscisse : " << pos3.getX() << endl;
  cout << "ordonnee : " << pos3.getY() << endl;

  cout << "setX et setY AVEC ARGUMENTS NEGATIFS: " << endl;
  pos3.setX(-10);
  pos3.setY(-20);

}
