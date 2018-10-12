// Generated by dia2code
#ifndef STATE__DECURION__H
#define STATE__DECURION__H


namespace state {
  class Position;
  class Units;
}

#include "Position.h"
#include "IdTextureUnits.h"
#include "Units.h"

namespace state {

  /// class Decurion - 
  class Decurion : public state::Units {
    // Operations
  public:
    Decurion ();
    Decurion (int level, int id, Position position, int life, int dammage, int strikeRange, int movingRange, IdTextureUnits idTextureUnits);
    Decurion (int level, Position position, int id);
    ~Decurion ();
    // Setters and Getters
  };

};

#endif
