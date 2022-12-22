#ifndef DON_H
#define DON_H
#include <string>
#include "../Attacker.h"
#include <QJsonObject>

class Don : public Card{
    private:
        Attacker*_attachedCard;
        static int const attackIncrement = 1000;

    public:
        void attachCard(Attacker *);
        void deattachCard();
        int getAttackIncrement();
        Don(std::string, std::string, std::string);
        Don(QJsonObject Json);
        ~Don();
        std::string* info();
};

#endif