#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <vector>
#include <iostream>

#include "../models/Player.h"
#include "../models/Deck.h"
#include "../models/card/Card.h"
#include "./fsm/fsm.h"
#include "./Enums.h"

//Create a class to save and load the status of player in a file
namespace Save
{
    QJsonObject savePalyer(Player *player);
    void saveGame(Player *player1, Player *player2, std::string path);
    Player* loadPlayer(std::string, std::string);
    Enums::State loadState(std::string path);
    std::string loadCurrentPlayer(std::string _path);
    bool checkJsonSaveIntegrity(QJsonObject jsonObject);
    int loadCurrentTurn(std::string path);
};

#endif // SAVE_H
