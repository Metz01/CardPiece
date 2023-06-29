#include "Player.h"
#include "card/Card.h"
#include "../utils/Debug.h"
#include "../utils/Utils.h"

/// @brief constructor for the player class, it will create a deck and set the leader from the deck
/// @param path path to the deck file
/// @param name name of the player
Player::Player(std::string path, std::string name) : deck(Deck(path)), hand(std::vector<Card *>()), graveyard(std::vector<Card *>()), ground(std::vector<Card *>()), _name(name)
{
    this->don = 0;
    this->activeDon = 0;
    this->leader = dynamic_cast<Leader *>(DatabaseHelper::selectJSonCard(getLeaderCodeFromDeck()));
    this->life = leader->getLife();
    for(int i = 0; i < this->life; i++){
        lifeCards.add(this->deck.drawCard());
    }

}

/// @brief get the leader code from the deck and remove it from the deck
/// @return leader code
std::string Player::getLeaderCodeFromDeck() const
{
    Debug::LogEnv("Player::getLeaderCodeFromDeck");
    return deck.findLeader();
}

/// @brief draw a card from the deck and add it to the hand
Card *Player::drawCard()
{   
    Debug::LogEnv("Player::drawCard");
    Card *drewCard = DatabaseHelper::selectJSonCard(deck.drawCard());
    hand.push_back(drewCard);
    return drewCard;
}

/// @brief print the deck
void Player::printDeck() const
{
    deck.printDeck();
}

std::vector<Don *> Player::drawDon(int numberOfDon = 2)
{
    Debug::LogEnv("Player::drawDon");
    don += numberOfDon;
    Debug::LogDebug("number of don " + std::to_string(don));
    std::vector<Don *> addedDon;
    for (int i = 0; i < numberOfDon; i++)
    {
        Don *don = new Don();
        addedDon.push_back(don);
        donList.push_back(don);
    }
    return addedDon;
}

bool Player::activeAllDon(){
    Debug::LogEnv("Player::activeAllDon");
    this->activeDon = this->don;
    for(Don* d: this->donList){
        d->active();
        d->deattachCard();
    }
    return true;
}

void Player::playCard(Card *selectedCard)
{
    Debug::LogEnv("Player::playCard");
    int cost = selectedCard->getCardInfo(Enums::InfoAttribute::Cost)->value.cost;
    Debug::LogDebug("Cost: " + std::to_string(cost) + " | ActiveDon: " + std::to_string(activeDon));
    if(activeDon < cost){
        Debug::LogError("Not enough don to play this card");
        return;
    }
    activeDon -= cost;
    int deactivated = 0;
    int lastAnalyzedDonPos = 0;
    int donSize = donList.size();
    while (deactivated < cost)
    {
        for (; lastAnalyzedDonPos < donSize; lastAnalyzedDonPos++)
        {
            if (!donList[lastAnalyzedDonPos]->isActive()) continue;
            
            donList[lastAnalyzedDonPos]->restCard();
            deactivated++;
            break;
        }
    }

    //remove selected card from hand
    hand.erase(std::remove(hand.begin(), hand.end(), selectedCard), hand.end());
    ground.push_back(selectedCard);
    Debug::LogDebug("played card | ActiveDon: " + std::to_string(activeDon));
}

bool Player::hasCard(Card *card)
{
    Debug::LogEnv("Player::print");
    if (std::find(hand.begin(), hand.end(), card) != hand.end())                    return true;
    if (std::find(ground.begin(), ground.end(), card) != ground.end())              return true;
    if (std::find(graveyard.begin(), graveyard.end(), card) != graveyard.end())     return true;
    if (std::find(donList.begin(), donList.end(), card) != donList.end())           return true;
    if(card == leader) return true;
    return false;
}

bool Player::hasOnHand(Card *card)
{
    Debug::LogEnv("Player::hasOnHand");
    if (std::find(hand.begin(), hand.end(), card) != hand.end())
        return true;
    return false;
}

bool Player::hasOnGround(Card *card)
{
    Debug::LogEnv("Player::hasOnGround");
    if (card == this->leader || std::find(ground.begin(), ground.end(), card) != ground.end())
        return true;
    return false;
}

bool Player::loseLife(int amount)
{
    Debug::LogEnv("Player::loseLife");
    life -= amount;
    if(life < 0) return false;
    for(int i = 0; i < amount; i++){
        Card* card = DatabaseHelper::selectJSonCard(lifeCards.popFirst());
        hand.push_back(card);
    }
    return true;
}

bool Player::killCard(Card *card)
{
    Debug::LogEnv("Player::killCard");
    if (std::find(ground.begin(), ground.end(), card) != ground.end())
    {
        ground.erase(std::remove(ground.begin(), ground.end(), card), ground.end());
        graveyard.push_back(card);
        return true;
    }
    return false;
}

//print all info of player
void Player::print() const
{
    Debug::LogEnv("Player::print");
    Debug::LogDebug("Player: " + _name);
    Debug::LogDebug("Leader: " + leader->getName());
    Debug::LogDebug("Life: " + std::to_string(life));
    Debug::LogDebug("Don: " + std::to_string(don));
    Debug::LogDebug("ActiveDon: " + std::to_string(activeDon));
    Debug::LogDebug("* Hand: ");
    for (Card *card : hand)
    {
        Debug::LogDebug(card->getName());
    }
    Debug::LogDebug("* Ground: ");
    for (Card *card : ground)
    {
        Debug::LogDebug(card->getName());
    }
    Debug::LogDebug("* Graveyard: ");
    for (Card *card : graveyard)
    {
        Debug::LogDebug(card->getName());
    }
    Debug::LogDebug("* DonList: ");
    for (Don *don : donList)
    {
        Debug::LogDebug(don->getName());
    }
    lifeCards.print();
}

Leader *Player::getLeader() const
{
    return leader;
}

bool Player::useDon(){
    if(activeDon <= 0) return false;

    activeDon--;
    return true;
}

std::vector<Don*> Player::getDonList() const{
    return this->donList;
}