// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <memory>
#include <string>
#include <stdlib.h>

namespace render {
  class Surface;
  class TileSet;
}

#include "Surface.h"
#include "TileSet.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    std::unique_ptr<Surface> surface;
    std::shared_ptr<Tileset> tileset;
    // Operations
  public:
    Layer ();
    ~Layer ();
    const Surface* const getSurface ();
    void setSurface (Surface* surface);
    void initSurface ();
    void printText (int x, int y, const std::string& msg, size_t tileMinIdx, size_t tileMaxIdx);
    // Setters and Getters
    const std::shared_ptr<Tileset>& getTileset() const;
    void setTileset(const std::shared_ptr<Tileset>& tileset);
  };

};

#endif
