#include <string>
#include <iostream>
#include "Leader.h"
#include "../../../utils/database_helper.h"


Leader::Leader(std::string name, std::string artPath, std::string code, Enums::Colors color, int attack, int life):
     ColoredCard(name, artPath, code, color), 
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

Utils::CardInfo* Leader::getCardInfo(Enums::InfoAttribute attribute) const{
    return new Utils::CardInfo(attribute, this);
}