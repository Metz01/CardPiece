#include "fsm.h"
#include "../utils/Debug.h"
#include "../utils/Enums.h"
#include "./api/api_logic.h"

Enums::State FSM::_currentState = Enums::State::Draw;
Player *FSM::_currentPlayer = NULL;
int FSM::_turnsPlayed = 0;

FSM::FSM(Player *starterPlayer)
{
    _currentPlayer = starterPlayer;
}

Card *FSM::drawCardRequest()
{
    Debug::LogEnv("FSM::drawCardRequest");

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

    Debug::LogInfo("Drew Card");

    return card;
}

std::vector<Don *> FSM::drawDonRequest()
{
    Debug::LogEnv("FSM::drawDonRequest");

    // Assert State
    if (_currentState != Enums::State::DrawDon)
    {
        Debug::LogError("Tried to Draw a Don, but the state is: " + EnumsHelper::ToString(_currentState));
        return std::vector<Don *>();
    }

    // Draw Don
    std::vector<Don*> drewDon = ApiLogic::drawDon(_currentPlayer, _turnsPlayed == 0 ? 1 : 2);

    // Deattach and Activate all Don and Character
    ApiLogic::setUpPlayer(_currentPlayer);

    // Change State
    _currentState = Enums::State::SelectCard;

    return drewDon;
}

bool FSM::selectCardRequest(Card* selectedCard)
{
    Debug::LogEnv("FSM::selectCardRequest");

    // Assert State
    if (_currentState != Enums::State::SelectCard)
    {
        Debug::LogError("Tried to Select a Card, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }

    if (ApiLogic::whoseCard(selectedCard) != _currentPlayer)
    {
        Debug::LogError("Tried to Select a Card, but the card is not yours");
        return false;
    }

    if(selectedCard->getCardType() == Enums::CardType::don)
    {
        Debug::LogInfo("Selected Don");
        _currentState = Enums::State::AttachDon;
        return true;
    }

    bool* isPlayedFromHand = (bool*)malloc(sizeof(bool));
    *isPlayedFromHand = false;

    ApiLogic::playCard(_currentPlayer, selectedCard, isPlayedFromHand);
    _currentState = isPlayedFromHand ? Enums::State::SelectCard : Enums::State::SelectEnemyCard;

    Debug::LogDebug("This card was " + (std::string)(isPlayedFromHand ? " played by hand" : " an enemy that has been selected"));
    
    return true;
}

bool FSM::attachDonRequest(Card* selectedCard, Don* selectedDon)
{
    Debug::LogEnv("FSM::attachDonRequest");

    // Assert State
    if (_currentState != Enums::State::AttachDon)
    {
        Debug::LogError("Tried to Attach a Don, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }

    // Change State
    _currentState = Enums::State::SelectCard;

    return ApiLogic::attachDonToCard(selectedCard, selectedDon, _currentPlayer);
}

bool FSM::selectEnemyCardRequest(Card* selectedCard, Card* selectedEnemyCard)
{
    Debug::LogEnv("FSM::selectEnemyCardRequest");

    // Assert State
    if (_currentState != Enums::State::SelectEnemyCard)
    {
        Debug::LogError("Tried to Select an Enemy Card, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }

    if (ApiLogic::whoseCard(selectedCard) == _currentPlayer)
    {
        Debug::LogError("Tried to Select an Enemy Card, but the card is yours");
        return false;
    }

    if (selectedCard->getCardType() != Enums::CardType::character && selectedCard->getCardType() != Enums::CardType::leader)
    {
        Debug::LogError("Tried to Select an Enemy Card, but the card is not a character or a leader");
        return false;
    }

    ApiLogic::attackCard(selectedCard, selectedEnemyCard, _currentPlayer);
    
    selectedEnemyCard->getCardType();

    return false;
}