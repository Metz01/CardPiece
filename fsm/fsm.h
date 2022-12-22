#ifndef FSM_H
#define FSM_H

#include <string>
#include "../utils/Enums.h"
#include "../models/card/Card.h"
#include "../models/Player.h"

class FSM {
    private:
        static Enums::State _currentState;
        static Player* _currentPlayer;
    public:
        FSM(Player* starterPlayer);
        static Card* drawCardRequest();
};

#endif