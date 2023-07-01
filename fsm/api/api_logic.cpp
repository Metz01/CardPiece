#include "api_logic.h"
#include "../../utils/Debug.h"
#include "battle.h"

Player *ApiLogic::player1 = NULL;
Player *ApiLogic::player2 = NULL;

ApiLogic::ApiLogic(Player *p1, Player *p2)
{
    player1 = p1;
    player2 = p2;
}

bool ApiLogic::setUpPlayer(Player *player)
{
    Debug::LogEnv("ApiLogic::setUpPlayer");
    return player->activeAllDon();
}

Card *ApiLogic::drawCard(Player *player)
{
    Debug::LogEnv("ApiLogic::drawCard");
    return player->drawCard();
}

std::vector<Don *> ApiLogic::drawDon(Player *player, int amount)
{
    Debug::LogEnv("ApiLogic::drawDon");
    return player->drawDon(amount);
}

Player* ApiLogic::whoseCard(Card* card)
{
    Debug::LogEnv("ApiLogic::whoseCard");
    if (player1->hasCard(card))
        return player1;
    else if (player2->hasCard(card))
        return player2;
    else
        return NULL;

}

Don* ApiLogic::attachDon(Don* don, Attacker* card, Player* currentPlayer)
{
    Debug::LogEnv("ApiLogic::attachDon");
    don->attachCard(card);
    currentPlayer->useDon();
    return don;
}

Card* ApiLogic::playCard(Player* player, Card* card, bool* isFromHand)
{
    Debug::LogEnv("ApiLogic::playCard");
    if(player->hasOnHand(card)){
        Debug::LogInfo("ApiLogic::playCard Card On Hand");
        bool isCharacter = (card->getCardInfo(Enums::InfoAttribute::Type)->value.type) == Enums::CardType::character;
        Debug::LogInfo("ApiLogic::playCard isCharacter: " + std::to_string(isCharacter));
        if(isCharacter){
            player->playCard(card);
            // _currentState = Enums::State::SelectCard;
            *isFromHand = true;
            Debug::LogInfo("Played Character");
        }else{
            //TODO: use effect
        }
    } else {
        // _currentState = Enums::State::SelectEnemyCard;
        *isFromHand = false;
    }

    return card;
}

bool ApiLogic::attackCard(Card* attacker, Card* defender, Player* currentPlayer)
{
    Debug::LogEnv("ApiLogic::attackCard");
    if (defender->isActive() && defender->getCardType() != Enums::CardType::leader){
        Debug::LogError("Tried to attack a non rested card");
        return false;
    }
    if (whoseCard(attacker) == whoseCard(defender))
    {
        Debug::LogError("Tried to attack a card from the same player");
        return false;
    }
    if (!whoseCard(defender)->hasOnGround(defender)){
        Debug::LogError("Tried to attack a card not on the ground");
        return false;
    }

    Battle::attackCard(attacker, defender, currentPlayer, getOpponent(currentPlayer));

    //bool result = defender->get
    return true;
}

bool ApiLogic::attachDonToCard(Card* card, Don* don, Player* currentPlayer)
{
    Debug::LogEnv("ApiLogic::attachDonToCard");
    if (don->getAttachedCard() != NULL)
    {
        Debug::LogError("Tried to Attach a Don, but the don is already attached");
        return false;
    }

    if (whoseCard(card) != currentPlayer)
    {
        Debug::LogError("Tried to Attach a Don, but the card is not yours");
        return false;
    }

    Attacker* attackerSelected = dynamic_cast<Attacker*>(card);

    if (attackerSelected == NULL)
    {
        Debug::LogError("Tried to Attach a Don, but the selected card is not a character");
        return false;
    }

    attachDon(don, attackerSelected, currentPlayer);

    return true;
}

Player* ApiLogic::getOpponent(Player* currentPlayer)
{
    if (currentPlayer == player1)
        return player2;
    else
        return player1;
}

bool ApiLogic::saveGame(Player* player1, Player* player2, std::string path)
{
    Debug::LogEnv("ApiLogic::saveGame");
    Save::saveGame(player1, player2, path);
    return true;
}

Player* ApiLogic::loadPlayer(std::string path, int playerNumber)
{
    Debug::LogEnv("ApiLogic::loadPlayer");
    switch (playerNumber){
    case 1:
        return Save::loadPlayer1(path);
    case 2:
        return Save::loadPlayer2(path);
    default:
        Debug::LogError("ApiLogic::loadPlayer - Invalid Player Number");
        return NULL;
    }
}

bool ApiLogic::useCardEffect(Card* cardToUse, Card* cardToUseOn, Player *currentPlayer)
{
    Debug::LogEnv("ApiLogic::useCardEffect");

    int buff = cardToUse->getCardInfo(Enums::InfoAttribute::Buff)->value.buff;

    dynamic_cast<Attacker*>(cardToUseOn)->buffAttack(buff);

    currentPlayer->discardCard(cardToUse);

    return true;
}

bool ApiLogic::resetBonusToCard(Player* currentPlayer){
    Debug::LogEnv("ApiLogic::resetCard");
    currentPlayer->resetCard();
    return true;
}

std::vector<Card *> ApiLogic::getCardsOnHand(int playerNumber)
{
    Debug::LogEnv("ApiLogic::getCardsOnHand");
    switch (playerNumber) {
    case 1:
        return player1->getHand();
        break;
    default:
        return player2->getHand();
        break;
    }

}

std::vector<Card *> ApiLogic::getCardsOnGround(int playerNumber)
{
    Debug::LogEnv("ApiLogic::getCardsOnGround");
    switch (playerNumber) {
    case 1:
        return player1->getGround();
        break;
    default:
        return player2->getGround();
        break;
    }
}

Leader* ApiLogic::getLeader(int playerNumber)
{
    Debug::LogEnv("ApiLogic::getLeader");
    switch (playerNumber) {
    case 1:
        return player1->getLeader();
        break;
    default:
        return player2->getLeader();
        break;
    }
}

int ApiLogic::getAvailableDon(int playerNumber)
{
    Debug::LogEnv("ApiLogic::getAvailableDon");
    switch (playerNumber) {
    case 1:
        return player1->getActiveDon();
        break;
    default:
        return player2->getActiveDon();
        break;
    }
}
