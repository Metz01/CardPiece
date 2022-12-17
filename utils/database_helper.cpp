#include "database_helper.h"

DatabaseHelper::DatabaseHelper() {
    QTextStream ts(stdout);
    QJsonParseError parseError;
    {
        QFile fin(JSON_PATH);
        fin.open(QIODevice::ReadWrite);
        QByteArray ba2 = fin.readAll();
        fin.close();
        database = QJsonDocument::fromJson(ba2, &parseError);
    }

    // Assert Json Syntax
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Parse error at" << parseError.offset << ":" << parseError.errorString();
    }else{
        ts << database.toJson(QJsonDocument::Compact); 
    }
}


Card* DatabaseHelper::selectJSonCard(char cardCode[]){
    QTextStream ts(stdout);
    QJsonObject jsonObj = database.object();
    QJsonObject cardInfoJson = jsonObj.value(QString(cardCode)).toObject();

    QJsonValue type = cardInfoJson.value(QString("type"));
    
    // if type.toString == enum.Leader.value

    int cardType = (type.toString().toInt());

    switch (cardType)
    {
    case Enums::leader:
        qWarning() << "Leader" << "\n";
        return new Leader(cardInfoJson);
        break;
    case Enums::character:
        return new Character(cardInfoJson);
        break;
    case Enums::event:
        return new Character(cardInfoJson);
        //return new Event(cardInfoJson);
        break;
    case Enums::stage:
        return new Character(cardInfoJson);
        //return new Stage(cardInfoJson);
        break;
    default:
        return new Character(cardInfoJson);
        break;
    }
    

    /* for (QString &currentKey : cardInfoJson.keys())
    {
        QJsonValue item = cardInfoJson.value(currentKey);
        if(item.isObject()){
            QJsonObject itemObj = item.toObject();
        }else{
            QString value = item.toString();
        }
        ts << currentKey << " - " << .toString() << "\n";
    } */
}