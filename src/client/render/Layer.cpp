#include "Layer.h"
#include <iostream>
using namespace render;
using namespace std;

Layer::Layer () {

}
// Layer foir units map, buildings map and decor map
Layer::Layer (const std::string& imageFile, int size, std::vector<int> tiles, int iso) {
  loadTexture(imageFile);
  initQuads(size);
  for (int y=0;y<size;y++){
    for(int x=0;x<size;x++){
      setSpriteLocation (size,x,y,iso);
      setSpriteTexture(size,tiles,x,y,iso);
    }
  }
}

// Layer for text

Layer::Layer(const std::string& fontFile, std::string text, int size, sf::Color color, int x, int y){

  loadFont(fontFile);
  setFont();
  setText(text);
  setCharacterSize(size);
  setColor(color);
  setPosition(x,y);

}

// Layer for background
Layer::Layer(const std::string& imageFile){

  loadTexture(imageFile);
  this->background.setTexture(this->texture);
  this->background.setScale(1.5f,1.15f);

}

void Layer::loadTexture (const std::string& imageFile) {
  // load the texure
  texture.loadFromFile(imageFile);
}

void Layer::initQuads (int size){
  // resize the tab
  quads.setPrimitiveType(sf::Quads);
  quads.resize(size * size * 4);
}

void Layer::setSpriteLocation (int size, int x, int y, int iso){
  sf::Vertex* quad = &quads[(x + y * size) * 4];

  if (iso==1){
    // define the four summits
    quad[0].position = sf::Vector2f(x*32 - y*32 + 32 + 12*64, y*16 + x*16 + 0*64);
    quad[1].position = sf::Vector2f(x*32 - y*32 + 64 + 12*64, y*16 + x*16 + 16 + 0*64);
    quad[2].position = sf::Vector2f(x*32 - y*32 + 12*64 + 32 , y*16 + x*16 + 32 + 0*64);
    quad[3].position = sf::Vector2f(x*32 - y*32 + 12*64, y*16 + x*16 + 16 + 0*64);

  } else {
    quad[0].position = sf::Vector2f(x *32, y * 64);
    quad[1].position = sf::Vector2f((x + 1) * 32, y * 64);
    quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 64);
    quad[3].position = sf::Vector2f(x * 32, (y + 1) * 64);
  }

}

void Layer::setSpriteTexture (int size, vector<int> tiles,int x, int y, int iso){
  // curent tile number
  int tileNumber = tiles[x + y * size];
  // define the four summits for the texture
  if (iso==1){

    // on en déduit sa position dans la texture du tileset
    int tu = tileNumber % (texture.getSize().x / 64);
    int tv = tileNumber / (texture.getSize().x / 64);
    sf::Vertex* quad = &quads[(x + y * size) * 4];

    quad[0].texCoords = sf::Vector2f(tu * 64+64/2, tv * 32);
    quad[1].texCoords = sf::Vector2f((tu + 1) * 64, tv * 32+32/2);
    quad[2].texCoords = sf::Vector2f((tu + 1) * 64-64/2, (tv + 1) * 32);
    quad[3].texCoords = sf::Vector2f(tu * 64, (tv + 1) * 32-32/2);
  }
  else {

    // on en déduit sa position dans la texture du tileset
    int tu = tileNumber % (texture.getSize().x / 32);
    int tv = tileNumber / (texture.getSize().x / 32);
    sf::Vertex* quad = &quads[(x + y * size) * 4];
    quad[0].texCoords = sf::Vector2f(tu * 32, tv * 64);
    quad[1].texCoords = sf::Vector2f((tu + 1) * 32-1, tv * 64);
    quad[2].texCoords = sf::Vector2f((tu + 1) * 32-1, (tv + 1) * 64);
    quad[3].texCoords = sf::Vector2f(tu * 32, (tv + 1) * 64);

  }
}

sf::VertexArray Layer::getQuads() const {
  return this->quads;
}

void Layer::draw (sf::RenderTarget& target, sf::RenderStates states) const{
  // apply the transformation
  states.transform *= getTransform();

  // apply tileset
  states.texture = &texture;

  // draw the tab
  target.draw(quads, states);

}

void Layer::drawText(sf::RenderWindow& window) const{

  // draw the tab
  window.draw(this->text);

}

void Layer::drawSprite(sf::RenderWindow& window) const{

  // draw the tab
  window.draw(this->background);

}

void Layer::loadFont (const std::string& fontFile){
  this->font.loadFromFile(fontFile);
}

void Layer::setFont (){
  this->text.setFont(this->font);
}

void Layer::setText (std::string& text){
  this->text.setString(text);
}

void Layer::setCharacterSize (int size){
    this->text.setCharacterSize(size);
}

void Layer::setColor (sf::Color& color){
    this->text.setColor(color);
}

void Layer::setPosition (int x, int y){
    this->text.setPosition(x,y);
}

sf::Text Layer::getText ()const{
    return this->text;
}



Layer::~Layer () {

}
