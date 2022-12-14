#ifndef COLORED_H
#define COLORED_H
#include <string>
#include "Card.h"
#include "../utils/Enums.h"

class ColoredCard: public Card 
{
    protected:
        std::string _code;
        Colors _color;
        
    public:
        ColoredCard(std::string, std::string, std::string, std::string, Colors);
        ColoredCard();
        virtual ~ColoredCard();
        virtual std::string* info() const = 0;

};

#endif