#include "Position.h"
#include <iostream>

using namespace state;

Position::Position () : x(0), y(0) {}

Position::Position (int x, int y) {
  if(x>=0){
    this->x = x;
  } else {
    std::cerr << "X must be >= 0"<< std::endl;
    this->x = 0;
  }
  if(y>=0){
    this->y = y;
  } else{
    std::cerr << "Y must be >= 0"<< std::endl;
    this->y = 0;
  }
}

int Position::getX() const{
  return x;
}

int Position::getY() const{
  return y;
}

Position::~Position(){

}
