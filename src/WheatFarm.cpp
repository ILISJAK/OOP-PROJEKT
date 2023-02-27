#include "../include/structures/WheatFarm.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define TYPE "Wheat Farm & Mill"
#define GOLDCOST 90
#define WOODCOST 50
#define STONECOST 0
#define OUTPUT 100

int WheatFarm::resourcesProduced = 0;

WheatFarm::WheatFarm(Town *parentTown) : Structure(parentTown), output(OUTPUT)
{
    if (parentTown == nullptr)
    {
        std::cout << "No existing town provided for WheatFarm constructor." << std::endl;
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
WheatFarm::~WheatFarm() {}

// key metode
void WheatFarm::work()
{
    parentTown->setRations(parentTown->getRations() + 100);
    resourcesProduced += 100;
}
void WheatFarm::info()
{
    std::cout << "Food produced by farms: " << resourcesProduced << std::endl;
}
// getteri
int WheatFarm::getOutput() { return output; }
// setteri
void WheatFarm::setOutput(int output)
{
    if (output >= 0)
        this->output = output;
    else
        throw InputValidation("Output value must be greater than zero.");
}
