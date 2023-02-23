#include "../include/structures/Structure.hpp"

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

// setteri
void Structure::setCost(int cost)
{
    this->cost = cost;
}
