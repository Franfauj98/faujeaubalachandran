/**
 * @file PlayerDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "PlayerDB.hpp"
#include <iostream>
#include <string>
using namespace server;
using namespace std;

PlayerDB::PlayerDB() : idseq(1) {

}

const Player* PlayerDB::getPlayer (int id) const {
    auto ite = players.find(id);
    if (ite == players.cend())
        return nullptr;
    return ite->second.get();
}

std::string PlayerDB::getAllPlayer () {
  std::string allPlayers = "[";
  for (std::map<int,unique_ptr<Player>>::iterator it=players.begin(); it!=players.end(); ++it){
    //     std::cout << it->first << " => " << it->second << '\n';
    // auto ite = allPlayers[i];
    Player *player = it->second.get();
    allPlayers+=("{\"name\": \""+player->name+"\", \"type\": "+to_string(player->type)+"},");
  }
  allPlayers.pop_back();
  allPlayers+= "]";
  return allPlayers;
}

int PlayerDB::addPlayer (unique_ptr<Player> player) {
    int id = idseq++;
    players.insert(std::make_pair(id,std::move(player)));
    return id;
}

void PlayerDB::setPlayer (int id, unique_ptr<Player> player) {
    players[id] = std::move(player);
    if (id > idseq) {
        idseq = id;
    }
}

void PlayerDB::removePlayer (int id) {
    auto ite = players.find(id);
    if (ite == players.end())
        return;
    players.erase(ite);
}
