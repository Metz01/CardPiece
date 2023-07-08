
#include <string>
#include "Card.h"


Card::Card(std::string name, std::string artPath) :
    _artPath(std::string(CARDIMAGE_PATH) + artPath),
    _name(name),
    _active(1){};

Card::Card(QJsonObject Json) : 
    _artPath(std::string(CARDIMAGE_PATH) + JsonParser::jsonKeytoString(Json, JSON_ARTPATH)),
    _name(JsonParser::jsonKeytoString(Json, JSON_NAME)),
    _active(1){}

Card::Card(){}

Card::~Card(){}


std::string Card::getArtPath() const { return _artPath; }

std::string Card::getName() const { return _name; }

bool Card::isActive() const{
    return _active;
}

void Card::restCard(){
    Debug::LogEnv("Card::restCard");
    _active = false;
}

void Card::setActive(){
    Debug::LogEnv("Card::activeCard");
    _active = true;
}

void Card::resetBuff(){
}



/* std::string* Card::info() {} */
