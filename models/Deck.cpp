#include "Deck.h"

Deck::Deck(std::string path) : cards(new LinkedList()){
    std::ifstream file;
    file.open(path);
    std::string line;
    while (std::getline(file, line))
    {
        cards->add(line);
    }
    file.close();
}

std::string Deck::findLeader() const
{
    for (int i = 0; i < cards->getSize(); i++){
        if (DatabaseHelper::isLeader(cards->getCardCode(i)))
            return cards->getCardCode(i);
    }
    return "";
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

void Deck::printDecK() const
{
    cards->print();
}