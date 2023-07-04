#include "fsm.h"
#include "../utils/Debug.h"
#include "../utils/Enums.h"
#include "./api/api_logic.h"

Enums::State FSM::_currentState = Enums::State::Draw;
Player *FSM::_currentPlayer = NULL;
int FSM::_turnsPlayed = 0;
Card *FSM::_buffedCard = NULL;

FSM::FSM(Player *starterPlayer)
{
    _currentPlayer = starterPlayer;
}

Card *FSM::drawCardRequest(Player* playerRequesting)
{
    Debug::LogEnv("FSM::drawCardRequest");

    // Assert State

    if(playerRequesting != _currentPlayer){
        Debug::LogError("Tried to Draw a card, but it's not your turn");
        return NULL;
    }

    if (_currentState != Enums::State::Draw)
    {
        Debug::LogError("Tried to Draw a card, but the state is: " + EnumsHelper::ToString(_currentState));
        return NULL;
    }

    // Draw Card
    Card *card = ApiLogic::drawCard(_currentPlayer);

    // Change State
    if(_currentPlayer->getDonList().size() == 10) _currentState = Enums::State::SelectCard;
    else _currentState = Enums::State::DrawDon;

    Debug::LogInfo("Drew Card");

    return card;
}

std::vector<Don *> FSM::drawDonRequest(Player* playerRequesting)
{
    Debug::LogEnv("FSM::drawDonRequest");

    if(playerRequesting != _currentPlayer){
        Debug::LogError("Tried to Draw don, but it's not your turn");
        return std::vector<Don *>();
    }

    // Assert State
    if (_currentState != Enums::State::DrawDon)
    {
        Debug::LogError("Tried to Draw a Don, but the state is: " + EnumsHelper::ToString(_currentState));
        return std::vector<Don *>();
    }

    // Draw Don
    std::vector<Don*> drewDon = ApiLogic::drawDon(_currentPlayer, _turnsPlayed == 0 ? 1 : 2);

    // Change State
    _currentState = Enums::State::SelectCard;

    return drewDon;
}

bool FSM::selectCardRequest(Card* selectedCard)
{
    Debug::LogEnv("FSM::selectCardRequest");

    // Assert State
    if (_currentState == Enums::State::SelectCard)
    {
        _buffedCard = selectedCard;
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
        else if (selectedCard->getCardType() == Enums::CardType::character)
        {
            bool* isPlayedFromHand = (bool*)malloc(sizeof(bool));
            *isPlayedFromHand = false;

            ApiLogic::playCard(_currentPlayer, selectedCard, isPlayedFromHand);
            _currentState = *isPlayedFromHand ? Enums::State::SelectCard : Enums::State::SelectEnemyCard;

            Debug::LogDebug("This card was " + (std::string)(*isPlayedFromHand ? " played by hand" : " an enemy that has been selected"));
            
            return true;
        } else if (selectedCard->getCardType() == Enums::CardType::leader)
        {
            Debug::LogInfo("Selected Leader");
            _currentState = Enums::State::SelectEnemyCard;
            return true;
        } else if (selectedCard->getCardType() == Enums::CardType::event)
        {
            Debug::LogInfo("Selected Event card");
            _currentState = Enums::State::UseCard;
            return true;
        }
        else
        {
            Debug::LogError("Tried to Select a Card, but the card is not a Don or Character");
            return false;
        }
    }
    else if(_currentState == Enums::State::SelectEnemyCard)
    {
        FSM::selectEnemyCardRequest(_buffedCard, selectedCard);
    }
    else if (_currentState == Enums::State::AttachDon)
    {
        FSM::attachDonRequest(selectedCard, dynamic_cast<Don*>(_buffedCard));
    }
    else if (_currentState == Enums::State::UseCard)
    {
        FSM::useCardRequest(_buffedCard, selectedCard);
    }
    else
    {
        Debug::LogError("Tried to Select a Card, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }
    return false;
    
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

    if (ApiLogic::whoseCard(selectedEnemyCard) == _currentPlayer)
    {
        Debug::LogError("Tried to Select an Enemy Card, but the card is yours");
        _currentState = Enums::SelectCard;
        return false;
    }

    if (selectedEnemyCard->getCardType() != Enums::CardType::character && selectedEnemyCard->getCardType() != Enums::CardType::leader)
    {
        Debug::LogError("Tried to Select an Enemy Card, but the card is not a character or a leader");
        _currentState = Enums::SelectCard;
        return false;
    }

    ApiLogic::attackCard(selectedCard, selectedEnemyCard, _currentPlayer);

    _currentState = Enums::State::SelectCard;

    return false;
}

bool FSM::useCardRequest(Card* cardToUse, Card* cardToUseOn)
{
    Debug::LogEnv("FSM::useCardRequest");

    // Assert State
    if (_currentState != Enums::State::UseCard)
    {
        Debug::LogError("Tried to Use a Card, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }

    if (ApiLogic::whoseCard(cardToUseOn) != _currentPlayer)
    {
        Debug::LogError("Tried to Use a Card, but the card is not yours");
        return false;
    }

    if (cardToUseOn->getCardType() != Enums::CardType::character && cardToUseOn->getCardType() != Enums::CardType::leader)
    {
        Debug::LogError("Tried to Use a Card, but the card is not a character or a leader");
        return false;
    }

    ApiLogic::useCardEffect(cardToUse, cardToUseOn, _currentPlayer);

    _currentState = Enums::State::SelectCard;

    return false;
}

bool FSM::endTurnRequest()
{
    Debug::LogEnv("FSM::endTurnRequest");

    // Assert State
    if (_currentState != Enums::State::SelectCard)
    {
        Debug::LogError("Tried to End the Turn, but the state is: " + EnumsHelper::ToString(_currentState));
        return false;
    }

    // Change State
    _currentState = Enums::State::Draw;
    
    //Reset bonus to card
    ApiLogic::resetBonusToCard(_currentPlayer);

    // Change Player

    _currentPlayer = ApiLogic::getOpponent(_currentPlayer);

    Debug::LogInfo("player2");

    // Deattach and Activate all Dons and Cards
    ApiLogic::setUpPlayer(_currentPlayer);
    
    // Increment Turns
    _turnsPlayed++;

    return true;
}

Player *FSM::getCurrentPlayer()
{
    return _currentPlayer;
}

Enums::State FSM::getCurrentState()
{
    return (_currentState);
}
