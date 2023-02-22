#ifndef ARCHER
#define ARCHER

#include "../include/troops/Archer.hpp"
#include <iostream>

#define IDENTIFIER "ARCHER"
#define MAXHEALTH 25
#define DAMAGE 30
#define DEFENSE 1
#define AGILITY 5
#define COST 50
#define MOUNTED false
#define RANGED true

Archer::Archer() : Troop::Troop(IDENTIFIER, MAXHEALTH, DAMAGE, DEFENSE, AGILITY, COST, MOUNTED, RANGED) {}
Archer::Archer(std::string identifier, double maxHealth, double damage, double defense, double agility, int cost, bool mounted, bool ranged) : Troop::Troop(identifier, health, damage, defense, agility, cost, mounted, ranged) {}

void Archer::ability()
{
    std::cout << "lamao" << std::endl;
}

#endif