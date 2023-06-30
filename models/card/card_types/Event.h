#ifndef EVENT_H
#define EVENT_H

#include "../PlayableCard.h"
#include "../../../utils/Utils.h"

class Event: public PlayableCard
{
    private:
        int _buff;
    public:
        Event(std::string, std::string, std::string, Enums::Colors, int, int);
        Event(QJsonObject Json, std::string cardCode);
        ~Event();
        Enums::CardType getCardType() const;
        Utils::CardInfo* getCardInfo(Enums::InfoAttribute attribute) const;
        int getBuff() const;
};
#endif