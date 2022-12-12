#include <string>
#include "Card.h"

Card::Card(std::string name, std::string artPath, std::string effect) : _name(name), _artPath(artPath), _effect(effect){};

Card::Card(){}

std::string Card::getArtPath() { return _artPath; }

std::string Card::getName() { return _name; }
