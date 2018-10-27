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
  DecorTileSet dts;
  cout<<"width:"<<dts.getCellWidth()<<endl;
  cout<<"height:"<<dts.getCellHeight()<<endl;
  cout<<"ImageFile:"<<dts.getImageFile()<<endl;
  Decor water(IdDecor::SEA,pos1);
  cout<<"Water tile position:"<<dts.getTile(water).getX()<<endl;
  Decor grass(IdDecor::GRASS,pos2);
  cout<<"Grass tile position:"<<dts.getTile(grass).getX()<<endl;
  cout<<endl;

  cout << "-------------------------------------" << endl;
  cout << "TEST UNITS TILESET" << endl;
  cout << "-------------------------------------" << endl;
  UnitsTileSet uts;
  cout<<"width:"<<uts.getCellWidth()<<endl;
  cout<<"height:"<<uts.getCellHeight()<<endl;
  cout<<"ImageFile:"<<uts.getImageFile()<<endl;
  Arrow arrow(2,pos1,7);
  cout<<"Arrow tile position:"<<uts.getTile(arrow).getX()<<endl;
  Cavalier cavalier (2,pos1,8);
  cout<<"Grass tile position:"<<uts.getTile(cavalier).getX()<<endl;
  cout<<endl;
}
