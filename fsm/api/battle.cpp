#include "battle.h"

bool Battle::attackCard(Card* attacker, Card* defender, Player* enemyPlayer){
    Debug::LogEnv("ApiLogic::attackCard");

    int attack = attacker->info(Enums::InfoAttribute::Attack, Utils::LoadCard).attack;
    int defense = defender->info(Enums::InfoAttribute::Attack, Utils::LoadCard).attack;

    int result = attack - defense;
    if(result > 0){
    
        if(defender->getCardType() == Enums::CardType::leader){
            enemyPlayer->loseLife(1);
        }else if(defender->getCardType() == Enums::CardType::character){
            enemyPlayer->killCard(defender);
        }
    }

    attacker->restCard();
    
    return true;   
}