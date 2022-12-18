
#include <string>
#include "Card.h"

Card::Card(std::string name, std::string artPath, std::string effect) : 
    _artPath(artPath), 
    _name(name), 
    _effect(effect){};

Card::Card(QJsonObject Json) : 
    _artPath(JsonParser::jsonKeytoString(Json, JSON_ARTPATH)), 
    _name(JsonParser::jsonKeytoString(Json, JSON_NAME)),
    _effect(JsonParser::jsonKeytoString(Json, JSON_EFFECT)){}

Card::Card(){}

Card::~Card(){}


std::string Card::getArtPath() { return _artPath; }

std::string Card::getName() { return _name; }

/* std::string* Card::info() {} */
