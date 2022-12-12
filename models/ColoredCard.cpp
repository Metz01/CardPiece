#include <string>
#include "ColoredCard.h"

ColoredCard::ColoredCard(std::string name, std::string artPath, std::string effect, std::string code, Colors color): 
    Card(name, artPath, effect), _code(code), _color(color) {}

ColoredCard::ColoredCard() {};