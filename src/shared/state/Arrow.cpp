#include "Arrow.h"
using namespace state;

// Arrow::Arrow () : Units(1, position, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Arrow::Arrow (int level,int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}
