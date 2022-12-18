#ifndef CARD_H
#define CARD_H
#include <string>
#include <QJsonObject>
#include "../utils/JsonParser.h"
#include "../utils/Constants.h"

class Card
{
protected:
    std::string _artPath;
    std::string _name;
    std::string _effect; // TODO: make effect class
public:
    Card(std::string name, std::string artPath, std::string effect);
    Card(QJsonObject Json);
    Card();
    virtual ~Card();
    std::string getArtPath();
    std::string getName();
    virtual std::string* info() const = 0;
};

#endif