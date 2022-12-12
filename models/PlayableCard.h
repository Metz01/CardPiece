#ifndef PLAYABLE_H
#define PLAYABLE_H
#include <string>
#include "ColoredCard.h"

class PlayableCard: virtual public ColoredCard
{
    private:
        int _cost;
    public:
        PlayableCard(std::string, std::string, std::string, std::string, Colors, int);
        PlayableCard(int);
        ~PlayableCard();
};

#endif