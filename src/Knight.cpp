#ifndef KNIGHT
#define KNIGHT

#include "../include/troops/Knight.hpp"
#include <iostream>

#define IDENTIFIER "KNIGHT"
#define MAXHEALTH 90
#define DAMAGE 50
#define DEFENSE 30
#define AGILITY 20
#define COST 250
#define MOUNTED true
#define RANGED false

Knight::Knight() : Troop::Troop(IDENTIFIER, MAXHEALTH, DAMAGE, DEFENSE, AGILITY, COST, MOUNTED, RANGED) {}
Knight::Knight(std::string identifier, double maxHealth, double damage, double defense, double agility, int cost, bool mounted, bool ranged) : Troop::Troop(identifier, health, damage, defense, agility, cost, mounted, ranged) {}

void Knight::ability()
{
    std::cout << "lmaao" << std::endl;
}

#endif