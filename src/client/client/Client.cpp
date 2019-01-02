#include "Client.h"
#include <iostream>
using namespace render;
using namespace state;
using namespace std;
using namespace engine;
using namespace client;



  // private:
  //   engine::Engine engine;
  //   std::vector<std::unique_ptr<ai::Ai>> ai;
  //   static state::Observable principalMap;
  //   render::RenderMap map;
  //   // Operations

Client::Client (){
  Engine engineT;
  this->engine=engineT;
}

void Client::run (){

}


void Client::engineUpdating (){

}

void Client::engineUpdated (){

}
