#include "Player.h"
#include "card/Card.h"

Player::Player(std::string path, std::string name) : 
    deck(Deck(path)), hand(std::vector<Card*>()), _name(name){
    this->leader = dynamic_cast<Leader*>(DatabaseHelper::selectJSonCard(getLeaderCodeFromDeck()));
    this->life = leader->getLife();
    std::cout << "Life set " << this->life << std::endl;
}

std::string Player::getLeaderCodeFromDeck() const
{
    return deck.findLeader();
}

void Player::drawCard()
{
    hand.push_back(DatabaseHelper::selectJSonCard(deck.drawCard()));
}

void Player::printDeck() const
{
    deck.printDecK();
}