#include "api_logic.h"
#include "../../utils/Debug.h"

Player *ApiLogic::player1 = NULL;
Player *ApiLogic::player2 = NULL;

ApiLogic::ApiLogic(Player *p1, Player *p2)
{
    player1 = p1;
    player2 = p2;
}

Card *ApiLogic::drawCard(Player *player)
{
    return player->drawCard();
}

std::vector<Don *> ApiLogic::drawDon(Player *player, int amount)
{
    return player->drawDon(amount);
}

Player* ApiLogic::whoseCard(Card* card)
{
    if (player1->hasCard(card))
        return player1;
    else if (player2->hasCard(card))
        return player2;
    else
        return NULL;

}

Don* ApiLogic::attachDon(Don* don, Attacker* card)
{
    don->attachCard(card);
    return don;
}

Card* ApiLogic::playCard(Player* player, Card* card, bool* isFromHand)
{
    if(player->hasOnHand(card)){
        Utils::CardInfo* info;
        card->info(Enums::InfoAttribute::Type, info, Utils::LoadCard);
        bool isCharacter = info->type == Enums::CardType::character;
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

bool ApiLogic::attackCard(Card* attacker, Card* defender)
{
    if (defender->getStatus() && defender->getCardType() != Enums::CardType::leader){
        Debug::LogError("Tried to attack a non rested card");
        return false;
    }
    if (whoseCard(attacker) == whoseCard(defender))
    {
        Debug::LogError("Tried to attack a card from the same player");
        return false;
    }
    if (whoseCard(defender)->hasOnHand(defender)){
        Debug::LogError("Tried to attack a card from the hand");
        return false;
    }
    //bool result = defender->get
}

bool ApiLogic::attachDonToCard(Card* card, Don* don, Player* currentPlayer)
{
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

    if(!currentPlayer->hasOnHand(don))
    {
        Debug::LogError("Tried to Attach a Don, but the don is not on your hand");
        return false;
    }
    Attacker* attackerSelected = dynamic_cast<Attacker*>(card);
    
    if (attackerSelected == NULL)
    {
        Debug::LogError("Tried to Attach a Don, but the selected card is not a character");
        return false;
    }

    attachDon(don, attackerSelected);

    return true;
}