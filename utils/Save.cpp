#include "Save.h"
#include "Debug.h"
#include <fstream>
#include <unistd.h>

Save::Save(std::string path, std::string name): _path(path), _name(name)
{
}

void Save::saveGame(Player *player1, Player *player2)
{
    std::ofstream file;
    file.open(_path + _name + ".txt");
    
    file << player1->getName() << std::endl;
    file << "-Life-" << std::endl;
    file << player1->getLife() << std::endl;
    file << "-Leader-" << std::endl;
    file << player1->getLeader()->getCode() << std::endl;
    file << "-DonNumber-" << std::endl;
    file << player1->getDonList().size() << std::endl;
    file << "-Hand-" << std::endl;
    for (Card *card : player1->getHand())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-Ground-" << std::endl;
    for (Card *card : player1->getGround())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-Graveyard-" << std::endl;
    for (Card *card : player1->getGraveyard())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-Deck-" << std::endl;
    for (std::string code : player1->getDeckCodes())
    {
        file << code << std::endl;
    }

    file << "!-Player2-!" << std::endl;

    file << player2->getName() << std::endl;
    file << "-Life-" << std::endl;
    file << player2->getLife() << std::endl;
    file << "-Leader-" << std::endl;
    file << player2->getLeader()->getCode() << std::endl;
    file << "-DonNumber-" << std::endl;
    file << player2->getDonList().size() << std::endl;
    file << "-Hand-" << std::endl;
    for (Card *card : player2->getHand())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-Ground-" << std::endl;
    for (Card *card : player2->getGround())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-Graveyard-" << std::endl;
    for (Card *card : player2->getGraveyard())
    {
        file << card->getCardInfo(Enums::InfoAttribute::Code)->value.code << std::endl;
    }
    file << "-Deck-" << std::endl;
    for (std::string code : player2->getDeckCodes())
    {
        file << code << std::endl;
    }

    file.close();

};

Player* Save::loadPlayer(std::vector<std::string> playerInfo){
    Debug::LogEnv("splitting  information");
    if (playerInfo.size() > 65){
        std::cerr << "Too many lines in the file.";
        return nullptr;
    } 
    
    try
    {
        std::string name = playerInfo.at(0);
        int life = std::stoi(playerInfo.at(2));
        std::string leaderCode = playerInfo.at(4);
        int donListSize = std::stoi(playerInfo.at(6));
        std::vector<std::string> handCodes;
        std::vector<std::string> groundCodes;
        std::vector<std::string> graveyardCodes;
        std::vector<std::string> deckCodes;
        int i = 8;
        while (playerInfo.at(i) != "-Ground-")
        {
            handCodes.push_back(playerInfo.at(i));
            i++;
        }
        i++;
        while (playerInfo.at(i) != "-Graveyard-")
        {
            groundCodes.push_back(playerInfo.at(i));
            i++;
        }
        i++;
        while (playerInfo.at(i) != "-Deck-")
        {
            graveyardCodes.push_back(playerInfo.at(i));
            i++;
        }
        i++;
        while (i < (int)playerInfo.size() && playerInfo.at(i).compare("!-Player2-!") != 0)
        {
            deckCodes.push_back(playerInfo.at(i));
            i++;
        }
        Debug::LogEnv("making player");
        return new Player(name, life, leaderCode, donListSize, handCodes, groundCodes, graveyardCodes, deckCodes);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << " : input File for load game not well formatted" << '\n';
    }
    return nullptr;
}

Player* Save::loadPlayer1(){
    std::ifstream file;
    file.open(_path + _name + ".txt");
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line) && line.compare("!-Player2-!") != 0)
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
    while (std::getline(file, line) && line.compare("!-Player2-!") != 0)
    {   }
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();
    return loadPlayer(lines);
}