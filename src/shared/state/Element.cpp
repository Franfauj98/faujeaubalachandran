#include "Element.h"
#include <iostream>

using namespace state;

Element::Element() {
  Position pos0(0,0);
  this->position=pos0;

}

Element::Element(Position position) : position(position){}

Position& Element::getPosition(){
  return position;
}

void Element::setPosition (const Position& pos){
  try{
    if(pos.getX()>0&&pos.getY()>0 && pos.getX()<10000 && pos.getY()<10000){
      this->position = pos;
    } else {
      Position p;
      throw std::string("Position must be positive  or on the map ");
      this->position = p;
    }
  } catch (std::string error){
    std::cerr << error << std::endl;
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
