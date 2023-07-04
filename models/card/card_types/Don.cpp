#include <string>
#include "Don.h"

Don::Don(std::string name, std::string artPath) : Card(name, artPath)
{
}

Don::Don() : Card()
{
}

Don::Don(QJsonObject Json) : Card(Json)
{
}

Don::~Don()
{
    delete _attachedCard;
}

void Don::attachCard(Attacker *card)
{
    _attachedCard = card;
    _attachedCard->buffAttack(attackIncrement);
    this->restCard();
}

void Don::deattachCard()
{
    if(_attachedCard == NULL)
        return;
    //_attachedCard->buffAttack(-attackIncrement);
    _attachedCard = NULL;
}

void Don::active(){
    this->_active = true;
}

int Don::getAttackIncrement()
{
    return attackIncrement;
}

Attacker *Don::getAttachedCard()
{
    return _attachedCard;
}

Utils::CardInfo* Don::getCardInfo(Enums::InfoAttribute attribute) const{
    Debug::LogDebug("Don::getCardInfo" + std::to_string(attribute));
    return new Utils::CardInfo(attribute, this);
}

Enums::CardType Don::getCardType() const
{
    return Enums::CardType::don;
}

void Don::resetCard(){
    this->deattachCard();
}
