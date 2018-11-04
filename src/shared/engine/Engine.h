// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <map>
#include <memory>

namespace engine {
  class Command;
};
namespace render {
  class renderMap;
};
namespace state {
  class Observable;
}

#include "render/renderMap.h"
#include "state/Observable.h"
#include "Command.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  public:
    state::Element currentElement;
  private:
    state::Map curentMap;
    std::map<int, std::unique_ptr<Command>> currentCommand;
    // Operations
  public:
    Engine ();
    ~Engine ();
    const state::Map& getMap () const;
    void addCommand (int priority, Command* command);
    void update ();
    // Setters and Getters
  };

};

#endif
