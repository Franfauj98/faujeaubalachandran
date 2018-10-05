// Generated by dia2code
#ifndef STATE__DECOR__H
#define STATE__DECOR__H


namespace state {
  class Position;
  class Element;
}

#include "Position.h"
#include "Element.h"
#include "IdDecor.h"

namespace state {

  /// class Decor - 
  class Decor : public state::Element {
    // Associations
    state::IdDecor idDecor;
    // Attributes
  private:
    bool passable;
    // Operations
  public:
    Decor (int id, Position position);
    // Setters and Getters
    IdDecor getIdDecor() const;
    void setIdDecor(IdDecor idDecor);
  };

};

#endif
