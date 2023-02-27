#include "../include/structures/StoneQuarry.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define TYPE "Stone Quarry & Ox Tether"
#define GOLDCOST 50
#define WOODCOST 40
#define STONECOST 25
#define OUTPUT 100

int StoneQuarry::resourcesProduced = 0;

StoneQuarry::StoneQuarry(Town *parentTown) : Structure(parentTown), output(OUTPUT)
{
    if (parentTown == nullptr)
    {
        std::cout << "No existing town provided for StoneQuarry constructor." << std::endl;
        return;
    }
    else
    {
        setType(TYPE);
        setGoldCost(GOLDCOST);
        setWoodCost(WOODCOST);
        setStoneCost(STONECOST);
    }
}
StoneQuarry::~StoneQuarry() {}

// key metode
void StoneQuarry::work()
{
    parentTown->setStone(parentTown->getStone() + 100);
    resourcesProduced += 100;
}
void StoneQuarry::info()
{
    std::cout << "Stone collected by quarries: " << resourcesProduced << std::endl;
}
// getteri
int StoneQuarry::getOutput() { return output; }
// setteri
void StoneQuarry::setOutput(int output)
{
    if (output >= 0)
        this->output = output;
    else
        throw InputValidation("Output value must be greater than zero.");
}
