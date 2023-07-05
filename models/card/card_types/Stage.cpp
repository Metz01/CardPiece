#include "Stage.h"

Stage::Stage(std::string name, std::string artPath, std::string code, Enums::Colors color, int buff, int cost):
    ColoredCard(name, artPath, code, color),
    PlayableCard(cost),
    _buff(buff) {
}

Stage::Stage(QJsonObject Json, std::string cardCode)
    :  ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode),
    PlayableCard(Json, cardCode), _buff(JsonParser::jsonKeytoInt(Json, JSON_BUFF))
{
}

Enums::CardType Stage::getCardType() const
{
    return Enums::CardType::stage;
}

Utils::CardInfo* Stage::getCardInfo(Enums::InfoAttribute attribute) const{
    return new Utils::CardInfo(attribute, this);
}

int Stage::getBuff() const{
    return _buff;
}
