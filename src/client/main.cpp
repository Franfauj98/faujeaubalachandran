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
  Position p(5,8);
  Element e(p);

  cout << "Position x : " << e.getPosition().getX() << endl;
  cout << "Position y : " << e.getPosition().getY() << endl;

  Position p2(1,2);
  e.setPosition(p2);
  cout << "Position x : " << e.getPosition().getX() << endl;
  cout << "Position y : " << e.getPosition().getY() << endl;

  cout << "abscisse : " << p.getX() << endl;
  cout << "ordonnee : " << p.getY() << endl;

  Units u(1, p, 1000, 100, 2, 1, 4, 3);
  cout << "Life : " << u.getLife() << endl;
  cout << "position x : " << u.getPosition().getX() << endl;
  cout << "position y : " << u.getPosition().getY() << endl;
  cout << "damage : " << u.getDamage() << endl;
  cout << "strikeRange : " << u.getStrikeRange() << endl;
  cout << "movingRange : " << u.getMovingRange() << endl;
  cout << "level : " << u.getLevel() << endl;
  cout << "idUnits : " << u.getIdUnits() << endl;
  cout << "idTextureUnits : " << u.getIdTextureUnits() << endl;

  u.setLife(3000);
  cout << "Life : " << u.getLife() << endl;

  // cout << "level : " << u.getLevel() << endl;


  if (argv[1] &&!strcmp(argv[1],"hello")){
    cout << "Bonjour le monde!" << endl;
  } else {
    cout << "Please type 'hello'!" << endl;
  }

  return 0;
}
