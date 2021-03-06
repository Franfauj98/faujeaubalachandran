// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H


namespace state {
  class Position;
}

#include "Position.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    Position position;
    int type;
    int level;
    // Operations
  public:
    virtual ~Element ();
    bool isPassable ();
    Position& getPosition ();
    void setPosition (const Position& position);
    int distance (Position pos1, Position pos2);
    int getType () const;
    virtual int getLevel () const;
    // Setters and Getters
    void setType(int type);
    void setLevel(int level);
  };

};

#endif
