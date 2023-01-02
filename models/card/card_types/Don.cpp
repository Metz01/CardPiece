#include <string>
#include "Don.h"

Don::Don(std::string name, std::string artPath, std::string effect) : Card(name, artPath, effect)
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
}

void Don::deattachCard()
{
    // TODO: remove buff to the attached card
    _attachedCard = NULL;
}

int Don::getAttackIncrement()
{
    return attackIncrement;
}

Attacker *Don::getAttachedCard()
{
    return _attachedCard;
}

Utils::CardInfo Don::info(Enums::InfoAttribute attribute, Utils::CardInfo onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo )) const{
    onGetAttribute(attribute, QJsonObject());
    throw "Don::info() not used";
}


Enums::CardType Don::getCardType() const
{
    return Enums::CardType::don;
}