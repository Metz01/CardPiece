#ifndef COLORED_H
#define COLORED_H
#include <string>
#include "Card.h"
#include "../utils/Enums.h"
#include <QJsonObject>

class ColoredCard: public Card 
{
    protected:
        std::string _code;
        Enums::Colors _color;
        
    public:
        ColoredCard(std::string, std::string, std::string, std::string, Enums::Colors);
        ColoredCard(QJsonObject Json);
        ColoredCard();
        virtual ~ColoredCard();
        virtual std::string* info() const = 0;

};

#endif