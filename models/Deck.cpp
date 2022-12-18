#include "Deck.h"

Deck::Deck(std::string path){
    std::ifstream file;
    file.open(path);
    std::string line;
    while (std::getline(file, line))
    {
        cards->add(line);
    }
    file.close();
}

Deck::~Deck()
{
    cards->clear();
    delete cards;
}

std::string Deck::drawCard()
{
    return cards->popFirst();
}