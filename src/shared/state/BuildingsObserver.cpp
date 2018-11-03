#include "BuildingsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void BuildingsObserver::changeBuildings(std::unique_ptr<Element> buildings,
Observable& mapToChange,
int position){
  std::vector<std::unique_ptr<Element>> const& map = mapToChange.getAllMaps().getBuildingsMap();
  for(size_t i=0; i<map.size(); i++){
    std::cout << (((Buildings *) map[i].get())->getIdTexture());
    if(i%25==0&&i!=0) std::cout<<"\n";
  }
  std::cout<<"\n";
  std::cout << "BuildingsObserver" << std::endl;
}
