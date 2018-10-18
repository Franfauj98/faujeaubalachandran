#include "DecurionTest.h"

using namespace std;
using namespace state;

void decurionTest(){


  Position pos1(2,2);
  Position pos2(2,1);
  Position pos3(2,3);
  Position pos4(1,2);
  Position pos5(3,2);
  Position pos6(3,3);
  UnitCost decurionCost(50,50);

  cout << "-------------------------------------" << endl;
  cout << "TEST DECURION" << endl;
  cout << "-------------------------------------" << endl;
  cout << "MOVE & ATTACK" << endl;
  Decurion decurion3(3, pos1, 5);
  Decurion decurion4(2, pos1, 5);
  Palace palace(1,pos2, 2);

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << decurion4.moveAllowed(pos2, 1) << endl;
  decurion4.move(pos2, 1);
  cout << "position x : " << decurion4.getPosition().getX() << endl;
  cout << "position y : " << decurion4.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "Life Decurion 4: " << decurion4.getLife() << endl;

  cout << "attackAllowed : " << decurion3.attackAllowed(decurion4) << endl;
  decurion3.attack(decurion4);
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "Life Decurion 4: " << decurion4.getLife() << endl;
  cout << "attackAllowed : " << decurion4.attackAllowed(decurion3) << endl;
  decurion4.attack(decurion3);
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "Life Decurion 4: " << decurion4.getLife() << endl;
  cout << "attackAllowed : " << decurion3.attackAllowed(decurion4) << endl;
  cout << "TESTLIFE" << endl;
  decurion3.attack(decurion4);
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "Life Decurion 4: " << decurion4.getLife() << endl;

  cout << "Attack Buildings" << endl;
  decurion3.attackBuilding(palace);
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  decurion3.attackBuilding(palace);
  cout << "After some attacks: " << endl;
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
}
