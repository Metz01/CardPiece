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
    std::string* info() const;
    std::string* lead() const;
};

#endif