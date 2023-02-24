#include "../include/structures/Structure.hpp"
#include "../include/misc/Town.hpp"

#define GOLDCOST 0
#define WOODCOST 0
#define STONECOST 0

Structure::Structure(Town *town) : parentTown(town)
{
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
