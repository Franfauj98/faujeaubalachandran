// Generated by dia2code
#ifndef ENGINE__CASEIDENTIFIER__H
#define ENGINE__CASEIDENTIFIER__H


namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class CaseIdentifier - 
  class CaseIdentifier : public engine::Command {
    // Operations
  public:
    ~CaseIdentifier ();
    CommandTypeId getTypeId () const;
    void execute (int x, int y);
    // Setters and Getters
  };

};

#endif
