#include <string>
#include "Character.h"

Character::Character(std::string name, std::string artPath, std::string effect, std::string code, Colors color, int attack, int cost):
    Attacker(attack) , PlayableCard(cost) , ColoredCard(name, artPath, effect, code, color){}

Character::~Character()
{
}

std::string* Character::info() const{
    std::string *c = new std::string("Otama");
    return c;
}
