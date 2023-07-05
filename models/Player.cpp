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
    Debug::LogEnv("Player::Player setrupped");
}

/// @brief constructor for the player class, it will create a deck and set the leader from the deck
/// @param name name of the player
/// @param life life of the player
/// @param leaderCode code of the leader
/// @param donNumber number of dons
/// @param handCode codes of the cards in the hand
/// @param groundCode codes of the cards in the ground
/// @param graveCode codes of the cards in the graveyard
/// @param deckCodes codes of the cards in the deck
Player::Player(std::string name, int life, std::string leaderCode, int donNumber, int activeDon, std::vector<std::string> handCode, std::vector<std::string> groundCode, std::vector<std::string> graveCode, std::string stage, std::vector<std::string> deckCodes) :
    deck(Deck(deckCodes)), hand(std::vector<Card *>()), graveyard(std::vector<Card *>()), ground(std::vector<Card *>()),don(donNumber), _name(name),  life(life)
{
    this->activeDon = donNumber;
    if(stage != "0") this->stage = DatabaseHelper::selectJSonCard(stage);
    else this->stage = NULL;
    size_t tokenPosition = leaderCode.find("-");
    this->leader = dynamic_cast<Leader *>(DatabaseHelper::selectJSonCard(leaderCode.substr(0, tokenPosition)));
    dynamic_cast<Attacker*>(leader)->buffAttack(std::stoi(leaderCode.substr(tokenPosition + std::string("-").length())));
    for (std::string code : handCode)
    {
        hand.push_back(DatabaseHelper::selectJSonCard(code));
    }
    for (std::string code : groundCode)
    {
        ground.push_back(DatabaseHelper::selectJSonCard(code.substr(0, tokenPosition)));
        dynamic_cast<Attacker*>(ground.back())->buffAttack(std::stoi(code.substr(tokenPosition + std::string("-").length())));
    }
    for (std::string code : graveCode)
    {
        graveyard.push_back(DatabaseHelper::selectJSonCard(code));
    }
    for(int i = 0; i < activeDon; i++){
        Don* don = new Don();
        don->active();
        donList.push_back(don);
    }
    for(int i = 0; i < donNumber - activeDon; i++){
        Don* don = new Don();
        don->restCard();
        donList.push_back(don);
    }
    this->activeDon = activeDon;
}


Player::~Player()
{
    delete leader;
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
    if(don + numberOfDon > 10) numberOfDon -= (don + numberOfDon) % 10;
    don += numberOfDon;
    Debug::LogDebug("number of don " + std::to_string(don));
    std::vector<Don *> addedDon;
    for (int i = 0; i < numberOfDon; i++)
    {
        Don *don = new Don();
        addedDon.push_back(don);
        donList.push_back(don);
    }
    activeDon = don;
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

void Player::useCard(Card *cardToUse, Card *cardToUseOn){
    Debug::LogEnv("Player::useCard");
    int cost = cardToUse->getCardInfo(Enums::InfoAttribute::Cost)->value.cost;
    Debug::LogDebug("Cost: " + std::to_string(cost) + " | ActiveDon: " + std::to_string(activeDon));
    if(activeDon < cost){
        Debug::LogError("Not enough don to use this card");
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

    int buff = cardToUse->getCardInfo(Enums::InfoAttribute::Buff)->value.buff;

    dynamic_cast<Attacker*>(cardToUseOn)->buffAttack(buff);

    discardCard(cardToUse);
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
    if(stage) dynamic_cast<Attacker*>(selectedCard)->buffAttack(stage->getCardInfo(Enums::Buff)->value.buff);
    Debug::LogDebug("played card | ActiveDon: " + std::to_string(activeDon));
}

bool Player::hasCard(Card *card)
{
    Debug::LogEnv("Player::hasCard");
    if (std::find(hand.begin(), hand.end(), card) != hand.end())                    return true;
    if (std::find(ground.begin(), ground.end(), card) != ground.end())              return true;
    if (std::find(graveyard.begin(), graveyard.end(), card) != graveyard.end())     return true;
    if (std::find(donList.begin(), donList.end(), card) != donList.end())           return true;
    if(card == leader) return true;
    if(card == stage) return true;
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
    if(life == 0) return false;
//    for(int i = 0; i < amount; i++){
//        Card* card = DatabaseHelper::selectJSonCard(lifeCards.popFirst());
//        hand.push_back(card);
//    }
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

bool Player::discardCard(Card *card)
{
    Debug::LogEnv("Player::discardCard");
    if (std::find(hand.begin(), hand.end(), card) != hand.end())
    {
        hand.erase(std::remove(hand.begin(), hand.end(), card), hand.end());
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
//    lifeCards.print();
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

std::string Player::getName() const{
    return this->_name;
}

int Player::getLife() const{
    return this->life;
}

Card *Player::getStage() const
{
    return this->stage;
}

void Player::setStage(Card* stage)
{
    int cost = stage->getCardInfo(Enums::InfoAttribute::Cost)->value.cost;
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
    Card* prev = this->stage;
    Debug::LogEnv("Player::setStage " + stage->getName());
    this->stage = stage;
    hand.erase(std::remove(hand.begin(), hand.end(), stage), hand.end());
    if(!prev) useStage();
}

std::vector<Card*> Player::getHand() const{
    return this->hand;
}

std::vector<Card*> Player::getGround() const{
    return this->ground;
}

std::vector<Card*> Player::getGraveyard() const{
    return this->graveyard;
}

std::vector<Don *> Player::getDonList() const
{
    return this->donList;
}

std::vector<std::string> Player::getDeckCodes() const{
    return this->deck.getDeckCodes();
}

int Player::getActiveDon() const
{
    return activeDon;
    //int activeDon = 0;
    //for(auto d: donList){
    //    if(d->isActive())
    //        activeDon ++;
    //}
    //return activeDon;
}

bool Player::resetBuffAllCards()
{
    for(Card* card: this->ground){
       card->resetBuff();
    }
    this->leader->resetBuff();
    return true;
}

bool Player::setAllCardActive()
{
    for(Card* card: this->ground){
       card->setActive();
    }
    this->leader->setActive();
    return true;
}

void Player::useStage(){
    Debug::LogEnv("Player::useBuffStage");
    int buff = this->stage->getCardInfo(Enums::InfoAttribute::Buff)->value.buff;
    for(Card* c: this->ground){
       dynamic_cast<Attacker*>(c)->buffAttack(buff);
    }
    leader->buffAttack(buff);
}
