#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Deck.h"
#include "./card/Card.h"
#include "./card/card_types/Leader.h"
#include "./card/card_types/Don.h"

class Player
{
private:
    Deck deck;
//    LinkedList lifeCards;
    std::vector<Card *> hand;
    std::vector<Card *> graveyard;
    std::vector<Card *> ground;
    std::vector<Don *> donList;
    int activeDon;
    int don;
    Leader *leader = NULL;
    Card *stage = nullptr;
    std::string _name;
    int life;
public:
    Player(std::string path, std::string name);
    Player(std::string name, int life, std::string leaderCode, int donNumber, int activeDon, std::vector<std::string> handCode,
           std::vector<std::string> groundCode, std::vector<std::string> graveCode, std::string stage, std::vector<std::string> deckCodes);
    ~Player();
    std::string getLeaderCodeFromDeck() const;
    Card *drawCard();
    void printDeck() const;
    std::vector<Don *> drawDon(int numberOfDon);
    bool activeAllDon();
    void playCard(Card *selectedCard);
    void useCard(Card *,Card*);
    bool hasCard(Card *card);
    bool hasOnHand(Card *card);
    bool hasOnGround(Card *card);
    bool loseLife(int amount);
    bool killCard(Card *card);
    bool discardCard(Card *card);
    void print() const;
    Leader *getLeader() const;
    bool useDon();
    std::string getName() const;
    int getLife() const;
    Card *getStage() const;
    std::vector<Card*> getHand() const;
    std::vector<Card*> getGraveyard() const;
    std::vector<Don*> getDonList() const;
    std::vector<Card*> getGround() const;
    std::vector<std::string> getDeckCodes() const;
    int getActiveDon() const;
    bool resetBuffAllCards();
    bool setAllCardActive();
    void setStage(Card* stage);
    void useStage();
    Deck* getDeck();
};

#endif // PLAYER_H
