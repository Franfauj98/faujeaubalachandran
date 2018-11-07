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
  private:
    std::vector<std::unique_ptr<Element>> basicMap;
    std::vector<std::unique_ptr<Element>> decorMap;
    std::vector<std::unique_ptr<Element>> unitsMap;
    std::vector<std::unique_ptr<Element>> buildingsMap;
    std::vector<std::unique_ptr<Element>> selectedMap;
    std::vector<int> statsMap;
    std::vector< std::vector<int> >   mapMatrix;
    int size     = 25;
    // Operations
  public:
    Map ();
    virtual ~Map ();
    void addElement (std::vector<std::unique_ptr<Element>> vect, std::unique_ptr<Element> elt);
    std::vector<std::unique_ptr<Element>>& getBasicMap ();
    void deleteElement (int pos);
    int getPositionElement (std::unique_ptr<Element> elt);
    std::vector<std::unique_ptr<Element>> & getDecorMap ();
    std::vector<std::unique_ptr<Element>> & getUnitsMap ();
    std::vector<std::unique_ptr<Element>> & getBuildingsMap ();
    std::vector<int> getBasicMapId ();
    std::vector<int> getDecorMapId ();
    std::vector<int> getUnitsMapId ();
    std::vector<int> getBuildingsMapId ();
    int getSize () const;
    std::vector<std::vector<int> >& getMapMatrix ();
    void addUnitsToMap (std::unique_ptr<Element>& unitsToMap, int& position);
    void deleteUnitsOnMap (std::unique_ptr<Element> unit);
    void setStatsMap (std::vector<int>& statsMap);
    void setSelectedMap (std::vector<std::unique_ptr<Element>>& selectedMap);
    std::vector<std::unique_ptr<Element>> & getSelectedMap ();
    std::vector<int> getStatsMap ();
    std::vector<int> getSelectedMapId ();
    // Setters and Getters
  };

};

#endif
