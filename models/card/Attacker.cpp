#include <string>
#include "Attacker.h"

Attacker::Attacker(std::string name, std::string artPath, std::string code, Enums::Colors color, int attack):
    ColoredCard(name, artPath, code, color), 
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
    _buffBonus += buff;
    Debug::LogDebug("Current buffed attack amounts to: " + std::to_string(_attack));
}

int Attacker::getAttack() const
{
    return _attack + _buffBonus;
}

void Attacker::resetAttack()
{
    _buffBonus = 0;
}



/* std::string* Attacker::info(){} */
