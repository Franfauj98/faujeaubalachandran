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

  if (argv[1] &&!strcmp(argv[1],"hello")){
    cout << "Bonjour le monde!" << endl;
  } else if (argv[1] &&!strcmp(argv[1],"state")) {
    positionTest();
    elementTest();
    UnitCostTest();
    unitsTest();
    arrowTest();
    catapultTest();
    cavalierTest();
    decurionTest();
    DecorTest();
    BuildingCostTest();
    BuildingsTest();
    PalaceTest();
    BarrackTest();
    EmpireTest();
    RessourceTest();
    mapTest();


    cout << "-------------------------------------" << endl;
    cout << "TEST LIVRABLE 1.1" << endl;
    cout << "-------------------------------------" << endl;

  } else {
    cout << "Please type 'hello' or 'state'" << endl;
  }


  return 0;
}
