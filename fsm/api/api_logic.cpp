#include "api_logic.h"
#include "../../utils/Debug.h"
#include "battle.h"

Player *ApiLogic::player1 = NULL;
Player *ApiLogic::player2 = NULL;

ApiLogic::ApiLogic(Player *p1, Player *p2)
{
    if(player1) delete player1;
    if(player2) delete player2;
    player1 = p1;
    player2 = p2;
}

ApiLogic::~ApiLogic()
{
}

bool ApiLogic::setUpPlayer(Player *player)
{
    Debug::LogEnv("ApiLogic::setUpPlayer");
    player->setAllCardActive();
    useStageCard(player);
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
    if(!currentPlayer->hasOnGround(card)) return nullptr;
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
    if(!attacker->isActive()){
        Debug::LogError("Tried to attack with a rested card");
        return false;
    }

    Battle::attackCard(attacker, defender, getOpponent(currentPlayer));

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

bool ApiLogic::saveGame(std::string path)
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
        return Save::loadPlayer(path, "Player1");
    case 2:
        return Save::loadPlayer(path, "Player2");
    default:
        Debug::LogError("ApiLogic::loadPlayer - Invalid Player Number");
        return NULL;
    }
}

bool ApiLogic::useCardEffect(Card* cardToUse, Card* cardToUseOn, Player *currentPlayer)
{
    Debug::LogEnv("ApiLogic::useCardEffect");

    currentPlayer->useCard(cardToUse, cardToUseOn);

    return true;
}

bool ApiLogic::resetBonusToCard(Player* currentPlayer){
    Debug::LogEnv("ApiLogic::resetCard");
    currentPlayer->resetBuffAllCards();
    return true;
}

std::vector<Card *> ApiLogic::getCardsOnHand(Player* player)
{
    Debug::LogEnv("ApiLogic::getCardsOnHand");
    return player->getHand();

}

std::vector<Card *> ApiLogic::getCardsOnGround(Player* player)
{
    Debug::LogEnv("ApiLogic::getCardsOnGround");
    return player->getGround();
}

Leader* ApiLogic::getLeader(Player* player)
{
    Debug::LogEnv("ApiLogic::getLeader");
    return player->getLeader();
}

int ApiLogic::getAvailableDon(Player* player)
{
    Debug::LogEnv("ApiLogic::getAvailableDon");
    return player->getActiveDon();
}

bool ApiLogic::setStageCard(Card * stage)
{
    ApiLogic::whoseCard(stage)->setStage(stage);
    return true;
}

bool ApiLogic::useStageCard(Player* player)
{
    if(!player->getStage()) return false;
    player->useStage();
    return true;
}

bool ApiLogic::checkCardVectorIntegrity(std::vector<Card*> list){
    for(int i = 0; i < (int)list.size(); i++){
        if(!DatabaseHelper::isInDataBase(list[i]->getCardInfo(Enums::Code)->value.code)) return false;
        if(DatabaseHelper::isLeader(list[i]->getCardInfo(Enums::Code)->value.code)) return false;
    }
    return true;
}

bool ApiLogic::checkPlayerIntegrity(Player* player)
{
    Debug::LogEnv("ApiLogic::checkPlayerIntegrity");
    if(player == NULL) return false;
    if(!player->getDeck()->checkDeckIntegrity() ) return false;
    if(player->getLeader() == NULL) return false;
    if(player->getName() == "") return false;
    if(player->getLife() <= 0) return false;
    if(!ApiLogic::checkCardVectorIntegrity(player->getHand())) return false;
    if(!ApiLogic::checkCardVectorIntegrity(player->getGround())) return false;
    if(!ApiLogic::checkCardVectorIntegrity(player->getGraveyard())) return false;
    Debug::LogInfo("Player integer");
    return true;
}
