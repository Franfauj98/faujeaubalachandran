// Generated by dia2code
#ifndef STATE__BUILDINGS__H
#define STATE__BUILDINGS__H


namespace state {
  class BuildingCost;
  class Position;
  class Element;
}

#include "BuildingCost.h"
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
    BuildingCost buildingCost;
    int life     = 0;
    // Operations
  public:
    Buildings ();
    Buildings (int id, Position position, int level, IdTexture idTexture, BuildingCost buildingCost, int life = 0);
    int getLevel () const;
    void setLevel (const int level);
    BuildingCost getBuildingCost () const;
    void setBuildingCost (const BuildingCost buildingCost);
    bool isPassable ();
    int getLife () const;
    void setLife (const int life);
    virtual ~Buildings ();
    // Setters and Getters
    IdTexture getIdTexture() const;
    void setIdTexture(IdTexture idTexture);
    int getIdBuilding() const;
    void setIdBuilding(int idBuilding);
  };

};

#endif
