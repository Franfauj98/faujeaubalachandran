// Generated by dia2code
#ifndef ENGINE__PRINTSTATS__H
#define ENGINE__PRINTSTATS__H


namespace state {
  class Observable;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class PrintStats - 
  class PrintStats : public engine::Command {
    // Attributes
  private:
    int x;
    int y;
    int element;
    // Operations
  public:
    ~PrintStats ();
    CommandTypeId getTypeId () const;
    void execute (state::Observable& principalMap);
    int get () const;
    PrintStats (int x, int y, int element);
    int getX () const;
    int getY () const;
    int getElement () const;
    // Setters and Getters
  };

};

#endif
