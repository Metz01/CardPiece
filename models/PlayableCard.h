#ifndef PLAYABLE_H
#define PLAYABLE_H
#include <string>
#include "ColoredCard.h"
#include <QJsonObject>

class PlayableCard: virtual public ColoredCard
{
    private:
        int _cost;
    public:
        PlayableCard(std::string, std::string, std::string, std::string, Enums::Colors, int);
        PlayableCard(QJsonObject Json);
        PlayableCard(int);
        virtual ~PlayableCard();
        virtual std::string* info() const = 0;
};

#endif