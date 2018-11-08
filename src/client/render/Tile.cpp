#include "Tile.h"
#include <iostream>
using namespace render;
using namespace std;

Tile::Tile (){
  this->x= 0;
  this->width= 64;
  this->height= 32;
}

Tile::Tile (int x, int width, int height){
  this->x= x;
  this->width= width;
  this->height= height;
}

int Tile::getX() const{
  return this->x;
}

void Tile::setX(int x){
  this->x=x;
}

int Tile::getWidth() const{
  return this->width;
}

void Tile::setWidth(int width){
  this->width=width;
}

int Tile::getHeight() const{
  return this->height;
}

void Tile::setHeight(int height){
  this->height=height;
}
