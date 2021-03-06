// Generated by dia2code
#ifndef STATE__ARROW__H
#define STATE__ARROW__H


namespace state {
  class Position;
  class UnitCost;
  class Units;
}

#include "Position.h"
#include "IdTextureUnits.h"
#include "UnitCost.h"
#include "Units.h"

namespace state {

  /// class Arrow - 
  class Arrow : public state::Units {
    // Operations
  public:
    Arrow ();
    Arrow (int level, int id, Position p, int life, int damage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits, UnitCost arrowCost);
    Arrow (int level, Position position, int id);
    virtual ~Arrow ();
    // Setters and Getters
  };

};

#endif
