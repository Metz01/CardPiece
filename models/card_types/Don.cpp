#include <string>
#include "Don.h"

void Don::attachCard(Card *card)
{
    _attachedCard = card;
}

int Don::getAttackIncrement()
{
    return attackIncrement;
}

Don::Don(std::string name, std::string artPath, std::string effect): Card(name, artPath, effect){
}

Don::~Don()
{
    delete _attachedCard;
}

std::string* Don::info(){
    std::string *c = new std::string("DON!");
    return c;
}