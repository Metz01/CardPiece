#include <string>
#include "Character.h"

Character::Character(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack, int cost):
     ColoredCard(name, artPath, effect, code, color), Attacker(attack) , PlayableCard(cost){}

Character::Character(QJsonObject Json) : 
    ColoredCard(Json.value("colorData").toObject()), Attacker(Json), PlayableCard(Json) {}

Character::~Character()
{
}

std::string* Character::info() const{
    std::string *c = new std::string("Otama");
    return c;
}
