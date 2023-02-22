#ifndef VILLAGER
#define VILLAGER

class Villager
{
public:
    Villager();
    Villager(double hitPoints);
    Villager(double hitPoints, double attack, double speed);
    Villager(const Villager &villager);
    double getHitPoints();
    double getAttack();
    double getMovementSpeed();
    void setHitPoints(double hitPoints);
    void setAttack(double attack);
    void setMovementSpeed(double movementSpeed);
    void info();

private:
    double hitPoints;
    double attack;
    double movementSpeed;
};

#endif