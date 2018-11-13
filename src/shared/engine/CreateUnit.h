// Generated by dia2code
#ifndef ENGINE__CREATEUNIT__H
#define ENGINE__CREATEUNIT__H


namespace state {
  class Observable;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class CreateUnit - 
  class CreateUnit : public engine::Command {
    // Attributes
  private:
    int x;
    int y;
    int x2;
    int y2;
    int unit;
    // Operations
  public:
    ~CreateUnit ();
    CommandTypeId getTypeId () const;
    void execute (state::Observable& principalMap);
    CreateUnit (int x, int y, int x2, int y2, int unit);
    // Setters and Getters
  };

};

#endif
