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
  Units unit(1, pos1, 1000, 100, 2, 1, 4, 3);
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
  Arrow arrow(10, pos1, 1, 1000, 70, 3, 1, 2);
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
  Arrow arrow2(10, pos1, 1, 1000, 50, 3, 1, 2);
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

<<<<<<< HEAD
    if (argv[1] &&!strcmp(argv[1],"hello")){
      cout << "Bonjour le monde!" << endl;
    } else {
      cout << "Please type 'helloo'!" << endl;
    }
=======
  cout << "-------------------------------------" << endl;
  cout << "TEST LIVRABLE 1.1" << endl;
  cout << "-------------------------------------" << endl;
  if (argv[1] &&!strcmp(argv[1],"hello")){
    cout << "Bonjour le monde!" << endl;
  } else {
    cout << "Please type 'hello'!" << endl;
  }
>>>>>>> 9a4c960175be46c2474aa9c4f7054d5c9445fa32

  return 0;
}
