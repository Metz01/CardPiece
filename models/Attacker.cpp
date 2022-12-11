#include <string>
#include "Attacker.h"

Attacker::Attacker(std::string name, std::string artPath, std::string effect, std::string code, int attack):
    ColoredCard(name, artPath, effect, code), _attack(attack) {}

Attacker::~Attacker()
{
}
