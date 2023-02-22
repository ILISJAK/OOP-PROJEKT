#include "Troop.hpp"

class Lord : public Troop
{
public:
    Lord();
    Lord(std::string identifier, double health, double damage, double defense, double agility, int cost, bool mounted, bool ranged);
    ~Lord();
    virtual void ability() override;
};