// Generated by dia2code
#ifndef CLIENT__CLIENT__H
#define CLIENT__CLIENT__H

#include <memory>
#include <mutex>
#include <SFML/Graphics.hpp>
#include <string>

namespace engine {
  class Engine;
};
namespace state {
  class Observable;
};
namespace render {
  class RenderMap;
};
namespace ai {
  class HeuristicAI;
}

#include "engine/Engine.h"
#include "state/Observable.h"
#include "render/RenderMap.h"
#include "ai/HeuristicAI.h"

namespace client {

  /// class Client - 
  class Client {
    // Associations
    // Attributes
  private:
    engine::Engine engine;
    std::unique_ptr<state::Observable> principalMap;
    render::RenderMap map;
    ai::HeuristicAI heuristic;
    std::mutex m;
    // Operations
  public:
    Client ();
    void run ();
    void aiUpdating (int& counter, bool& canPlay1, bool& canPlay2, bool& canPlay3, int& controller, sf::RenderWindow& window, int& stop);
    void engineUpdating (int& renderSignal, int& id, std::string& gold, std::string& wood, std::string& food, std::string& text, sf::RenderWindow& window, int& stop);
    void playerUpdating (state::Observable& principalMap, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2, bool& palace3, int& counter, state::Empire& empire1, state::Empire& empire2, state::Empire& empire3, int& id, int& idPalace, int& stop, int& controller, int player, bool& firstC, bool& secondC, bool& thirdC, sf::RenderWindow& window);
    void connect ();
    // Setters and Getters
  };

};

#endif
