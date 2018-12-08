#include "Engine.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <cmath>
#include <unistd.h>
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;
using namespace render;

Engine::Engine (){
}

void Engine::addCommand(std::unique_ptr<Command> cmd, int commandId){
  this->commandListId.push(commandId);
  this->commandList.push(std::move(cmd));
  if (commandListPrev.size()<60){
    this->commandListIdPrev.push_back(commandId);
    this->commandListPrev.push_back(std::move(cmd));
  } else {
    this->commandListIdPrev.pop_front();
    this->commandListPrev.pop_front();
    this->commandListIdPrev.push_back(commandId);
    this->commandListPrev.push_back(std::move(cmd));
  }
}

void Engine::execute(state::Observable& principalMap){
  while(!this->commandList.empty()){
    switch(commandListId.front()){
      case 1:{
        CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
        ci->execute(principalMap);
        break;
      }
      case 3:{
        PrintStats* pst = (PrintStats*) commandList.front().get();
        pst->execute(principalMap);
        break;
      }
      case 2:{
        Possibilities* ps = (Possibilities*) commandList.front().get();
        ps->execute(principalMap);
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
    this->commandList.pop();
    this->commandListId.pop();
  }

}

void Engine::rollback (state::Observable& principalMap){
    switch(commandListIdPrev.back()){
      case 6:{
        Move* mv = (Move*) commandListPrev.back().get();
        mv->rollback(principalMap);
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        pst->execute(principalMap);
        ps->execute(principalMap);
        usleep(500000);
        break;
      }
      case 7:{
        Attack* at = (Attack*) commandListPrev.back().get();
        at->rollback(principalMap);
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        pst->execute(principalMap);
        ps->execute(principalMap);
        usleep(500000);
        break;
      }
      case 5:{
        LevelUp* lu = (LevelUp*) commandListPrev.back().get();
        lu->rollback(principalMap);
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        pst->execute(principalMap);
        ps->execute(principalMap);
        usleep(500000);
        break;
      }
      case 4:{
        CreateUnit* cu = (CreateUnit*) commandListPrev.back().get();
        cu->rollback(principalMap);
        this->commandListPrev.pop_back();
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        ci->execute(principalMap);
        pst->execute(principalMap);
        ps->execute(principalMap);
        usleep(500000);
        break;
      }
      default: break;
    }
    this->commandListIdPrev.pop_back();
}

std::queue<int> Engine::getCommandListId(){
  return this->commandListId;
}

Engine::~Engine (){

}
