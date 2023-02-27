#ifndef STRUCTURE
#define STRUCTURE

#include "../troops/Troop.hpp"
#include "../misc/Exception.hpp"

class Town; // forward deklaracija

class Structure
{
public:
    Structure(Town *town);
    Structure(Town *town, std::string type, int goldCost, int woodCost, int stoneCost);
    virtual ~Structure();
    // key metode
    virtual void work() = 0;
    virtual void info() = 0;

    // getteri
    std::string getType();
    int getGoldCost();
    int getWoodCost();
    int getStoneCost();
    Town *getParentTown();

    // setteri
    void setType(std::string type);
    void setGoldCost(int);
    void setWoodCost(int);
    void setStoneCost(int);
    void setParentTown(Town *parentTown);

protected:
    std::string type;
    int goldCost;
    int woodCost;
    int stoneCost;
    Town *parentTown;
};

#endif