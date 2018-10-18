#include "CatapultTest.h"

using namespace std;
using namespace state;

void catapultTest(){

  Position pos1(2,2);
  Position pos2(2,1);
  Position pos3(2,3);
  Position pos4(1,2);
  Position pos5(3,2);
  Position pos6(3,3);
  UnitCost catapultCost(50,50);
  cout << "-------------------------------------" << endl;
  cout << "TEST CATAPULT" << endl;
  cout << "-------------------------------------" << endl;
  cout << "MOVE & ATTACK" << endl;
  Catapult catapult3(3, pos1, 5);
  Catapult catapult4(2, pos1, 5);
  Palace palace(1,pos2, 2);

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << catapult4.moveAllowed(pos2, 1) << endl;
  catapult4.move(pos2, 1);
  cout << "position x : " << catapult4.getPosition().getX() << endl;
  cout << "position y : " << catapult4.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "Life Catapult 4: " << catapult4.getLife() << endl;

  cout << "attackAllowed : " << catapult3.attackAllowed(catapult4) << endl;
  catapult3.attack(catapult4);
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "Life Catapult 4: " << catapult4.getLife() << endl;
  cout << "attackAllowed : " << catapult4.attackAllowed(catapult3) << endl;
  catapult4.attack(catapult3);
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "Life Catapult 4: " << catapult4.getLife() << endl;
  cout << "attackAllowed : " << catapult3.attackAllowed(catapult4) << endl;
  cout << "TESTLIFE" << endl;
  catapult3.attack(catapult4);
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "Life Catapult 4: " << catapult4.getLife() << endl;

  cout << "Attack Buildings" << endl;
  catapult3.attackBuilding(palace);
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  catapult3.attackBuilding(palace);
  cout << "After some attacks: " << endl;
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
}
