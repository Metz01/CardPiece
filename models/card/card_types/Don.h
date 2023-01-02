#ifndef DON_H
#define DON_H
#include <string>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "../Attacker.h"

class Don : public Card
{
private:
    Attacker *_attachedCard;
    int const attackIncrement = 1000;

public:
    Don();
    Don(QJsonObject Json);
    Don(std::string, std::string, std::string);
    ~Don();
    void attachCard(Attacker *);
    void deattachCard();
    int getAttackIncrement();
    Attacker *getAttachedCard();
    Utils::CardInfo info(Enums::InfoAttribute attribute, Utils::CardInfo onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo)) const;
    Enums::CardType getCardType() const;
};

#endif