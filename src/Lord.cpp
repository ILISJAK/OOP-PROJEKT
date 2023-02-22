#ifndef LORD
#define LORD

#include "../include/troops/Lord.hpp"
#include <iostream>

#define IDENTIFIER "LORD"
#define MAXHEALTH 250
#define DAMAGE 60
#define DEFENSE 100
#define AGILITY 10
#define COST 50
#define MOUNTED false
#define RANGED false

Lord::Lord() : Troop::Troop(IDENTIFIER, MAXHEALTH, DAMAGE, DEFENSE, AGILITY, COST, MOUNTED, RANGED) {}
Lord::Lord(std::string identifier, double maxHealth, double damage, double defense, double agility, int cost, bool mounted, bool ranged) : Troop::Troop(identifier, health, damage, defense, agility, cost, mounted, ranged) {}
Lord::~Lord()
{
    std::cout << "The lord has been defeated." << std::endl;
}
void Lord::ability()
{
    std::cout << "lmaoa" << std::endl;
}
#endif