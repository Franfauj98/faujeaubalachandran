#include "Position.h"

using namespace state;

Position::Position () {
  this->x = 0;
  this->y = 0;
}

Position::Position (int x, int y) : x(x), y(y){}

int Position::getX() const{
  return x;
}

int Position::getY() const{
  return y;
}

Position::~Position(){

}
