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

  // cout << "CONSTRUCTEUR SANS ARGUMENTS" << endl;
  // Arrow arrow1;
  // cout << "Life : " << arrow1.getLife() << endl;
  // cout << "position x : " << arrow1.getPosition().getX() << endl;
  // cout << "position y : " << arrow1.getPosition().getY() << endl;
  // cout << "damage : " << arrow1.getDamage() << endl;
  // cout << "strikeRange : " << arrow1.getStrikeRange() << endl;
  // cout << "movingRange : " << arrow1.getMovingRange() << endl;
  // cout << "level : " << arrow1.getLevel() << endl;
  // cout << "idUnits : " << arrow1.getIdUnits() << endl;
  // cout << "UnitCost : gold : " << arrow1.getUnitCost().getGold() << ", food : " << arrow1.getUnitCost().getGold() << endl;
  // cout << "idTextureUnits : " << arrow1.getIdTextureUnits() << endl;
  //
  //
  // cout << "CONSTRUCTEUR AVEC TOUS LES ARGUMENTS" << endl;
  // Arrow arrow2(10,1, pos1, 1000, 70, 3, 1, ARROW2,arrowCost);
  // cout << "Life : " << arrow2.getLife() << endl;
  // cout << "position x : " << arrow2.getPosition().getX() << endl;
  // cout << "position y : " << arrow2.getPosition().getY() << endl;
  // cout << "damage : " << arrow2.getDamage() << endl;
  // cout << "strikeRange : " << arrow2.getStrikeRange() << endl;
  // cout << "movingRange : " << arrow2.getMovingRange() << endl;
  // cout << "level : " << arrow2.getLevel() << endl;
  // cout << "idUnits : " << arrow2.getIdUnits() << endl;
  // cout << "UnitCost : gold : " << arrow2.getUnitCost().getGold() << ", food : " << arrow2.getUnitCost().getGold() << endl;
  // cout << "idTextureUnits : " << arrow2.getIdTextureUnits() << endl;
  //
  // cout << "CONSTRUCTEUR AVEC 3 ARGUMENTS" << endl;
  // Arrow arrow3(3, pos2, 5);
  // cout << "Life : " << arrow3.getLife() << endl;
  // cout << "position x : " << arrow3.getPosition().getX() << endl;
  // cout << "position y : " << arrow3.getPosition().getY() << endl;
  // cout << "damage : " << arrow3.getDamage() << endl;
  // cout << "strikeRange : " << arrow3.getStrikeRange() << endl;
  // cout << "movingRange : " << arrow3.getMovingRange() << endl;
  // cout << "level : " << arrow3.getLevel() << endl;
  // cout << "idUnits : " << arrow3.getIdUnits() << endl;
  // cout << "UnitCost : gold : " << arrow3.getUnitCost().getGold() << ", food : " << arrow3.getUnitCost().getGold() << endl;
  // cout << "idTextureUnits : " << arrow3.getIdTextureUnits() << endl;

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
