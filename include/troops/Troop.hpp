#ifndef TROOP
#define TROOP
#include <vector>
#include <string>

class Troop
{
public:
    Troop();
    Troop(std::string identifier, double health, double damage, double defense, double agility, int cost, bool mounted, bool ranged);
    virtual ~Troop();
    Troop(const Troop &troop);
    // key metode
    virtual void attack(Troop *target);
    void const info();  // identifikacija troopa
    void const stats(); // ispis statova i identifikacija troopa
    virtual void ability() = 0;

    // getteri
    double getHealth();
    double getDamage();
    double getDefense();
    double getAgility();
    bool getMounted();
    bool getRanged();
    // setteri
    void setHealth(double health);
    void setDamage(double damage);
    void setDefense(double defense);
    void setAgility(double agility);
    void setCost(int cost);
    bool setMounted(bool);
    bool setRanged(bool);

protected:
    std::string troopIdentifier;
    double health;
    double maxHealth;
    double damage;
    double defense;
    double agility;
    int cost;
    bool mounted;
    bool ranged;
};

#endif