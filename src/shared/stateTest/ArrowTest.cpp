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

  cout << "-------------------------------------" << endl;
  cout << "TEST ARROW" << endl;
  cout << "-------------------------------------" << endl;

  cout << "CONSTRUCTEUR SANS ARGUMENTS" << endl;
  Arrow arrow1;
  cout << "Life : " << arrow1.getLife() << endl;
  cout << "position x : " << arrow1.getPosition().getX() << endl;
  cout << "position y : " << arrow1.getPosition().getY() << endl;
  cout << "damage : " << arrow1.getDamage() << endl;
  cout << "strikeRange : " << arrow1.getStrikeRange() << endl;
  cout << "movingRange : " << arrow1.getMovingRange() << endl;
  cout << "level : " << arrow1.getLevel() << endl;
  cout << "idUnits : " << arrow1.getIdUnits() << endl;
  cout << "idTextureUnits : " << arrow1.getIdTextureUnits() << endl;


  cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  Arrow arrow2(10,1, pos1, 1000, 70, 3, 1, ARROW2);
  cout << "Life : " << arrow2.getLife() << endl;
  cout << "position x : " << arrow2.getPosition().getX() << endl;
  cout << "position y : " << arrow2.getPosition().getY() << endl;
  cout << "damage : " << arrow2.getDamage() << endl;
  cout << "strikeRange : " << arrow2.getStrikeRange() << endl;
  cout << "movingRange : " << arrow2.getMovingRange() << endl;
  cout << "level : " << arrow2.getLevel() << endl;
  cout << "idUnits : " << arrow2.getIdUnits() << endl;
  cout << "idTextureUnits : " << arrow2.getIdTextureUnits() << endl;
  // cout << "level : " << u.getLevel() << endl;

  cout << "CONSTRUCTEUR AVEC 3 ARGUMENTS" << endl;
  Arrow arrow3(3, pos2, 5);
  cout << "Life : " << arrow3.getLife() << endl;
  cout << "position x : " << arrow3.getPosition().getX() << endl;
  cout << "position y : " << arrow3.getPosition().getY() << endl;
  cout << "damage : " << arrow3.getDamage() << endl;
  cout << "strikeRange : " << arrow3.getStrikeRange() << endl;
  cout << "movingRange : " << arrow3.getMovingRange() << endl;
  cout << "level : " << arrow3.getLevel() << endl;
  cout << "idUnits : " << arrow3.getIdUnits() << endl;
  cout << "idTextureUnits : " << arrow3.getIdTextureUnits() << endl;

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed de (2,2) à (2,1): " << arrow2.moveAllowed(pos2, 1) << endl;
  arrow2.move(pos2, 1);
  cout << "position x : " << arrow2.getPosition().getX() << endl;
  cout << "position y : " << arrow2.getPosition().getY() << endl;
  arrow2.move(pos1, 1);
  cout << "Retour en pos1" << endl;
  cout << "position x : " << arrow2.getPosition().getX() << endl;
  cout << "position y : " << arrow2.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;

  cout << "Life Arrow 2: " << arrow2.getLife() << endl;
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;

  cout << "attackAllowed : " << arrow2.attackAllowed(arrow3) << endl;
  arrow2.attack(arrow3);
  cout << "Life Arrow 2: " << arrow2.getLife() << endl;
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
  cout << "attackAllowed : " << arrow3.attackAllowed(arrow2) << endl;
  arrow3.attack(arrow2);
  cout << "Life Arrow 2: " << arrow2.getLife() << endl;
  cout << "Life Arrow 3: " << arrow3.getLife() << endl;
}
