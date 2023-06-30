#include <string>
#include "PlayableCard.h"

PlayableCard::PlayableCard(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int cost):
    ColoredCard(name, artPath, effect, code, color), 
    _cost(cost) {}

PlayableCard::PlayableCard(QJsonObject Json, std::string cardCode) : 
    ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode), 
    _cost(JsonParser::jsonKeytoInt(Json, JSON_COST)){
}

PlayableCard::PlayableCard(int cost): _cost(cost) {}

PlayableCard::~PlayableCard()
{
}

int PlayableCard::getCost() const{
    return _cost;
}

/* std::string* PlayableCard::info(){} */