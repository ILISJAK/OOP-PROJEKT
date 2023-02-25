#ifndef STONE_QUARRY
#define STONE_QUARRY

#include "Structure.hpp"

class StoneQuarry : public Structure
{
public:
    StoneQuarry(Town *parentTown);
    ~StoneQuarry();

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