#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>

#include "File_parser.h"

bool checkCodePresence(std::string line, std::string code){
    std::string tempBuildString = "";
    for (char currentChar : line) {
        if (currentChar == token) return (tempBuildString.compare(code) == 0) ? true : false;
        else tempBuildString += currentChar;
    }return false;
}

std::string findInfoOfCodeInFile(std::ifstream* file, std::string code){
    std::string line;
    while (getline(*file, line)) {
        if(checkCodePresence(line, code)) return line;
    }return ""; //code not found in file
}

std::vector<std::string> getLineInfo(std::ifstream* file, std::string code){
    std::string tempBuildString = "";
    std::vector<std::string> info;
    for (char currentChar : (findInfoOfCodeInFile(file, code))) {
        if (currentChar == token || currentChar == '\n') {
            if(tempBuildString.compare("") != 0) info.push_back(tempBuildString);
            tempBuildString = "";
        } else tempBuildString += currentChar;
    } return info;
}

std::vector<std::string> getInfoFromId(std::string path, std::string code) {
    std::ifstream file(path);
    if (!file) std::cerr << "Can't open input file!";
    std::vector<std::string> data;
    data = getLineInfo(&file, code);
    return data;
}
