#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <vector>

#include "../models/Player.h"
#include "../models/Deck.h"
#include "../models/card/Card.h"

//Create a class to save and load the status of player in a file
class Save
{
private:
    std::string _path;
    std::string _name;
public:
    Save(std::string path, std::string name);
    void saveGame(Player *player1, Player *player2);
    Player* loadPlayer1();
    Player* loadPlayer2();
    Player* loadPlayer(std::vector<std::string> playerInfo);
};

#endif // SAVE_H