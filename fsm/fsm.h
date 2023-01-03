#ifndef FSM_H
#define FSM_H

#include <string>
#include <vector>
#include "../utils/Enums.h"
#include "../models/card/Card.h"
#include "../models/Player.h"

class FSM
{
private:
    static Enums::State _currentState;
    static Player *_currentPlayer;
    static int _turnsPlayed;

public:
    FSM(Player *starterPlayer);
    static Card *drawCardRequest();
    static std::vector<Don *> drawDonRequest();
    static bool selectCardRequest(Card* selectedCard);
    static bool attachDonRequest(Card* selectedCard, Don* selectedDon);
    static bool selectEnemyCardRequest(Card* selectedCard, Card* selectedEnemyCard);
    static bool endTurnRequest();
};

#endif