#ifndef API_LOGIC_H
#define API_LOGIC_H

#include <string>
#include "../../models/Player.h"

class ApiLogic
{
private:
    static Player *player1;
    static Player *player2;

public:
    ApiLogic();
    static Card *drawCard(Player *player);
    static void drawDon(Player *player);
    // static void selectCard();
    // static void useCard();
    // static void selectEnemyCard();
};

#endif