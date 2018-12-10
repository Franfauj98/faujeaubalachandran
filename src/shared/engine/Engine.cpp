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
  //std::shared_ptr<Command> cmd2=std::move(cmd);
  this->commandListId.push(commandId);
  this->commandList.push(std::move(cmd));
  // this->commandListId.push(commandId);
  // this->commandList.push(std::move(cmd2));
  // this->commandListIdPrev.push_back(commandId);
  // this->commandListPrev.push_back(std::move(cmd2));
  // if (commandListPrev.size()<60){
  //cout<<"Id:"<< commandListId.back()<<" IdPrev:"<<commandListIdPrev.back()<<endl;
//  }// else {
  //   this->commandListIdPrev.pop_front();
  //   this->commandListPrev.pop_front();
  //   this->commandListIdPrev.push_back(commandId);
  //   this->commandListPrev.push_back(std::move(cmd));
  // }
}

void Engine::execute(state::Observable& principalMap){
  while(!this->commandList.empty()){
    switch(commandListId.front()){
      case 1:{
        CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
        ci->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(ci)));
        break;
      }
      case 2:{
        Possibilities* ps = (Possibilities*) commandList.front().get();
        ps->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(ps)));
        break;
      }
      case 3:{
        PrintStats* pst = (PrintStats*) commandList.front().get();
        pst->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(pst)));
        break;
      }

      case 6:{
        Move* mv = (Move*) commandList.front().get();
        mv->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(mv)));
        break;
      }
      case 7:{
        Attack* at = (Attack*) commandList.front().get();
        at->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(at)));
        break;
      }
      case 5:{
        LevelUp* lu = (LevelUp*) commandList.front().get();
        cout<<"x:"<<lu->getX()<<" y:"<<lu->getY()<<endl;
        lu->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(lu)));
        LevelUp* lu2 = (LevelUp*) commandListPrev.back().get();
        cout<<"x:"<<lu2->getX()<<" y:"<<lu2->getY()<<endl;
        break;
      }
      case 4:{
        CreateUnit* cu = (CreateUnit*) commandList.front().get();
        cu->execute(principalMap);
        this->commandListPrev.push_back(std::move(std::unique_ptr<Command>(cu)));
        break;
      }
      default: break;
    }
    this->commandListIdPrev.push_back(commandListId.front());
    //this->commandListPrev.push_back(std::move(commandList.front()));
    this->commandList.pop();
    this->commandListId.pop();
  }

}

void Engine::rollback (state::Observable& principalMap){
  if(commandListPrev.size()>0){
    switch(commandListIdPrev.back()){
      case 6:{
        std::cout << "/* message 1*/" << '\n';
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
        std::cout << "/* message 2*/" << '\n';
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
        //Attack* lu = (Attack*) commandListPrev.back().get();

        std::cout << "/* message 3*/" << '\n';
        cout<<"size:"<<commandListPrev.size()<<endl;
        LevelUp* lu = (LevelUp*) commandListPrev.back().get();
        cout<<"x:"<<lu->getX()<<" y:"<<lu->getY()<<endl;

        cout<<"size:"<<commandListPrev.size()<<endl;
        cout<<"typeId:"<<lu->getTypeId()<<endl;
        cout<<"xPrev:"<<lu->getX()<<" yPrev:"<<lu->getY()<<endl;
        cout<<"coucou"<<endl;
        lu->rollback(principalMap);
        this->commandListPrev.pop_back();
        cout<<"coucou2"<<endl;
        PrintStats* pst = (PrintStats*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        cout<<"coucou3"<<endl;
        Possibilities* ps = (Possibilities*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        cout<<"coucou4"<<endl;
        CaseIdentifier* ci = (CaseIdentifier*) commandListPrev.back().get();
        this->commandListPrev.pop_back();
        cout<<"coucou5"<<endl;
        ci->execute(principalMap);
        cout<<"coucou6"<<endl;
        ps->execute(principalMap);
        cout<<"coucou7"<<endl;
        pst->execute(principalMap);
        cout<<"coucou8"<<endl;
        usleep(500000);
        break;
      }
      case 4:{
        std::cout << "/* message 4*/" << '\n';
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
    cout<<"coucou9"<<endl;
    this->commandListIdPrev.pop_back();
    this->commandListIdPrev.pop_back();
    this->commandListIdPrev.pop_back();
    this->commandListIdPrev.pop_back();
    cout<<"coucou10"<<endl;
  }
}



std::queue<int> Engine::getCommandListId(){
  return this->commandListId;
}

std::deque<int> Engine::getCommandListIdPrev(){
  return this->commandListIdPrev;
}

Engine::~Engine (){

}
