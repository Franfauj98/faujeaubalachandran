// Generated by dia2code
#ifndef STATE__UNITS__H
#define STATE__UNITS__H


namespace state {
  class UnitCost;
  class Position;
  class Units;
  class Palace;
  class Buildings;
  class Element;
}

#include "UnitCost.h"
#include "Position.h"
#include "IdTextureUnits.h"
#include "Palace.h"
#include "Element.h"

namespace state {

  /// class Units - 
  class Units : public state::Element {
    // Associations
    state::IdTextureUnits idTextureUnits;
    // Attributes
  private:
    UnitCost unitCost;
  protected:
    int idUnits;
    int life;
    int damage;
    int strikeRange;
    int movingRange     = 1;
    int level;
    // Operations
  public:
    Units ();
    Units (int idUnits, Position position, int life, int damage, int strikeRange, int movingRange, int level, IdTextureUnits idTextureUnits, UnitCost unitCost);
    ~Units ();
    void setLife (const int life);
    int getLife () const;
    void setDamage (const int damage);
    int getDamage () const;
    void setStrikeRange (const int strikeRange);
    int getStrikeRange () const;
    void setMovingRange (const int movingRange);
    int getMovingRange () const;
    void move (Position& p2, int moveNumber);
    bool moveAllowed (Position p2, int moveNumber);
    void attack (Units& unit2);
    bool attackAllowed (Units unit2);
    int getLevel () const;
    void setLevel (const int level);
    IdTextureUnits getIdTextureUnits () const;
    void setIdTextureUnits (const IdTextureUnits idTextureUnits);
    int getIdUnits () const;
    void setIdUnits (const int idUnits);
    UnitCost getUnitCost () const;
    void setUnitCost (const UnitCost unitCost);
    bool isPassable ();
    void attackPalace (Palace palace);
    void attackBuilding (Buildings& building);
    // Setters and Getters
  };

};

#endif
