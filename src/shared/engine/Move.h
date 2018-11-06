// Generated by dia2code
#ifndef ENGINE__MOVE__H
#define ENGINE__MOVE__H


namespace state {
  class Observable;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class Move - 
  class Move : public engine::Command {
    // Operations
  public:
    ~Move ();
    CommandTypeId getTypeId () const;
    void execute (state::Observable& map, int x, int y, int x2, int y2);
    // Setters and Getters
  };

};

#endif
