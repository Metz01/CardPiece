#ifndef API_LOGIC_H
#define API_LOGIC_H

#include <string>
#include <vector>
#include "../../models/Player.h"
#include "../../utils/Enums.h"
#include "../../utils/Save.h"

class ApiLogic
{
private:
    static Player *player1;
    static Player *player2;

public:
    ApiLogic(Player *p1, Player *p2);
    ~ApiLogic();
    static bool setUpPlayer(Player *player);
    static Card *drawCard(Player *player);
    static std::vector<Don *> drawDon(Player *player, int amount);
    static Player* whoseCard(Card* card);
    static Don* attachDon(Don* don, Attacker* card, Player* currentPlayer);
    static Card* playCard(Player* player, Card* card, bool* isFromHand);
    static bool attackCard(Card* attacker, Card* defender, Player* currentPlayer);
    static bool battlePhase(Card* attacker, Card* defender, Player* currentPlayer);
    static bool attachDonToCard(Card* card, Don* don, Player* currentPlayer);
    static Player* getOpponent(Player* currentPlayer);
    static bool saveGame(std::string);
    static Player* loadPlayer(std::string path, int playerNumber);
    static bool useCardEffect(Card* cardToUse, Card* cardToUseOn, Player* currentPlayer);
    static bool resetBonusToCard(Player* currentPlayer);
    static std::vector<Card*> getCardsOnHand(Player*);
    static std::vector<Card*> getCardsOnGround(Player*);
    static Leader* getLeader(Player*);
    static int getAvailableDon(Player*);
    static bool setStageCard(Card *);
    static bool useStageCard(Player *);
    static bool checkCardVectorIntegrity(std::vector<Card*> list);
    static bool checkPlayerIntegrity(Player *);
    // static void selectCard();
    // static void useCard();
    // static void selectEnemyCard();
};

#endif
