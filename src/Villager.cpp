#include <iostream>
#include "../include/misc/Villager.hpp"
// defineovi za defaultne vrijednosti
#define HIT_POINTS 25
#define ATTACK 3
#define MOVEMENT_SPEED 0.8

Villager::Villager() : Villager::Villager(HIT_POINTS, ATTACK, MOVEMENT_SPEED) {}                // defaultni konstruktor
Villager::Villager(double hitPoints) : Villager::Villager(hitPoints, ATTACK, MOVEMENT_SPEED) {} // konstruktor za samo hp koji se delegira na konstruktor ispod
Villager::Villager(double hitPoints, double attack, double movementSpeed)                       // setter konstruktor za sve vrijednosti
{
    setHitPoints(hitPoints);
    setAttack(attack);
    setMovementSpeed(movementSpeed);
}
Villager::Villager(const Villager &villager) : Villager::Villager(villager.hitPoints, villager.attack, villager.movementSpeed) // copy konstruktor
{
    setHitPoints(hitPoints);
} // getteri
double Villager::getHitPoints()
{
    return hitPoints;
}
double Villager::getAttack()
{
    return attack;
}
double Villager::getMovementSpeed()
{
    return movementSpeed;
} // setteri koji osiguravaju unos legitimnih vrijednosti
void Villager::setHitPoints(double hitPoints)
{
    if (hitPoints > 0 && hitPoints <= HIT_POINTS)
        this->hitPoints = hitPoints;
    else
        std::cout << "Invalid variable value." << std::endl;
}
void Villager::setAttack(double attack)
{
        if (attack > 0 && attack <= ATTACK)
        this->attack = attack;
    else
        std::cout << "Invalid variable value." << std::endl;
}
void Villager::setMovementSpeed(double movementSpeed)
{
        if (movementSpeed > 0 && movementSpeed <= MOVEMENT_SPEED)
        this->movementSpeed = movementSpeed;
    else
        std::cout << "Invalid variable value." << std::endl;
} // prikaz metoda
void Villager::info()
{
    std::cout << "Villager (" << hitPoints << ", " << attack << ", " << movementSpeed << ")" << std::endl;
}