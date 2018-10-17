// Generated by dia2code
#ifndef STATE__RESSOURCE__H
#define STATE__RESSOURCE__H


namespace state {
  class Position;
  class BuildingCost;
  class Buildings;
}

#include "Position.h"
#include "IdTexture.h"
#include "BuildingCost.h"
#include "Buildings.h"

namespace state {

  /// class Ressource - 
  class Ressource : public state::Buildings {
    // Attributes
  private:
    int production;
    // Operations
  public:
    Ressource ();
    Ressource (int id, Position position, int level);
    Ressource (int production, int id, Position position, int level, IdTexture idTexture, BuildingCost ressourceCost);
    int getProduction () const;
    void setProduction (const int production);
    ~Ressource ();
    // Setters and Getters
  };

};

#endif
