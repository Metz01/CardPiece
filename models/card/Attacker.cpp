#include <string>
#include "Attacker.h"

Attacker::Attacker(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack):
    ColoredCard(name, artPath, effect, code, color), 
    _attack(attack) {}

Attacker::Attacker(QJsonObject Json, std::string cardCode) : 
    ColoredCard(Json, cardCode), 
    _attack(JsonParser::jsonKeytoInt(Json, JSON_ATTACK)){}

Attacker::Attacker(int attack):
     ColoredCard(), _attack(attack) {}


Attacker::~Attacker()
{
}

void Attacker::buffAttack(int buff)
{
    Debug::LogEnv("Attacker::buffAttack");
    _attack += buff;
    Debug::LogDebug("Current buffed attack amouts to: " + std::to_string(_attack));
}

int Attacker::getAttack() const
{
    return _attack;
}

/* std::string* Attacker::info(){} */
