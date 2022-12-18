 #include "JsonParser.h" 
 #include <QString>
 
 /// @brief returns the info of the key in the json object as a string
 /// @param json all the info of the card
 /// @param key the key of the info you want to get
 /// @return the info of the key in the json object as a string
 std::string JsonParser::jsonKeytoString(QJsonObject json, std::string key){
    return json.value(QString::fromStdString(key)).toString().toStdString();
 }

/// @brief returns the info of the key in the json object as an int
/// @param json all the info of the card
/// @param key the key of the info you want to get
/// @return the info of the key in the json object as an int
 int JsonParser::jsonKeytoInt(QJsonObject json, std::string key){
    return json.value(QString::fromStdString(key)).toInt();
 }

/// @brief returns the info of the key in the json object as a QJsonObject
/// @param json all the info of the card
/// @param key the key of the info you want to get
/// @return the info of the key in the json object as a QJsonObject
 QJsonObject JsonParser::jsonKeytoJsonObject(QJsonObject json, std::string key){
    return json.value(QString::fromStdString(key)).toObject();
 }