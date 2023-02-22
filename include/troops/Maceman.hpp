#include "Troop.hpp"

class Maceman : public Troop
{
public:
    Maceman();
    Maceman(std::string identifier, double health, double damage, double defense, double agility, int cost, bool mounted, bool ranged);
    virtual void ability() override;
};