#include "Arrow.h"
using namespace state;

// Arrow::Arrow () : Units(1, position, life, damage, strikeRange, movingRange, level, idTextureUnits) {}

Arrow::Arrow (int level, Position p, int id, int life, int damage, int strikeRange, int movingRange, int idTextureUnits) :
  Units(id, p, life, damage, strikeRange, movingRange, level, idTextureUnits) {}
