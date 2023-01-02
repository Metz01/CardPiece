#ifndef API_LOGIC_H
#define API_LOGIC_H

#include <string>
#include <vector>
#include "../../models/Player.h"
#include "../../utils/Enums.h"

class ApiLogic
{
private:
    static Player *player1;
    static Player *player2;

public:
    ApiLogic(Player *p1, Player *p2);
    static Card *drawCard(Player *player);
    static std::vector<Don *> drawDon(Player *player, int amount);
    static Player* whoseCard(Card* card);
    static Don* attachDon(Don* don, Attacker* card);
    static Card* playCard(Player* player, Card* card, bool* isFromHand);
    static bool attackCard(Card* attacker, Card* defender);
    static bool attachDonToCard(Card* card, Don* don, Player* player);
    // static void selectCard();
    // static void useCard();
    // static void selectEnemyCard();
};

#endif