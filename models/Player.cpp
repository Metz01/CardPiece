#include "Player.h"
#include "card/Card.h"

/// @brief constructor for the player class, it will create a deck and set the leader from the deck
/// @param path path to the deck file
/// @param name name of the player
Player::Player(std::string path, std::string name) : 
    deck(Deck(path)), hand(std::vector<Card*>()), _name(name){
    this->leader = dynamic_cast<Leader*>(DatabaseHelper::selectJSonCard(getLeaderCodeFromDeck()));
    this->life = leader->getLife();
    std::cout << "Life set " << this->life << std::endl;
}

/// @brief get the leader code from the deck and remove it from the deck
/// @return leader code
std::string Player::getLeaderCodeFromDeck() const
{
    return deck.findLeader();
}

/// @brief draw a card from the deck and add it to the hand
void Player::drawCard()
{
    hand.push_back(DatabaseHelper::selectJSonCard(deck.drawCard()));
}

/// @brief print the deck
void Player::printDeck() const
{
    deck.printDecK();
}