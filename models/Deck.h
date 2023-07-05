#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "LinkedList.h"
#include "../utils/database_helper.h"

class Deck
{
private:
    LinkedList *cards;
public:
    Deck(std::string path);
    Deck(std::vector<std::string> deckCodes);
    ~Deck();
    std::string findLeader() const;
    std::string drawCard();
    std::vector<std::string> getDeckCodes() const;
    void printDeck() const;
};

#endif
