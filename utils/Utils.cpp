#include "Utils.h"

Utils::CardInfo::CardInfo(Utils::info value, Enums::InfoAttribute attribute){
    switch (attribute)
    {
    case Enums::InfoAttribute::Name:
        this->value.name = value.name;
        break;
    case Enums::InfoAttribute::Type:
        this->value.type = value.type;
        break;
    case Enums::InfoAttribute::Attack:
        this->value.attack = value.attack;
        break;
    case Enums::InfoAttribute::Cost:
        this->value.cost = value.cost;
        break;
    case Enums::InfoAttribute::Effect:
        this->value.effect = value.effect;
        break;
    case Enums::InfoAttribute::Color:
        this->value.color = value.color;
        break;
    case Enums::InfoAttribute::ArtPath:
        this->value.artPath = value.artPath;
        break;
    case Enums::InfoAttribute::Life:
        this->value.life = value.life;
        break;
    default:
        break;
    }
    this->attribute = attribute;
}
