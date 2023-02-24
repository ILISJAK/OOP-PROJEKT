#ifndef STRUCTURE
#define STRUCTURE

#include "../troops/Troop.hpp"

class Town; // forward deklaracija

class Structure
{
public:
    Structure();
    Structure(Town *town);
    virtual ~Structure();
    // key metode
    virtual void work() = 0;
    virtual void info() = 0;

    // getteri
    int getGoldCost();
    int getWoodCost();
    int getStoneCost();
    Town *getParentTown();

    // setteri
    void setGoldCost(int);
    void setWoodCost(int);
    void setStoneCost(int);
    void setParentTown(Town *parentTown);

protected:
    int goldCost;
    int woodCost;
    int stoneCost;
    Town *parentTown;
    Troop *guard;
};

#endif