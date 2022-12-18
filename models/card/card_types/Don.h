#ifndef DON_H
#define DON_H
#include <string>
#include "../Card.h"
#include <QJsonObject>

class Don : public Card{
    private:
        Card *_attachedCard;
        static int const attackIncrement = 1000;

    public:
        void attachCard(Card *);
        int getAttackIncrement();
        Don(std::string, std::string, std::string);
        Don(QJsonObject Json);
        ~Don();
        std::string* info();
};

#endif