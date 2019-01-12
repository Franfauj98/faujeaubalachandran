/**
 * @file PlayerService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */
//Updates from faujeaubalachandran

#include "PlayerService.hpp"
using namespace server;

PlayerService::PlayerService (PlayerDB& playerDB) : AbstractService("/player"),
    playerDB(playerDB) {

}

HttpStatus PlayerService::get (Json::Value& out, int id) const {
  const Player *player = playerDB.getPlayer(id);
  if (!player){
    throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
  }

  out["type"] = player->type;
  out["name"] = player->name;
  return HttpStatus::OK;
}

HttpStatus PlayerService::getAll (Json::Value& out) const {
  out["players"] = playerDB.getAllPlayer();
  return HttpStatus::OK;
}

HttpStatus PlayerService::post (const Json::Value& in, int id) {
  const Player *player = playerDB.getPlayer(id);
  if (!player)
    throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");

  unique_ptr<Player> newPlayer (new Player(*player));
  if(in.isMember("name")) newPlayer->name = in["name"].asString();
  if(in.isMember("type")) newPlayer->type = in["type"].asInt();
  playerDB.setPlayer(id,std::move(newPlayer));
  return HttpStatus::NO_CONTENT;

}

HttpStatus PlayerService::put (Json::Value& out,const Json::Value& in) {
  if(playerDB.getAllPlayer().size()>2) {
    throw ServiceException(HttpStatus::OK,"Already 3 players in the game");
    return HttpStatus::OK;
  }
  string name = in["name"].asString();
  int type = in["type"].asInt();
  out["id"] = playerDB.addPlayer(make_unique<Player>(name,type));
  return HttpStatus::CREATED;
}

HttpStatus PlayerService::remove (int id) {
  const Player* player = playerDB.getPlayer(id);
  if (!player)
      throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
  playerDB.removePlayer(id);
  return HttpStatus::NO_CONTENT;
}
