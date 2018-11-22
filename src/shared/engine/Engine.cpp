#include "Engine.h"
#include "state.h"
#include "engine.h"
#include "render.h"
#include <cmath>
#include <iostream>
using namespace engine;
using namespace state;
using namespace std;
using namespace render;

Engine::Engine (){
}

void Engine::addCommand(std::unique_ptr<Command> cmd, int commandId){
  this->commandListId.push(commandId);
  std::cout << "commandID " << commandId << '\n';
  this->commandList.push(std::move(cmd));
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
        std::cout << "je devrais move" << '\n';
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

std::queue<int> Engine::getCommandListId(){
  return this->commandListId;
}

Engine::~Engine (){

}
