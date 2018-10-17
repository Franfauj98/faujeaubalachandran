#include "Position.h"
#include <iostream>

using namespace state;

Position::Position () : x(0), y(0) {}

Position::Position (int x, int y) {
  if(x>=0 && x<10000){
    this->x = x;
  } else {
    std::cerr << "X must be positive or be on the map"<< std::endl;
    this->x = 0;
  }
  if(y>=0 && y<10000){
    this->y = y;
  } else{
    std::cerr << "Y must be positive or be on the map"<< std::endl;
    this->y = 0;
  }
}

int Position::getX() const{
  return this->x;
}

int Position::getY() const{
  return this->y;
}

void Position::setX(const int x) {
  if(x>=0 && x<10000){
    this->x = x;
  } else {
    std::cerr << "X must be positive or be on the map"<< std::endl;
    this->x = 0;
  }
}

void Position::setY(const int y) {
  if(y>=0 && y<10000){
    this->y = y;
  } else{
    std::cerr << "Y must be positive or be on the map"<< std::endl;
    this->y = 0;
  }
}

Position::~Position(){

}
