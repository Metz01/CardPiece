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
        virtual bool info(Enums::InfoAttribute attribute, Utils::CardInfo*, bool onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo, Utils::CardInfo*)) const = 0;
        std::string getCode() const;
        virtual Enums::CardType getCardType() const = 0;
};  

#endif