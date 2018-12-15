#include "Engine.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <cmath>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../../extern/jsoncpp-1.8.0/json/json-forwards.h"
#include "../../extern/jsoncpp-1.8.0/json/json.h"
#include "../../extern/jsoncpp-1.8.0/jsoncpp.cpp"

using namespace engine;
using namespace state;
using namespace std;
using namespace render;

//global jsonFile for engine.
std::ofstream outputFile;

Engine::Engine (){
  outputFile.open("outputFile.json");
}

void Engine::addCommand(std::unique_ptr<Command> cmd, int commandId){
  this->commandListId.push(commandId);
  this->commandList.push(std::move(cmd));
}

void Engine::execute(state::Observable& principalMap){

  Json::Reader reader;
  Json::Value value, value2;
  Json::StyledStreamWriter writer;

  while(!this->commandList.empty()){
    switch(commandListId.front()){
      case 1:{
        CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
        value["name"]="CaseIdentifier";
        value["id"]="1";
        value2["x"]=ci->getX();
        value2["y"]=ci->getY();
        value["properties"]=value2;
        ci->execute(principalMap);
        break;
      }
      case 2:{
        Possibilities* ps = (Possibilities*) commandList.front().get();
        value["name"]="Possibilities";
        value["id"]="2";
        value2["x"]=ps->getX();
        value2["y"]=ps->getY();
        value2["element"]=ps->getElement();
        value["properties"]=value2;
        ps->execute(principalMap);
        break;
      }
      case 3:{
        PrintStats* pst = (PrintStats*) commandList.front().get();
        value["name"]="PrintStats";
        value["id"]="3";
        value2["x"]=pst->getX();
        value2["y"]=pst->getY();
        value2["element"]=pst->getElement();
        value["properties"]=value2;
        pst->execute(principalMap);
        break;
      }

      case 6:{
        Move* mv = (Move*) commandList.front().get();
        value["name"]="Move";
        value["id"]="6";
        value2["x"]=mv->getX();
        value2["y"]=mv->getY();
        value2["x2"]=mv->getX2();
        value2["y2"]=mv->getY2();
        value["properties"]=value2;
        mv->execute(principalMap);
        break;
      }
      case 7:{
        Attack* at = (Attack*) commandList.front().get();
        value["name"]="Attack";
        value["id"]="7";
        value2["x"]=at->getX();
        value2["y"]=at->getY();
        value2["x2"]=at->getX2();
        value2["y2"]=at->getY2();
        value["properties"]=value2;
        at->execute(principalMap);
        break;
      }
      case 5:{
        LevelUp* lu = (LevelUp*) commandList.front().get();
        value["name"]="LevelUp";
        value["id"]="5";
        value2["x"]=lu->getX();
        value2["y"]=lu->getY();
        value["properties"]=value2;
        lu->execute(principalMap);
        break;
      }
      case 4:{
        CreateUnit* cu = (CreateUnit*) commandList.front().get();
        value["name"]="Attack";
        value["id"]="4";
        value2["x"]=cu->getX();
        value2["y"]=cu->getY();
        value2["x2"]=cu->getX2();
        value2["y2"]=cu->getY2();
        value2["unit"]=cu->getUnit();
        value["properties"]=value2;
        cu->execute(principalMap);
        break;
      }
      default: break;
    }
    //usleep(500000);
    this->commandListPrev.push_back(std::move(commandList.front()));
    this->commandListIdPrev.push_back(commandListId.front());
    this->commandList.pop();
    this->commandListId.pop();
    writer.write(outputFile, value);
  }
}

void Engine::rollback (state::Observable& principalMap){
  if(commandListPrev.size()>0){
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
        usleep(500000);
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
        usleep(500000);
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
        usleep(500000);
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
        usleep(500000);
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



std::queue<int> Engine::getCommandListId(){
  return this->commandListId;
}

std::deque<int> Engine::getCommandListIdPrev(){
  return this->commandListIdPrev;
}

Engine::~Engine (){
  outputFile.close();
}
