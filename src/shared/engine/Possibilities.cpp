#include "Possibilities.h"
#include <iostream>
using namespace engine;
using namespace std;

Possibilities::~Possibilities (){

}

CommandTypeId Possibilities::getTypeId () const{
  return CommandTypeId::POSSIBILITIES;
}
void Possibilities::execute (state::Observable& map,int x, int y, int element){
  switch(element){
    case 10:
    
    break;
  }
}
