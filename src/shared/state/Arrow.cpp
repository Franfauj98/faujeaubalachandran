#include "Arrow.h"
using namespace state;

// Arrow::Arrow () : Units(1, position, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Arrow::Arrow (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Arrow::Arrow (int level, Position p, int id){
  switch(level){
    case 1 :
      Units(id, p, 1000, 100, 2, 1, level, ARROW1);
      break;
    case 2 :
      Units(id, p, 2000, 200, 2, 1, level, ARROW2);
      break;
    case 3 :
      Units(id, p, 3000, 300, 3, 1, level, ARROW3);
      break;
    case 4 :
      Units(id, p, 4000, 400, 3, 1, level, ARROW4);
      break;
    default :
      Units(id, p, 1000, 100, 2, 1, 1, ARROW1);
      break;
  }
}

Arrow::~Arrow(){

}
