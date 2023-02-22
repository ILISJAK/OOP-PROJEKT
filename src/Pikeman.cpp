#ifndef PIKEMAN
#define PIKEMAN

#include "../include/troops/Pikeman.hpp"
#include <iostream>

#define IDENTIFIER "PIKEMAN"
#define MAXHEALTH 120
#define DAMAGE 10
#define DEFENSE 50
#define AGILITY 1
#define COST 75
#define MOUNTED false
#define RANGED false

Pikeman::Pikeman() : Troop::Troop(IDENTIFIER, MAXHEALTH, DAMAGE, DEFENSE, AGILITY, COST, MOUNTED, RANGED) {}
Pikeman::Pikeman(std::string identifier, double maxHealth, double damage, double defense, double agility, int cost, bool mounted, bool ranged) : Troop::Troop(identifier, health, damage, defense, agility, cost, mounted, ranged) {}

void Pikeman::ability()
{
    std::cout << "lmcao" << std::endl;
}

#endif