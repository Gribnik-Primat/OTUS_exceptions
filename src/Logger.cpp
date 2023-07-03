#include "Logger.h"

void Logger::Log(const std::string& message) {
    std::cout << "Logging: " << message << std::endl;
    lastLog = message;
}

std::string Logger::GetLastLog() const {
    return lastLog;
}
