#ifndef LEADER_H
#define LEADER_H
#include <string>
#include "../Attacker.h"
#include "../../../utils/Utils.h"
#include <QJsonValue>

class Leader: public Attacker
{
private:
    int _life;
public:
    Leader(std::string name, std::string artPath, std::string code, Enums::Colors color, int attack, int life);
    Leader(QJsonObject Json, std::string cardCode);
    ~Leader();
    int getLife() const;
    std::string* lead() const;
    Enums::CardType getCardType() const;
    Utils::CardInfo* getCardInfo(Enums::InfoAttribute attribute) const override;
};

#endif