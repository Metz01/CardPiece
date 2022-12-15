#include <string>
#include "Leader.h"

Leader::Leader(std::string name, std::string artPath, std::string effect, std::string code, Colors color, int attack, int life):
    Attacker(attack), _life(life) , ColoredCard(name, artPath, effect, code, color) {}

Leader::~Leader()
{
}

std::string* Leader::info() const{
    std::string *c = new std::string("Leader");
    return c;
}

std::string* Leader::lead() const{
    std::string *c = new std::string("Leader");
    return c;
}