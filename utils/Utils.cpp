#include "Utils.h"
#include "../models/card/card_types/CardTypes.h"


Utils::CardInfo::CardInfo(Enums::InfoAttribute attribut, Character const* card){
    attribute = attribut;
    switch (attribut)
    {
    case Enums::Name:
        std::strcpy(value.name, card->getName().c_str());
        break;
    case Enums::Type:
        value.type = card->getCardType();
        break;
    case Enums::Attack:
        value.attack = card->getAttack();
        break;
    case Enums::Cost:
        value.cost = card->getCost();
        break;
    case Enums::Color:
        value.color = card->getColor();
        break;
    case Enums::ArtPath:
        std::strcpy(value.artPath, card->getArtPath().c_str());
        break;
    case Enums::Code:
        std::strcpy(value.code, card->getCode().c_str());
        break;
    case Enums::Buff:
        value.buff = card->getBuff();
        break;
    default:
        break;
    }
}

Utils::CardInfo::CardInfo(Enums::InfoAttribute attribut, Don const* card){
    attribute = attribut;
    switch (attribut)
    {
    case Enums::Name:
        std::strcpy(value.name, card->getName().c_str());
        break;
    case Enums::Type:
        value.type = card->getCardType();
        break;
    case Enums::ArtPath:
        std::strcpy(value.artPath, card->getArtPath().c_str());
        break;
    default:
        break;
    }
}

Utils::CardInfo::CardInfo(Enums::InfoAttribute attribut, Leader const* card){
    attribute = attribut;
    switch (attribut)
    {
    case Enums::Name:
        std::strcpy(value.name, card->getName().c_str());
        break;
    case Enums::Type:
        value.type = card->getCardType();
        break;
    case Enums::Attack:
        value.attack = card->getAttack();
        break;
    case Enums::Color:
        value.color = card->getColor();
        break;
    case Enums::ArtPath:
        std::strcpy(value.artPath, card->getArtPath().c_str());
        break;
    case Enums::Life:
        value.life = card->getLife();
        break;
    case Enums::Code:
        std::strcpy(value.code, card->getCode().c_str());
        break;
    case Enums::Buff:
        value.buff = card->getBuff();
        break;
    default:
        break;
    }
}

Utils::CardInfo::CardInfo(Enums::InfoAttribute attribut, Event const* card){
    attribute = attribut;
    switch (attribut)
    {
    case Enums::Name:
        std::strcpy(value.name, card->getName().c_str());
        break;
    case Enums::Type:
        value.type = card->getCardType();
        break;
    case Enums::Cost:
        value.cost = card->getCost();
        break;
    case Enums::Color:
        value.color = card->getColor();
        break;
    case Enums::ArtPath:
        std::strcpy(value.artPath, card->getArtPath().c_str());
        break;
    case Enums::Code:
        std::strcpy(value.code, card->getCode().c_str());
        break;
    case Enums::Buff:
        value.buff = card->getBuff();
        break;
    default:
        break;
    }
}

Utils::CardInfo::CardInfo(Enums::InfoAttribute attribut, Stage const* card){
    attribute = attribut;
    switch (attribut)
    {
    case Enums::Name:
        std::strcpy(value.name, card->getName().c_str());
        break;
    case Enums::Type:
        value.type = card->getCardType();
        break;
    case Enums::Cost:
        value.cost = card->getCost();
        break;
    case Enums::Color:
        value.color = card->getColor();
        break;
    case Enums::ArtPath:
        std::strcpy(value.artPath, card->getArtPath().c_str());
        break;
    case Enums::Code:
        std::strcpy(value.code, card->getCode().c_str());
        break;
    case Enums::Buff:
        value.buff = card->getBuff();
        break;
    default:
        break;
    }
}


Utils::CardInfo::~CardInfo(){
    
}
