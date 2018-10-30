#include "LayerCreator.h"
#include <iostream>
using namespace render;
using namespace std;

LayerCreator::LayerCreator () {

}

LayerCreator::LayerCreator (const std::string& imageFile, int size, std::vector<int> tiles) {
  loadTexture(imageFile);
  initQuads(size);
  for (int x=0;x<size;x++){
    for(int y=0;y<size;y++){
      setSpriteLocation (size,x,y);
      setSpriteTexture(size,tiles,x,y);
    }
  }
}

LayerCreator::LayerCreator(const std::string& fontFile, std::string& text, int size, sf::Color& color, int x, int y){

  this->font.loadFromFile(fontFile);
  this->text.setFont(this->font);
  this->text.setString(text);
  this->text.setCharacterSize(size);
  this->text.setColor(color);
  this->text.setPosition(x,y);

}




void LayerCreator::loadTexture (const std::string& imageFile) {
  // load the texure
  texture.loadFromFile(imageFile);
}

void LayerCreator::initQuads (int size){
  // resize the tab
  quads.setPrimitiveType(sf::Quads);
  quads.resize(size * size * 4);
}

void LayerCreator::setSpriteLocation (int size, int x, int y){
  sf::Vertex* quad = &quads[(x + y * size) * 4];
  // define the four summits
  quad[0].position = sf::Vector2f(x*32 - y*32 + 32 + 12*64, y*16 + x*16 + 0*64);
  quad[1].position = sf::Vector2f(x*32 - y*32 + 64 + 12*64, y*16 + x*16 + 16 + 0*64);
  quad[2].position = sf::Vector2f(x*32 - y*32 + 12*64 + 32 , y*16 + x*16 + 32 + 0*64);
  quad[3].position = sf::Vector2f(x*32 - y*32 + 12*64, y*16 + x*16 + 16 + 0*64);
}

void LayerCreator::setSpriteTexture (int size, vector<int> tiles,int x, int y){
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

void LayerCreator::draw (sf::RenderTarget& target, sf::RenderStates states) const{
  // apply the transformation
  states.transform *= getTransform();

  // apply tileset
  states.texture = &texture;

  // draw the tab
  target.draw(quads, states);

}


void LayerCreator::loadFont (const std::string& fontFile){
  this->font.loadFromFile(fontFile);
}

void LayerCreator::setFont (){
  this->text.setFont(this->font);
}

void LayerCreator::setText (std::string& text){
  this->text.setString(text);
}

void LayerCreator::setCharacterSize (int size){
    this->text.setCharacterSize(size);
}

void LayerCreator::setColor (sf::Color& color){
    this->text.setColor(color);
}

void LayerCreator::setPosition (int x, int y){
    this->text.setPosition(x,y);
}

sf::Text LayerCreator::getText ()const{
    return this->text;
}
