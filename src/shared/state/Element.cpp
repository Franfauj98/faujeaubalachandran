#include "Element.h"

using namespace state;

Element::Element() {
  Position position;
}

Element::Element(Position position) : position(position){}

Position& Element::getPosition(){
  return position;
}

void Element::setPosition (Position& pos){
  position = pos;
}

Element::~Element(){
  // delete &position;
}
