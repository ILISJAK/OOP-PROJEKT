#ifndef TOWN
#define TOWN

#include <vector>
#include <memory>
#include "../structures/Structure.hpp"
#include "../troops/Troop.hpp"
#include "../troops/Lord.hpp"

class Market;    // forward deklaracija
class Structure; // forward deklaracija

class Town final
{
public:
    Town();
    Town(char team);
    Town(char team, int housing, double gold, int rations, int wood, int stone, Troop *lord);
    ~Town();

    // key metode
    static void addAllTowns(std::vector<Town *> &towns);
    static void wait();
    void const info();
    void const listTroops();
    void const listStructures();
    void buyFromMarket(std::string what, int amount);
    void sellToMarket(std::string what, int amount);
    void destroyStructure(Structure *structure);
    void buildStructure(Structure *structure);
    void buildHousing(int n = 1);
    bool sufficientRations();
    void trainVillager(int = 1);
    void trainTroop(Troop *troop);
    void raid(Town *town);
    void attackLord(Town *town);

    // getteri
    static std::vector<Town *> &getAllTowns();
    std::vector<Structure *> getStructures();
    char getTeam();
    double getGold();
    int getRations();
    int getHousing();
    int getWood();
    int getStone();
    int getPopulation();
    int getActivePopulation();

    // setteri
    void setTeam(char team);
    void setGold(double gold);
    void setRations(int rations);
    void setHousing(int housing);
    void setWood(int wood);
    void setStone(int stone);
    void setPopulation(int population);
    void setActivePopulation(int activePopulation);

private:
    char team;
    std::vector<Troop *> army;           // vojska grada pohranjena
    std::vector<Structure *> structures; // sve građevine grada pohranjene
    static std::vector<Town *> allTowns;
    Troop *lord;
    double gold;
    int rations;
    int wood;
    int stone;
    int housing;
    int population = 0;
    int activePopulation = 0;
};

#endif