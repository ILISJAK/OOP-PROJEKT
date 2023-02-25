#ifndef WHEAT_FARM
#define WHEAT_FARM

#include "Structure.hpp"

class WheatFarm : public Structure
{
public:
    WheatFarm(Town *parentTown);
    ~WheatFarm();

    // key metode

    virtual void work() override;
    virtual void info() override;
    // getteri
    int getOutput();
    // setteri
    void setOutput(int);

protected:
    int output;
    static int resourcesProduced;
};

#endif