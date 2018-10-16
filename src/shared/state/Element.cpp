#include "Element.h"
#include <iostream>

using namespace state;

Element::Element() {

}

Element::Element(Position position) : position(position){}

Position& Element::getPosition(){
  return position;
}

void Element::setPosition (Position& pos){
  if(pos.getX()>0&&pos.getY()>0){
    this->position = pos;
  } else {
    std::cerr << "Position must be >= 0"<< std::endl;
    Position p;
    this->position = p;
  }
}

int Element::distance(Position pos1, Position pos2){
  int absdiff, orddiff;
  absdiff = std::abs(pos1.getX() - pos2.getX());
  orddiff = std::abs(pos1.getY() - pos2.getY());
  return(absdiff+orddiff);
}

Element::~Element(){
  // delete &position;
}
