#include "Event.h"

Event::Event(std::string name, std::string artPath, std::string code, Enums::Colors color, int buff, int cost):
     ColoredCard(name, artPath, code, color), 
     PlayableCard(cost),
    _buff(buff) {
}

Event::Event(QJsonObject Json, std::string cardCode)
    :  ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode),
    PlayableCard(Json, cardCode), _buff(JsonParser::jsonKeytoInt(Json, JSON_BUFF))
{
}

Event::~Event()
{
}

Enums::CardType Event::getCardType() const
{
    return Enums::CardType::event;
}

Utils::CardInfo* Event::getCardInfo(Enums::InfoAttribute attribute) const{
    return new Utils::CardInfo(attribute, this);
}

int Event::getBuff() const{
    return _buff;
}