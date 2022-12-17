#include <string>
#include "Card.h"

Card::Card(std::string name, std::string artPath, std::string effect) : _name(name), _artPath(artPath), _effect(effect){};

Card::Card(QJsonObject Json) : 
    _name(Json["name"].toString().toStdString()), _artPath(Json["artPath"].toString().toStdString()), _effect(Json["effect"].toString().toStdString()){}

Card::Card(){}

Card::~Card(){}

std::string Card::getArtPath() { return _artPath; }

std::string Card::getName() { return _name; }

/* std::string* Card::info() {} */
