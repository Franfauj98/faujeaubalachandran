// Generated by dia2code
#ifndef STATE__PALACE__H
#define STATE__PALACE__H


namespace state {
  class Position;
  class Buildings;
}

#include "Position.h"
#include "Buildings.h"

namespace state {

  /// class Palace - 
  class Palace : public state::Buildings {
    // Operations
  public:
    Palace (int id, Position position, int level, int idTexture);
    // Setters and Getters
  };

};

#endif
