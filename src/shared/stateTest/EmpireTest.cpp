#include "EmpireTest.h"
#include "BarrackTest.h"
#include "PalaceTest.h"
#include "RessourceTest.h"

using namespace std;
using namespace state;

void EmpireTest(){}
//
//   cout << "-------------------------------------" << endl;
//   cout << "TEST EMPIRE" << endl;
//   cout << "-------------------------------------" << endl;
//
//   cout << "DEFAULT CONSTRUCTOR" << endl;
//   Empire empire0;
//   cout << "idEmpire: " << empire0.getId() << endl;
//   cout << "Name: " << empire0.getName() << endl;
//   cout << "EmpireLevel: " << empire0.getEmpireLevel() << endl;
//   cout << "GoldRessource: " << empire0.getGoldRessource() << endl;
//   cout << "WoodRessource: " << empire0.getWoodRessource() << endl;
//   cout << "FoodRessource: " << empire0.getFoodRessource() << endl;
//   std::vector<Position> pos=empire0.getPosition();
//   for (unsigned int i=0;i<pos.size();i++ ){
//     cout << "Position X: " << pos[i].getX() << endl;
//     cout << "Position Y: " << pos[i].getY() << endl;
//   }
//   Barrack* empireBarrack0=empire0.getBarrack();
//   cout<< "Barrack X position:" << empireBarrack0->getPosition().getX() << endl;
//   cout<< "Barrack Y position:" << empireBarrack0->getPosition().getY() << endl;
//   cout<< "Barrack level:" << empireBarrack0->getLevel() << endl;
//   cout<< "Barrack life:" << empireBarrack0->getLife() << endl;
//   cout << endl;
//
//   Palace* empirePalace0=empire0.getPalace();
//   cout<< "Palace X position:" << empirePalace0->getPosition().getX() << endl;
//   cout<< "Palace Y position:" << empirePalace0->getPosition().getY() << endl;
//   cout<< "Palace level:" << empirePalace0->getLevel() << endl;
//   cout<< "Palace life:" << empirePalace0->getLife() << endl;
//   cout << endl;
//
//   Ressource* empireRessource0=empire0.getRessource();
//   cout<< "Ressource X position:" << empireRessource0->getPosition().getX() << endl;
//   cout<< "Ressource Y position:" << empireRessource0->getPosition().getY() << endl;
//   cout<< "Ressource level:" << empireRessource0->getLevel() << endl;
//   cout<< "Ressource life:" << empireRessource0->getLife() << endl;
//   cout << endl;
//
//   cout << "SETTER WITH PARAMETERS INSIDE OF DEF DOMAIN" << endl;
//   //empire0.setId(10);
//   empire0.setName("Warriors");
//   empire0.setEmpireLevel(5);
//   empire0.setGoldRessource(100);
//   empire0.setWoodRessource(100);
//   empire0.setFoodRessource(100);
//   std::vector<Position> pos1(1);
//   for (unsigned int i=0;i<pos1.size();i++ ){
//     pos1[i].setX(50);
//     pos1[i].setY(50);
//   }
//   empire0.setPosition(pos1);
//   Position pos2(90,200);
//   Barrack* barrack1 = new Barrack(2,pos2,3);
//   Palace* palace1 = new Palace(2,pos2,3);
//   Ressource* ressource1 = new Ressource(2,pos2,3);
//   empire0.setBarrack(barrack1);
//   empire0.setPalace(palace1);
//   empire0.setRessource(ressource1);
//   cout << "idEmpire: " << empire0.getId() << endl;
//   cout << "Name: " << empire0.getName() << endl;
//   cout << "EmpireLevel: " << empire0.getEmpireLevel() << endl;
//   cout << "GoldRessource: " << empire0.getGoldRessource() << endl;
//   cout << "WoodRessource: " << empire0.getWoodRessource() << endl;
//   cout << "FoodRessource: " << empire0.getFoodRessource() << endl;
//   std::vector<Position> pos3=empire0.getPosition();
//   for (unsigned int i=0;i<pos3.size();i++ ){
//     cout << "Position X: " << pos3[i].getX() << endl;
//     cout << "Position Y: " << pos3[i].getY() << endl;
//   }
//   Barrack* empireBarrack1=empire0.getBarrack();
//   cout<< "Barrack X position:" << empireBarrack1->getPosition().getX() << endl;
//   cout<< "Barrack Y position:" << empireBarrack1->getPosition().getY() << endl;
//   cout<< "Barrack level:" << empireBarrack1->getLevel() << endl;
//   cout<< "Barrack life:" << empireBarrack1->getLife() << endl;
//   cout << endl;
//
//   Palace* empirePalace1=empire0.getPalace();
//   cout<< "Palace X position:" << empirePalace1->getPosition().getX() << endl;
//   cout<< "Palace Y position:" << empirePalace1->getPosition().getY() << endl;
//   cout<< "Palace level:" << empirePalace1->getLevel() << endl;
//   cout<< "Palace life:" << empirePalace1->getLife() << endl;
//   cout << endl;
//
//   Ressource* empireRessource1=empire0.getRessource();
//   cout<< "Ressource X position:" << empireRessource1->getPosition().getX() << endl;
//   cout<< "Ressource Y position:" << empireRessource1->getPosition().getY() << endl;
//   cout<< "Ressource level:" << empireRessource1->getLevel() << endl;
//   cout<< "Ressource life:" << empireRessource1->getLife() << endl;
//   cout << endl;
//
//   cout << "CONSTRUCTEUR WITH PARAMETERS INSIDE OF THE DEF DOMAIN" << endl;
//   Empire empire1(5,"ENSEA",2,500,100,100,100,pos1,empireBarrack1,empireRessource1,empirePalace1);
//   cout << "idEmpire: " << empire1.getId() << endl;
//   cout << "Name: " << empire1.getName() << endl;
//   cout << "EmpireLevel: " << empire1.getEmpireLevel() << endl;
//   cout << "GoldRessource: " << empire1.getGoldRessource() << endl;
//   cout << "WoodRessource: " << empire1.getWoodRessource() << endl;
//   cout << "FoodRessource: " << empire1.getFoodRessource() << endl;
//   std::vector<Position> pos4=empire0.getPosition();
//   for (unsigned int i=0;i<pos4.size();i++ ){
//     cout << "Position X: " << pos4[i].getX() << endl;
//     cout << "Position Y: " << pos4[i].getY() << endl;
//   }
//   Barrack* empireBarrack2=empire1.getBarrack();
//   cout<< "Barrack X position:" << empireBarrack2->getPosition().getX() << endl;
//   cout<< "Barrack Y position:" << empireBarrack2->getPosition().getY() << endl;
//   cout<< "Barrack level:" << empireBarrack2->getLevel() << endl;
//   cout<< "Barrack life:" << empireBarrack2->getLife() << endl;
//   cout << endl;
//
//   Palace* empirePalace2=empire1.getPalace();
//   cout<< "Palace X position:" << empirePalace2->getPosition().getX() << endl;
//   cout<< "Palace Y position:" << empirePalace2->getPosition().getY() << endl;
//   cout<< "Palace level:" << empirePalace2->getLevel() << endl;
//   cout<< "Palace life:" << empirePalace2->getLife() << endl;
//   cout << endl;
//
//   Ressource* empireRessource2=empire1.getRessource();
//   cout<< "Ressource X position:" << empireRessource2->getPosition().getX() << endl;
//   cout<< "Ressource Y position:" << empireRessource2->getPosition().getY() << endl;
//   cout<< "Ressource level:" << empireRessource2->getLevel() << endl;
//   cout<< "Ressource life:" << empireRessource2->getLife() << endl;
//   cout << endl;
//
//   cout << "CONSTRUCTEUR WITH ARGUMENTS OUTSIDE DEF DOMAINE" << endl;
//   Empire empire2(-5,"ENSEA",1000,50000,100,100,100,pos1,empireBarrack1,empireRessource1,empirePalace1);
//   cout << endl;
// }
