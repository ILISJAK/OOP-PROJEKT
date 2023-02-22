#include <vector>
#include "../structures/Structure.hpp"
#include "../troops/Troop.hpp"
#include "../troops/Lord.hpp"
#include "Villager.hpp"

class Town final
{
public:
    Town();
    Town(char team);
    Town(char team, int housing, double gold, int rations, int wood, int stone);
    ~Town();

    // key metode
    void const info();
    void const listTroops();
    void const listStructures();
    void buildHousing();
    void trainVillager();
    Structure *construct();
    void trainTroop(std::string troopName);
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
    static int villagersTrained;
};