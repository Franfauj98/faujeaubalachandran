#include <iostream>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "../shared/state/Position.h"
void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
  cout << "-------------------------------------" << endl;
  cout << "TEST POSITION : " << endl;
  cout << "-------------------------------------" << endl;

  Position pos1(5,8);
  Position pos2(1,2);

  cout << "abscisse : " << pos1.getX() << endl;
  cout << "ordonnee : " << pos1.getY() << endl;


  cout << "-------------------------------------" << endl;
  cout << "TEST ELEMENT" << endl;
  cout << "-------------------------------------" << endl;

  Element elt(pos1);

  cout << "Position x : " << elt.getPosition().getX() << endl;
  cout << "Position y : " << elt.getPosition().getY() << endl;

  cout << "Change position from pos1 to pos 2" << endl;
  elt.setPosition(pos2);
  cout << "Position x : " << elt.getPosition().getX() << endl;
  cout << "Position y : " << elt.getPosition().getY() << endl;


  cout << "-------------------------------------" << endl;
  cout << "TEST UNITS" << endl;
  cout << "-------------------------------------" << endl;
  Units unit(1, pos1, 1000, 100, 2, 1, 4, CAVALIER1);
  cout << "Life : " << unit.getLife() << endl;
  cout << "position x : " << unit.getPosition().getX() << endl;
  cout << "position y : " << unit.getPosition().getY() << endl;
  cout << "damage : " << unit.getDamage() << endl;
  cout << "strikeRange : " << unit.getStrikeRange() << endl;
  cout << "movingRange : " << unit.getMovingRange() << endl;
  cout << "level : " << unit.getLevel() << endl;
  cout << "idUnits : " << unit.getIdUnits() << endl;
  cout << "idTextureUnits : " << unit.getIdTextureUnits() << endl;
  unit.setLife(3000);
  cout << "Life : " << unit.getLife() << endl;

  cout << "-------------------------------------" << endl;
  cout << "TEST ARROW" << endl;
  cout << "-------------------------------------" << endl;
  Arrow arrow(10,1, pos1, 1000, 70, 3, 1, ARROW2);
  cout << "Life : " << arrow.getLife() << endl;
  cout << "position x : " << arrow.getPosition().getX() << endl;
  cout << "damage : " << arrow.getDamage() << endl;
  cout << "strikeRange : " << arrow.getStrikeRange() << endl;
  cout << "movingRange : " << arrow.getMovingRange() << endl;
  cout << "level : " << arrow.getLevel() << endl;
  cout << "idUnits : " << arrow.getIdUnits() << endl;
  cout << "idTextureUnits : " << arrow.getIdTextureUnits() << endl;
  cout << "position y : " << arrow.getPosition().getY() << endl;
  // cout << "level : " << u.getLevel() << endl;
  Position pos3(5,9);
  Position pos4(5,7);
  Position pos5(6,8);
  Position pos6(4,8);
  Position pos7(4,7);

  cout << "TEST MOVEALLOWED & MOVE : " << endl;
  cout << "moveAllowed : " << arrow.moveAllowed(pos2, 1) << endl;
  cout << "moveAllowed : " << arrow.moveAllowed(pos3, 1) << endl;
  cout << "moveAllowed : " << arrow.moveAllowed(pos4, 1) << endl;
  cout << "moveAllowed : " << arrow.moveAllowed(pos5, 1) << endl;
  cout << "moveAllowed : " << arrow.moveAllowed(pos6, 1) << endl;
  cout << "moveAllowed : " << arrow.moveAllowed(pos7, 1) << endl;
  arrow.move(pos3, 1);
  cout << "position x : " << arrow.getPosition().getX() << endl;
  cout << "position y : " << arrow.getPosition().getY() << endl;

  cout << "TEST ATTACKALLOWED & ATTACK : " << endl;
  Arrow arrow2(10,1, pos1,  1000, 50, 3, 1, ARROW2);
  cout << "Life Arrow 1: " << arrow.getLife() << endl;
  cout << "Life Arrow 2: " << arrow2.getLife() << endl;

  cout << "attackAllowed : " << arrow.attackAllowed(arrow2) << endl;
  arrow.attack(arrow2);
  cout << "Life Arrow 1: " << arrow.getLife() << endl;
  cout << "Life Arrow 2: " << arrow2.getLife() << endl;
  cout << "attackAllowed : " << arrow2.attackAllowed(arrow) << endl;
  arrow2.attack(arrow);
  cout << "Life Arrow 1: " << arrow.getLife() << endl;
  cout << "Life Arrow 2: " << arrow2.getLife() << endl;


  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDINGS" << endl;
  cout << "-------------------------------------" << endl;
  Position pos8(10,5);
  Position pos9(5,5);
  Buildings Bat(1, pos8, 0,HDV0);

  cout << "id : " << Bat.getId() << endl;
  cout << "Position x : " << Bat.getPosition().getX() << endl;
  cout << "Position y : " << Bat.getPosition().getY() << endl;
  cout << "Level : " << Bat.getLevel() << endl;
  cout << "idTexture : " << Bat.getIdTexture() << endl;

  Bat.setId(2);
  Bat.setLevel(1);
  Bat.setIdTexture(RESSOURCE);
  Bat.setPosition(pos9);
  cout << "new id : " << Bat.getId() << endl;
  cout << "new Position x : " << Bat.getPosition().getX() << endl;
  cout << "new Position y : " << Bat.getPosition().getY() << endl;
  cout << "new Level : " << Bat.getLevel() << endl;
  cout << "new idTexture : " << Bat.getIdTexture() << endl;

  cout << "-------------------------------------" << endl;
  cout << "TEST PALACE" << endl;
  cout << "-------------------------------------" << endl;

  Palace P(0, pos8, 0,HDV0);

  cout << "id : " << P.getId() << endl;
  cout << "Position x : " << P.getPosition().getX() << endl;
  cout << "Position y : " << P.getPosition().getY() << endl;
  cout << "Level : " << P.getLevel() << endl;
  cout << "idTexture : " << P.getIdTexture() << endl;

  P.setId(1);
  P.setLevel(1);
  P.setIdTexture(HDV1);
  P.setPosition(pos9);
  cout << "new id : " << P.getId() << endl;
  cout << "new Position x : " << P.getPosition().getX() << endl;
  cout << "new Position y : " << P.getPosition().getY() << endl;
  cout << "new Level : " << P.getLevel() << endl;
  cout << "new idTexture : " << P.getIdTexture() << endl;

  cout << "-------------------------------------" << endl;
  cout << "TEST RESSOURCE" << endl;
  cout << "-------------------------------------" << endl;

  Ressource R(5,1, pos8, 0,RESSOURCE);

  cout << "id : " << R.getId() << endl;
  cout << "Position x : " << R.getPosition().getX() << endl;
  cout << "Position y : " << R.getPosition().getY() << endl;
  cout << "Level : " << R.getLevel() << endl;
  cout << "idTexture : " << R.getIdTexture() << endl;
  cout << "production : " << R.getProduction() << endl;


  R.setLevel(1);
  R.setPosition(pos9);
  R.setProduction(10);

  cout << "new Position x : " << R.getPosition().getX() << endl;
  cout << "new Position y : " << R.getPosition().getY() << endl;
  cout << "new Level : " << R.getLevel() << endl;
  cout << "new production : " << R.getProduction() << endl;

  cout << "-------------------------------------" << endl;
  cout << "TEST BARRACK" << endl;
  cout << "-------------------------------------" << endl;

  Barrack B(2,3, pos8, 0,BARRACK);

  cout << "id : " << B.getId() << endl;
  cout << "Position x : " << B.getPosition().getX() << endl;
  cout << "Position y : " << B.getPosition().getY() << endl;
  cout << "Level : " << B.getLevel() << endl;
  cout << "idTexture : " << B.getIdTexture() << endl;
  cout << "production : " << B.getCapacity() << endl;

  
  cout << "-------------------------------------" << endl;
  cout << "TEST LIVRABLE 1.1" << endl;
  cout << "-------------------------------------" << endl;



  if (argv[1] &&!strcmp(argv[1],"hello")){
    cout << "Bonjour le monde!" << endl;
  } else {
    cout << "Please type 'hello'!" << endl;
  }


  return 0;
}
