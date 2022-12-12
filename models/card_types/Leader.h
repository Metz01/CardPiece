#ifndef LEADER_H
#define LEADER_H
#include <string>
#include "../Attacker.h"

class Leader: public Attacker
{
private:
    int _life;
public:
    Leader(std::string name, std::string artPath, std::string effect, std::string code, Colors color, int attack, int life);
    ~Leader();
};

#endif