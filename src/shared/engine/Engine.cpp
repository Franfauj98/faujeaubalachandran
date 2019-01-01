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
std::ifstream inputFileTxt, inputFileJson;
Json::StyledStreamWriter writer;
std::vector<std::string> vectTest;
string commands;
Engine::Engine (){
  commands = "{\"commands\" : [";
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
  // Json::Value value, value2, value3;

  while(!this->commandList.empty()){
    switch(commandListId.front()){
      case 1:{
        CaseIdentifier* ci = (CaseIdentifier*) commandList.front().get();
        if(this->record){
          commands+=("{\"name\": \"CaseIdentifier\",\"id\": \"1\",\"x\": \""+to_string(ci->getX())+"\",\"y\": \""+to_string(ci->getY())+"\"},\n");
          // vectTest.push_back("name:CaseIdentifier");
          // vectTest.push_back("id:1");
          // vectTest.push_back("x:"+to_string(ci->getX()));
          // vectTest.push_back("y:"+to_string(ci->getY()));
          // vectTest.push_back("end");

          // value["name"]="CaseIdentifier";
          // value["id"]="1";
          // value2["x"]=ci->getX();
          // value2["y"]=ci->getY();
          // value["properties"]=value2;
          // value3["command"]=value;

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
          commands+=("{\"name\": \"Possibilities\",\"id\": \"2\",\"x\": \""+to_string(ps->getX())+"\",\"y\": \""+to_string(ps->getY())+"\",\"element\": \""+to_string(ps->getElement())+"\"},\n");
          // vectTest.push_back("name:Possibilities");
          // vectTest.push_back("id:2");
          // vectTest.push_back("x:"+to_string(ps->getX()));
          // vectTest.push_back("y:"+to_string(ps->getY()));
          // vectTest.push_back("element:"+to_string(ps->getElement()));
          // vectTest.push_back("end");

          // value["name"]="Possibilities";
          // value["id"]="2";
          // value2["x"]=ps->getX();
          // value2["y"]=ps->getY();
          // value2["element"]=ps->getElement();
          // value["properties"]=value2;
          // value3["command"]=value;

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
          commands+=("{\"name\": \"PrintStats\",\"id\": \"3\",\"x\": \""+to_string(pst->getX())+"\",\"y\": \""+to_string(pst->getY())+"\", \"element\": \""+to_string(pst->getElement())+"\"},\n");
          // vectTest.push_back("name:PrintStats");
          // vectTest.push_back("id:3");
          // vectTest.push_back("x:"+to_string(pst->getX()));
          // vectTest.push_back("y:"+to_string(pst->getY()));
          // vectTest.push_back("element:"+to_string(pst->getElement()));
          // vectTest.push_back("end");

          // value["name"]="PrintStats";
          // value["id"]="3";
          // value2["x"]=pst->getX();
          // value2["y"]=pst->getY();
          // value2["element"]=pst->getElement();
          // value["properties"]=value2;
          // value3["command"]=value;

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
          commands+=("{\"name\": \"Move\",\"id\": \"6\",\"x\": \""+to_string(mv->getX())+"\",\"y\": \""+to_string(mv->getY())+"\",\"x2\": \""+to_string(mv->getX2())+"\",\"y2\": \""+to_string(mv->getY2())+"\"},\n");
          // vectTest.push_back("name:Move");
          // vectTest.push_back("id:6");
          // vectTest.push_back("x:"+to_string(mv->getX()));
          // vectTest.push_back("y:"+to_string(mv->getY()));
          // vectTest.push_back("x2:"+to_string(mv->getX2()));
          // vectTest.push_back("y2:"+to_string(mv->getY2()));
          // vectTest.push_back("end");

          // value["name"]="Move";
          // value["id"]="6";
          // value2["x"]=mv->getX();
          // value2["y"]=mv->getY();
          // value2["x2"]=mv->getX2();
          // value2["y2"]=mv->getY2();
          // value["properties"]=value2;
          // value3["command"]=value;

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
          commands+=("{\"name\": \"Attack\",\"id\": \"7\",\"x\": \""+to_string(at->getX())+"\",\"y\": \""+to_string(at->getY())+"\",\"x2\": \""+to_string(at->getX2())+"\",\"y2\": \""+to_string(at->getY2())+"\"},\n");
          // vectTest.push_back("name:Attack");
          // vectTest.push_back("id:7");
          // vectTest.push_back("x:"+to_string(at->getX()));
          // vectTest.push_back("y:"+to_string(at->getY()));
          // vectTest.push_back("x2:"+to_string(at->getX2()));
          // vectTest.push_back("y2:"+to_string(at->getY2()));
          // vectTest.push_back("end");

          // value["name"]="Attack";
          // value["id"]="7";
          // value2["x"]=at->getX();
          // value2["y"]=at->getY();
          // value2["x2"]=at->getX2();
          // value2["y2"]=at->getY2();
          // value["properties"]=value2;
          // value3["command"]=value;

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
          commands+=("{\"name\": \"LevelUp\",\"id\": \"5\",\"x\": \""+to_string(lu->getX())+"\",\"y\": \""+to_string(lu->getY())+"\"},\n");
          // vectTest.push_back("name:LevelUp");
          // vectTest.push_back("id:5");
          // vectTest.push_back("x:"+to_string(lu->getX()));
          // vectTest.push_back("y:"+to_string(lu->getY()));
          // vectTest.push_back("end");

          // value["name"]="LevelUp";
          // value["id"]="5";
          // value2["x"]=lu->getX();
          // value2["y"]=lu->getY();
          // value["properties"]=value2;
          // value3["command"]=value;

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
          commands+=("{\"name\": \"CreateUnit\",\"id\": \"4\",\"x\": \""+to_string(cu->getX())+"\",\"y\": \""+to_string(cu->getY())+"\",\"x2\": \""+to_string(cu->getX2())+"\",\"y2\": \""+to_string(cu->getY2())+
          "\",\"unit\": \"" +to_string(cu->getUnit())+"\"},\n");
          // vectTest.push_back("name:CreateUnit");
          // vectTest.push_back("id:4");
          // vectTest.push_back("x:"+to_string(cu->getX()));
          // vectTest.push_back("y:"+to_string(cu->getY()));
          // vectTest.push_back("x2:"+to_string(cu->getX2()));
          // vectTest.push_back("y2:"+to_string(cu->getY2()));
          // vectTest.push_back("unit:"+to_string(cu->getUnit()));
          // vectTest.push_back("end");

          // value["name"]="CreateUnit";
          // value["id"]="4";
          // value2["x"]=cu->getX();
          // value2["y"]=cu->getY();
          // value2["x2"]=cu->getX2();
          // value2["y2"]=cu->getY2();
          // value2["unit"]=cu->getUnit();
          // value["properties"]=value2;
          // value3["command"]=value;

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
    // if(this->record){
    //   writer.write(outputFileJson, value3);
    // }
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
  inputFileJson.open("cmdJson.json");
  string tmp;

  Json::Value commands;
  Json::Reader reader1;
  reader1.parse(inputFileJson, commands);
  Json::Value myCommands = commands["commands"];

  for(int i = 0; i < myCommands.size(); i++) std::cout << myCommands[i]["id"] << '\n';

  if(inputFileTxt.is_open()){
    while(getline(inputFileTxt, tmp)){
      vector<string> commands = explode2(tmp, ';');
      if(commands.size()<7){
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

Engine::~Engine (){
  if(this->record){
    commands.pop_back();
    commands.pop_back();
    commands+="]\n}";
    std::cout << commands << '\n';
    // Json::Value value, value2, value3;
    // Json::StyledWriter fast;
    // string sFast;
    // for(size_t i = 0; i < vectTest.size(); i++){
    //   std::cout << vectTest[i] << '\n';
    //   if(vectTest[i] == "end"){
    //     value3["command"]=value;
    //     // writer.write(outputFileJson, value3);
    //   } else {
    //     vector<string> toFill = explode2(vectTest[i], ':');
    //     if(toFill[0]=="id"){
    //       value["id"]=toFill[1];
    //     }
    //     if(toFill[0]=="x"){
    //       value["x"]=toFill[1];
    //     }
    //     if(toFill[0]=="y"){
    //       value["y"]=toFill[1];
    //     }
    //   }
    //
      // value["name"]=vectTest[i];
      // value["id"]=vectTest[i];
      // value2["x"]=cu->getX();
      // value2["y"]=cu->getY();
      // value2["x2"]=cu->getX2();
      // value2["y2"]=cu->getY2();
      // value2["unit"]=cu->getUnit();
      // value["properties"]=value2;
      // value3["command"]=value;
    //
    // }
    // sFast = fast.write(value3);
    outputFileJson<<commands;

    outputFileJson.close();
    outputFileTxt.close();
  }
  // value2["unit"]=cu->getUnit();

// if(this->record){
//   writer.write(outputFileJson, value3);
// }

}
