#include <iostream>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "state.h"
#include "render.h"
#include "renderTest.h"
#include "stateTest.h"


using namespace std;
using namespace state;
using namespace render;

int main(int argc,char* argv[])
{

  if (argv[1] &&!strcmp(argv[1],"hello")){
    cout << "Bonjour le monde!" << endl;
  } else if (argv[1] &&!strcmp(argv[1],"state")) {
    positionTest();
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

  } else if (argv[1] &&!strcmp(argv[1],"render")) {

    //tileTest();
    //ileSetTest();
    //mapCreatorTest();
    Layer layer;
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tilemap");
    window.setVerticalSyncEnabled(false);
    // sf::Font font;
    // font.loadFromFile("res/helvetica.ttf");
    //
    // sf::Text text;
    // // choix de la police à utiliser
    // text.setFont(font); // font est un sf::Font
    // // choix de la chaîne de caractères à afficher
    // text.setString("Stats");
    // // choix de la taille des caractères
    // text.setCharacterSize(14); // exprimée en pixels, pas en points !
    // // choix de la couleur du texte
    // text.setFillColor(sf::Color::White);
    // text.setPosition(800, 100);
    //
    // sf::Text text1;
    // // choix de la police à utiliser
    // text1.setFont(font); // font est un sf::Font
    // // choix de la chaîne de caractères à afficher
    // text1.setString("Level:");
    // // choix de la taille des caractères
    // text1.setCharacterSize(14); // exprimée en pixels, pas en points !
    // // choix de la couleur du texte
    // text1.setFillColor(sf::Color::Red);
    // text1.setPosition(800, 150);
    //
    // sf::Text text2;
    // // choix de la police à utiliser
    // text2.setFont(font); // font est un sf::Font
    // // choix de la chaîne de caractères à afficher
    // text2.setString("Life:");
    // // choix de la taille des caractères
    // text2.setCharacterSize(14); // exprimée en pixels, pas en points !
    // // choix de la couleur du texte
    // text2.setFillColor(sf::Color::Red);
    // text2.setPosition(800, 200);
    //
    // sf::Text text3;
    // // choix de la police à utiliser
    // text3.setFont(font); // font est un sf::Font
    // // choix de la chaîne de caractères à afficher
    // text3.setString("Damage:");
    // // choix de la taille des caractères
    // text3.setCharacterSize(14); // exprimée en pixels, pas en points !
    // // choix de la couleur du texte
    // text3.setFillColor(sf::Color::Red);
    // text3.setPosition(800, 250);


    while (window.isOpen())
    {
  // on gère les évènements
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      window.close();
    }

  // on dessine le niveau
    window.clear();
    window.draw(layer.getBasicMap());
    window.draw(layer.getDecorMap());
    window.draw(layer.getBuildingMap());
    MenuLayer menu1("res/helvetica.ttf", "Stats", 14, sf::Color::White, 900, 100);
    // text.push_back(menu1);
    MenuLayer menu2("res/helvetica.ttf", "Level", 14, sf::Color::White, 900, 130);
    // text.push_back(menu2);
   MenuLayer menu3("res/helvetica.ttf", "Life", 14, sf::Color::White, 900, 160);
    // text.push_back(menu3);
   MenuLayer menu4("res/helvetica.ttf", "Damage", 14, sf::Color::White, 900, 190);
    // window.draw(layer.getText()[0]);
    // window.draw(layer.getText()[1]);
    // window.draw(layer.getText()[2]);
    // window.draw(layer.getText()[3]);
    window.draw(menu1);
    window.draw(menu2);
    window.draw(menu3);
    window.draw(menu4);
    window.display();
    }


  }
  else {
    cout << "Please type 'hello' or 'state'" << endl;
  }


  return 0;
}
