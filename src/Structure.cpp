#include "../include/structures/Structure.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define GOLDCOST 0
#define WOODCOST 0
#define STONECOST 0

Structure::Structure(Town *town)
{
    std::cout << "Creating new Structure object with parent town: " << parentTown->getTeam() << std::endl;
    setParentTown(town);
    setGoldCost(GOLDCOST);
    setWoodCost(WOODCOST);
    setStoneCost(STONECOST);
}
Structure::~Structure() {}

// key metode

// getteri

int Structure::getGoldCost() { return goldCost; }
int Structure::getWoodCost() { return woodCost; }
int Structure::getStoneCost() { return stoneCost; }
Town *Structure::getParentTown() { return parentTown; }

// setteri

void Structure::setGoldCost(int goldCost) { this->goldCost = goldCost; }
void Structure::setWoodCost(int woodCost) { this->woodCost = woodCost; }
void Structure::setStoneCost(int stoneCost) { this->stoneCost = stoneCost; }
void Structure::setParentTown(Town *parentTown) { this->parentTown = parentTown; }
