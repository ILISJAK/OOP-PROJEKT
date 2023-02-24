#include "../include/structures/Structure.hpp"
#include "../include/misc/Town.hpp"

#define COST 0

Structure::Structure(Town *town) : parentTown(town)
{
    setCost(COST);
}
Structure::~Structure() {}
// key metode

// getteri
int Structure::getCost()
{
    return cost;
}
Town *Structure::getParentTown()
{
    return parentTown;
}

// setteri
void Structure::setCost(int cost)
{
    this->cost = cost;
}
