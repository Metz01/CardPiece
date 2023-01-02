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

bool Character::info(Enums::InfoAttribute attribute, Utils::CardInfo* info, bool onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo, Utils::CardInfo* info)) const{
    QJsonObject rawData = DatabaseHelper::getCardInfo(this->_code);
    return onGetAttribute(attribute, rawData, info);
}

Enums::CardType Character::getCardType() const{
    return Enums::CardType::character;
}