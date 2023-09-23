#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
private:
    std::string lastLog;

public:
    void Log(const std::string& message);
    std::string GetLastLog() const;
};

#endif
