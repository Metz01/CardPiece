#include <string>
#include "Character.h"
#include "../../../utils/database_helper.h"

Character::Character(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack, int cost):
     ColoredCard(name, artPath, effect, code, color),
     Attacker(attack), 
     PlayableCard(cost){}

Character::Character(QJsonObject Json, std::string cardCode) : 
    ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode), 
    Attacker(Json, cardCode), 
    PlayableCard(Json, cardCode) {}

Character::~Character()
{
}

Enums::CardType Character::getCardType() const{
    return Enums::CardType::character;
}

Utils::CardInfo* Character::getCardInfo(Enums::InfoAttribute attribute) const{
    Debug::LogDebug("Character::getCardInfo" + std::to_string(attribute));
    return new Utils::CardInfo(attribute, this);
}