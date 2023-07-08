#include "Deck.h"


/// @brief constructor for the deck class, it will read the file and add the cards to the linked list
/// @param path path to the deck file
Deck::Deck(std::string path) : cards(new LinkedList()){
    std::ifstream file;
    std::vector<std::string> cardCodes;
    file.open(path);
    std::string line;
    while (std::getline(file, line))
    {
        cardCodes.push_back(line);
    }

    std::random_device rd;
    std::mt19937 rng(rd());

    std::shuffle(cardCodes.begin(), cardCodes.end(), rng);
    for(int i = 0; i < (int)cardCodes.size(); i++){
        cards->add(cardCodes[i]);
    }

    file.close();
}

/// @brief constructor for the deck class, it will add the cards to the linked list
/// @param deckCodes codes of the cards in the deck
Deck::Deck(std::vector<std::string> deckCodes) : cards(new LinkedList()){
    for(std::string code : deckCodes){
        cards->add(code);
    }
}

/// @brief find the leader in the deck and remove it from the deck
/// @return the code of the leader in the deck
std::string Deck::findLeader() const
{
    std::string currentCard = "";
    for (int i = 0; i < cards->getSize(); i++){
        currentCard = cards->getCardCode(i);
        Debug::LogEnv("Deck::findLeader currentCard: " + currentCard);
        if (DatabaseHelper::isLeader(currentCard)){
            Debug::LogEnv("Deck::findLeader Found leader");
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
void Deck::printDeck() const
{
    cards->print();
}

bool Deck::checkDeckIntegrity() const
{
    bool leader = false;
    Enums::Colors color = EnumsHelper::getCardColor(DatabaseHelper::cardColor(cards->getCardCode(0)));
    Debug::LogInfo(std::to_string(DatabaseHelper::cardColor(cards->getCardCode(0))));
    for(int i = 0; i < cards->getSize(); i++){
        if(!DatabaseHelper::isInDataBase(cards->getCardCode(i))) return false;
        Debug::LogInfo(std::to_string(DatabaseHelper::cardColor(cards->getCardCode(i))));
        if(color != DatabaseHelper::cardColor(cards->getCardCode(i))) return false;
        if(DatabaseHelper::isLeader(cards->getCardCode(i))){
            if(leader) return false;
            if(!leader) leader = true;
        }
    }
    return true;
}

/// @brief get the deck codes
/// @return vector of deck codes
std::vector<std::string> Deck::getDeckCodes() const
{
    std::vector<std::string> deckCodes;
    for (int i = 0; i < cards->getSize(); i++){
        deckCodes.push_back(cards->getCardCode(i));
    }
    return deckCodes;
}
