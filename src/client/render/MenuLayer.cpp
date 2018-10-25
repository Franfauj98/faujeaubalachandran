#include "MenuLayer.h"

using namespace render;
using namespace std;


MenuLayer::MenuLayer(const std::string& fontFile, std::string text, int size, sf::Color color, int x, int y){

  this->font.loadFromFile(fontFile);
  this->text.setFont(this->font);
  this->text.setString(text);
  this->text.setCharacterSize(size);
  this->text.setFillColor(color);
  this->text.setPosition(x,y);
}


void MenuLayer::loadFont (const std::string& fontFile){
  this->font.loadFromFile(fontFile);
}

void MenuLayer::setFont (){
  this->text.setFont(this->font);
}

void MenuLayer::setText (std::string text){
  this->text.setString(text);
}

void MenuLayer::setCharacterSize (int size){
    this->text.setCharacterSize(size);
}

void MenuLayer::setColor (sf::Color color){
    this->text.setFillColor(color);
}

void MenuLayer::setPosition (int x, int y){
    this->text.setPosition(x,y);
}
