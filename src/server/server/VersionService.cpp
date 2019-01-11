/**
 * @file VersionService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "VersionService.hpp"
using namespace server;

VersionService::VersionService () : AbstractService("/version") {

}

HttpStatus VersionService::get (Json::Value& out, int id) const {
  out["major"] = 1;
  out["minor"] = 0;
  return HttpStatus::OK;
}

HttpStatus VersionService::getAll (Json::Value& out) const {
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}
