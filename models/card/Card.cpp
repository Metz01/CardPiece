
#include <string>
#include "Card.h"


Card::Card(std::string name, std::string artPath) : 
    _artPath(artPath), 
    _name(name), 
    _active(0){};

Card::Card(QJsonObject Json) : 
    _artPath(JsonParser::jsonKeytoString(Json, JSON_ARTPATH)), 
    _name(JsonParser::jsonKeytoString(Json, JSON_NAME)),
    _active(0){}

Card::Card(){}

Card::~Card(){}


std::string Card::getArtPath() const { return _artPath; }

std::string Card::getName() const { return _name; }

bool Card::isActive() const{
    return _active;
}

void Card::restCard(){
    _active = 0;
}

/* std::string* Card::info() {} */
