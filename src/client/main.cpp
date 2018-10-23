#include <iostream>
#include "string.h"
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

#include "state.h"
#include "render.h"
#include "stateTest.h"

using namespace std;
using namespace state;
using namespace render;
// //
// class TileMap : public sf::Drawable, public sf::Transformable
// {
// public:
//
//     bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
//     {
//         // on charge la texture du tileset
//         if (!m_tileset.loadFromFile(tileset))
//             return false;
//
//         // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
//         m_vertices.setPrimitiveType(sf::Quads);
//         m_vertices.resize((width) * height * 4);
//
//         // on remplit le tableau de vertex, avec un quad par tuile
//         for (unsigned int i = 0; i < width; ++i)
//             for (unsigned int j = 0; j < height; ++j)
//             {
//                 // on récupère le numéro de tuile courant
//                 int tileNumber = tiles[i + j * (width)];
//
//                 // on en déduit sa position dans la texture du tileset
//                 int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
//                 int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
//
//                 // on récupère un pointeur vers le quad à définir dans le tableau de vertex
//                 sf::Vertex* quad = &m_vertices[(i + j * (width)) * 4];
//                 // on définit ses quatre coins
//                 if(i%2==0) {
//                   quad[0].position = sf::Vector2f(i/2 * tileSize.x+tileSize.x/2, j * tileSize.y);
//                   quad[1].position = sf::Vector2f((i/2 +1 ) * tileSize.x, j * tileSize.y+tileSize.y/2);
//                   quad[2].position = sf::Vector2f((i/2 + 1) * tileSize.x-tileSize.x/2, (j+1) * tileSize.y);
//                   quad[3].position = sf::Vector2f((i/2) * tileSize.x, (j + 1) * tileSize.y-tileSize.y/2);
//
//                 }
//                 else if(j<height-1) {
//                   quad[0].position = sf::Vector2f((i+1)/2 * tileSize.x, j * tileSize.y+tileSize.y/2);
//                   quad[1].position = sf::Vector2f(((i+1)/2 +1 ) * tileSize.x-tileSize.x/2, (j+1) * tileSize.y);
//                   quad[2].position = sf::Vector2f((i+1)/2 * tileSize.x, (j+1) * tileSize.y+tileSize.y/2);
//                   quad[3].position = sf::Vector2f((i+1)/2 * tileSize.x-tileSize.x/2, (j + 1) * tileSize.y);
//                 }
//
//                 quad[0].texCoords = sf::Vector2f(tu * tileSize.x+tileSize.x/2, tv * tileSize.y);
//                 quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y+tileSize.y/2);
//                 quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x-tileSize.x/2, (tv + 1) * tileSize.y);
//                 quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y-tileSize.y/2);
//
//                 // quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
//                 // quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
//                 // quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
//                 // quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
//                 //
//                 // on définit ses quatre coordonnées de texture
//                 // quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
//                 // quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
//                 // quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
//                 // quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
//               }
//
//     return true;
//   }
//
//   private:
//
//     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
//     {
//         // on applique la transformation
//         states.transform *= getTransform();
//
//         // on applique la texture du tileset
//         states.texture = &m_tileset;
//
//         // et on dessine enfin le tableau de vertex
//         target.draw(m_vertices, states);
//       }
//
//       sf::VertexArray m_vertices;
//       sf::Texture m_tileset;
//     };



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
    sf::RenderWindow window(sf::VideoMode(450, 450), "Tilemap");

  //  const int level[] =
  //  {
  //     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  //     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  //     2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
  //     2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
  //     2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
  //     2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 3, 4, 5, 6, 7, 8,
  //     2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 12, 11, 10, 9,
  //     2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  // };
   // on crée la tilemap avec le niveau précédemment défini
   // TileMap map;
   // if (!map.load("res/terrain.png", sf::Vector2u(64, 32), level, 16, 8))
   //     return -1;

   MapCreator map;
   const int tiles[] ={2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,0,0,2,2,2,2,
                      2,2,2,2,0,0,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,1,1,2,2,2,2,
                      2,2,2,2,1,1,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2,
                      2,2,2,2,2,2,2,2,2,2};
   map.loadTexture("res/terrain.png");
   map.initQuads(10);
   for (int x=0;x<10;x++){
     for(int y=0;y<10;y++){
       map.setSpriteLocation (10,x,y,0);
       map.setSpriteTexture(10,tiles,0,x,y);
     }
   }

   MapCreator building;
   const int bu[] ={6,6,6,6,6,6,6,6,6,6,
                    6,1,6,6,6,6,6,6,6,6,
                    6,6,6,6,6,6,6,0,6,6,
                    6,6,6,6,6,6,6,6,6,6,
                    6,6,6,6,6,6,6,6,6,6,
                    6,6,6,6,6,6,6,6,6,6,
                    6,6,6,6,6,6,6,6,6,6,
                    6,6,6,6,6,6,6,6,6,6,
                    6,6,3,6,6,6,6,6,3,6,
                    6,6,6,6,6,6,6,6,6,6};
   building.loadTexture("res/Buildings.png");
   building.initQuads(10);
   for (int x=0;x<10;x++){
     for(int y=0;y<10;y++){
       building.setSpriteLocation (10,x,y,0);
       building.setSpriteTexture(10,bu,0,x,y);
     }
   }

   MapCreator units;
   const int un[] ={16,16,3,16,16,16,16,16,16,16,
                    16,16,16,16,16,16,16,16,16,16,
                    16,16,16,16,16,16,16,16,16,16,
                    16,16,16,16,16,16,16,5,16,16,
                    16,16,16,16,16,16,16,16,16,16,
                    16,6,16,16,16,16,16,16,16,16,
                    16,16,16,16,16,16,16,16,16,16,
                    16,16,16,16,16,16,16,16,16,16,
                    16,16,16,16,16,9,16,16,16,16,
                    16,16,16,16,16,16,16,16,16,16};
   units.loadTexture("res/Units.png");
   units.initQuads(10);
   for (int x=0;x<10;x++){
     for(int y=0;y<10;y++){
       units.setSpriteLocation (10,x,y,0);
       units.setSpriteTexture(10,un,0,x,y);
     }
   }
   // on fait tourner la boucle principale
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
       window.draw(map);
       window.draw(building);
       window.draw(units);
       window.display();
   }

   return 0;
  }
  else {
    cout << "Please type 'hello' or 'state'" << endl;
  }


  return 0;
}
