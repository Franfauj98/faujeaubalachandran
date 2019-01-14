#include "CommandService.hpp"
using namespace server;

CommandService::CommandService (CommandDB& commandDB) : AbstractService("/command"),
    commandDB(commandDB) {
}

HttpStatus CommandService::get (Json::Value& out, int id) const {
  const Command *command = commandDB.getCommand(id);
  if (!command){
    throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
  }
  out["num"] = command->num;
  out["id"] = command->id;
  out["x"] = command->x;
  out["y"] = command->y;
  out["x2"] = command->x2;
  out["y2"] = command->y2;
  out["unit"] = command->unit;
  out["element"] = command->element;
  return HttpStatus::OK;
}

HttpStatus CommandService::getAll (Json::Value& out) const {
  out["commands"] = commandDB.getAllCommand();
  return HttpStatus::OK;
}

HttpStatus CommandService::post (const Json::Value& in, int id) {
  const Command *command = commandDB.getCommand(id);
  if (!command)
    throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
  unique_ptr<Command> newCommand (new Command(*command));
  if(in.isMember("num")) newCommand->num = in["num"].asInt();
  if(in.isMember("id")) newCommand->id = in["id"].asInt();
  if(in.isMember("x")) newCommand->x = in["x"].asInt();
  if(in.isMember("y")) newCommand->y = in["y"].asInt();
  if(in.isMember("x2")) newCommand->x2 = in["x2"].asInt();
  if(in.isMember("y2")) newCommand->y2 = in["y2"].asInt();
  if(in.isMember("unit")) newCommand->unit = in["unit"].asInt();
  if(in.isMember("element")) newCommand->element = in["element"].asInt();
  commandDB.setCommand(id,std::move(newCommand));
  return HttpStatus::NO_CONTENT;

}

HttpStatus CommandService::put (Json::Value& out,const Json::Value& in) {
  int num = in["num"].asInt();
  int id = in["id"].asInt();
  int x = in["x"].asInt();
  int y = in["y"].asInt();
  int x2 = in["x2"].asInt();
  int y2 = in["y2"].asInt();
  int unit = in["unit"].asInt();
  int element = in["element"].asInt();
  out["id"] = commandDB.addCommand(make_unique<Command>(num, id, x, y, x2, y2, unit, element));
  return HttpStatus::CREATED;
}

HttpStatus CommandService::remove (int id) {
  const Command* command = commandDB.getCommand(id);
  if (!command)
      throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
  commandDB.removeCommand(id);
  return HttpStatus::NO_CONTENT;
}
