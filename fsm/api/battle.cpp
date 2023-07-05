#include "battle.h"

bool Battle::attackCard(Card* attacker, Card* defender, Player* enemyPlayer){
    Debug::LogEnv("ApiLogic::attackCard");

    int attack = attacker->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;
    int defense = defender->getCardInfo(Enums::InfoAttribute::Attack)->value.attack;

    Debug::LogDebug("Attack: " + std::to_string(attack) + " - Defense: " + std::to_string(defense));

    int result = attack - defense;
    if(result >= 0){
    
        if(defender->getCardType() == Enums::CardType::leader){
            enemyPlayer->loseLife(1);
        }else if(defender->getCardType() == Enums::CardType::character){
            enemyPlayer->killCard(defender);
        }
    }

    attacker->restCard();
    
    return true;   
}

int Battle::buffCount(Card* card, Player* playerOwner){
    int count = 0;
    for(Don* d: playerOwner->getDonList()){
        if(d->getAttachedCard() == card){
            count += d->getAttackIncrement();
        }
    }
    return count;
}
