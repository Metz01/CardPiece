#ifndef COLORED_H
#define COLORED_H
#include <string>
#include <QJsonObject>
#include "Card.h"
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
        std::string getCode() const;
        Enums::Colors getColor() const;
        virtual Enums::CardType getCardType() const = 0;
};  

#endif