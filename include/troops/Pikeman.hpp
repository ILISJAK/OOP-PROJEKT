#include "Troop.hpp"

class Pikeman : public Troop
{
public:
    Pikeman();
    Pikeman(std::string identifier, double health, double damage, double defense, double agility, int cost, bool mounted, bool ranged);
    virtual void ability() override;
};