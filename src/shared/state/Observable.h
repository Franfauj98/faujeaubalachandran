// Generated by dia2code
#ifndef STATE__OBSERVABLE__H
#define STATE__OBSERVABLE__H

#include <memory>

namespace state {
  class Map;
  class Observable;
  class Element;
  class UnitsObserver;
  class BuildingsObserver;
}

#include "Map.h"
#include "Element.h"
#include "UnitsObserver.h"
#include "BuildingsObserver.h"

namespace state {

  /// class Observable - 
  class Observable {
    // Associations
    // Attributes
  private:
    Map allMaps;
    // Operations
  public:
    ~Observable ();
    void notifyObserver (state::Observable& observable, std::unique_ptr<Element> toChange, int position, int idToChange, int action, int unitToCreate, int level, int position2) const;
    Observable ();
    Map& getAllMaps ();
    // Setters and Getters
  };

};

#endif
