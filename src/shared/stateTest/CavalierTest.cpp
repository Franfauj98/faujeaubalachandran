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

  cout << "-------------------------------------" << endl;
  cout << "TEST CAVALIER" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR SANS ARGUMENTS" << endl;
  Cavalier cavalier1;
  cout << "Life : " << cavalier1.getLife() << endl;
  cout << "position x : " << cavalier1.getPosition().getX() << endl;
  cout << "position y : " << cavalier1.getPosition().getY() << endl;
  cout << "damage : " << cavalier1.getDamage() << endl;
  cout << "strikeRange : " << cavalier1.getStrikeRange() << endl;
  cout << "movingRange : " << cavalier1.getMovingRange() << endl;
  cout << "level : " << cavalier1.getLevel() << endl;
  cout << "idUnits : " << cavalier1.getIdUnits() << endl;
  cout << "idTextureUnits : " << cavalier1.getIdTextureUnits() << endl;


  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  Cavalier cavalier2(10,1, pos1, 1000, 70, 3, 1, CAVALIER2);
  cout << "Life : " << cavalier2.getLife() << endl;
  cout << "position x : " << cavalier2.getPosition().getX() << endl;
  cout << "position y : " << cavalier2.getPosition().getY() << endl;
  cout << "damage : " << cavalier2.getDamage() << endl;
  cout << "strikeRange : " << cavalier2.getStrikeRange() << endl;
  cout << "movingRange : " << cavalier2.getMovingRange() << endl;
  cout << "level : " << cavalier2.getLevel() << endl;
  cout << "idUnits : " << cavalier2.getIdUnits() << endl;
  cout << "idTextureUnits : " << cavalier2.getIdTextureUnits() << endl;
  // cout << "level : " << u.getLevel() << endl;

  cout << "CONSTRUCTEUR AVEC 3 ARGUMENTS" << endl;
  Cavalier cavalier3(3, pos2, 5);
  cout << "Life : " << cavalier3.getLife() << endl;
  cout << "position x : " << cavalier3.getPosition().getX() << endl;
  cout << "position y : " << cavalier3.getPosition().getY() << endl;
  cout << "damage : " << cavalier3.getDamage() << endl;
  cout << "strikeRange : " << cavalier3.getStrikeRange() << endl;
  cout << "movingRange : " << cavalier3.getMovingRange() << endl;
  cout << "level : " << cavalier3.getLevel() << endl;
  cout << "idUnits : " << cavalier3.getIdUnits() << endl;
  cout << "idTextureUnits : " << cavalier3.getIdTextureUnits() << endl;

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << cavalier2.moveAllowed(pos2, 1) << endl;
  cavalier2.move(pos2, 1);
  cout << "position x : " << cavalier2.getPosition().getX() << endl;
  cout << "position y : " << cavalier2.getPosition().getY() << endl;
  cavalier2.move(pos1, 1);
  cout << "Retour en pos1" << endl;
  cout << "position x : " << cavalier2.getPosition().getX() << endl;
  cout << "position y : " << cavalier2.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Cavalier 2: " << cavalier2.getLife() << endl;
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;

  cout << "attackAllowed : " << cavalier2.attackAllowed(cavalier3) << endl;
  cavalier2.attack(cavalier3);
  cout << "Life Cavalier 2: " << cavalier2.getLife() << endl;
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
  cout << "attackAllowed : " << cavalier3.attackAllowed(cavalier2) << endl;
  cavalier3.attack(cavalier2);
  cout << "Life Cavalier 2: " << cavalier2.getLife() << endl;
  cout << "Life Cavalier 3: " << cavalier3.getLife() << endl;
}
