/**
 * @file PlayerService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "PlayerService.hpp"
using namespace server;

PlayerService::PlayerService (PlayerDB& playerDB) : AbstractService("/player"),
    playerDB(playerDB) {

}

HttpStatus PlayerService::get (Json::Value& out, int id) const {
  // const Player *player = playerDB.getPlayer(id);
  // if (!player)
  //     throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
  //
  // out["type"] = player->type;
  // out["name"] = player->name;
  // return HttpStatus::OK;
  // std::cout << "/* message */" << '\n';
  // std::cout << playerDB.getAllPlayer() << '\n';
  out["players"] = playerDB.getAllPlayer();
  return HttpStatus::OK;
}

// HttpStatus PlayerService::getAll (Json::Value& out) const {
  // int i = 1;
  // int j = 1;
  // while(j){
  //   const Player *player = playerDB.getPlayer(i);
  //   if (!player)
  //       throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
  //   out[i]["type"] = player->type;
  //   out[i]["name"] = player->name;
  //   std::cout << player->type << '\n';
  //   std::cout << player->name << '\n';
  //   i++;
  // const map<int,unique_ptr<Player> > allPlayers = playerDB.getAllPlayer();
  // for(size_t i = 0; i < allPlayers.size(); i++){
  //   auto ite = allPlayers[i];
  //   Player *player = ite->second.get();
  //   std::cout << player->type << '\n';
  //   std::cout << player->name << '\n';
  //   return HttpStatus::OK;
  // }

//   }
//   return HttpStatus::OK;
// }

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
