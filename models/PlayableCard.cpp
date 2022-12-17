#include <string>
#include "PlayableCard.h"

PlayableCard::PlayableCard(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int cost):
    ColoredCard(name, artPath, effect, code, color), _cost(cost) {}

PlayableCard::PlayableCard(QJsonObject Json) : ColoredCard(Json.value("colorData").toObject()), _cost(Json.value("cost").toInt()){
}

PlayableCard::PlayableCard(int cost): _cost(cost) {}

PlayableCard::~PlayableCard()
{
}

/* std::string* PlayableCard::info(){} */