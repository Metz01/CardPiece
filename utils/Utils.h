#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <QJsonObject>
#include "Enums.h"
#include "Constants.h"
#include "JsonParser.h"
#include "Debug.h"

class Character;
class Don;
class Leader;
class Event;
namespace Utils{
    class CardInfo{
        
        public:

            union Value {
                char name[50];
                Enums::CardType type;
                int attack;
                int cost;
                char effect[100];
                Enums::Colors color;
                char artPath[100];
                int life;
                char code[30];
                int buff;
            } value;
    

            Enums::InfoAttribute attribute;

            CardInfo(Enums::InfoAttribute attribute, Character const* card);
            CardInfo(Enums::InfoAttribute attribute, Don const* card);
            CardInfo(Enums::InfoAttribute attribute, Leader const* card);
            CardInfo(Enums::InfoAttribute attribute, Event const* card);

            ~CardInfo();
    };

    std::string GetCardName(QJsonObject rawInfo);
    
};

#endif