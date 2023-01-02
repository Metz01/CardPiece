#ifndef PLAYABLE_H
#define PLAYABLE_H
#include <string>
#include <QJsonObject>
#include "ColoredCard.h"

class PlayableCard: virtual public ColoredCard{
    private:
        int _cost;
    public:
        PlayableCard(std::string, std::string, std::string, std::string, Enums::Colors, int);
        PlayableCard(QJsonObject Json, std::string cardCode);
        PlayableCard(int);
        virtual ~PlayableCard();
        virtual bool info(Enums::InfoAttribute attribute, Utils::CardInfo*, bool onGetAttribute(Enums::InfoAttribute, QJsonObject,Utils::CardInfo*)) const = 0;
        virtual Enums::CardType getCardType() const = 0;
};

#endif