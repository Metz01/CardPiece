#include <string>
#include "ColoredCard.h"

ColoredCard::ColoredCard(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color): 
    Card(name, artPath, effect), _code(code), _color(color) {}

ColoredCard::ColoredCard(QJsonObject Json) : 
    Card(Json.value("cardData").toObject()), _code(Json.value("code").toString().toStdString()), _color(Enums::getColor(Json.value("color").toString().toInt())) {}
    
ColoredCard::ColoredCard() {}
ColoredCard::~ColoredCard() {}

/* std::string* ColoredCard::info(){} */