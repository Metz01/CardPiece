#include "Save.h"
#include "Debug.h"
#include <fstream>
#include <unistd.h>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QJsonArray>

QJsonObject Save::savePalyer(Player *player){
    QJsonObject jsonObject;
    jsonObject["Name"] = QString::fromStdString(player->getName());
    jsonObject["Life"] = QString::fromStdString(std::to_string(player->getLife()));
    jsonObject["Leader"] = QString::fromStdString(player->getLeader()->getCode() +
                                                  "-" + std::to_string(player->getLeader()->getCardInfo(Enums::InfoAttribute::Buff)->value.buff)+
                                                  "+" + std::to_string(player->getLeader()->isActive()));
    jsonObject["DonNumber"] = QString::fromStdString(std::to_string((int)player->getDonList().size()));
    jsonObject["ActiveDon"] = QString::fromStdString(std::to_string(player->getActiveDon()));
    if(player->getStage()) jsonObject["Stage"] = QString::fromStdString(player->getStage()->getCardInfo(Enums::Code)->value.code);
    else jsonObject["Stage"] = "0";
    QJsonArray jsonArray;
    for (Card *card : player->getHand())
    {
        QString qStringValue = QString::fromStdString(card->getCardInfo(Enums::Code)->value.code);
        jsonArray.append(qStringValue);
    }
    jsonObject["Hand"] = jsonArray;
    jsonArray = QJsonArray();
    for (Card *card : player->getGround())
    {
        QString qStringValue = QString::fromStdString(std::string(card->getCardInfo(Enums::Code)->value.code) +
                                                      "-" + std::to_string(card->getCardInfo(Enums::InfoAttribute::Buff)->value.buff)+
                                                      "+" + std::to_string(card->isActive()));
        jsonArray.append(qStringValue);
    }
    jsonObject["Ground"] = jsonArray;
    jsonArray = QJsonArray();
    for (Card *card : player->getGraveyard())
    {
        QString qStringValue = QString::fromStdString(card->getCardInfo(Enums::Code)->value.code);
        jsonArray.append(qStringValue);
    }
    jsonObject["Graveyard"] = jsonArray;
    jsonArray = QJsonArray();
    for (std::string card : player->getDeckCodes())
    {
        QString qStringValue = QString::fromStdString(card);
        jsonArray.append(qStringValue);
    }
    jsonObject["Deck"] = jsonArray;
    return jsonObject;
}

void Save::saveGame(Player *player1, Player *player2, std::string path) {

    // Create a JSON object
    QJsonObject fileInfo;
    fileInfo["GameStatus"] = QString::fromStdString(EnumsHelper::ToString(FSM::getCurrentState()));
    fileInfo["CurrentPlayer"] =  QString::fromStdString(FSM::getCurrentPlayer()->getName());
    QJsonObject p1Info = Save::savePalyer(player1);
    QJsonObject p2Info = Save::savePalyer(player2);


    fileInfo["Player1"] = p1Info;
    fileInfo["Player2"] = p2Info;

    // Create a JSON document
    QJsonDocument jsonDoc(fileInfo);

    // Convert the JSON document to a string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Indented);

    // Save the JSON string to a file
    QFile file(QString::fromStdString(path));
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << jsonString;
        file.close();
        qDebug() << "JSON data saved successfully!";
    } else {
        qDebug() << "Failed to save JSON data!";
    }
}

bool Save::checkJsonSaveIntegrity(QJsonObject jsonObject){
    if(!jsonObject.contains("Name")) return false;
    if(!jsonObject.contains("Life")) return false;
    if(!jsonObject.contains("Leader")) return false;
    if(!jsonObject.contains("DonNumber")) return false;
    if(!jsonObject.contains("ActiveDon")) return false;
    if(!jsonObject.contains("Stage")) return false;
    if(!jsonObject.contains("Hand")) return false;
    if(!jsonObject.contains("Ground")) return false;
    if(!jsonObject.contains("Graveyard")) return false;
    if(!jsonObject.contains("Deck")) return false;
    return true;
}

Player* Save::loadPlayer(std::string path, std::string player){
    if (path != "") {
        // Read the JSON file
        QFile file(QString::fromStdString(path));
        if (file.open(QIODevice::ReadOnly)) {
            // Load the JSON document
            QByteArray jsonData = file.readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

            if (!jsonDoc.isNull()) {
                // Retrieve values from the JSON document
                QJsonObject jsonObject = jsonDoc.object();
                QJsonObject PlayerInfo = jsonObject[QString::fromStdString(player)].toObject();
                if(!Save::checkJsonSaveIntegrity(PlayerInfo)){
                    Debug::LogError("File Json of Save not right formatted");
                    return NULL;
                }
                std::string name = PlayerInfo["Name"].toString().toStdString();
                int life = std::stoi(PlayerInfo["Life"].toString().toStdString());
                std::string leaderCode =PlayerInfo["Leader"].toString().toStdString();
                int donListSize = std::stoi(PlayerInfo["DonNumber"].toString().toStdString());
                int donactive = std::stoi(PlayerInfo["ActiveDon"].toString().toStdString());
                std::string stage = PlayerInfo["Stage"].toString().toStdString();
                std::vector<std::string> handCodes;
                std::vector<std::string> groundCodes;
                std::vector<std::string> graveyardCodes;
                std::vector<std::string> deckCodes;
                QJsonArray jsonArray;
                jsonArray = PlayerInfo["Hand"].toArray();
                for (const QJsonValue& value : jsonArray) {
                    // Check if the element is a string
                    if (value.isString())
                        handCodes.push_back(value.toString().toStdString());
                }
                jsonArray = PlayerInfo["Ground"].toArray();
                for (const QJsonValue& value : jsonArray) {
                    // Check if the element is a string
                    if (value.isString())
                        groundCodes.push_back(value.toString().toStdString());
                }
                jsonArray = PlayerInfo["Graveyard"].toArray();
                for (const QJsonValue& value : jsonArray) {
                    // Check if the element is a string
                    if (value.isString())
                        graveyardCodes.push_back(value.toString().toStdString());
                }
                jsonArray = PlayerInfo["Deck"].toArray();
                for (const QJsonValue& value : jsonArray) {
                    // Check if the element is a string
                    if (value.isString())
                        deckCodes.push_back(value.toString().toStdString());
                }
                Debug::LogEnv("making player");
                return new Player(name, life, leaderCode, donListSize, donactive, handCodes, groundCodes, graveyardCodes, stage, deckCodes);
            } else {
                qDebug() << "Failed to parse JSON document.";
            }
        } else {
            qDebug() << "Failed to open JSON file.";
        }
    } else {
        qDebug() << "No file selected.";
    }
    return NULL;
}

Enums::State Save::loadState(std::string path){
    std::string state;
    if (path != "") {
        // Read the JSON file
        QFile file(QString::fromStdString(path));
        if (file.open(QIODevice::ReadOnly)) {
            // Load the JSON document
            QByteArray jsonData = file.readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
            if (!jsonDoc.isNull()) {
                QJsonObject jsonObject = jsonDoc.object();
                state = jsonObject["GameStatus"].toString().toStdString();
            } else {
                qDebug() << "Failed to parse JSON document.";
            }
        } else {
            qDebug() << "Failed to open JSON file.";
        }
    } else {
        qDebug() << "No file selected.";
    }
    return EnumsHelper::getState(state);
}

std::string Save::loadCurrentPlayer(std::string path){
    std::string player;
    if (path != "") {
        // Read the JSON file
        QFile file(QString::fromStdString(path));
        if (file.open(QIODevice::ReadOnly)) {
            // Load the JSON document
            QByteArray jsonData = file.readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
            if (!jsonDoc.isNull()) {
                QJsonObject jsonObject = jsonDoc.object();
                player = jsonObject["CurrentPlayer"].toString().toStdString();
            } else {
                qDebug() << "Failed to parse JSON document.";
            }
        } else {
            qDebug() << "Failed to open JSON file.";
        }
    } else {
        qDebug() << "No file selected.";
    }
    return player;
}
