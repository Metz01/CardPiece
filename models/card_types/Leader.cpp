#include <string>
#include "Leader.h"

Leader::Leader(std::string name, std::string artPath, std::string effect, std::string code, int attack, int life):
    Attacker(name, artPath, effect, code, attack), _life(life), ColoredCard(name, artPath, effect, code) {}

Leader::~Leader()
{
}
