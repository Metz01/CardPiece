#include "Utils.h"

Utils::CardInfo Utils::LoadCard(Enums::InfoAttribute attribute, QJsonObject rawInfo){

    Debug::LogEnv("Utils::LoadCard");
        
    Debug::LogDebug("Loading card info " + EnumsHelper::getAttributeName(attribute));
    Utils::CardInfo *info = new CardInfo;
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
    }
    Debug::LogDebug("Card info loaded");
    return *info;
}