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

  cout << "CONSTRUCTEUR SANS ARGUMENTS" << endl;
  Catapult catapult1;
  cout << "Life : " << catapult1.getLife() << endl;
  cout << "position x : " << catapult1.getPosition().getX() << endl;
  cout << "position y : " << catapult1.getPosition().getY() << endl;
  cout << "damage : " << catapult1.getDamage() << endl;
  cout << "strikeRange : " << catapult1.getStrikeRange() << endl;
  cout << "movingRange : " << catapult1.getMovingRange() << endl;
  cout << "level : " << catapult1.getLevel() << endl;
  cout << "idUnits : " << catapult1.getIdUnits() << endl;
  cout << "UnitCost : gold : " << catapult1.getUnitCost().getGold() << ", food : " << catapult1.getUnitCost().getGold() << endl;
  cout << "idTextureUnits : " << catapult1.getIdTextureUnits() << endl;


  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  Catapult catapult2(10,1, pos1, 1000, 70, 3, 1, CATAPULT2,catapultCost);
  cout << "Life : " << catapult2.getLife() << endl;
  cout << "position x : " << catapult2.getPosition().getX() << endl;
  cout << "position y : " << catapult2.getPosition().getY() << endl;
  cout << "damage : " << catapult2.getDamage() << endl;
  cout << "strikeRange : " << catapult2.getStrikeRange() << endl;
  cout << "movingRange : " << catapult2.getMovingRange() << endl;
  cout << "level : " << catapult2.getLevel() << endl;
  cout << "idUnits : " << catapult2.getIdUnits() << endl;
  cout << "UnitCost : gold : " << catapult2.getUnitCost().getGold() << ", food : " << catapult2.getUnitCost().getGold() << endl;
  cout << "idTextureUnits : " << catapult2.getIdTextureUnits() << endl;
  // cout << "level : " << u.getLevel() << endl;

  cout << "CONSTRUCTEUR AVEC 3 ARGUMENTS" << endl;
  Catapult catapult3(3, pos2, 5);
  cout << "Life : " << catapult3.getLife() << endl;
  cout << "position x : " << catapult3.getPosition().getX() << endl;
  cout << "position y : " << catapult3.getPosition().getY() << endl;
  cout << "damage : " << catapult3.getDamage() << endl;
  cout << "strikeRange : " << catapult3.getStrikeRange() << endl;
  cout << "movingRange : " << catapult3.getMovingRange() << endl;
  cout << "level : " << catapult3.getLevel() << endl;
  cout << "idUnits : " << catapult3.getIdUnits() << endl;
  cout << "UnitCost : gold : " << catapult3.getUnitCost().getGold() << ", food : " << catapult3.getUnitCost().getGold() << endl;
  cout << "idTextureUnits : " << catapult3.getIdTextureUnits() << endl;

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << catapult2.moveAllowed(pos2, 1) << endl;
  catapult2.move(pos2, 1);
  cout << "position x : " << catapult2.getPosition().getX() << endl;
  cout << "position y : " << catapult2.getPosition().getY() << endl;
  catapult2.move(pos1, 1);
  cout << "Retour en pos1" << endl;
  cout << "position x : " << catapult2.getPosition().getX() << endl;
  cout << "position y : " << catapult2.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Catapult 2: " << catapult2.getLife() << endl;
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;

  cout << "attackAllowed : " << catapult2.attackAllowed(catapult3) << endl;
  catapult2.attack(catapult3);
  cout << "Life Catapult 2: " << catapult2.getLife() << endl;
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
  cout << "attackAllowed : " << catapult3.attackAllowed(catapult2) << endl;
  catapult3.attack(catapult2);
  cout << "Life Catapult 2: " << catapult2.getLife() << endl;
  cout << "Life Catapult 3: " << catapult3.getLife() << endl;
}
