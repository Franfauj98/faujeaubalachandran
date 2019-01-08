/**
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"
using namespace server;

UserService::UserService (UserDB& userDB) : AbstractService("/user"),
    userDB(userDB) {

}

HttpStatus UserService::get (Json::Value& out, int id) const {
  const User *user = userDB.getUser(id);
  if (!user)
      throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");

  out["age"] = user->age;
  out["name"] = user->name;
  return HttpStatus::OK;
}

// HttpStatus UserService::getAll (Json::Value& out) const {
//   int i = 1;
//   int j = 1;
//   while(j){
//     const User *user = userDB.getUser(i);
//     if (!user)
//         throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
//     out[i]["age"] = user->age;
//     out[i]["name"] = user->name;
//     std::cout << user->age << '\n';
//     std::cout << user->name << '\n';
//     i++;
//   }
//   return HttpStatus::OK;
// }

HttpStatus UserService::post (const Json::Value& in, int id) {
  const User *user = userDB.getUser(id);
  if (!user)
    throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");

  unique_ptr<User> newUser (new User(*user));
  if(in.isMember("name")) newUser->name = in["name"].asString();
  if(in.isMember("age")) newUser->age = in["age"].asInt();
  userDB.setUser(id,std::move(newUser));
  return HttpStatus::NO_CONTENT;

}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
  string name = in["name"].asString();
  int age = in["age"].asInt();
  out["id"] = userDB.addUser(make_unique<User>(name,age));
  return HttpStatus::CREATED;
}

HttpStatus UserService::remove (int id) {
  const User* user = userDB.getUser(id);
  if (!user)
      throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
  userDB.removeUser(id);
  return HttpStatus::NO_CONTENT;
}
