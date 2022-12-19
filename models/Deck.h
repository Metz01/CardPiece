#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "../utils/database_helper.h"

class Deck
{
private:
    LinkedList *cards;
public:
    Deck(std::string path);
    ~Deck();
    std::string findLeader() const;
    std::string drawCard();
    void printDecK() const;
};

#endif