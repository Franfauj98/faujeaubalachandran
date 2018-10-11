// Generated by dia2code
#ifndef STATE__BUILDINGS__H
#define STATE__BUILDINGS__H


namespace state {
  class Position;
  class Element;
}

#include "Position.h"
#include "IdTexture.h"
#include "Element.h"

namespace state {

  /// class Buildings - 
  class Buildings : public state::Element {
    // Associations
    state::IdTexture idTexture;
    // Attributes
  protected:
    int idBuilding;
    int level;
    // Operations
  public:
    Buildings ();
    Buildings (int id, Position position, int level, IdTexture idTexture);
    int getId () const;
    void setId (int id);
    int getLevel () const;
    void setLevel (int level);
    // Setters and Getters
    IdTexture getIdTexture() const;
    void setIdTexture(IdTexture idTexture);
    int getIdBuilding() const;
    void setIdBuilding(int idBuilding);
  };

};

#endif