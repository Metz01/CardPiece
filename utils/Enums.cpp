 #include <map>

#include "Enums.h"

/// @brief return color from the given value, using the enum Colors
/// @param value integer value corresponding to the enum color
/// @return the enum color
Enums::Colors EnumsHelper::getColor(int value){
    std::map<int, Enums::Colors> map = {
        {1, Enums::red},
        {2, Enums::green},
        {3, Enums::blue},
        {4, Enums::purple},
    };
    for(auto it = map.begin(); it != map.end(); it++){
        if(it->first == value){
            return it->second;
        }
    }
    return Enums::red;
}