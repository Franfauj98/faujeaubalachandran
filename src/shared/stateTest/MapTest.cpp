#include "MapTest.h"
#include <time.h>
using namespace std;
using namespace state;

void mapTest(){
  cout << "-------------------------------------" << endl;
  cout << "TEST MAP" << endl;
  cout << "-------------------------------------" << endl;

  srand(time(NULL));

  Map map;
  std::vector<int> const &basic = map.getBasicMapId();
  std::vector<int> const &decor = map.getDecorMapId();
  std::vector<int> const &buildings = map.getBuildingsMapId();

  for(size_t i=0; i<basic.size(); i++){
    if(i%map.getSize()==0) cout<<"\n";
    cout<< basic[i];
  }
  cout<<"\n";
  cout<<"\n";
  for(size_t i=0; i<decor.size(); i++){
    if(i%25==0) cout<<"\n";
    cout<< decor[i];
  }

}
