// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <queue>
#include <memory>

namespace engine {
  class Command;
};
namespace state {
  class Observable;
};
namespace sf {
  class Drawable;
  class Transformable;
  class Font;
  class RenderWindow;
  class Texture;
  class Color;
  class Text;
  class Sprite;
  class VertexArray;
};
namespace render {
  class RenderMap;
}

#include "Command.h"
#include "render/RenderMap.h"
#include "state/Observable.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  private:
    std::queue<std::unique_ptr<Command>> commandList;
    std::deque<std::unique_ptr<Command>> commandListPrev;
    std::queue<int> commandListId;
    std::deque<int> commandListIdPrev;
    // Operations
  public:
    Engine ();
    ~Engine ();
    void addCommand (std::unique_ptr<Command> cmd, int commandId);
    void execute (state::Observable& principalMap);
    void rollback (state::Observable& principalMap);
    std::queue<int> getCommandListId ();
    // Setters and Getters
  };

};

#endif
