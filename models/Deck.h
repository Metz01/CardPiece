#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

class Deck
{
private:
    LinkedList *cards;
public:
    Deck(std::string path);
    ~Deck();
    std::string drawCard();
};

#endif