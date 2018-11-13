// Generated by dia2code
#ifndef ENGINE__CASEIDENTIFIER__H
#define ENGINE__CASEIDENTIFIER__H


namespace state {
  class Observable;
};
namespace engine {
  class Command;
}

#include "state/Observable.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class CaseIdentifier - 
  class CaseIdentifier : public engine::Command {
    // Attributes
  private:
    state::Observable map;
    int x;
    int y;
    // Operations
  public:
    ~CaseIdentifier ();
    CommandTypeId getTypeId () const;
    void execute ();
    // Setters and Getters
  };

};

#endif
