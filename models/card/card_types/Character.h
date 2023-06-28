#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "../Attacker.h"
#include "../PlayableCard.h"
#include <QJsonObject>

class Character: public Attacker, public PlayableCard
{
private:
    int counter;
public:
    Character(std::string, std::string, std::string, std::string, Enums::Colors, int, int);
    Character(QJsonObject Json, std::string cardCode);
    ~Character();
    Enums::CardType getCardType() const;
    Utils::CardInfo getCardInfo(Enums::InfoAttribute attribute) const;
};

#endif