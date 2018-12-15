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
#include "../../extern/jsoncpp-1.8.0/json/json-forwards.h"
#include "../../extern/jsoncpp-1.8.0/json/json.h"
#include "../../extern/jsoncpp-1.8.0/jsoncpp.cpp"

using namespace engine;
using namespace state;
using namespace std;
using namespace render;

//global jsonFile for engine.
std::ofstream outputFileJson, outputFileTxt;
std::ifstream inputFileTxt;

Engine::Engine (){
}

void Engine::openFiles(){
  if(this->record){
    outputFileJson.open("cmdJson.json");
    outputFileTxt.open("cmdTxt.txt", ios::app);
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
  Json::Reader reader;
  Json::Value value, value2;
  Json::StyledStreamWriter writer;

  while(!this->commandList.empty()){
    switch(commandListId.front()){
      case 1:{
        CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
        if(this->record){
          value["name"]="CaseIdentifier";
          value["id"]="1";
          value2["x"]=ci->getX();
          value2["y"]=ci->getY();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"1;"+to_string(ci->getX())+";"+to_string(ci->getY())+"\n";
          }
        }
        ci->execute(principalMap);
        break;
      }
      case 2:{
        Possibilities* ps = (Possibilities*) commandList.front().get();
        if(this->record){
          value["name"]="Possibilities";
          value["id"]="2";
          value2["x"]=ps->getX();
          value2["y"]=ps->getY();
          value2["element"]=ps->getElement();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"2;"+to_string(ps->getX())+";"+to_string(ps->getY()) +";"+ to_string(ps->getElement())+"\n";
          }
        }
        ps->execute(principalMap);
        break;
      }
      case 3:{
        PrintStats* pst = (PrintStats*) commandList.front().get();
        if(this->record){
          value["name"]="PrintStats";
          value["id"]="3";
          value2["x"]=pst->getX();
          value2["y"]=pst->getY();
          value2["element"]=pst->getElement();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"3;"+to_string(pst->getX())+";"+to_string(pst->getY()) +";"+ to_string(pst->getElement())+"\n";
          }
        }
        pst->execute(principalMap);
        break;
      }

      case 6:{
        Move* mv = (Move*) commandList.front().get();
        if(this->record){
          value["name"]="Move";
          value["id"]="6";
          value2["x"]=mv->getX();
          value2["y"]=mv->getY();
          value2["x2"]=mv->getX2();
          value2["y2"]=mv->getY2();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"6;"+to_string(mv->getX())+";"+to_string(mv->getY()) + ";" +to_string(mv->getX2())+";"+to_string(mv->getY2())+"\n";
          }
        }
        mv->execute(principalMap);
        break;
      }
      case 7:{
        Attack* at = (Attack*) commandList.front().get();
        if(this->record){
          value["name"]="Attack";
          value["id"]="7";
          value2["x"]=at->getX();
          value2["y"]=at->getY();
          value2["x2"]=at->getX2();
          value2["y2"]=at->getY2();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"7;"+to_string(at->getX())+";"+to_string(at->getY()) + ";" +to_string(at->getX2())+";"+to_string(at->getY2())+"\n";
          }
        }
        at->execute(principalMap);
        break;
      }
      case 5:{
        LevelUp* lu = (LevelUp*) commandList.front().get();
        if(this->record){
          value["name"]="LevelUp";
          value["id"]="5";
          value2["x"]=lu->getX();
          value2["y"]=lu->getY();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"5;"+to_string(lu->getX())+";"+to_string(lu->getY())+"\n";
          }
        }
        lu->execute(principalMap);
        break;
      }
      case 4:{
        CreateUnit* cu = (CreateUnit*) commandList.front().get();
        if(this->record){
          value["name"]="Attack";
          value["id"]="4";
          value2["x"]=cu->getX();
          value2["y"]=cu->getY();
          value2["x2"]=cu->getX2();
          value2["y2"]=cu->getY2();
          value2["unit"]=cu->getUnit();
          value["properties"]=value2;

          if(outputFileTxt.is_open()){
            outputFileTxt<<"4;"+to_string(cu->getX())+";"+to_string(cu->getY()) + ";" +to_string(cu->getX2())+";"+to_string(cu->getY2()) +";"+ to_string(cu->getUnit())+"\n";
          }
        }
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
    if(this->record){
      writer.write(outputFileJson, value);
    }
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


vector<string> explode2(string const & s, const char& c){
  string buff{""};
  vector<string> v;
  for(auto n:s){
    if(n!=c) buff+=n;
    else if(n==c && buff != "") {
      v.push_back(buff);
      buff="";
    }
  }
  if(buff!="") v.push_back(buff);
  return v;
}


void Engine::replay(state::Observable& principalMap){
  inputFileTxt.open("cmdTxt.txt");
  string tmp;
  if(inputFileTxt.is_open()){
    while(getline(inputFileTxt, tmp)){
      cout<<tmp;
      vector<string> commands = explode2(tmp, ';');
      if(commands.size()<7){
        std::cout << "id" << commands[0] << '\n';
        switch(stoi(commands[0], nullptr, 10)){
          case 1:{
            addCommand((unique_ptr<Command> (new CaseIdentifier(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10)))),1);
            break;
          }
          case 2:{
            addCommand(unique_ptr<Command> (new Possibilities(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10),stoi(commands[3], nullptr, 10))),2);
            break;
          }
          case 3:{
            addCommand(unique_ptr<Command> (new PrintStats(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10),stoi(commands[3], nullptr, 10))),3);
            break;
          }

          case 6:{
            addCommand((unique_ptr<Command> (new Move(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10),stoi(commands[3], nullptr, 10),stoi(commands[4], nullptr, 10)))),6);
            break;
          }
          case 7:{
            addCommand((unique_ptr<Command> (new Attack(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10),stoi(commands[3], nullptr, 10),stoi(commands[4], nullptr, 10)))),7);
            break;
          }
          case 5:{
            addCommand((unique_ptr<Command> (new LevelUp(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10)))),5);
            break;
          }
          case 4:{
            addCommand((unique_ptr<Command> (new CreateUnit(stoi(commands[1], nullptr, 10),stoi(commands[2], nullptr, 10),stoi(commands[3], nullptr, 10),stoi(commands[4], nullptr, 10),stoi(commands[5], nullptr, 10)))),4);
            break;
          }
          default: break;
        }

      }
    }

    inputFileTxt.close();
  }
}

void Engine::execReplay(state::Observable& principalMap){
  int i=0;
  while(i<4){
    if(this->commandList.size()>0){
      std::cout << "coucou1" << '\n';
      switch(commandListId.front()){
        case 1:{
          std::cout << "coucou2" << '\n';
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

      usleep(500000);
      this->commandList.pop();
      this->commandListId.pop();
    }
    i++;
  }
}

std::queue<int> Engine::getCommandListId(){
  return this->commandListId;
}

std::deque<int> Engine::getCommandListIdPrev(){
  return this->commandListIdPrev;
}

Engine::~Engine (){
  if(this->record){
    outputFileJson.close();
    outputFileTxt.close();
  }
}
