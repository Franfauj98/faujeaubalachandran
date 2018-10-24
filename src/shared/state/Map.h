// Generated by dia2code
#ifndef STATE__MAP__H
#define STATE__MAP__H

#include <vector>
#include <memory>

namespace state {
  class Element;
  class Empire;
}

#include "Element.h"
#include "Empire.h"

namespace state {

  /// class Map - 
  class Map {
    // Associations
    // Attributes
  public:
    int size     = 20;
  private:
    std::vector<std::unique_ptr<Element>> basicMap;
    std::vector<std::unique_ptr<Element>> decorMap;
    std::vector<std::unique_ptr<Element>> unitsMap;
    std::vector<std::unique_ptr<Element>> buildingsMap;
    // Operations
  public:
    Map ();
    ~Map ();
    void addElement (std::vector<std::unique_ptr<Element>> vect, std::unique_ptr<Element> elt);
    std::vector<std::unique_ptr<Element>> const& getBasicMap ();
    void deleteElement (int pos);
    int getPositionElement (std::unique_ptr<Element> elt);
    std::vector<std::unique_ptr<Element>> const& getDecorMap ();
    std::vector<std::unique_ptr<Element>> const& getUnitsMap ();
    std::vector<std::unique_ptr<Element>> const& getBuildingsMap ();
    std::vector<int> getBasicMapId ();
    std::vector<int> getDecorMapId ();
    std::vector<int> getUnitsMapId ();
    std::vector<int> getBuildingsMapId ();
    int getSize () const;
    // Setters and Getters
  };

};

#endif
