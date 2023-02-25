#ifndef MARKET
#define MARKET

#include "Structure.hpp"

// class Town; // forward deklaracija

class Market : public Structure
{
public:
    Market(Town *town);
    ~Market();
    // key metode
    virtual void work() override;
    virtual void info() override;
    bool buy(std::string what, int amount);
    bool sell(std::string what, int amount);

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