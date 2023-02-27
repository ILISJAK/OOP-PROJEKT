#include "../include/troops/Troop.hpp"
#include <iostream>

#define IDENTIFIER "abc"
#define MAXHEALTH 1
#define DAMAGE 1
#define DEFENSE 1
#define AGILITY 1
#define COST 1
#define MOUNTED false
#define RANGED false

Troop::Troop() : Troop::Troop(IDENTIFIER, MAXHEALTH, DAMAGE, DEFENSE, AGILITY, COST, MOUNTED, RANGED) {}
Troop::Troop(std::string identifier, double maxHealth, double damage, double defense, double agility, int cost, bool mounted, bool ranged)
{
    this->troopIdentifier = identifier;
    this->maxHealth = maxHealth;
    setHealth(health);
    setDamage(damage);
    setDefense(defense);
    setAgility(agility);
    setCost(cost);
    setMounted(mounted);
    setRanged(ranged);
}
Troop::~Troop() {}

Troop::Troop(const Troop &troop) {}
void Troop::attack(Troop *target)
{
    if (target == nullptr)
    {
        std::cout << "target is nullptr" << std::endl;
        return;
    }

    target->health -= this->damage;
    this->health -= target->damage;
}
void const Troop::info()
{
    std::cout << troopIdentifier << " ";
    std::cout << "HP: " << health << "/" << maxHealth << std::endl;
}
void const Troop::stats()
{
    info();
    std::cout << "DMG: " << damage << std::endl;
    std::cout << "DEF: " << defense << std::endl;
    std::cout << "AGI: " << agility << std::endl;
    std::cout << "MOUNTED: " << mounted << std::endl;
    std::cout << "RANGED: " << ranged << std::endl;
}

// getteri
double Troop::getHealth()
{
    return health;
}
double Troop::getDamage()
{
    return damage;
}
double Troop::getDefense()
{
    return defense;
}
double Troop::getAgility()
{
    return agility;
}
int Troop::getCost()
{
    return cost;
}
bool Troop::getMounted()
{
    return mounted;
}
bool Troop::getRanged()
{
    return ranged;
}

// setteri
void Troop::setHealth(double health)
{
    if (health >= 0)
        this->health = health;
    else
        health = 0;
}
void Troop::setDamage(double damage)
{
    if (damage > 0)
        this->damage = damage;
    else
        throw InputValidation("Damage value must be greater than zero.");
}
void Troop::setDefense(double defense)
{
    if (defense > 0)
        this->defense = defense;
    else
        throw InputValidation("Defense value must be greater than zero.");
}
void Troop::setAgility(double agility)
{
    if (agility > 0)
        this->agility = agility;
    else
        throw InputValidation("Agility value must be greater than zero.");
}
void Troop::setCost(int cost)
{
    if (cost >= 0)
        this->cost = cost;
    else
        throw InputValidation("Cost value cant be negative.");
}
bool Troop::setMounted(bool mounted)
{
    this->mounted = mounted;
}
bool Troop::setRanged(bool ranged)
{
    this->ranged = ranged;
}
