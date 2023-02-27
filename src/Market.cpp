#include "../include/structures/Market.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define TYPE "Market"
#define GOLDCOST 400
#define WOODCOST 50
#define STONECOST 0
#define MAXGOLD 1500
#define MAXRATIONS 300
#define MAXWOOD 500
#define MAXSTONE 600

Market::Market(Town *parentTown) : Structure(parentTown), maxGold(MAXGOLD), maxRations(MAXRATIONS), maxWood(MAXWOOD), maxStone(MAXSTONE)
{
    if (parentTown == nullptr)
    {
        std::cout << "No existing town provided for market constructor." << std::endl;
        return;
    }
    else
    {
        setType(TYPE);
        setGoldCost(GOLDCOST);
        setWoodCost(WOODCOST);
        setStoneCost(STONECOST);
        gold = maxGold / 2;
        rations = maxRations / 2;
        wood = maxWood / 2;
        stone = maxStone / 2;
    }
}
Market::~Market() {}

// key metode

void Market::work() // restock
{
    gold = maxGold;
    rations = maxRations;
    wood = maxWood;
    stone = maxStone;
}
void Market::info()
{
    std::cout << "MARKET: " << std::endl;
    std::cout << "Merchant gold: " << gold << std::endl;
    std::cout << "Rations on stock: " << rations << std::endl;
    std::cout << "Wood on stock: " << wood << std::endl;
    std::cout << "Stone on stock: " << wood << std::endl;
}
bool Market::buy(std::string what, int amount)
{
    if (what == "rations")
    {
        if (rations <= amount)
        {
            return false;
        }
        parentTown->setGold((parentTown->getGold() - (8 * amount))); // 1 ration = 8 gold
        parentTown->setRations(parentTown->getRations() + amount);
        std::cout << "Bought " << amount << " " << what << "(s) for " << 8 * amount << " gold." << std::endl;
        return true;
    }
    else if (what == "wood" && rations >= amount)
    {
        if (wood <= amount)
        {
            return false;
        }
        parentTown->setGold((parentTown->getGold() - (5 * amount))); // 1 wood = 5 gold
        parentTown->setWood(parentTown->getWood() + amount);
        std::cout << "Bought " << amount << " " << what << " for " << 5 * amount << " gold." << std::endl;
        return true;
    }
    else if (what == "stone" && rations >= amount)
    {
        if (stone <= amount)
        {
            return false;
        }
        parentTown->setGold((parentTown->getGold() - (10 * amount))); // 1 stone = 10 gold
        parentTown->setStone(parentTown->getStone() + amount);
        std::cout << "Bought " << amount << " " << what << "(s) for " << 10 * amount << " gold." << std::endl;
        return true;
    }
    else
    {
        std::cout << "No such resource." << std::endl;
        return true;
    }
}
bool Market::sell(std::string what, int amount)
{
    if (what == "rations")
    {
        if (gold <= 6 * amount)
        {
            return false;
        }
        parentTown->setGold((parentTown->getGold() + (6 * amount))); // 1 ration = 6 gold
        parentTown->setRations(parentTown->getRations() - amount);
        std::cout << "Sold " << amount << " " << what << "(s) for " << 6 * amount << " gold." << std::endl;
        return true;
    }
    else if (what == "wood")
    {
        if (gold <= 3 * amount)
        {
            return false;
        }
        parentTown->setGold((parentTown->getGold() + (3 * amount))); // 1 wood = 3 gold
        parentTown->setWood(parentTown->getWood() - amount);
        std::cout << "Sold " << amount << " " << what << " for " << 3 * amount << " gold." << std::endl;
        return true;
    }
    else if (what == "stone")
    {
        if (gold <= 8 * amount)
        {
            return false;
        }
        parentTown->setGold((parentTown->getGold() + (8 * amount))); // 1 stone = 8 gold
        parentTown->setStone(parentTown->getStone() - amount);
        std::cout << "Sold " << amount << " " << what << "(s) for " << 8 * amount << " gold." << std::endl;
        return true;
    }
    else
    {
        std::cout << "No such resource." << std::endl;
        return true;
    }
}

// getteri
double Market::getMaxGold() { return maxGold; }
int Market::getMaxRations() { return maxRations; }
int Market::getMaxWood() { return maxWood; }
int Market::getMaxStone() { return maxStone; }

// setteri
double Market::setMaxGold(double maxGold)
{
    if (maxGold >= 0)
        this->maxGold = maxGold;
    else
        throw InputValidation("maxGold value must be greater than zero.");
}
int Market::setMaxRations(int maxRations)
{
    if (maxRations >= 0)
        this->maxRations = maxRations;
    else
        throw InputValidation("maxRations value must be greater than zero.");
}
int Market::setMaxWood(int maxWood)
{
    if (maxWood >= 0)
        this->maxWood = maxWood;
    else
        throw InputValidation("maxWood value must be greater than zero.");
}
int Market::setMaxStone(int maxStone)
{
    if (maxStone >= 0)
        this->maxStone = maxStone;
    else
        throw InputValidation("maxStone value must be greater than zero.");
}