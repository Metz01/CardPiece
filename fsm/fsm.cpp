#include "fsm.h"
#include "../utils/Debug.h"
#include "../utils/Enums.h"
#include "./api/api_logic.h"

Enums::State FSM::_currentState = Enums::State::Draw;
Player *FSM::_currentPlayer = NULL;

FSM::FSM(Player *starterPlayer)
{
    _currentPlayer = starterPlayer;
}

Card *FSM::drawCardRequest()
{

    // Assert State
    if (_currentState != Enums::State::Draw)
    {
        Debug::LogError("Tried to Draw a card, but the state is: " + EnumsHelper::ToString(_currentState));
        return NULL;
    }

    // Draw Card
    Card *card = ApiLogic::drawCard(_currentPlayer);

    // Change State
    _currentState = Enums::State::DrawDon;

    return card;
}

bool FSM::drawDonRequest()
{

    // Assert State
    if (_currentState != Enums::State::DrawDon)
    {
        Debug::LogError("Tried to Draw a Don, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }

    // Draw Don
    ApiLogic::drawDon(_currentPlayer);

    // Change State
    _currentState = Enums::State::SelectCard;

    return true;
}