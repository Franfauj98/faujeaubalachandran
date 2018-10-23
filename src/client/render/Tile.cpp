#include "Tile.h"
#include <iostream>
using namespace render;
using namespace std;

Tile::Tile (){
  this->x= 0;
  this->y= 0;
  this->width= 64;
  this->height= 32;
}
Tile::Tile (int x, int y, int width, int height){
  this->x= x;
  this->y= y;
  this->width= width;
  this->height= height;
}
// Setters and Getters
int Tile::getX() const{
  return this->x;
}

void Tile::setX(int x){
  this->x=x;
}

int Tile::getY() const{
  return this->y;
}

void Tile::setY(int y){
  this->y=y;
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
