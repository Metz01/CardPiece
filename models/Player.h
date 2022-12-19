#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Deck.h"
#include "./card/Card.h"
#include "./card/card_types/Leader.h"

class Player
{
public:
    Player(std::string path, std::string name);
    std::string getLeaderCodeFromDeck() const;
    void drawCard();
    void printDeck() const;
private:
    Deck deck;
    std::vector<Card*> hand;
    Leader* leader;
    std::string _name;
    int life;
};

#endif // PLAYER_H