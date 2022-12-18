#ifndef ENUMS_H
#define ENUMS_H

#include <vector>

namespace Enums{
    
    enum Colors {red=1, green=2, blue=3, purple=4};

    enum CardType {leader=1, character=2, event=3, stage=4};
}

class EnumsHelper{
    public:
        static Enums::Colors getColor(int value);
};

#endif