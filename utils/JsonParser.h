#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonDocument>
#include <QJsonObject>

class JsonParser
{
    public:
        static std::string jsonKeytoString(QJsonObject json, std::string key);
        static int jsonKeytoInt(QJsonObject json, std::string key);
        static QJsonObject jsonKeytoJsonObject(QJsonObject json, std::string key);
        JsonParser();
        ~JsonParser();
};

#endif
