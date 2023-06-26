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
    Debug::LogDebug("Current buffed attack amounts to: " + std::to_string(_attack));
}

int Attacker::getAttack() const
{
    return _attack;
}

/* std::string* Attacker::info(){} */

Utils::CardInfo Attacker::getCardInfo(Enums::InfoAttribute attribute) const{
    Debug::LogEnv("Attacker::getCardInfo");
    Utils::info i = info();
    switch (attribute)
    {
    case Enums::InfoAttribute::Name:
        return Utils::CardInfo(info(_name), Enums::InfoAttribute::Name);
    case Enums::InfoAttribute::TYPE:
        return Utils::CardInfo(Utils::info{type}, Enums::InfoAttribute::TYPE);
    case Enums::InfoAttribute::ATTACK:
        return Utils::CardInfo(Utils::info{attack}, Enums::InfoAttribute::ATTACK);
    case Enums::InfoAttribute::COST:
        return Utils::CardInfo(Utils::info{cost}, Enums::InfoAttribute::COST);
    case Enums::InfoAttribute::EFFECT:
        return Utils::CardInfo(Utils::info{effect}, Enums::InfoAttribute::EFFECT);
    case Enums::InfoAttribute::COLOR:
        return Utils::CardInfo(Utils::info{color}, Enums::InfoAttribute::COLOR);
    case Enums::InfoAttribute::ARTPATH:
        return Utils::CardInfo(Utils::info{artPath}, Enums::InfoAttribute::ARTPATH);
    case Enums::InfoAttribute::LIFE:
        return Utils::CardInfo(Utils::info{life}, Enums::InfoAttribute::LIFE);
    default:
        return Utils::CardInfo(Utils::info{""}, Enums::InfoAttribute::NONE);
    }
}
