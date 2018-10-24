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

  // Position p(1,2);
  // Position p2(3,4);

  // Arrow* arrow = new Arrow(2,p2,2);
  // Arrow* arrow2 = new Arrow(3,p,3);
  // Arrow* arrow3 = new Arrow(3,p,3);
  // Catapult* catap = new Catapult(3,p2,3);
  // cout << "Life : " << arrow->getLife() << endl;
  // map.addElement(arrow);
  // map.addElement(arrow2);
  // map.addElement(arrow3);
  // map.addElement(catap);
  //
  // Arrow* arr = (Arrow *)map.getMap()[0].get();
  // cout << "arrow" << endl;
  // cout << arr->getLife() << endl;
  // cout << arr->getType() << endl;
  // cout << "Pos X : " << arr->getPosition().getX() << endl;
  // cout << "Pos Y : " << arr->getPosition().getY() << endl;
  //
  // Arrow* arr3 = (Arrow *)map.getMap()[2].get();
  // cout << "arrow" << endl;
  // cout << arr3->getLife() << endl;
  // cout << arr3->getType() << endl;
  // cout << "Pos X : " << arr3->getPosition().getX() << endl;
  // cout << "Pos Y : " << arr3->getPosition().getY() << endl;

  // Decor* arr = (Decor *)map.getMap()[0].get();
  // cout << "decor" << endl;
  // // cout << arr->getLife() << endl;
  // cout << arr->getType() << endl;
  // cout << arr->getIdDecor() << endl;
  // cout << "Pos X : " << arr->getPosition().getX() << endl;
  // cout << "Pos Y : " << arr->getPosition().getY() << endl;
  //
  // Arrow* arr3 = (Arrow *)map.getMap()[2].get();
  // cout << "Decor" << endl;
  // // cout << arr3->getLife() << endl;
  // cout << arr3->getType() << endl;
  // cout << arr->getIdDecor() << endl;
  // cout << "Pos X : " << arr3->getPosition().getX() << endl;
  // cout << "Pos Y : " << arr3->getPosition().getY() << endl;

  // std::vector<std::unique_ptr<Element>> const &basic = map.getBasicMap();
  // std::vector<std::unique_ptr<Element>> const &decor = map.getDecorMap();
  //
  // for(size_t i=0; i<basic.size(); i++){
  //   if(i%40==0) cout<<"\n";
  //   Decor* d = (Decor *) basic[i].get();
  //   cout<< d->getIdDecor();
  // }
  // cout<<"\n";
  // cout<<"\n";
  // for(size_t i=0; i<decor.size(); i++){
  //   if(i%40==0) cout<<"\n";
  //   Decor* d = (Decor *) decor[i].get();
  //   cout<< d->getIdDecor();
  // }
  // cout<<"\n";
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
  // cout<<"\n";
  // cout<<"\n";
  // for(size_t i=0; i<buildings.size(); i++){
  //   if(i%40==0) cout<<"\n";
  //   cout<< buildings[i];
  // }
  // cout<<"\n";

  // cout<<rand()%40<<endl;

  // Catapult* ca = (Catapult *)map.getMap()[3].get();
  // cout << "Catapult" << endl;
  // cout << ca->getLife() << endl;
  // cout << ca->getType() << endl;
  //
  // map.deleteElement(0);
  //
  // cout << "POSITION OF ARROW 1" << endl;
  // cout << map.getPositionElement(arrow2) << endl;

}
