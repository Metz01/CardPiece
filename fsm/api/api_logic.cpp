#include "api_logic.h"

Card *ApiLogic::drawCard(Player *player)
{
    return player->drawCard();
}

void ApiLogic::drawDon(Player *player)
{
    return player->drawDon(1);
}