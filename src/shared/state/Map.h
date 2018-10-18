// Generated by dia2code
#ifndef STATE__MAP__H
#define STATE__MAP__H

#include <vector>

namespace state {
  class Element;
  class Empire;
}

#include "Empire.h"
#include "Element.h"

namespace state {

  /// class Map - 
  class Map {
    // Associations
    // Attributes
  private:
    std::vector<Element*> playingMap;
    // Operations
  public:
    Map ();
    ~Map ();
    void addElement (Element* elt);
    std::vector<Element*> getMap () const;
    void deleteElement (int pos);
    int getPositionElement (Element* elt);
    // Setters and Getters
  };

};

#endif
