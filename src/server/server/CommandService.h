// Generated by dia2code
#ifndef SERVER__COMMANDSERVICE__H
#define SERVER__COMMANDSERVICE__H

#include <json/json.h>

namespace server {
  class CommandDB;
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"
#include "CommandDB.h"

namespace server {

  /// class CommandService - 
  class CommandService : public server::AbstractService {
    // Associations
    // Attributes
  protected:
    CommandDB& commandDB;
    // Operations
  public:
    CommandService (CommandDB& commandDB);
    HttpStatus get (Json::Value& out, int id) const;
    HttpStatus post (const Json::Value& in, int id);
    HttpStatus put (Json::Value& out, const Json::Value& in);
    HttpStatus remove (int id);
    HttpStatus getAll (Json::Value& out) const;
    // Setters and Getters
    CommandDB& getCommandDB() const;
    void setCommandDB(const CommandDB&& commandDB);
  };

};

#endif