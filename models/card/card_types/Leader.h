#ifndef LEADER_H
#define LEADER_H
#include <string>
#include "../Attacker.h"
#include <QJsonValue>

class Leader: public Attacker
{
private:
    int _life;
public:
    Leader(std::string name, std::string artPath, std::string effect, std::string code, Enums::Colors color, int attack, int life);
    Leader(QJsonObject Json, std::string cardCode);
    ~Leader();
    int getLife() const;
    bool info(Enums::InfoAttribute attribute, Utils::CardInfo*, bool onGetAttribute(Enums::InfoAttribute attribute, QJsonObject rawInfo, Utils::CardInfo*)) const;
    std::string* lead() const;
    Enums::CardType getCardType() const;
};

#endif