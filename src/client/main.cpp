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

#include "stateTest.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
  positionTest();
  elementTest();
  unitsTest();
  arrowTest();
  catapultTest();
  cavalierTest();
  decurionTest();

  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDINGS" << endl;
  cout << "-------------------------------------" << endl;
  Position pos8(10,5);
  Position pos9(5,5);
  BuildingCost bc(10,100);
  Buildings Bat(1, pos8, 0,HDV1,bc);

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

  Palace P(0, pos8, 0,HDV1,bc);

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

  Ressource R(5,1, pos8, 0,RESSOURCE,bc);

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

  Barrack B(2,3, pos8, 0,BARRACK,bc);

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
