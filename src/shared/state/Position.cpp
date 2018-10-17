#include "Position.h"
#include <iostream>

using namespace state;

Position::Position () : x(0), y(0) {}

Position::Position (int x, int y) {
  try{
    if(x>=0 && x<10000){
      this->x = x;
    } else {
      throw std::string("X must be positive or be on the map");
      this->x = 0;
    }
    if(y>=0 && y<10000){
      this->y = y;
    } else{
      throw std::string("Y must be positive or be on the map")  ;
      this->y = 0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

int Position::getX() const{
  return this->x;
}

int Position::getY() const{
  return this->y;
}

void Position::setX(const int x) {
  try{
    if(x>=0 && x<10000){
      this->x = x;
    } else {
      throw std::string("X must be positive or be on the map");
      this->x = 0;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

void Position::setY(const int y) {
  if(y>=0 && y<10000){
    this->y = y;
  } else{
    throw std::string("Y must be positive or be on the map");
    this->y = 0;
  }
}

Position::~Position(){

}
