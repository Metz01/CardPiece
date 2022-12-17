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

#include "../models/card_types/CardTypes.h"
#define JSON_PATH "assets/cardDB.json"

class DatabaseHelper{
    private:
        QJsonDocument database;
    public: 
        DatabaseHelper();
        ~DatabaseHelper();
        Card* selectJSonCard(char cardCode[]);
};

#endif