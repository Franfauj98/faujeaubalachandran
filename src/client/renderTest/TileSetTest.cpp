#include "TileSetTest.h"

using namespace std;
using namespace render;
using namespace state;

void tileSetTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST BUILDING TILESET" << endl;
  cout << "-------------------------------------" << endl;

  BuildingTileSet bts;
  cout<<"width:"<<bts.getCellWidth()<<endl;
  cout<<"height:"<<bts.getCellHeight()<<endl;
  cout<<"ImageFile:"<<bts.getImageFile()<<endl;

  Position pos1(10,30);
  Barrack barrack(1,pos1,1);
  cout<<"Barrack tile position:"<<bts.getTile(barrack).getX()<<endl;
  Position pos2(10,40);
  Palace palace(1,pos2,3);
  cout<<"Palace tile position:"<<bts.getTile(palace).getX()<<endl;
  cout<<endl;

  cout << "-------------------------------------" << endl;
  cout << "TEST DECOR TILESET" << endl;
  cout << "-------------------------------------" << endl;
}
