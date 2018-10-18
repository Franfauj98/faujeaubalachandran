// Generated by dia2code
#ifndef STATE__EMPIRE__H
#define STATE__EMPIRE__H

#include <string>
#include <vector>

namespace state {
  class Barrack;
  class Ressource;
  class Palace;
  class Position;
  class Buildings;
}

#include "Position.h"
#include "Buildings.h"

namespace state {

  /// class Empire - 
  class Empire {
    // Associations
    // Attributes
  public:
    Barrack* barrack;
    Ressource* ressource;
    Palace* palace;
  private:
    int idEmpire;
    std::string name;
    int empireLevel;
    int life;
    int goldRessource;
    int woodRessource;
    int foodRessource;
    std::vector<Position> position;
    // Operations
  public:
    Empire ();
    Empire (int id, std::string name, int empireLevel, int life, int goldRessource, int woodRessource, int foodRessource, std::vector<Position> position, Barrack* barrack, Ressource* ressource, Palace* palace);
    int getId () const;
    void setName (const std::string name);
    std::string getName () const;
    void setEmpireLevel (const int level);
    int getEmpireLevel () const;
    void setLife (const int life);
    int getLife () const;
    int getGoldRessource () const;
    void setGoldRessource (const int gold);
    int getWoodRessource () const;
    void setWoodRessource (const int wood);
    int getFoodRessource () const;
    void setFoodRessource (const int food);
    std::vector<Position> getPosition () const;
    void setPosition (const std::vector<Position> postion);
    Barrack* getBarrack () const;
    void setBarrack (Barrack* barrack);
    Palace* getPalace () const;
    void setPalace (Palace* palace);
    Ressource* getRessource () const;
    void setRessource (Ressource* ressource);
    Barrack* createBarrack (Barrack* barrack, int id, Position position, int level);
    Ressource* createRessource (Ressource* ressource, int id, Position position, int level);
    Palace* createPalace (Palace* palace, int id, Position position, int level);
    void destructBarrack (Barrack* barrack);
    void destructRessource (Ressource* ressource);
    void destructPalace (Palace* palace);
    ~Empire ();
    // Setters and Getters
  };

};

#endif
