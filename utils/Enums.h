#ifndef ENUMS_H
#define ENUMS_H

#include <vector>
#include <string>

namespace Enums{
    
    enum Colors {red=1, green=2, blue=3, purple=4};

    enum CardType {leader=1, character=2, event=3, stage=4, don=5};

    enum State {
        Draw=1,
        DrawDon=2,
        SelectCard=3,
        UseCard=4,
        SelectEnemyCard=5,
        AttachDon=6,
    };

    enum InfoAttribute{
        Name=1,
        Type=2,
        Attack=3,
        Cost=4,
        Effect=5,
        Color=6,
        ArtPath=7,
        Life=8,
        Code=9,
        Buff=10
    };
}

class EnumsHelper{
    public:
        static Enums::Colors getColor(int value);
        static std::string ToString(Enums::State state);
        static Enums::CardType getCardType(int value);
        static std::string getAttributeName(Enums::InfoAttribute type);
};

#endif