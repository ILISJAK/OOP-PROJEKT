#include "Troop.hpp"

class Archer : public Troop
{
public:
    Archer();
    Archer(std::string identifier, double health, double damage, double defense, double agility, int cost, bool mounted, bool ranged);
    virtual void ability() override;
};