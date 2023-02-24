#include "../include/structures/Market.hpp"
#include "../include/misc/Town.hpp"
#include <iostream>

#define MAXGOLD 10000
#define MAXRATIONS 1000
#define MAXWOOD 1000
#define MAXSTONE 1000

Market::Market(Town *town) : Structure::Structure(parentTown)
{
    setMaxGold(MAXGOLD);
    gold = maxGold;
    setMaxRations(MAXRATIONS);
    rations = maxRations;
    setMaxWood(MAXWOOD);
    wood = maxWood;
    setMaxStone(MAXSTONE);
    stone = maxStone;
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
void Market::buy(std::string what, int amount)
{
    if (what == "rations")
    {
        parentTown->setGold((parentTown->getGold() - (8 * amount))); // 1 ration = 8 gold
        parentTown->setRations(parentTown->getRations() + amount);
        std::cout << "Bought " << amount << " " << what << "(s) for " << 8 * amount << " gold->";
    }
    else if (what == "wood")
    {
        parentTown->setGold((parentTown->getGold() - (5 * amount))); // 1 wood = 5 gold
        parentTown->setRations(parentTown->getRations() + amount);
        std::cout << "Bought " << amount << " " << what << " for " << 5 * amount << " gold->";
    }
    else if (what == "stone")
    {
        parentTown->setGold((parentTown->getGold() - (10 * amount))); // 1 stone = 10 gold
        parentTown->setStone(parentTown->getStone() + amount);
        std::cout << "Bought " << amount << " " << what << "(s) for " << 10 * amount << " gold->";
    }
    else
    {
        std::cout << "No such resource->" << std::endl;
    }
}
void Market::sell(std::string what, int amount)
{
    if (what == "rations")
    {
        parentTown->setGold((parentTown->getGold() + (6 * amount))); // 1 ration = 6 gold
        parentTown->setRations(parentTown->getRations() - amount);
        std::cout << "Sold " << amount << " " << what << "(s) for " << 6 * amount << " gold->";
    }
    else if (what == "wood")
    {
        parentTown->setGold((parentTown->getGold() + (3 * amount))); // 1 wood = 3 gold
        parentTown->setRations(parentTown->getRations() - amount);
        std::cout << "Sold " << amount << " " << what << " for " << 3 * amount << " gold->";
    }
    else if (what == "stone")
    {
        parentTown->setGold((parentTown->getGold() + (8 * amount))); // 1 stone = 8 gold
        parentTown->setStone(parentTown->getStone() - amount);
        std::cout << "Sold " << amount << " " << what << "(s) for " << 8 * amount << " gold->";
    }
    else
    {
        std::cout << "No such resource->" << std::endl;
    }
}

// getteri
double Market::getMaxGold() { return maxGold; }
int Market::getMaxRations() { return maxRations; }
int Market::getMaxWood() { return maxWood; }
int Market::getMaxStone() { return maxStone; }

// setteri
double Market::setMaxGold(double maxGold) { this->maxGold = maxGold; }
int Market::setMaxRations(int maxRations) { this->maxRations = maxRations; }
int Market::setMaxWood(int maxWood) { this->maxWood = maxWood; }
int Market::setMaxStone(int maxStone) { this->maxStone = maxStone; }