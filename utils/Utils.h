#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <QJsonObject>
#include "Enums.h"
#include "Constants.h"
#include "JsonParser.h"
#include "Debug.h"

namespace Utils{
    union info{
        std::string name;
        Enums::CardType type;
        int attack;
        int cost;
        std::string effect;
        Enums::Colors color;
        std::string artPath;
        int life;
        info() {}       // Explicit constructor definition
        ~info() { };    // Explicit destructor definition
    };

    class CardInfo{
        public:

            info value;

            Enums::InfoAttribute attribute;

            CardInfo(info value, Enums::InfoAttribute attribute);
        // Non dovrebbe servire dato che non ci sono puntatori
        // ~CardInfo(){
        //     delete &name;
        //     delete &effect;
        //     Debug::LogDebug("Destroying CardInfo");
        // }
    };

    CardInfo LoadCard(Enums::InfoAttribute attribute, QJsonObject rawInfo);

    std::string GetCardName(QJsonObject rawInfo);
    
};

#endif