#ifndef BATTLE_H
#define BATTLE_H

#include "../../models/Player.h"

namespace Battle
{
    bool attackCard(Card* attacker, Card* defender, Player* enemyPlayer);
}

#endif