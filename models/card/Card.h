#ifndef CARD_H
#define CARD_H
#include <string>
#include <QJsonObject>
#include "../../utils/JsonParser.h"
#include "../../utils/Constants.h"
#include "../../utils/Enums.h"
#include "../../utils/Utils.h"


class Card
{
protected:
    std::string _artPath;
    std::string _name;
    std::string _effect; // TODO: make effect class
    bool _active;
public:
    Card(std::string name, std::string artPath, std::string effect);
    Card(QJsonObject Json);
    Card();
    virtual ~Card();
    std::string getArtPath();
    std::string getName();
    virtual Utils::CardInfo info(Enums::InfoAttribute attribute, Utils::CardInfo onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo)) const = 0;
    virtual Enums::CardType getCardType() const = 0;
    bool isActive() const;
    void restCard();
};


#endif