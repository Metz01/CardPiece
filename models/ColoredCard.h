#ifndef COLORED_H
#define COLORED_H
#include <string>
#include "Card.h"

const enum colors { red, green, blue, purple};
//const enum types { slasher, special, strike};

class ColoredCard: public Card{
    protected:
        std::string _code;
        colors _color;
        
    public:
        ColoredCard(std::string, std::string, std::string, std::string);

};

#endif