// Generated by dia2code
#ifndef STATE__OBSERVABLE__H
#define STATE__OBSERVABLE__H


namespace state {
  class UnitsObserver;
  class BuildingObserver;
}

#include "UnitsObserver.h"
#include "BuildingObserver.h"

namespace state {

  /// class Observable - 
  class Observable {
    // Associations
    // Operations
  public:
    ~Observable ();
    void notifyObserver () const;
    // Setters and Getters
  };

};

#endif
