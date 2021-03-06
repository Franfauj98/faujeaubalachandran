// Generated by dia2code
#ifndef RENDER__BUILDINGTILESET__H
#define RENDER__BUILDINGTILESET__H

#include <vector>
#include <string>

namespace render {
  class Tile;
};
namespace state {
  class Buildings;
};
namespace render {
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"
#include "state/Buildings.h"

namespace render {

  /// class BuildingTileSet - 
  class BuildingTileSet : public render::TileSet {
    // Associations
    // Attributes
  private:
    std::vector<Tile> palace;
    std::vector<Tile> barrack;
    std::vector<Tile> ressource;
    // Operations
  public:
    BuildingTileSet ();
    ~BuildingTileSet ();
    const std::string getImageFile () const;
    const Tile getTile (const state::Buildings& e) const;
    // Setters and Getters
  };

};

#endif
