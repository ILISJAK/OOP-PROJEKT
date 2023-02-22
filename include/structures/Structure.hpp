#ifndef STRUCTURE
#define STRUCTURE

#include "include/misc/Town.hpp"
#include "../troops/Troop.hpp"

class Structure
{
public:
    Structure();
    Structure(Town &town);
    virtual ~Structure();
    // key metode
    virtual void work() = 0;
    virtual void info() = 0;

    // getteri
    int getCost();

    // setteri
    void setCost(int cost);

protected:
    int cost;
    Town &parentTown;
    Troop *guard;
};

#endif