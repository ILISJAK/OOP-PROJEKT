#ifndef MACEMAN
#define MACEMAN

#include "../include/troops/Maceman.hpp"
#include <iostream>

#define IDENTIFIER "MACEMAN"
#define MAXHEALTH 40
#define DAMAGE 60
#define DEFENSE 10
#define AGILITY 10
#define COST 100
#define MOUNTED false
#define RANGED false

Maceman::Maceman() : Troop::Troop(IDENTIFIER, MAXHEALTH, DAMAGE, DEFENSE, AGILITY, COST, MOUNTED, RANGED) {}
Maceman::Maceman(std::string identifier, double maxHealth, double damage, double defense, double agility, int cost, bool mounted, bool ranged) : Troop::Troop(identifier, health, damage, defense, agility, cost, mounted, ranged) {}

void Maceman::ability()
{
    std::cout << "lmaoa" << std::endl;
}
#endif