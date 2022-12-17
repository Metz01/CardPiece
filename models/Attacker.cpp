#include <string>
#include "Attacker.h"

Attacker::Attacker(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack):
    ColoredCard(name, artPath, effect, code, color), _attack(attack) {}

Attacker::Attacker(QJsonObject Json) : ColoredCard(Json), _attack(Json.value("attack").toInt()){}

Attacker::Attacker(int attack):
     ColoredCard(), _attack(attack) {}


Attacker::~Attacker()
{
}

/* std::string* Attacker::info(){} */
