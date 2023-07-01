#ifndef ATTACKER_H
#define ATTACKER_H
#include <string>
#include <QJsonObject>
#include "ColoredCard.h"

class Attacker: virtual public ColoredCard
{
    private:
        int _attack;
        int _buffBonus = 0;
    public:
        Attacker(std::string, std::string, std::string, Enums::Colors, int);
        Attacker(QJsonObject json, std::string cardCodes);
        Attacker(int attack);
        virtual ~Attacker();
        virtual Enums::CardType getCardType() const = 0;
        int getAttack() const;
        void buffAttack(int);
        void resetCard();
        
};



#endif