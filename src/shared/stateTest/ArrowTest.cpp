#include "ArrowTest.h"

using namespace std;
using namespace state;

void arrowTest(){


  Position pos1(2,2);
  Position pos2(2,1);
  Position pos3(2,3);
  Position pos4(1,2);
  Position pos5(3,2);
  Position pos6(3,3);
  UnitCost arrowCost(50,50);

  cout << "-------------------------------------" << endl;
  cout << "TEST ARROW" << endl;
  cout << "-------------------------------------" << endl;

  cout << "MOVE & ATTACK" << endl;
  Arrow arrow3(3, pos1, 5);
  Arrow arrow4(2, pos1, 5);
  Palace palace(1,pos2, 2);

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << arrow4.moveAllowed(pos2, 1) << endl;
  arrow4.move(pos2, 1);
  cout << "position x : " << arrow4.getPosition().getX() << endl;
  cout << "position y : " << arrow4.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "Life Arrow 4: " << arrow4.getLife() << endl;

  cout << "attackAllowed : " << arrow3.attackAllowed(arrow4) << endl;
  arrow3.attack(arrow4);
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "Life Arrow 4: " << arrow4.getLife() << endl;
  cout << "attackAllowed : " << arrow4.attackAllowed(arrow3) << endl;
  arrow4.attack(arrow3);
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "Life Arrow 4: " << arrow4.getLife() << endl;
  cout << "attackAllowed : " << arrow3.attackAllowed(arrow4) << endl;
  cout << "TESTLIFE" << endl;
  arrow3.attack(arrow4);
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "Life Arrow 4: " << arrow4.getLife() << endl;

  cout << "Attack Buildings" << endl;
  arrow3.attackBuilding(palace);
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  arrow3.attackBuilding(palace);
  cout << "After some attacks: " << endl;
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
}
