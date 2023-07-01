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
    bool _active;
    
public:
    Card(std::string name, std::string artPath);
    Card(QJsonObject Json);
    Card();
    virtual ~Card();
    std::string getArtPath() const;
    std::string getName() const;
    virtual Enums::CardType getCardType() const = 0;
    bool isActive() const;
    void restCard();
    void setActive();
    virtual Utils::CardInfo* getCardInfo(Enums::InfoAttribute attribute) const = 0;
    virtual void resetCard();
};


#endif