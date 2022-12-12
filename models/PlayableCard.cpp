#include <string>
#include "PlayableCard.h"

PlayableCard::PlayableCard(std::string name, std::string artPath, std::string effect, std::string code, Colors color, int cost):
    ColoredCard(name, artPath, effect, code, color), _cost(cost) {}

PlayableCard::PlayableCard(int cost): _cost(cost) {}

PlayableCard::~PlayableCard()
{
}