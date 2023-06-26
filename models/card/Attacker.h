#ifndef ATTACKER_H
#define ATTACKER_H
#include <string>
#include <QJsonObject>
#include "ColoredCard.h"

class Attacker: virtual public ColoredCard
{
    private:
        int _attack;
    public:
        Attacker(std::string, std::string, std::string, std::string, Enums::Colors, int);
        Attacker(QJsonObject json, std::string cardCodes);
        Attacker(int attack);
        virtual ~Attacker();
        virtual Utils::CardInfo info(Enums::InfoAttribute attribute, Utils::CardInfo onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo)) const = 0;
        virtual Enums::CardType getCardType() const = 0;
        int getAttack() const;
        void buffAttack(int);
        Utils::CardInfo getCardInfo(Enums::InfoAttribute attribute) const override;
};



#endif