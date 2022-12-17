#ifndef ENUMS_H
#define ENUMS_H

#include <vector>

namespace Enums{
    
    enum Colors {red=1, green=2, blue=3, purple=4};
    static Colors getColor(int value){
        std::map<int, Enums::Colors> map = {
            {1, red},
            {2, green},
            {3, blue},
            {4, purple},
        };
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->first == value){
                return it->second;
            }
        }
        return red;
    }

    enum CardType {leader=1, character=2, event=3, stage=4};
}

#endif