#ifndef WOOD_CAMP
#define WOOD_CAMP

#include "Structure.hpp"

class WoodCamp : public Structure
{
public:
    WoodCamp(Town *parentTown);
    ~WoodCamp();

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