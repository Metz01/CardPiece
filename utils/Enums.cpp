/* #include <map>

#include "Enums.h"

Enums::Colors Enums::getColor(int value){
        std::map<int, Colors> map = {
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
    } */