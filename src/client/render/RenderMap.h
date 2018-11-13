// Generated by dia2code
#ifndef RENDER__RENDERMAP__H
#define RENDER__RENDERMAP__H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

namespace render {
  class Layer;
};
namespace state {
  class Observable;
};
namespace sf {
  class RenderWindow;
};
namespace engine {
  class Engine;
};
namespace render {
  class TileSet;
}

#include "Layer.h"
#include "engine/Engine.h"
#include "TileSet.h"
#include "state/Observable.h"

namespace render {

  /// class RenderMap - 
  class RenderMap {
    // Associations
    // Attributes
  private:
    Layer basicMap;
    Layer decorMap;
    Layer buildingMap;
    Layer unitMap;
    Layer statsMap;
    std::unique_ptr<Layer> background;
    Layer selectedMap;
    Layer gold;
    Layer wood;
    Layer food;
    Layer message;
    // Operations
  public:
    RenderMap ();
    ~RenderMap ();
    Layer getBuildingMap () const;
    Layer getBasicMap () const;
    Layer getDecorMap () const;
    Layer getUnitMap () const;
    Layer getStatsMap () const;
    std::unique_ptr<Layer> const& getBackground () const;
    Layer getSelectedMap () const;
    void setBuildingMap (Layer* buildingLayer);
    void setUnitMap (Layer* unitLayer);
    void setStatsMap (Layer* statsLayer);
    void setSelectedMap (Layer* selectedLayer);
    void update (state::Observable& principalMap, std::string gold, std::string wood, std::string food, std::string message);
    Layer getGold () const;
    Layer getWood () const;
    Layer getFood () const;
    Layer getMessage () const;
    void drawMap (sf::RenderWindow& window);
    void handle (sf::RenderWindow& window, state::Observable& principalMap, engine::Engine& engine, sf::Event& event);
    // Setters and Getters
  };

};

#endif
