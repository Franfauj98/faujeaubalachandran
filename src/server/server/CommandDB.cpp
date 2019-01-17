#include "CommandDB.hpp"
#include <iostream>
#include <string>
#include <json/json.h>

using namespace server;
using namespace std;

CommandDB::CommandDB() : idseq(1) {

}

const Command* CommandDB::getCommand (int id) const {
    auto ite = commands.find(id);
    if (ite == commands.cend())
        return nullptr;
    return ite->second.get();
}

Json::Value CommandDB::getAllCommand () {
  Json::Value foo, command1;
  for (std::map<int,unique_ptr<Command>>::iterator it=commands.begin(); it!=commands.end(); ++it){
    Command *command = it->second.get();
    command1["num"] = command->num;
    command1["id"] = command->id;
    command1["x"] = command->x;
    command1["y"] = command->y;
    command1["x2"] = command->x2;
    command1["y2"] = command->y2;
    command1["unit"] = command->unit;
    command1["element"] = command->element;
    command1["message"] = command->message;
    foo.append(command1);
  }
  return foo;
}

int CommandDB::addCommand (unique_ptr<Command> command) {
    int id = idseq++;
    commands.insert(std::make_pair(id,std::move(command)));
    return id;
}

void CommandDB::setCommand (int id, unique_ptr<Command> command) {
    commands[id] = std::move(command);
    if (id > idseq) {
        idseq = id;
    }
}

void CommandDB::removeCommand (int id) {
    auto ite = commands.find(id);
    if (ite == commands.end())
        return;
    commands.erase(ite);
}

int CommandDB::getIdseq () const{
  return this->idseq;
}
