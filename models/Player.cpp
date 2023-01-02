#include "Player.h"
#include "card/Card.h"
#include "../utils/Debug.h"

/// @brief constructor for the player class, it will create a deck and set the leader from the deck
/// @param path path to the deck file
/// @param name name of the player
Player::Player(std::string path, std::string name) : deck(Deck(path)), hand(std::vector<Card *>()), graveyard(std::vector<Card *>()), ground(std::vector<Card *>()), _name(name)
{
    this->leader = dynamic_cast<Leader *>(DatabaseHelper::selectJSonCard(getLeaderCodeFromDeck()));
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
Card *Player::drawCard()
{   
    Debug::LogDebug("Player::drawedCard called");
    Card *drawedCard = DatabaseHelper::selectJSonCard(deck.drawCard());
    hand.push_back(drawedCard);
    Debug::LogDebug("Player::drawedCard ended");
    return drawedCard;
}

/// @brief print the deck
void Player::printDeck() const
{
    deck.printDeck();
}

std::vector<Don *> Player::drawDon(int numberOfDon = 2)
{
    don += numberOfDon;
    std::vector<Don *> addedDon;
    for (int i = 0; i < numberOfDon; i++)
    {
        Don *don = new Don();
        addedDon.push_back(don);
        donList.push_back(don);
    }
    return addedDon;
}

void Player::playCard(Card *selectedCard)
{
    Utils::CardInfo info = selectedCard->info(Enums::Cost, Utils::LoadCard);
    /* if(info == nullptr){
        Debug::LogError("Failed to get Info");
        return;
    } */
    int cost = info.cost;
    if(activeDon >= cost){
        activeDon -= cost;
        int deactivated = 0;
        int lastAnalyzedDonPos = 0;
        int donSize = donList.size();
        while (deactivated < cost)
        {
            for (; lastAnalyzedDonPos < donSize; lastAnalyzedDonPos++)
            {
                if (donList[lastAnalyzedDonPos]->getStatus())
                {
                    donList[lastAnalyzedDonPos]->restCard();
                    deactivated++;
                    break;
                }
            }
        }
        
        std::remove(hand.begin(), hand.end(), selectedCard);
        ground.push_back(selectedCard);
    }else{
        Debug::LogError("Not enough don to play this card");
    }
    
}

bool Player::hasCard(Card *card)
{
    if (std::find(hand.begin(), hand.end(), card) != hand.end())
        return true;
    if (std::find(ground.begin(), ground.end(), card) != ground.end())
        return true;
    if (std::find(graveyard.begin(), graveyard.end(), card) != graveyard.end())
        return true;
    if (std::find(donList.begin(), donList.end(), card) != donList.end())
        return true;
    if(card == leader) return true;
    return false;

}

bool Player::hasOnHand(Card *card)
{
    if (std::find(hand.begin(), hand.end(), card) != hand.end())
        return true;
    return false;
}

