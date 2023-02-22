#include <iostream>
#include "../include/misc/Town.hpp"
#include "../include/troops/Archer.hpp"
#include "../include/troops/Knight.hpp"
#include "../include/troops/Maceman.hpp"
#include "../include/troops/Pikeman.hpp"

#define TEAM 'A'
#define HOUSING 10
#define GOLD 1000
#define RATIONS 350
#define WOOD 200
#define STONE 200

Town::Town() : Town::Town(TEAM, HOUSING, GOLD, RATIONS, WOOD, STONE) {}
Town::Town(char team) : Town::Town(team, HOUSING, GOLD, RATIONS, WOOD, STONE) {}
Town::Town(char team, int housing, double gold, int rations, int wood, int stone)
{
    setTeam(team);
    setHousing(housing);
    setGold(gold);
    setRations(rations);
    setWood(wood);
    setStone(stone);
}
Town::~Town()
{
    delete this->lord;
    std::cout << "Town " << getTeam() << " destroyed." << std::endl;
    // std::cout << "TEST6" << std::endl;
}

Troop *lord = new Lord();
double Town::goldEarned = 0;
int Town::troopsProduced = 0;
int Town::structuresConstructed = 0;
int Town::villagersTrained = 0;

// key metode
void const Town::info()
{
    std::cout << "TEAM " << team << " TOWN: " << std::endl;
    std::cout << "Population: " << villagersTrained << "/" << housing << std::endl;
    std::cout << "Number of troops: " << army.size() << std::endl;
    std::cout << "Structures built: " << structuresConstructed << std::endl;
    std::cout << "Gold: " << gold << std::endl;
    std::cout << "Stone: " << stone << std::endl;
    std::cout << "Wood: " << wood << std::endl;
    std::cout << "Rations: " << rations << std::endl;
    std::cout << "Total gold earned: " << goldEarned << std::endl;
    std::cout << "Total troops produced: " << troopsProduced << std::endl;
}

// metode vezane uz gradevine i ekonomiju

void const Town::listStructures() // treba smisliti nacin za identifikaciju troopova gradevina
{
    for (auto &it : structures)
    {
        if (it != structures.back())
            std::cout << it << ", ";
        else
        {
            std::cout << it << std::endl;
        }
    }
}
void Town::buildHousing() // placeholder exception handle
{
    if (structuresConstructed + 1 <= housing && wood >= 20)
    {
        this->wood -= 20;
        this->housing += 5;
        structuresConstructed++;
    }
}
void Town::trainVillager()
{
    this->rations -= 10;
    villagersTrained++;
}

// metode vezane uz troopove

void const Town::listTroops() // treba smisliti nacin za identifikaciju troopova - smisljeno
{
    std::cout << "TOWN " << team << " ARMY SIZE: " << army.size() << std::endl;
    for (auto &it : army)
    {
        if (it != army.back())
            it->info();
        else
        {
            it->info();
            std::cout << std::endl;
        }
    }
}

void Town::trainTroop(std::string troopName)
{
    if (troopName == "archer")
    {
        army.push_back(new Archer());
    }
    else if (troopName == "knight")
    {
        army.push_back(new Knight());
    }
    else if (troopName == "maceman")
    {
        army.push_back(new Maceman());
    }
    else if (troopName == "pikeman")
    {
        army.push_back(new Pikeman());
    }
    else
    {
        std::cout << "No such troop." << std::endl;
    }
}

void Town::raid(Town *town) // eraseat iz vektora pa obrisat
{
    std::cout << "Town " << getTeam() << " has attacked town " << town->getTeam() << "!" << std::endl;
    int allyCasualties = 0;
    int enemyCasualties = 0;
    while (1)
    {
        Troop *attacker = this->army.front();
        Troop *target = town->army.front();
        if (!this->army.empty())
        {
            if (!town->army.empty())
            {
                attacker->attack(target);
                if (target->getHealth() <= 0)
                {
                    enemyCasualties++;
                    town->army.erase(town->army.begin());
                    delete target;
                }
                if (attacker->getHealth() <= 0)
                {
                    allyCasualties++;
                    this->army.erase(this->army.begin());
                    delete attacker;
                }
            }
            else
            {
                std::cout << "Town " << getTeam() << " has won the battle." << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Town " << town->getTeam() << " has won the battle." << std::endl;
            break;
        }
    }
    std::cout << "Town " << getTeam() << " casualties: " << allyCasualties << std::endl;
    std::cout << "Town " << town->getTeam() << " casualties: " << enemyCasualties << std::endl;
}

void Town::attackLord(Town *town)
{
    std::cout << "Town " << getTeam() << " has attacked the town " << town->getTeam() << " Lord!" << std::endl;
    while (1)
    {
        std::cout << "TEST1" << std::endl;
        Troop *attacker = this->army.front();
        Troop *target = town->lord;
        std::cout << "TEST2" << std::endl;
        if (!this->army.empty())
        {
            std::cout << "TEST3" << std::endl;
            if (town->army.empty())
            {
                std::cout << "TEST4" << std::endl;
                attacker->attack(target);
                std::cout << "TEST5" << std::endl;
                if (target->getHealth() <= 0)
                {
                    std::cout << "King" << std::endl;
                    delete town;
                    std::cout << "Town " << getTeam() << " remaining troops: " << this->army.size() << std::endl;
                    return;
                }
                if (attacker->getHealth() <= 0)
                {
                    std::cout << "Troop" << std::endl;
                    this->army.erase(this->army.begin());
                    delete attacker;
                }
            }
            else
            {
                std::cout << "Town " << town->getTeam() << " lord is still protected." << std::endl;
                return;
            }
        }
        else
        {
            target->info();
            std::cout << std::endl;
            return;
        }
    }
}

// getteri
char Town::getTeam()
{
    return team;
}
double Town::getGold()
{
    return gold;
}
int Town::getRations()
{
    return rations;
}
int Town::getHousing()
{
    return housing;
}
int Town::getWood()
{
    return wood;
}
int Town::getStone()
{
    return stone;
}

// setteri
void Town::setTeam(char team)
{
    this->team = team;
}
void Town::setGold(double gold)
{
    this->gold = gold;
}
void Town::setRations(int rations)
{
    this->rations = rations;
}
void Town::setHousing(int housing)
{
    this->housing = housing;
}
void Town::setWood(int wood)
{
    this->wood = wood;
}
void Town::setStone(int stone)
{
    this->stone = stone;
}
