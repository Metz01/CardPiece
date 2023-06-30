#include <string>
#include "ColoredCard.h"

ColoredCard::ColoredCard(std::string name, std::string artPath, std::string code, Enums::Colors color): 
    Card(name, artPath), 
    _code(code), 
    _color(color) {}

ColoredCard::ColoredCard(QJsonObject Json, std::string cardCode) : 
    Card(JsonParser::jsonKeytoJsonObject(Json, JSON_CARD_DATA)), 
    _code(cardCode), 
    _color(EnumsHelper::getColor(JsonParser::jsonKeytoInt(Json, JSON_COLOR)))
{}
    
ColoredCard::ColoredCard() {}
ColoredCard::~ColoredCard() {}

std::string ColoredCard::getCode() const
{
    return _code;
}

Enums::Colors ColoredCard::getColor() const
{
    return _color;
}

/* std::string* ColoredCard::info(){} */