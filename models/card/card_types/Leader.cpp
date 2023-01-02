#include <string>
#include <iostream>
#include "Leader.h"
#include "../../../utils/database_helper.h"


Leader::Leader(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack, int life):
     ColoredCard(name, artPath, effect, code, color), 
     Attacker(attack), 
     _life(life) {}

Leader::Leader(QJsonObject Json, std::string cardCode) : 
    ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode), 
    Attacker(Json, cardCode),  
    _life(JsonParser::jsonKeytoInt(Json, JSON_LIFE)){
}

Leader::~Leader()
{
}


Utils::CardInfo Leader::info(Enums::InfoAttribute attribute, Utils::CardInfo onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo)) const{
    QJsonObject rawData = DatabaseHelper::getCardInfo(this->_code);
    return onGetAttribute(attribute, rawData);
}

std::string* Leader::lead() const{
    std::string *c = new std::string("Leader");
    return c;
}

int Leader::getLife() const{
    return _life;
}

Enums::CardType Leader::getCardType() const{
    return Enums::CardType::leader;
}