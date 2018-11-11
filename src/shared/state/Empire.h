// Generated by dia2code
#ifndef STATE__EMPIRE__H
#define STATE__EMPIRE__H

#include <string>
#include <vector>
#include <memory>

namespace state {
  class Position;
  class Barrack;
  class Ressource;
  class Palace;
  class Buildings;
}

#include "Position.h"
#include "Barrack.h"
#include "Ressource.h"
#include "Palace.h"
#include "Buildings.h"

namespace state {

  /// class Empire - 
  class Empire {
    // Associations
    // Attributes
  private:
    int idEmpire;
    std::string name;
    int empireLevel;
    int life;
    int goldRessource;
    int woodRessource;
    int foodRessource;
    std::vector<Position> position;
    std::unique_ptr<Barrack> barrack;
    std::unique_ptr<Ressource> ressource;
    std::unique_ptr<Palace> palace;
    int shot;
    // Operations
  public:
    Empire ();
    Empire (int id, std::string name, int empireLevel, int life, int goldRessource, int woodRessource, int foodRessource, std::vector<Position> position, std::unique_ptr<Barrack>& barrack, std::unique_ptr<Ressource>& ressource, std::unique_ptr<Palace>& palace, int shot);
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
    std::unique_ptr<Barrack>& getBarrack ();
    void setBarrack (std::unique_ptr<Barrack>& barrack);
    std::unique_ptr<Palace>& getPalace ();
    void setPalace (std::unique_ptr<Palace>& palace);
    std::unique_ptr<Ressource>& getRessource ();
    void setRessource (std::unique_ptr<Ressource>& ressource);
    int getShot ();
    void setShot (int shot);
    ~Empire ();
    // Setters and Getters
  };

};

#endif
