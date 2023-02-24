#ifndef TOWN
#define TOWN

#include <vector>
#include <memory>
#include "../structures/Structure.hpp"
#include "../troops/Troop.hpp"
#include "../troops/Lord.hpp"
#include "../structures/Market.hpp"

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
    void const info();
    void const listTroops();
    void const listStructures();
    bool sufficientRations();
    void destroyStructure(Structure *structure);
    void buildStructure(Structure *structure);
    void buildHousing();
    void trainVillager();
    void trainTroop(Troop *troop);
    void raid(Town *town);
    void attackLord(Town *town);

    // getteri
    char getTeam();
    double getGold();
    int getRations();
    int getHousing();
    int getWood();
    int getStone();

    // setteri
    void setTeam(char team);
    void setGold(double gold);
    void setRations(int rations);
    void setHousing(int housing);
    void setWood(int wood);
    void setStone(int stone);

private:
    char team;
    std::vector<Troop *> army;           // vojska grada pohranjena
    std::vector<Structure *> structures; // sve građevine grada pohranjene
    Troop *lord;
    double gold;
    int rations;
    int wood;
    int stone;
    int housing;
    static double goldEarned;
    static int troopsProduced;
    static int structuresConstructed;
    int villagersTrained = 0;
};

#endif