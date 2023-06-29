#include "Save.h"
#include "Debug.h"
#include <fstream>
#include <unistd.h>

//Create a class to save and load the status of player in a file

Save::Save(std::string path, std::string name): _path(path), _name(name)
{
}

void Save::saveGame(Player *player1, Player *player2)
{
    std::ofstream file;
    file.open(_path + _name + ".txt");
    
    file << player1->getName() << std::endl;
    file << "-!-" << std::endl;
    file << player1->getLife() << std::endl;
    file << "-!-" << std::endl;
    file << player1->getLeader()->getCode() << std::endl;
    file << "-!-" << std::endl;
    file << player1->getDonList().size() << std::endl;
    file << "-!-" << std::endl;
    for (Card *card : player1->getHand())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-!-" << std::endl;
    for (Card *card : player1->getGround())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-!-" << std::endl;
    for (Card *card : player1->getGraveyard())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-!-" << std::endl;
    for (std::string code : player1->getDeckCodes())
    {
        file << code << std::endl;
    }

    file << "!-!-!" << std::endl;

    file << player2->getName() << std::endl;
    file << "-!-" << std::endl;
    file << player2->getLeader()->getCode() << std::endl;
    file << "-!-" << std::endl;
    file << player2->getDonList().size() << std::endl;
    file << "-!-" << std::endl;
    for (Card *card : player2->getHand())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-!-" << std::endl;
    for (Card *card : player2->getGround())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-!-" << std::endl;
    for (Card *card : player2->getGraveyard())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-!-" << std::endl;
    for (std::string code : player2->getDeckCodes())
    {
        file << code << std::endl;
    }

    file.close();

};

Player* Save::loadPlayer(std::vector<std::string> playerInfo){
    Debug::LogEnv("splitting  information");
    std::string name = playerInfo[0];
    int life = std::stoi(playerInfo[2]);
    std::string leaderCode = playerInfo[4];
    int donListSize = std::stoi(playerInfo[6]);
    std::vector<std::string> handCodes;
    std::vector<std::string> groundCodes;
    std::vector<std::string> graveyardCodes;
    std::vector<std::string> deckCodes;
    int i = 8;
    while (playerInfo[i] != "-!-")
    {
        handCodes.push_back(playerInfo[i]);
        i++;
    }
    i++;
    while (playerInfo[i] != "-!-")
    {
        groundCodes.push_back(playerInfo[i]);
        i++;
    }
    i++;
    while (playerInfo[i] != "-!-")
    {
        graveyardCodes.push_back(playerInfo[i]);
        i++;
    }
    i++;
    while (playerInfo[i] != "!-!-!" && i < (int)playerInfo.size())
    {
        deckCodes.push_back(playerInfo[i]);
        i++;
    }
    Debug::LogEnv("making player");
    return new Player(name, life, leaderCode, donListSize, handCodes, groundCodes, graveyardCodes, deckCodes);
}

Player* Save::loadPlayer1(){
    std::ifstream file;
    file.open(_path + _name + ".txt");
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line) && line.compare("!-!-!") != 0)
    {
        lines.push_back(line);
    }
    file.close();
    return loadPlayer(lines);
}

Player* Save::loadPlayer2(){
    std::ifstream file;
    file.open(_path + _name + ".txt");
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line) && line.compare("!-!-!") != 0)
    {   }
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();
    return loadPlayer(lines);
}