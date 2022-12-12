#include <string>
#include "Character.h"

Character::Character(std::string name, std::string artPath, std::string effect, std::string code, int attack, int cost):
    Attacker(name, artPath, effect, code, attack) , PlayableCard(name, artPath, effect, code, cost) , ColoredCard(name, artPath, effect, code){}

Character::~Character()
{
}
