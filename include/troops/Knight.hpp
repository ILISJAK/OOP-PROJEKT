#include "Troop.hpp"

class Knight : public Troop
{
public:
    Knight();
    Knight(std::string identifier, double health, double damage, double defense, double agility, int cost, bool mounted, bool ranged);
    virtual void ability() override;
};