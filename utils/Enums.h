#ifndef ENUMS_H
#define ENUMS_H

#include <vector>
#include <string>

namespace Enums{
    
    enum Colors {red=1, green=2, blue=3, purple=4};

    enum CardType {leader=1, character=2, event=3, stage=4};

    enum State {
        Draw=1,
        DrawDon=2,
        SelectCard=3,
        UseCard=4,
        SelectEnemyCard=5
    };
}

class EnumsHelper{
    public:
        static Enums::Colors getColor(int value);
        static const std::string ToString(Enums::State state);
};

#endif