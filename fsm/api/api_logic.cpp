#include "api_logic.h"

Card* ApiLogic::drawCard(Player* player){
    return player->drawCard();
}