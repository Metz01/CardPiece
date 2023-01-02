#include "Debug.h"
#include <iostream>

/*

export const black = "\x1b[30m"
export const red = "\x1b[31m" X
export const green = "\x1b[32m" X
export const yellow = "\x1b[33m" X
export const blue = "\x1b[34m" X
export const magenta = "\x1b[35m"
export const cyan = "\x1b[36m" X
export const white = "\x1b[37m"

*/

void Debug::LogError(std::string text){
    std::cout << "\x1b[31m[Error]: " << text << "\033[0m" << std::endl;
}

void Debug::LogWarning(std::string text){
    std::cout << "\x1b[33m[Warning]: " << text << "\033[0m" << std::endl;
}

void Debug::LogInfo(std::string text){
    std::cout << "\x1b[32m[Info]: " << text << "\033[0m" << std::endl;
}

void Debug::LogDebug(std::string text){
    std::cout << "\x1b[34m[Debug]: " << text << "\033[0m" << std::endl;
}

void Debug::LogEnv(std::string text){
    std::cout << "\x1b[35m[Env]: " << "----- " << text << " -----" << "\033[0m" << std::endl;
}