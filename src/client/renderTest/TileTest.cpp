#include "TileTest.h"

using namespace std;
using namespace render;


void tileTest(){

  cout << "-------------------------------------" << endl;
  cout << "TEST TILE" << endl;
  cout << "-------------------------------------" << endl;

  Tile tile;
  cout<<"x:"<<tile.getX()<<endl;
  cout<<"width:"<<tile.getWidth()<<endl;
  cout<<"height:"<<tile.getHeight()<<endl;
  tile.setX(10);
  tile.setWidth(30);
  tile.setHeight(40);
  cout<<"new x:"<<tile.getX()<<endl;
  cout<<"new width:"<<tile.getWidth()<<endl;
  cout<<"new height:"<<tile.getHeight()<<endl;
  cout<<endl;
}
