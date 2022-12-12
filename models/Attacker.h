#ifndef ATTACKER_H
#define ATTACKER_H
#include <string>
#include "ColoredCard.h"

class Attacker: virtual public ColoredCard
{
    private:
        int _attack;
    public:
        Attacker(std::string, std::string, std::string, std::string, Colors, int);
        Attacker(int attack);
        ~Attacker();
};



#endif