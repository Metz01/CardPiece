#ifndef COLORED_H
#define COLORED_H
#include <string>
#include "Card.h"
#include <QJsonObject>
#include "../../utils/Enums.h"

class ColoredCard: public Card 
{
    protected:
        std::string _code;
        Enums::Colors _color;
        
    public:
        ColoredCard(std::string, std::string, std::string, std::string, Enums::Colors);
        ColoredCard(QJsonObject Json, std::string cardCode);
        ColoredCard();
        virtual ~ColoredCard();
        virtual std::string* info() const = 0;

};

#endif