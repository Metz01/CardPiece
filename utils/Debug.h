#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <string>

namespace Debug{
    // static HANDLE hConsole;
    void LogError(std::string text);
    void LogWarning(std::string text);
    void LogInfo(std::string text);
    void LogDebug(std::string text);
    void LogEnv(std::string text);
}

#endif