#include "../misc/Villager.hpp"
#include "../troops/Troop.hpp"
#include <vector>

class Structure
{
public:
    Structure();
    virtual ~Structure() = 0;
    void construct();
    virtual void info() = 0;

protected:
    double health;
    int cost;
    Troop *guard;
    Villager *worker;
};