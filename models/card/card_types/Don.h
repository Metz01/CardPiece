#ifndef DON_H
#define DON_H
#include <string>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "../../../utils/Utils.h"
#include "../Attacker.h"

class Don : public Card
{
private:
    Attacker *_attachedCard = NULL;
    int const attackIncrement = 1000;

public:
    Don();
    Don(QJsonObject Json);
    Don(std::string, std::string);
    ~Don();
    void attachCard(Attacker *);
    void deattachCard();
    void active();
    int getAttackIncrement();
    Attacker *getAttachedCard();
    Utils::CardInfo* getCardInfo(Enums::InfoAttribute attribute) const;
    Enums::CardType getCardType() const;
    void resetCard();
};

#endif