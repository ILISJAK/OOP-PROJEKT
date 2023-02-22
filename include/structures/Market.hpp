#ifndef STRUCTURE_BASE
#define STRUCTURE_BASE

#include "include/misc/Town.hpp"
#include "../troops/Troop.hpp"
#include "Structure.hpp"

class Market : public Structure
{
public:
    Market();
    Market(Town *town);
    ~Market();
    // key metode
    virtual void work() override;
    virtual void info() override;
    void buy(std::string what, int amount);
    void sell(std::string what, int amount);

    // getteri
    double getMaxGold();
    int getMaxRations();
    int getMaxWood();
    int getMaxStone();

    // setteri
    double setMaxGold(double);
    int setMaxRations(int);
    int setMaxWood(int);
    int setMaxStone(int);

protected:
    Town *parentTown;
    double gold;
    int rations;
    int wood;
    int stone;
    double maxGold;
    int maxRations;
    int maxWood;
    int maxStone;
};

#endif