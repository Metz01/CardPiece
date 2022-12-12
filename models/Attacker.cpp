#include <string>
#include "Attacker.h"

Attacker::Attacker(std::string name, std::string artPath, std::string effect, std::string code, Colors color, int attack):
    ColoredCard(name, artPath, effect, code, color), _attack(attack) {}

Attacker::Attacker(int attack):
    _attack(attack), ColoredCard() {}


Attacker::~Attacker()
{
}
