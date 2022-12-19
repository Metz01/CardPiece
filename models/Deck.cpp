#include "Deck.h"


/// @brief constructor for the deck class, it will read the file and add the cards to the linked list
/// @param path path to the deck file
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

/// @brief find the leader in the deck and remove it from the deck
/// @return the code of the leader in the deck
std::string Deck::findLeader() const
{
    std::string currentCard = "";
    for (int i = 0; i < cards->getSize(); i++){
        currentCard = cards->getCardCode(i);
        if (DatabaseHelper::isLeader(currentCard)){
            cards->remove(currentCard);
            return currentCard;
        }
    }
    return "";
}

Deck::~Deck()
{
    cards->clear();
    delete cards;
}

/// @brief draw(not paint) a card from the deck
/// @return the code of the first card and remove it from the list of cards
std::string Deck::drawCard()
{
    return cards->popFirst();
}
/// @brief print the deck
void Deck::printDecK() const
{
    cards->print();
}