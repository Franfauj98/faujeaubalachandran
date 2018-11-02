// Generated by dia2code
#ifndef RENDER__UPDATERENDER__H
#define RENDER__UPDATERENDER__H

#include <vector>
#include <memory>

namespace state {
  class Units;
  class Buildings;
};
namespace render {
  class Layer;
}

#include "state/Units.h"
#include "state/Buildings.h"
#include "Layer.h"

namespace render {

  /// class UpdateRender - 
  class UpdateRender {
    // Associations
    // Operations
  public:
    UpdateRender ();
    void ReloadRender (std::vector<std::unique_ptr<state::Units>> units, std::vector<std::unique_ptr<state::Buildings>> building) const;
    // Setters and Getters
  };

};

#endif