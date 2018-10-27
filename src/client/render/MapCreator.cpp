#include "MapCreator.h"
#include <iostream>
using namespace render;
using namespace std;

void MapCreator::loadTexture (const std::string& imageFile) {
  // load the texure
  texture.loadFromFile(imageFile);
}

void MapCreator::initQuads (int size){
  // resize the tab
  quads.setPrimitiveType(sf::Quads);
  quads.resize(size * size * 4);
}

void MapCreator::setSpriteLocation (int size, int x, int y){
  sf::Vertex* quad = &quads[(x + y * size) * 4];
  // define the four summits
  quad[0].position = sf::Vector2f(x*32 - y*32 + 32 + 12*64, y*16 + x*16 + 0*64);
  quad[1].position = sf::Vector2f(x*32 - y*32 + 64 + 12*64, y*16 + x*16 + 16 + 0*64);
  quad[2].position = sf::Vector2f(x*32 - y*32 + 12*64 + 32 , y*16 + x*16 + 32 + 0*64);
  quad[3].position = sf::Vector2f(x*32 - y*32 + 12*64, y*16 + x*16 + 16 + 0*64);
}

void MapCreator::setSpriteTexture (int size, vector<int> tiles,int x, int y){
  // curent tile number
  int tileNumber = tiles[x + y * size];

  // on en déduit sa position dans la texture du tileset
  int tu = tileNumber % (texture.getSize().x / 64);
  int tv = tileNumber / (texture.getSize().x / 64);
  sf::Vertex* quad = &quads[(x + y * size) * 4];
  // define the four summits for the texture
  quad[0].texCoords = sf::Vector2f(tu * 64+64/2, tv * 32);
  quad[1].texCoords = sf::Vector2f((tu + 1) * 64, tv * 32+32/2);
  quad[2].texCoords = sf::Vector2f((tu + 1) * 64-64/2, (tv + 1) * 32);
  quad[3].texCoords = sf::Vector2f(tu * 64, (tv + 1) * 32-32/2);

}

void MapCreator::draw (sf::RenderTarget& target, sf::RenderStates states) const{
  // apply the transformation
  states.transform *= getTransform();

  // apply tileset
  states.texture = &texture;

  // draw the tab
  target.draw(quads, states);

}
