// Generated by dia2code
#ifndef ENGINE__LEVELUP__H
#define ENGINE__LEVELUP__H


namespace state {
  class Observable;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class LevelUp - 
  class LevelUp : public engine::Command {
    // Operations
  public:
    ~LevelUp ();
    CommandTypeId getTypeId () const;
    void execute (state::Observable& map, int x, int y);
    // Setters and Getters
  };

};

#endif
