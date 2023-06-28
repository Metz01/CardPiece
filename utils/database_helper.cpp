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

QJsonObject DatabaseHelper::getCardInfo(std::string cardCode){
    Debug::LogDebug(cardCode);
    QJsonObject jsonObj = database.object();
    QJsonObject cardInfoJson = JsonParser::jsonKeytoJsonObject(jsonObj, cardCode);
    QJsonDocument doc(jsonObj);
//    QString jsonString = doc.toJson(QJsonDocument::Indented);
//    qDebug() << jsonString.toStdString().c_str();
    return cardInfoJson;
}

/// @brief from the json file, select the card with the given cardCode and initialize it
/// @param cardCode code of the card to be selected
/// @return istanciated card

Card* DatabaseHelper::selectJSonCard(std::string cardCode){

    Debug::LogEnv("DatabaseHelper::selectJSonCard");
    
    QJsonObject cardInfoJson = getCardInfo(cardCode);
    QJsonValue type = cardInfoJson.value(QString("type"));

    int cardType = (type.toString().toInt());

    switch (cardType)
    {
    case Enums::leader:
        return new Leader(cardInfoJson, cardCode);
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

bool DatabaseHelper::isLeader(std::string cardCode){
    QJsonObject jsonObj = database.object();
    QJsonObject cardInfoJson = JsonParser::jsonKeytoJsonObject(jsonObj, cardCode);
    QJsonValue type = cardInfoJson.value(QString("type"));
    int cardType = (type.toString().toInt());
    if(cardType == Enums::leader){
        return true;
    }else{
        return false;
    }
}
