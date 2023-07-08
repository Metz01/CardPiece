#include "fsm.h"
#include "../utils/Debug.h"
#include "../utils/Enums.h"
#include "./api/api_logic.h"

Enums::State FSM::_currentState = Enums::State::Draw;
Player *FSM::_currentPlayer = NULL;
int FSM::_turnsPlayed = 0;
std::vector<Card *>FSM::_bufferCard(2);
int FSM::_buffCounter = 0;

FSM::FSM(Player *starterPlayer, int turn, Enums::State state)
{
    _currentPlayer = starterPlayer;
    FSM::_currentState = state;
    _turnsPlayed = turn;
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
    if(!card) FSM::endGameRequest();

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
        _bufferCard[0] = selectedCard;
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
        if(selectedCard->getCardType() == Enums::CardType::stage)
        {
            Debug::LogInfo("Selected Stage");
            _currentState = Enums::State::UseCard;
            FSM::useCardRequest(selectedCard);
            return true;
        }
        else if (selectedCard->getCardType() == Enums::CardType::character)
        {
            bool* isPlayedFromHand = (bool*)malloc(sizeof(bool));
            *isPlayedFromHand = false;

            ApiLogic::playCard(_currentPlayer, selectedCard, isPlayedFromHand);
            _currentState = *isPlayedFromHand ? Enums::State::SelectCard : Enums::State::SelectEnemyCard;

            if(_currentState == Enums::State::SelectEnemyCard && !selectedCard->isActive()){
                Debug::LogError("Tried to attack with a rested card");
                _currentState = Enums::State::SelectCard;
                return false;
            }

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
        if((!selectedCard->isActive()|| selectedCard->getCardType() == Enums::leader)
            && ApiLogic::whoseCard(selectedCard) == ApiLogic::getOpponent(_currentPlayer)){
            _bufferCard[1] = selectedCard;
            FSM::selectEnemyCardRequest(_bufferCard[0], selectedCard);
        }else{
            _currentState = Enums::SelectCard;
        }
    }
    else if (_currentState == Enums::State::AttachDon)
    {
        FSM::attachDonRequest(selectedCard, dynamic_cast<Don*>(_bufferCard[0]));
    }
    else if (_currentState == Enums::State::UseCard)
    {
        FSM::useCardRequest(_bufferCard[0], selectedCard);
    }
    else if (_currentState == Enums::CounterPhase){

        if(selectedCard->getCardType() == Enums::character)
            FSM::useCounterRequest(_bufferCard[1], selectedCard);
        else Debug::LogWarning("Tried to Select a Card, but it's not a counter");
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


    FSM::_currentState = Enums::CounterPhase;

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

    if(cardToUse->getCardType() == Enums::CardType::stage){
        ApiLogic::setStageCard(cardToUse);
        FSM::_currentState = Enums::State::SelectCard;
        return true;
    }

    if(!cardToUseOn){
        Debug::LogError("card was not a stage and no card to use on selected");
        return false;
    }

    if (ApiLogic::whoseCard(cardToUseOn) != _currentPlayer)
    {
        Debug::LogError("Tried to Use a Card, but the card is not yours");
        _currentState = Enums::State::SelectCard;
        return false;
    }

    if (cardToUseOn->getCardType() != Enums::CardType::character && cardToUseOn->getCardType() != Enums::CardType::leader)
    {
        Debug::LogError("Tried to Use a Card, but the card is not a character or a leader");
        return false;
    }

    if(!_currentPlayer->hasOnGround(cardToUseOn) && _currentPlayer->getLeader() != cardToUseOn){
        Debug::LogError("Tried to Use a Card, but the card is not on ground");
        _currentState = Enums::State::SelectCard;
        return false;
    }

    ApiLogic::useCardEffect(cardToUse, cardToUseOn, _currentPlayer);

    _currentState = Enums::State::SelectCard;

    return false;
}

bool FSM::useCounterRequest(Card * defender, Card * counter)
{
    if(counter && ApiLogic::getOpponent(_currentPlayer)->hasOnHand(counter)){
        if(ApiLogic::whoseCard(counter) == _currentPlayer) return false;
        int buff = counter->getCardInfo(Enums::Counter)->value.counter;
        if(buff == 0) return false;
        Attacker* def = dynamic_cast<Attacker*>(defender);
        def->buffAttack(buff);
        _buffCounter += buff;
        ApiLogic::getOpponent(_currentPlayer)->discardCard(counter);
    }
    return true;

}

bool FSM::battleRequest(Card* attacker, Card* defender){
    if(_currentState == Enums::CounterPhase)
    ApiLogic::attackCard(attacker, defender, _currentPlayer);
    if(_buffCounter != 0) dynamic_cast<Attacker*>(defender)->buffAttack(-_buffCounter);
    _buffCounter = 0;
    if(ApiLogic::getOpponent(_currentPlayer)->getLife() == 0)
    {
    FSM::endGameRequest();
    } else{
    _currentState = Enums::State::SelectCard;
    }
    return true;
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

int FSM::getCurrentTurn()
{
    return _turnsPlayed;
}

Enums::State FSM::getCurrentState()
{
    return (_currentState);
}

bool FSM::endGameRequest()
{
    Debug::LogEnv("FSM::endGameRequest");

    _currentState = Enums::State::EndGame;
    return true;
}
