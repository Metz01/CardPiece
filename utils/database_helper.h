#ifndef __DATABASE_HELPER_H__
#define __DATABASE_HELPER_H__

#include <string>
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

class DatabaseHelper
{
private:
public:
    static QJsonDocument database;
    DatabaseHelper();
    /* ~DatabaseHelper(); */
    static QJsonObject getJsonInfo(std::string cardCode);
    static Card *selectJSonCard(std::string cardCode);
    static bool isLeader(std::string cardCode);
};

#endif
