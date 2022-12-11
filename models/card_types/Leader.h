#ifndef CARD_H
#define CARD_H
#include <string>
#include "../Attacker.h"

class Leader: public Attacker
{
private:
    int _life;
public:
    Leader(std::string, std::string, std::string, std::string, int, int);
    ~Leader();
};

#endif