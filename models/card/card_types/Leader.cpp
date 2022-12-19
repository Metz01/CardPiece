#include <string>
#include <iostream>
#include "Leader.h"


Leader::Leader(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack, int life):
     ColoredCard(name, artPath, effect, code, color), 
     Attacker(attack), 
     _life(life) {}

Leader::Leader(QJsonObject Json, std::string cardCode) : 
    ColoredCard(JsonParser::jsonKeytoJsonObject(Json, JSON_COLOR_DATA), cardCode), 
    Attacker(Json, cardCode),  
    _life(JsonParser::jsonKeytoInt(Json, JSON_LIFE)){
}

Leader::~Leader()
{
}


std::string* Leader::info() const{
    std::string life = std::to_string(this->_life);
    std::cout << "Info Leader" << std::endl;
    std::string *c = new std::string(_name);
    return c;
}

std::string* Leader::lead() const{
    std::string *c = new std::string("Leader");
    return c;
}

int Leader::getLife() const{
    return _life;
}