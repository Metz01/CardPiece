#ifndef COLORED_H
#define COLORED_H
#include <string>
#include "Card.h"

class ColoredCard: public Card 
{
    protected:
        std::string _code;
        std::string _color;
        
    public:
        ColoredCard(std::string, std::string, std::string, std::string);

};

#endif