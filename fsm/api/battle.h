#ifndef BATTLE_H
#define BATTLE_H

#include "../../models/Player.h"
#include "./api_logic.h"

namespace Battle
{
    bool attackCard(Card* attacker, Card* defender, Player* currentPlayer, Player* enemyPlayer);
    int buffCount(Card* card, Player* playerOwner);
}

#endif