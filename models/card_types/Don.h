#ifndef DON_H
#define DON_H
#include <string>
#include "../Card.h"

class Don : public Card{
    private:
        Card *_attachedCard;
        static int const attackIncrement = 1000;

    public:
        void attachCard(Card *);
        int getAttackIncrement();
        Don(std::string, std::string, std::string);
        ~Don();
        std::string* info();
};

#endif