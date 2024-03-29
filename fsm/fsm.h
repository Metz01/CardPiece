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
    static std::vector<Card *>_bufferCard;
    static int _buffCounter;

public:
    FSM(Player *starterPlayer,int turn = 0, Enums::State state = Enums::State::Draw);
    static Card *drawCardRequest(Player* playerRequesting);
    static std::vector<Don *> drawDonRequest(Player* playerRequesting);
    static bool selectCardRequest(Card* selectedCard);
    static bool attachDonRequest(Card* selectedCard, Don* selectedDon);
    static bool selectEnemyCardRequest(Card* selectedEnemyCard);
    static bool useCardRequest(Card* cardToUse, Card* cardToUseOn = NULL);
    static bool useCounterRequest(Card* defender, Card* counter = NULL);
    static bool battleRequest(Card* attacker = _bufferCard[0], Card* defende = _bufferCard[1]);
    static bool endTurnRequest();
    static Player* getCurrentPlayer();
    static int getCurrentTurn();
    static Enums::State getCurrentState();
    static bool endGameRequest();
};

#endif
