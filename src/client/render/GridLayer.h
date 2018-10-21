// Generated by dia2code
#ifndef RENDER__GRIDLAYER__H
#define RENDER__GRIDLAYER__H


namespace state {
  class Grid;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "state/Grid.h"

namespace render {

  /// class GridLayer - 
  class GridLayer : public render::Layer {
    // Associations
    // Attributes
  private:
    const state::Grid& grid;
    // Operations
  public:
    GridLayer (const state::Grid& grid);
    void initSurface ();
    // Setters and Getters
  };

};

#endif
