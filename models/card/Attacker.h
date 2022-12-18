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
        Attacker(QJsonObject Json, std::string cardCodes);
        Attacker(int attack);
        virtual ~Attacker();
        virtual std::string* info() const = 0;
};



#endif