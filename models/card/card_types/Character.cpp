#include <string>
#include "Character.h"
#include "../../../utils/database_helper.h"

Character::Character(std::string name, std::string artPath, std::string code, Enums::Colors color, int attack, int cost, int count):
     ColoredCard(name, artPath, code, color),
     Attacker(attack), 
     PlayableCard(cost),
    counter(count){}

Character::Character(QJsonObject Json, std::string cardCode) : 
    ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode), 
    Attacker(Json, cardCode), 
    PlayableCard(Json, cardCode),
    counter(JsonParser::jsonKeytoInt(Json, JSON_COUNTER)){}

Character::~Character()
{
}

Enums::CardType Character::getCardType() const{
    return Enums::CardType::character;
}

Utils::CardInfo* Character::getCardInfo(Enums::InfoAttribute attribute) const{
    return new Utils::CardInfo(attribute, this);
}

int Character::getCounter() const
{
    return this->counter;
}
