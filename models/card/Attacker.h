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
        virtual bool info(Enums::InfoAttribute attribute, Utils::CardInfo*, bool onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInf, Utils::CardInfo*o)) const = 0;
        virtual Enums::CardType getCardType() const = 0;
        int getAttack() const;
        void buffAttack(int);
};



#endif