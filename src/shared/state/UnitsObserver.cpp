#include "UnitsObserver.h"
#include <iostream>
#include "../../shared/state.h"
using namespace state;

void UnitsObserver::changeUnits(std::unique_ptr<Element> unit,
Observable& mapToChange,
int position){
  std::vector<std::unique_ptr<Element>> const& map = mapToChange.getAllMaps().getUnitsMap();
  for(size_t i=0; i<map.size(); i++){
    std::cout << (((Units *) map[i].get())->getIdTextureUnits());
    if(i%25==0&&i!=0) std::cout<<"\n";
  }
  std::cout<<"\n";
  std::cout << "UnitsObserver" << std::endl;
}
