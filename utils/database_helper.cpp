#include "database_helper.h"
#include "Constants.h"

#include <QtDebug>


QJsonDocument DatabaseHelper::database = (QJsonDocument());



/// @brief Constructor for DatabaseHelper to read the json file

DatabaseHelper::DatabaseHelper() {

    // Initialize variables
    QTextStream ts(stdout);
    QJsonParseError parseError;
    
    // Read Json File
    QFile fin(JSON_PATH);
    fin.open(QIODevice::ReadOnly);
    QByteArray ba2 = fin.readAll();
    fin.close();
    database = QJsonDocument::fromJson(ba2, &parseError);    
    // Assert Json Syntax
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at" << parseError.offset << ":" << parseError.errorString();
    }else{
        Debug::LogDebug("Database loaded");
        //ts << database.toJson(QJsonDocument::Compact); //write in console the database
    }
}

QJsonObject DatabaseHelper::getJsonInfo(std::string code){
    Debug::LogDebug(code);
    QJsonObject jsonObj = database.object();

    QJsonObject cardInfoJson = JsonParser::jsonKeytoJsonObject(jsonObj, code);
    //QJsonDocument doc(jsonObj);
//    QString jsonString = doc.toJson(QJsonDocument::Indented);
//    qDebug() << jsonString.toStdString().c_str();
    return cardInfoJson;
}

/// @brief from the json file, select the card with the given cardCode and initialize it
/// @param cardCode code of the card to be selected
/// @return istanciated card

Card* DatabaseHelper::selectJSonCard(std::string cardCode){

    Debug::LogEnv("DatabaseHelper::selectJSonCard " + cardCode);
    
    QJsonObject cardInfoJson = getJsonInfo(cardCode);
    QJsonValue type = cardInfoJson.value(QString("type"));

    int cardType = (type.toString().toInt());
    Debug::LogEnv("DatabaseHelper::selectJSonCard cardType: " + std::to_string(cardType));
    Debug::LogEnv("DatabaseHelper::selectJSonCard cardName: " + JsonParser::jsonKeytoString(cardInfoJson, JSON_NAME));
    switch (cardType)
    {
    case Enums::leader:
        return new Leader(cardInfoJson, cardCode);
        break;
    case Enums::character:
        return new Character(cardInfoJson, std::string(cardCode));
        break;
    case Enums::event:
        return new Event(cardInfoJson, cardCode);
        break;
    case Enums::stage:
        return new Stage(cardInfoJson, cardCode);
        break;
    default:
        return new Character(cardInfoJson, std::string(cardCode));
        break;
    }
}

bool DatabaseHelper::isLeader(std::string cardCode){
    QJsonObject jsonObj = database.object();
    QJsonObject cardInfoJson = JsonParser::jsonKeytoJsonObject(jsonObj, cardCode);
    QJsonValue type = cardInfoJson.value(QString("type"));
    int cardType = (type.toString().toInt());
    Debug::LogInfo(std::to_string(cardType));
    if(cardType == Enums::leader){
        return true;
    }else{
        return false;
    }
}
