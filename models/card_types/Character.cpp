#include <string>
#include "Character.h"

Character::Character(std::string name, std::string artPath, std::string effect, std::string code, Colors color, int attack, int cost):
    Attacker(attack) , PlayableCard(cost) , ColoredCard(name, artPath, effect, code, color){}

Character::~Character()
{
}
