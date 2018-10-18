#include "CavalierTest.h"

using namespace std;
using namespace state;

void cavalierTest(){

  Position pos1(2,2);
  Position pos2(2,1);
  Position pos3(2,3);
  Position pos4(1,2);
  Position pos5(3,2);
  Position pos6(3,3);
  UnitCost cavalierCost(50,50);

  cout << "-------------------------------------" << endl;
  cout << "TEST CAVALIER" << endl;
  cout << "-------------------------------------" << endl;
  cout << "MOVE & ATTACK" << endl;
  Cavalier cavalier3(3, pos1, 5);
  Cavalier cavalier4(2, pos1, 5);
  Palace palace(1,pos2, 2);

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << cavalier4.moveAllowed(pos2, 1) << endl;
  cavalier4.move(pos2, 1);
  cout << "position x : " << cavalier4.getPosition().getX() << endl;
  cout << "position y : " << cavalier4.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "Life Cavalier 4: " << cavalier4.getLife() << endl;

  cout << "attackAllowed : " << cavalier3.attackAllowed(cavalier4) << endl;
  cavalier3.attack(cavalier4);
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "Life Cavalier 4: " << cavalier4.getLife() << endl;
  cout << "attackAllowed : " << cavalier4.attackAllowed(cavalier3) << endl;
  cavalier4.attack(cavalier3);
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "Life Cavalier 4: " << cavalier4.getLife() << endl;
  cout << "attackAllowed : " << cavalier3.attackAllowed(cavalier4) << endl;
  cout << "TESTLIFE" << endl;
  cavalier3.attack(cavalier4);
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "Life Cavalier 4: " << cavalier4.getLife() << endl;

  cout << "Attack Buildings" << endl;
  cavalier3.attackBuilding(palace);
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cavalier3.attackBuilding(palace);
  cout << "After some attacks: " << endl;
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "Life Palace: " << palace.getLife() << endl;
}
