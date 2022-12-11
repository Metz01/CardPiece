#include <string>
#include "PlayableCard.h"

PlayableCard::PlayableCard(std::string name, std::string artPath, std::string effect, std::string code, int cost):
    ColoredCard(name, artPath, effect, code), _cost(cost) {}

PlayableCard::~PlayableCard()
{
}