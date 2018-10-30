#include "Position.h"
#include <iostream>

using namespace state;

Position::Position () : x(0), y(0) {}

Position::Position (int x, int y) {
  try{
    if(x>=0 && x<=30 && y>=0 && y<=30){
      this->x = x;
      this->y = y;
    } else {
      throw std::string("Position must be positive or be on the map");
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
    if(x>=0 && x<=25){
      this->x = x;
    } else {
      this->x = 0;
      throw std::string("X must be positive or be on the map");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

void Position::setY(const int y) {
  try{
    if(y>=0 && y<=25){
      this->y = y;
    } else{
      this->y = 0;
      throw std::string("Y must be positive or be on the map");
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
    }
}

Position::~Position(){

}
