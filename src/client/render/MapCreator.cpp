#include "MapCreator.h"
#include <iostream>
using namespace render;
using namespace std;

void MapCreator::loadTexture (const std::string& imageFile) {
  // on charge la texture du tileset
  texture.loadFromFile(imageFile);
}

void MapCreator::initQuads (int size){
  // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
  quads.setPrimitiveType(sf::Quads);
  quads.resize(size * size * 4);
}

void MapCreator::setSpriteLocation (int size, int x, int y,int form){
  sf::Vertex* quad = &quads[(x + y * size) * 4];
  // on définit ses quatre coins
  quad[0].position = sf::Vector2f(x*32 - y*32 + 32 + 14*64, y*16 + x*16 + 1*64);
  quad[1].position = sf::Vector2f(x*32 - y*32 + 64 + 14*64, y*16 + x*16 + 16 + 1*64);
  quad[2].position = sf::Vector2f(x*32 - y*32 + 14*64 + 32 , y*16 + x*16 + 32 + 1*64);
  quad[3].position = sf::Vector2f(x*32 - y*32 + 14*64, y*16 + x*16 + 16 + 1*64);
}

void MapCreator::setSpriteTexture (int size, vector<int> tiles, int form,int x, int y){
  // on récupère le numéro de tuile courant
  int tileNumber = tiles[x + y * size];

  // on en déduit sa position dans la texture du tileset
  int tu = tileNumber % (texture.getSize().x / 64);
  int tv = tileNumber / (texture.getSize().x / 64);
  sf::Vertex* quad = &quads[(x + y * size) * 4];
  // on définit ses quatre coins
  if (form==0){

    quad[0].texCoords = sf::Vector2f(tu * 64+64/2, tv * 32);
    quad[1].texCoords = sf::Vector2f((tu + 1) * 64, tv * 32+32/2);
    quad[2].texCoords = sf::Vector2f((tu + 1) * 64-64/2, (tv + 1) * 32);
    quad[3].texCoords = sf::Vector2f(tu * 64, (tv + 1) * 32-32/2);
  }
  else if (form==1){
     quad[0].texCoords = sf::Vector2f(tu * 64, tv * 32);
     quad[1].texCoords = sf::Vector2f((tu + 1) * 64, tv * 32);
     quad[2].texCoords = sf::Vector2f((tu + 1) * 64, (tv + 1) * 32);
     quad[3].texCoords = sf::Vector2f(tu * 64, (tv + 1) * 32);
  }

}

void MapCreator::draw (sf::RenderTarget& target, sf::RenderStates states) const{
  // on applique la transformation
  states.transform *= getTransform();

  // on applique la texture du tileset
  states.texture = &texture;

  // et on dessine enfin le tableau de vertex
  target.draw(quads, states);

}
