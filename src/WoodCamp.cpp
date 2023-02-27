#include "../include/structures/WoodCamp.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define TYPE "Wood Camp"
#define GOLDCOST 25
#define WOODCOST 25
#define STONECOST 0
#define OUTPUT 100

int WoodCamp::resourcesProduced = 0;

WoodCamp::WoodCamp(Town *parentTown) : Structure(parentTown), output(OUTPUT)
{
    if (parentTown == nullptr)
    {
        std::cout << "No existing town provided for WoodCamp constructor." << std::endl;
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
WoodCamp::~WoodCamp() {}

// key metode
void WoodCamp::work()
{
    parentTown->setRations(parentTown->getRations() + 100);
}
void WoodCamp::info()
{
    std::cout << "Wood collected by camps: " << resourcesProduced << std::endl;
}
// getteri
int WoodCamp::getOutput() { return output; }
// setteri
void WoodCamp::setOutput(int output)
{
    if (output >= 0)
        this->output = output;
    else
        throw InputValidation("Output value must be greater than zero.");
}
