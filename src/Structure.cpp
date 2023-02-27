#include "../include/structures/Structure.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define TYPE ""
#define GOLDCOST 0
#define WOODCOST 0
#define STONECOST 0

Structure::Structure(Town *town) : Structure(town, TYPE, GOLDCOST, WOODCOST, STONECOST) {}
Structure::Structure(Town *town, std::string type, int goldCost, int woodCost, int stoneCost)
{
    if (town == nullptr)
    {
        std::cout << "No existing town provided for structure constructor." << std::endl;
        return;
    }
    setParentTown(town);
    setGoldCost(goldCost);
    setWoodCost(woodCost);
    setStoneCost(stoneCost);
}
Structure::~Structure() {}

// key metode

// getteri

std::string Structure::getType() { return type; }
int Structure::getGoldCost() { return goldCost; }
int Structure::getWoodCost() { return woodCost; }
int Structure::getStoneCost() { return stoneCost; }
Town *Structure::getParentTown() { return parentTown; }

// setteri

void Structure::setType(std::string type)
{
    this->type = type;
}
void Structure::setGoldCost(int goldCost)
{
    if (goldCost >= 0)
        this->goldCost = goldCost;
    else
        throw InputValidation("Gold cost can't be negative.");
}
void Structure::setWoodCost(int woodCost)
{
    if (woodCost >= 0)
        this->woodCost = woodCost;
    else
        throw InputValidation("Wood cost can't be negative.");
}
void Structure::setStoneCost(int stoneCost)
{
    if (stoneCost >= 0)
        this->stoneCost = stoneCost;
    else
        throw InputValidation("Stone cost can't be negative.");
}
void Structure::setParentTown(Town *parentTown)
{
        this->parentTown = parentTown;
}
