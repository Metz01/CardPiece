#ifndef __DATABASE_HELPER_H__
#define __DATABASE_HELPER_H__

#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QCoreApplication>
#include <QString>
#include <QVariant>
#include <QFile>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>


#include "../models/card/card_types/CardTypes.h"

class DatabaseHelper{
    private:
        
    public: 
        static QJsonDocument database;
        DatabaseHelper();
        /* ~DatabaseHelper(); */
        static Card* selectJSonCard(char cardCode[]);
        static void testFunctions();
};

#endif

QJsonDocument DatabaseHelper::database = QJsonDocument();



/// @brief Constructor for DatabaseHelper to read the json file

DatabaseHelper::DatabaseHelper() {

    // Initialize variables
    QTextStream ts(stdout);
    QJsonParseError parseError;
    
    // Read Json File
    QFile fin(JSON_PATH);
    fin.open(QIODevice::ReadWrite);
    QByteArray ba2 = fin.readAll();
    fin.close();
    database = QJsonDocument::fromJson(ba2, &parseError);
    
    // Assert Json Syntax
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at" << parseError.offset << ":" << parseError.errorString();
    }else{
        ts << database.toJson(QJsonDocument::Compact); 
    }
}

/// @brief from the json file, select the card with the given cardCode and initialize it
/// @param cardCode code of the card to be selected
/// @return istanciated card

Card* DatabaseHelper::selectJSonCard(char cardCode[]){
    QTextStream ts(stdout);
    QJsonObject jsonObj = database.object();
    QJsonObject cardInfoJson = JsonParser::jsonKeytoJsonObject(jsonObj, cardCode);

    QJsonValue type = cardInfoJson.value(QString("type"));

    int cardType = (type.toString().toInt());

    switch (cardType)
    {
    case Enums::leader:
        qWarning() << "Leader" << "\n";
        return new Leader(cardInfoJson, std::string(cardCode));
        break;
    case Enums::character:
        return new Character(cardInfoJson, std::string(cardCode));
        break;
    case Enums::event:
        return new Character(cardInfoJson, std::string(cardCode));
        //return new Event(cardInfoJson);
        break;
    case Enums::stage:
        return new Character(cardInfoJson, std::string(cardCode));
        //return new Stage(cardInfoJson);
        break;
    default:
        return new Character(cardInfoJson, std::string(cardCode));
        break;
    }
}

void DatabaseHelper::testFunctions(){
    std::cout << "test" << std::endl;
}