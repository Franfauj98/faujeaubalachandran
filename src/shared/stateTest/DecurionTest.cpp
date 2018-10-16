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

  cout << "CONSTRUCTEUR SANS ARGUMENTS" << endl;
  Decurion decurion1;
  cout << "Life : " << decurion1.getLife() << endl;
  cout << "position x : " << decurion1.getPosition().getX() << endl;
  cout << "position y : " << decurion1.getPosition().getY() << endl;
  cout << "damage : " << decurion1.getDamage() << endl;
  cout << "strikeRange : " << decurion1.getStrikeRange() << endl;
  cout << "movingRange : " << decurion1.getMovingRange() << endl;
  cout << "level : " << decurion1.getLevel() << endl;
  cout << "idUnits : " << decurion1.getIdUnits() << endl;
  cout << "UnitCost : gold : " << decurion1.getUnitCost().getGold() << ", food : " << decurion1.getUnitCost().getGold() << endl;
  cout << "idTextureUnits : " << decurion1.getIdTextureUnits() << endl;


  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  Decurion decurion2(10,1, pos1, 1000, 70, 3, 1, DECURION2, decurionCost);
  cout << "Life : " << decurion2.getLife() << endl;
  cout << "position x : " << decurion2.getPosition().getX() << endl;
  cout << "position y : " << decurion2.getPosition().getY() << endl;
  cout << "damage : " << decurion2.getDamage() << endl;
  cout << "strikeRange : " << decurion2.getStrikeRange() << endl;
  cout << "movingRange : " << decurion2.getMovingRange() << endl;
  cout << "level : " << decurion2.getLevel() << endl;
  cout << "idUnits : " << decurion2.getIdUnits() << endl;
  cout << "UnitCost : gold : " << decurion2.getUnitCost().getGold() << ", food : " << decurion2.getUnitCost().getGold() << endl;
  cout << "idTextureUnits : " << decurion2.getIdTextureUnits() << endl;
  // cout << "level : " << u.getLevel() << endl;

  cout << "CONSTRUCTEUR AVEC 3 ARGUMENTS" << endl;
  Decurion decurion3(3, pos2, 5);
  cout << "Life : " << decurion3.getLife() << endl;
  cout << "position x : " << decurion3.getPosition().getX() << endl;
  cout << "position y : " << decurion3.getPosition().getY() << endl;
  cout << "damage : " << decurion3.getDamage() << endl;
  cout << "strikeRange : " << decurion3.getStrikeRange() << endl;
  cout << "movingRange : " << decurion3.getMovingRange() << endl;
  cout << "level : " << decurion3.getLevel() << endl;
  cout << "idUnits : " << decurion3.getIdUnits() << endl;
  cout << "UnitCost : gold : " << decurion3.getUnitCost().getGold() << ", food : " << decurion3.getUnitCost().getGold() << endl;
  cout << "idTextureUnits : " << decurion3.getIdTextureUnits() << endl;

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << decurion2.moveAllowed(pos2, 1) << endl;
  decurion2.move(pos2, 1);
  cout << "position x : " << decurion2.getPosition().getX() << endl;
  cout << "position y : " << decurion2.getPosition().getY() << endl;
  decurion2.move(pos1, 1);
  cout << "Retour en pos1" << endl;
  cout << "position x : " << decurion2.getPosition().getX() << endl;
  cout << "position y : " << decurion2.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Decurion 2: " << decurion2.getLife() << endl;
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;

  cout << "attackAllowed : " << decurion2.attackAllowed(decurion3) << endl;
  decurion2.attack(decurion3);
  cout << "Life Decurion 2: " << decurion2.getLife() << endl;
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
  cout << "attackAllowed : " << decurion3.attackAllowed(decurion2) << endl;
  decurion3.attack(decurion2);
  cout << "Life Decurion 2: " << decurion2.getLife() << endl;
  cout << "Life Decurion 3: " << decurion3.getLife() << endl;
}
