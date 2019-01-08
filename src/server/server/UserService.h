// Generated by dia2code
#ifndef SERVER__USERSERVICE__H
#define SERVER__USERSERVICE__H

#include <json/json.h>

namespace server {
  class UserDB;
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"
#include "UserDB.h"

namespace server {

  /// class UserService - 
  class UserService : public server::AbstractService {
    // Associations
    // Attributes
  protected:
    UserDB& userDB;
    // Operations
  public:
    UserService (UserDB& userDB);
    HttpStatus get (Json::Value& out, int id) const;
    HttpStatus post (const Json::Value& in, int id);
    HttpStatus put (Json::Value& out, const Json::Value& in);
    HttpStatus remove (int id);
    HttpStatus getAll (Json::Value& out);
    // Setters and Getters
    UserDB& getUserDB() const;
    void setUserDB(const UserDB&& userDB);
  };

};

#endif
