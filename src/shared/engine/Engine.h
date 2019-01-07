// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <queue>
#include <memory>
#include <string>

namespace state {
  class Observable;
};
namespace engine {
  class Command;
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
    bool record     = false;
    std::string message;
    // Operations
  public:
    Engine ();
    ~Engine ();
    void run (state::Observable& principalMap, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2, bool& palace3, int& counter, state::Empire& empire1, state::Empire& empire2, state::Empire& empire3, int& id, int& idPalace, std::string& gold, std::string& wood, std::string& food, std::string& text, int& stop);
    void addCommand (std::unique_ptr<Command> cmd, int commandId);
    void execute (state::Observable& principalMap);
    void rollback (state::Observable& principalMap);
    std::queue<int> getCommandListId ();
    std::deque<int> getCommandListIdPrev ();
    void beginRecord ();
    void openFiles ();
    void replay (state::Observable& principalMap);
    int execReplay (state::Observable& principalMap);
    void setMessage (std::string message);
    std::string getMessage ();
    // Setters and Getters
  };

};

#endif
