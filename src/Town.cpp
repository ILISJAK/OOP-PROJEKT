#include <iostream>
#include <algorithm>
#include "../include/misc/Town.hpp"
#include "../include/troops/Archer.hpp"
#include "../include/troops/Knight.hpp"
#include "../include/troops/Maceman.hpp"
#include "../include/troops/Pikeman.hpp"
#include "../include/structures/Market.hpp"

#define TEAM 'A'
#define HOUSING 10
#define GOLD 1000
#define RATIONS 350
#define WOOD 200
#define STONE 200

std::vector<Town *> Town::allTowns;

Town::Town() : Town::Town(TEAM, HOUSING, GOLD, RATIONS, WOOD, STONE, new Lord()) {}

Town::Town(char team) : Town::Town(team, HOUSING, GOLD, RATIONS, WOOD, STONE, new Lord()) {}

Town::Town(char team, int housing, double gold, int rations, int wood, int stone, Troop *lord)
{
    std::cout << "A new town " << team << " has been created!" << std::endl;
    setTeam(team);
    setHousing(housing);
    setGold(gold);
    setRations(rations);
    setWood(wood);
    setStone(stone);
    this->lord = lord;
}
Town::~Town()
{
    delete lord;
    for (auto &troop : army)
    {
        delete troop;
    }
    army.clear();
    for (auto &structure : structures)
    {
        delete structure;
    }
    structures.clear();
    std::cout << "Town " << getTeam() << " destroyed." << std::endl;
    // std::cout << "TEST6" << std::endl;
}

// key metode

void Town::addAllTowns(std::vector<Town *> &towns)
{
    for (auto town : towns)
    {
        allTowns.push_back(town);
    }
}

void const Town::info()
{
    std::cout << "TEAM " << team << " TOWN: " << std::endl;
    std::cout << "- Population: " << population << "/" << housing << ", " << population - activePopulation << " unassigned" << std::endl;
    std::cout << "- Army size: " << army.size() << std::endl;
    std::cout << "- Structures built: " << structures.size() << std::endl;
    std::cout << "- Gold: " << gold << std::endl;
    std::cout << "- Stone: " << stone << std::endl;
    std::cout << "- Wood: " << wood << std::endl;
    std::cout << "- Rations: " << rations << std::endl;
}

void Town::wait()
{
    std::cout << "Some time has passed..." << std::endl;
    for (auto it = allTowns.begin(); it != allTowns.end();)
    {
        if (!(*it)->sufficientRations()) // dereferenciranje iteratora
        {
            std::cout << (*it)->getTeam() << " suffers from famine." << std::endl;
            it = allTowns.erase(it); // samo allTowns.erase(it) = memory leak
            delete *it;
            *it = nullptr;
            continue;
        }
        else
        {
            for (auto &structure : (*it)->getStructures())
            {
                structure->work();
            }
            (*it)->setRations((*it)->getRations() - (*it)->getPopulation());
            ++it;
        }
    }
}

// metode vezane uz strukture i ekonomiju

void const Town::listStructures()
{
    std::cout << "Town " << team << " structures: " << structures.size() << std::endl;
    int i = 1;
    for (auto &it : structures)
    {
        if (it != structures.back())
        {
            std::cout << i << ". " << it->getType() << ", ";
            i++;
        }
        else
        {
            std::cout << i << ". " << it->getType() << std::endl;
            ;
        }
    }
}
void Town::buildHousing(int n) // placeholder exception handle
{
    int counter = 0;
    for (int i = 0; i < n && getWood() - 10 >= 0; i++)
    {
        setWood(getWood() - 10);
        housing++;
        counter++;
    }
    if (counter == 0)
    {
        std::cout << "Insufficient wood." << std::endl;
        return;
    }
}
void Town::trainVillager(int n)
{
    int counter = 0;
    for (int i = 0; i < n && ((getRations() - 10 >= 0) && (population + 1) <= housing); i++)
    {
        setRations(getRations() - 10);
        population++;
        counter++;
    }
    if (counter == 0)
    {
        std::cout << "Insufficient housing or rations." << std::endl;
        return;
    }
}

void Town::buildStructure(Structure *structure)
{
    if (structure && gold >= structure->getGoldCost() && wood >= structure->getWoodCost() && stone >= structure->getStoneCost() && activePopulation + 2 <= population)
    {
        setActivePopulation(getActivePopulation() + 2);
        setGold(getGold() - structure->getGoldCost());
        setWood(getWood() - structure->getWoodCost());
        setStone(getStone() - structure->getStoneCost());
        structures.push_back(structure);
        std::cout << "A new structure has been built in " << structure->getParentTown()->getTeam() << " town." << std::endl;
    }
    else
    {
        std::cout << "Unable to build " << structure->getType() << std::endl;
    }
}

void Town::destroyStructure(Structure *structure)
{
    if (structure)
    {
        auto it = std::find(structures.begin(), structures.end(), structure);
        if (it != structures.end())
        {
            setActivePopulation(getActivePopulation() - 2);
            setGold(getGold() + structure->getGoldCost() / 2);
            setWood(getWood() + structure->getWoodCost() / 2);
            setStone(getStone() + structure->getStoneCost() / 2);
            structures.erase(it);
            std::cout << "A structure has been destroyed in " << team << " town." << std::endl;
        }
    }
}
void Town::buyFromMarket(std::string what, int amount)
{
    for (auto it = structures.begin(); it != structures.end(); ++it)
    {
        if ((*it)->getType() == "Market")
        {
            Market *market = dynamic_cast<Market *>(*it);
            if (market)
            {
                std::cout << "Market: ";
                if (!market->buy(what, amount)) // ako pronadeni market nema dovoljno resursa, trazimo sljedeci
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
    }
    std::cout << "No suitable market in town." << std::endl;
}
void Town::sellToMarket(std::string what, int amount)
{
    for (auto it = structures.begin(); it != structures.end(); ++it)
    {
        if ((*it)->getType() == "Market")
        {
            Market *market = dynamic_cast<Market *>(*it);
            if (market)
            {
                std::cout << "Market: ";
                if (!market->sell(what, amount)) // ako pronadeni market nema dovoljno resursa, trazimo sljedeci
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
    }
    std::cout << "No suitable market in town." << std::endl;
}
bool Town::sufficientRations()
{
    return (rations >= population);
}

// metode vezane uz vojsku

void const Town::listTroops() // treba smisliti nacin za identifikaciju troopova - smisljeno
{
    std::cout << "Town " << team << " army size: " << army.size() << std::endl;
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

void Town::trainTroop(Troop *troop)
{
    if (troop && gold >= troop->getCost() && (activePopulation + 1) <= population)
    {
        setGold(getGold() - troop->getCost());
        army.push_back(troop);
        setActivePopulation(getActivePopulation() + 1);
    }
    else
    {
        std::cout << "No villagers to turn into troops." << std::endl;
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
                    setActivePopulation(getActivePopulation() - 1);
                    setPopulation(getPopulation() - 1);
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
    if (town == nullptr)
    {
        std::cout << "Town doesnt exist." << std::endl;
        return;
    }
    if (town->lord == nullptr)
    {
        std::cout << "Lord doesnt exist." << std::endl;
        delete town;
        town = nullptr;
        return;
    }
    std::cout << "Town " << getTeam() << " has attacked the town " << town->getTeam() << " Lord!" << std::endl;
    while (1)
    {
        // std::cout << "TEST1" << std::endl;
        Troop *attacker = this->army.front();
        Troop *target = town->lord;
        // std::cout << "TEST2" << std::endl;
        if (!this->army.empty())
        {
            // std::cout << "TEST3" << std::endl;
            if (town->army.empty())
            {
                // std::cout << "TEST4" << std::endl;
                attacker->attack(target);
                // std::cout << "TEST5" << std::endl;
                if (target->getHealth() <= 0)
                {
                    // std::cout << "King" << std::endl;
                    this->gold += town->gold;
                    this->rations += town->rations;
                    this->stone += town->stone;
                    this->wood += town->wood;
                    this->population += town->population;
                    std::cout << "All of town " << town->getTeam() << "'s resources have been plundered! " << std::endl;
                    std::cout << town->population << " citizen(s) have assimilated to town " << getTeam() << "." << std::endl;
                    delete town;
                    std::cout << "Town " << getTeam() << " remaining troops: " << this->army.size() << std::endl;
                    return;
                }
                if (attacker->getHealth() <= 0)
                {
                    // std::cout << "Troop" << std::endl;
                    this->army.erase(this->army.begin());
                    delete attacker;
                    setActivePopulation(getActivePopulation() - 1);
                    setPopulation(getPopulation() - 1);
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
std::vector<Town *> &Town::getAllTowns()
{
    return allTowns;
}
std::vector<Structure *> Town::getStructures()
{
    return structures;
}
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
int Town::getPopulation()
{
    return population;
}
int Town::getActivePopulation()
{
    return activePopulation;
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
void Town::setPopulation(int population)
{
    this->population = population;
}
void Town::setActivePopulation(int activePopulation)
{
    this->activePopulation = activePopulation;
}