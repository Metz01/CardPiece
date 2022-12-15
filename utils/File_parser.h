#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>

const std::string cardDB = "cardDB.csv";
const char token = ',';

bool checkCodePresence(std::string line, std::string code);

std::string findInfoOfCodeInFile(std::ifstream* file, std::string code);

std::vector<std::string> getLineInfo(std::ifstream* file, std::string code);

std::vector<std::string> getInfoFromId(std::string path, std::string code);