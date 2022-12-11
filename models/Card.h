#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
protected:
    std::string _artPath;
    std::string _name;
    std::string _effect; // TODO: make effect class
public:
    Card(std::string, std::string, std::string);
    std::string getArtPath();
    std::string getName();
};

#endif