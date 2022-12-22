#include "Player.h"
#include "card/Card.h"

/// @brief constructor for the player class, it will create a deck and set the leader from the deck
/// @param path path to the deck file
/// @param name name of the player
Player::Player(std::string path, std::string name) : 
    deck(Deck(path)), hand(std::vector<Card*>()), graveyard(std::vector<Card*>()), ground(std::vector<Card*>()) ,_name(name){
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
Card* Player::drawCard()
{
    Card* drawedCard = DatabaseHelper::selectJSonCard(deck.drawCard());
    hand.push_back(drawedCard);
    return drawedCard;
}

/// @brief print the deck
void Player::printDeck() const
{
    deck.printDeck();
}

void Player::drawDon(int numberOfDon = 2){
    don += numberOfDon;
}

void Player::playCard(Card* selctedCard){
    std::remove(hand.begin(), hand.end(), selctedCard);
    ground.push_back(selctedCard);
}