#ifndef PLAYABLE_H
#define PLAYABLE_H
#include <string>
#include <QJsonObject>
#include "ColoredCard.h"

class PlayableCard: virtual public ColoredCard{
    private:
        int _cost;
    public:
        PlayableCard(std::string, std::string, std::string, Enums::Colors, int);
        PlayableCard(QJsonObject Json, std::string cardCode);
        PlayableCard(int);
        virtual ~PlayableCard();
        virtual Enums::CardType getCardType() const = 0;
        int getCost() const;
};

#endif