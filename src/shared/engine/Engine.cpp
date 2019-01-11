#include "Engine.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <cmath>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
// #include "../../extern/jsoncpp-1.8.0/json/json-forwards.h"
// #include "../../extern/jsoncpp-1.8.0/json/json.h"
// #include "../../extern/jsoncpp-1.8.0/jsoncpp.cpp"
#include <json/json.h>

using namespace engine;
using namespace state;
using namespace std;
using namespace render;

//global jsonFile for engine.
std::ofstream outputFileJson;
std::ifstream inputFileJson;
Json::StyledStreamWriter writer;
std::vector<std::string> vectTest;
string commands;
Engine::Engine (){
  commands = "\"commands\" : [";
  this->message="";
}

void Engine::run(Observable& principalMap, bool& canPlay1, bool& canPlay2, bool& canPlay3, bool& palace1, bool& palace2,
  bool& palace3, int& counter, Empire& empire1, Empire& empire2,Empire& empire3, int& id, int& idPalace, int& stop,int player, bool& firstC, bool& secondC, bool& thirdC){
    if (counter>=0 && counter <=2){
      id = 0;
      idPalace=1;
      for (unsigned int i=0;i<(principalMap).getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> ((principalMap).getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace1=true;
            break;
          } else {
            palace1=false;
          }
        }
      }
      if (palace1){
        empire1.setShot(1);
        empire2.setShot(0);
        empire3.setShot(0);

        if(player==0){
          firstC=false;
          secondC=false;
          thirdC=false;
          canPlay1 = true;
        } else if(player==1 || player==2){
          canPlay1 = false;
        }
        canPlay2 = false;
        canPlay3 = false;

      } else {
        counter=3;
      }

    }
    else if (counter>=3 && counter <=5){
      id = 1;
      idPalace=2;
      for (unsigned int i=0;i<(principalMap).getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> ((principalMap).getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace2=true;
            break;
          } else {
            palace2=false;
          }
        }
      }
      if (palace2){
        empire1.setShot(0);
        empire2.setShot(1);
        empire3.setShot(0);



        if(player==1 || player==0){
          firstC = false;
          secondC = false;
          thirdC = false;
        }

        if(player==0 || player==1){
          canPlay1 = false;
          canPlay2 = true;
          canPlay3 = false;
        } else if(player==2){
          canPlay1 = false;
          canPlay2 = false;
          canPlay3 = false;
        }

      } else {
        counter=6;
      }
    }
    else if (counter>=6 && counter <=8){
      id = 2;
      idPalace=3;
      for (unsigned int i=0;i<(principalMap).getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> ((principalMap).getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace3=true;
            break;
          } else {
            palace3=false;
          }
        }
      }
      if (palace3){
        empire1.setShot(0);
        empire2.setShot(0);
        empire3.setShot(1);

        canPlay1 = false;
        canPlay2 = false;
        canPlay3 = true;

        if(player==1 || player==0 || player ==2){
          firstC = false;
          secondC = false;
          thirdC = false;
        }

      } else {
        counter=9;
      }
    }

    else if(counter>=9){
      idPalace = 1;
      for (unsigned int i=0;i<(principalMap).getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> ((principalMap).getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace1=true;
            break;
          } else {
            palace1=false;
          }
        }
      }
      idPalace = 2;

      for (unsigned int i=0;i<(principalMap).getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> ((principalMap).getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace2=true;
            break;
          } else {
            palace2=false;
          }
        }
      }
      idPalace = 3;

      for (unsigned int i=0;i<(principalMap).getAllMaps().getBuildingsMap().size();i++){
        Palace* building = dynamic_cast<Palace*> ((principalMap).getAllMaps().getBuildingsMap()[i].get());
        if (building!=nullptr){
          int idBuilding=building->getIdBuilding();
          if (idBuilding==idPalace){
            palace3=true;
            break;
          } else {
            palace3=false;
          }
        }
      }
      if (palace1){
        empire1.updateRessource((principalMap).getAllMaps().getBuildingsMap());

      }
      if (palace2){
        empire2.updateRessource((principalMap).getAllMaps().getBuildingsMap());
      }
      if (palace3){
        empire3.updateRessource((principalMap).getAllMaps().getBuildingsMap());
      }
      if ((palace1==true && palace2==false && palace3==false) || (palace1==false && palace2==true && palace3==false) || (palace1==false && palace2==false && palace3==true)){
        stop=1;
      }
      else {
        counter=0;
        id = 0;
        idPalace=1;
        if (player==0){
          canPlay1 = true;
          canPlay2 = false;
          canPlay3 = false;
        }
        else if (player==1 || player==2){
          firstC = true;
          secondC = false;
          thirdC = false;
          canPlay1 = false;
          canPlay2 = false;
          canPlay3 = false;
        }
      }
    }
}

void Engine::openFiles(){
  if(this->record){
    outputFileJson.open("replay.json", ios::app);
  }
}

void Engine::beginRecord(){
  this->record = true;
}

void Engine::addCommand(std::unique_ptr<Command> cmd, int commandId){
  this->commandListId.push(commandId);
  this->commandList.push(std::move(cmd));
}

void Engine::execute(state::Observable& principalMap){
  while(!this->commandList.empty()){
    switch(commandListId.front()){
      case 1:{
        CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"CaseIdentifier\",\"id\": 1,\"x\": "+to_string(ci->getX())+",\"y\": "+to_string(ci->getY())+"},\n");
        }
        ci->execute(principalMap);
        break;
      }
      case 2:{
        Possibilities* ps = (Possibilities*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"Possibilities\",\"id\": 2,\"x\": "+to_string(ps->getX())+",\"y\": "+to_string(ps->getY())+",\"element\": "+to_string(ps->getElement())+"},\n");
        }
        ps->execute(principalMap);
        break;
      }
      case 3:{
        PrintStats* pst = (PrintStats*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"PrintStats\",\"id\": 3,\"x\": "+to_string(pst->getX())+",\"y\": "+to_string(pst->getY())+", \"element\": "+to_string(pst->getElement())+"},\n");
        }
        pst->execute(principalMap);
        break;
      }

      case 6:{
        Move* mv = (Move*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"Move\",\"id\": 6,\"x\": "+to_string(mv->getX())+",\"y\": "+to_string(mv->getY())+",\"x2\": "+to_string(mv->getX2())+",\"y2\": "+to_string(mv->getY2())+"},\n");
        }
        mv->execute(principalMap);
        usleep(250000);
        break;
      }
      case 7:{
        Attack* at = (Attack*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"Attack\",\"id\": 7,\"x\": "+to_string(at->getX())+",\"y\": "+to_string(at->getY())+",\"x2\": "+to_string(at->getX2())+",\"y2\": "+to_string(at->getY2())+"},\n");
        }
        at->execute(principalMap);
        usleep(250000);
        break;
      }
      case 5:{
        LevelUp* lu = (LevelUp*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"LevelUp\",\"id\": 5,\"x\": "+to_string(lu->getX())+",\"y\": "+to_string(lu->getY())+"},\n");
        }
        lu->execute(principalMap);
        usleep(250000);
        break;
      }
      case 4:{
        CreateUnit* cu = (CreateUnit*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"CreateUnit\",\"id\": 4,\"x\": "+to_string(cu->getX())+",\"y\": "+to_string(cu->getY())+",\"x2\": "+to_string(cu->getX2())+",\"y2\": "+to_string(cu->getY2())+
          ",\"unit\": " +to_string(cu->getUnit())+"},\n");
        }
        cu->execute(principalMap);
        usleep(250000);
        break;
      }
      default: break;
    }
    this->commandListPrev.push_back(std::move(commandList.front()));
    this->commandListIdPrev.push_back(commandListId.front());
    this->commandList.pop();
    this->commandListId.pop();
  }
}

void Engine::rollback (state::Observable& principalMap){
  if(commandListPrev.size()>0){
    usleep(1000000);
    switch(commandListIdPrev.back()){
      case 6:{
        Move* mv = (Move*) commandListPrev.back().get();
        mv->rollback(principalMap);
        std::unique_ptr<Command> mv2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        std::unique_ptr<Command> pst2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        std::unique_ptr<Command> ps2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        std::unique_ptr<Command> ci2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        ps->execute(principalMap);
        pst->execute(principalMap);
        break;
      }
      case 7:{
        Attack* at = (Attack*) commandListPrev.back().get();
        at->rollback(principalMap);
        std::unique_ptr<Command> at2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        std::unique_ptr<Command> pst2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        std::unique_ptr<Command> ps2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        std::unique_ptr<Command> ci2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        ps->execute(principalMap);
        pst->execute(principalMap);
        break;
      }
      case 5:{
        LevelUp* lu = (LevelUp*) commandListPrev.back().get();
        lu->rollback(principalMap);
        std::unique_ptr<Command> lu2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        std::unique_ptr<Command> pst2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        std::unique_ptr<Command> ps2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        std::unique_ptr<Command> ci2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        ps->execute(principalMap);
        pst->execute(principalMap);
        break;
      }
      case 4:{
        CreateUnit* cu = (CreateUnit*) commandListPrev.back().get();
        cu->rollback(principalMap);
        std::unique_ptr<Command> cu2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        std::unique_ptr<Command> pst2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        std::unique_ptr<Command> ps2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        std::unique_ptr<Command> ci2=std::move(commandListPrev.back());
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        ps->execute(principalMap);
        pst->execute(principalMap);
        break;
      }
      default: break;
    }
    this->commandListIdPrev.pop_back();
    this->commandListIdPrev.pop_back();
    this->commandListIdPrev.pop_back();
    this->commandListIdPrev.pop_back();
  }
}

void Engine::replay(state::Observable& principalMap){
  inputFileJson.open("replay.json");
  if(inputFileJson.is_open()){
    Json::Value commands;
    Json::Reader reader1;
    reader1.parse(inputFileJson, commands);
    Json::Value myCommand = commands["commands"];
    for(int i = 0; i < (int)myCommand.size(); i++){
      int id = myCommand[i]["id"].asInt();
      switch(id){
        case 1:{
          addCommand((unique_ptr<Command> (new CaseIdentifier(myCommand[i]["x"].asInt(), myCommand[i]["y"].asInt()))),1);
          break;
        }
        case 2:{
          addCommand(unique_ptr<Command> (new Possibilities(myCommand[i]["x"].asInt(), myCommand[i]["y"].asInt(), myCommand[i]["element"].asInt())),2);
          break;
        }
        case 3:{
          addCommand(unique_ptr<Command> (new PrintStats(myCommand[i]["x"].asInt(), myCommand[i]["y"].asInt(), myCommand[i]["element"].asInt())),3);
          break;
        }
        case 6:{
          addCommand((unique_ptr<Command> (new Move(myCommand[i]["x"].asInt(), myCommand[i]["y"].asInt(), myCommand[i]["x2"].asInt(), myCommand[i]["y2"].asInt()))),6);
          break;
        }
        case 7:{
          addCommand((unique_ptr<Command> (new Attack(myCommand[i]["x"].asInt(),myCommand[i]["y"].asInt(),myCommand[i]["x2"].asInt(),myCommand[i]["y2"].asInt()))),7);
          break;
        }
        case 5:{
          addCommand((unique_ptr<Command> (new LevelUp(myCommand[i]["x"].asInt(),myCommand[i]["y"].asInt()))),5);
          break;
        }
        case 4:{
          addCommand((unique_ptr<Command> (new CreateUnit(myCommand[i]["x"].asInt(), myCommand[i]["y"].asInt(), myCommand[i]["x2"].asInt(), myCommand[i]["y2"].asInt(), myCommand[i]["unit"].asInt()))),4);
          break;
        }
        default: break;
      }
    }
    inputFileJson.close();
  }
}

int Engine::execReplay(state::Observable& principalMap){
  int i=0;
  while(i<4){
    if(this->commandList.size()>0){
      switch(commandListId.front()){
        case 1:{
          CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
          ci->execute(principalMap);
          break;
        }
        case 2:{
          Possibilities* ps = (Possibilities*) commandList.front().get();
          ps->execute(principalMap);
          break;
        }
        case 3:{
          PrintStats* pst = (PrintStats*) commandList.front().get();
          pst->execute(principalMap);
          break;
        }

        case 6:{
          Move* mv = (Move*) commandList.front().get();
          mv->execute(principalMap);
          break;
        }
        case 7:{
          Attack* at = (Attack*) commandList.front().get();
          at->execute(principalMap);
          break;
        }
        case 5:{
          LevelUp* lu = (LevelUp*) commandList.front().get();
          lu->execute(principalMap);
          break;
        }
        case 4:{
          CreateUnit* cu = (CreateUnit*) commandList.front().get();
          cu->execute(principalMap);
          break;
        }
        default: break;
      }

      usleep(100000);
      this->commandList.pop();
      this->commandListId.pop();
      i++;
    } else {
      return -1;
    }
  }
  return 1;
}

std::queue<int> Engine::getCommandListId(){
  return this->commandListId;
}

std::deque<int> Engine::getCommandListIdPrev(){
  return this->commandListIdPrev;
}

void Engine::setMessage(std::string message){
  this->message=message;
}

std::string Engine::getMessage(){
  return this->message;
}

Engine::~Engine (){
  if(this->record){
    commands.pop_back();
    commands.pop_back();
    commands+="]\n}";
    if(outputFileJson.is_open()){
      outputFileJson<<commands;
      outputFileJson.close();
    }
  }

}
