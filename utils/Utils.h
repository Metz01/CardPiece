#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <QJsonObject>
#include "Enums.h"
#include "Constants.h"
#include "JsonParser.h"
#include "Debug.h"

namespace Utils{


    class CardInfo{
        public:
            std::string name;
            Enums::CardType type;
            int attack;
            int cost;
            std::string effect;
            Enums::Colors color;
            std::string artPath;
            int life;

        // Non dovrebbe servire dato che non ci sono puntatori
        // ~CardInfo(){
        //     delete &name;
        //     delete &effect;
        //     Debug::LogDebug("Destroying CardInfo");
        // }
    };

    static bool LoadCard(Enums::InfoAttribute attribute, QJsonObject rawInfo, CardInfo* info){
        
        Debug::LogDebug("Loading card info " + EnumsHelper::getAttributeName(attribute));
        switch (attribute){
        case Enums::InfoAttribute::ArtPath:
            info->artPath = JsonParser::jsonKeytoString(rawInfo, JSON_ARTPATH);
            break;
        case Enums::InfoAttribute::Name:
            
            Debug::LogDebug("Contains name : " + std::to_string(rawInfo.contains(QString::fromStdString(JSON_NAME))));
            
            info->name = JsonParser::jsonKeytoString(rawInfo, JSON_NAME);
            Debug::LogDebug("Name Loaded");
            break;
        case Enums::InfoAttribute::Type:
            info->type = EnumsHelper::getCardType(JsonParser::jsonKeytoInt(rawInfo, JSON_TYPE)); 
            break;
        case Enums::InfoAttribute::Attack:
            info->attack =  JsonParser::jsonKeytoInt(rawInfo, JSON_ATTACK);
            break;
        case Enums::InfoAttribute::Cost:
            info->cost =  JsonParser::jsonKeytoInt(rawInfo, JSON_COST);
            break;
        case Enums::InfoAttribute::Effect:
            info->effect = (JsonParser::jsonKeytoString(rawInfo, JSON_EFFECT));
            break;
        case Enums::InfoAttribute::Life:
            info->life =  JsonParser::jsonKeytoInt(rawInfo, JSON_LIFE);
            break;
        case Enums::InfoAttribute::Color:
            info->color =  EnumsHelper::getColor(JsonParser::jsonKeytoInt(rawInfo, JSON_COLOR));
            break;
        default:
            std::string errorMessage = std::string("Attribute ") + std::to_string((int)attribute) + std::string(" not implemented on Utils.LoadCard");
            Debug::LogError(errorMessage);
            return false;
        }
        Debug::LogDebug("Card info loaded");
        return true;
    }

};

#endif