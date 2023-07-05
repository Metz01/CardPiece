#ifndef STAGE_H
#define STAGE_H

#include "./utils/Enums.h"
#include "./utils/Utils.h"
#include "../PlayableCard.h"


class Stage: public PlayableCard
{
    private:
        int _buff;
    public:
        Stage(std::string, std::string, std::string, Enums::Colors, int, int);
        Stage(QJsonObject Json, std::string cardCode);
        Enums::CardType getCardType() const;
        Utils::CardInfo* getCardInfo(Enums::InfoAttribute attribute) const;
        int getBuff() const;
};

#endif // STAGE_H
