#include <string>
#include "Don.h"

Don::Don(std::string name, std::string artPath, std::string effect): Card(name, artPath, effect){
}

Don::Don(QJsonObject Json) : Card(Json){
    
}

Don::~Don()
{
    delete _attachedCard;
}


void Don::attachCard(Card *card)
{
    _attachedCard = card;
}

int Don::getAttackIncrement()
{
    return attackIncrement;
}



std::string* Don::info(){
    std::string *c = new std::string("DON!");
    return c;
}