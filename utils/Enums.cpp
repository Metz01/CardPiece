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



std::string EnumsHelper::ToString(Enums::State state){
    switch (state){
        case Enums::Draw:   return "Draw";
        case Enums::DrawDon:   return "DrawDon";
        case Enums::SelectCard: return "SelectCard";
        case Enums::UseCard: return "UseCard";
        case Enums::SelectEnemyCard: return "SelectEnemyCard";
        case Enums::AttachDon: return "AttachDon";
        default:      return "[Unknown State]";
    }
}

/// @brief return card type from the given value, using the enum CardType
/// @param value integer value corresponding to the enum card type
/// @return the enum card type
Enums::CardType EnumsHelper::getCardType(int value){
    std::map<int, Enums::CardType> map = {
        {1, Enums::leader},
        {2, Enums::character},
        {3, Enums::event},
        {4, Enums::stage},
        {5, Enums::don},
    };
    for(auto it = map.begin(); it != map.end(); it++){
        if(it->first == value){
            return it->second;
        }
    }
    return Enums::leader;
}

/// @brief return the attribute name from the given card type
/// @param type the card type
/// @return the attribute name
std::string EnumsHelper::getAttributeName(Enums::InfoAttribute type){
    switch (type){
        case Enums::Name:   return "Name";
        case Enums::Type:   return "Type";
        case Enums::Attack: return "Attack";
        case Enums::Cost: return "Cost";
        case Enums::Effect: return "Effect";
        case Enums::Color: return "Color";
        case Enums::ArtPath: return "ArtPath";
        case Enums::Life: return "Life";
        case Enums::Code: return "Code";
        default:      return "[Unknown Attribute]";
    }
}
