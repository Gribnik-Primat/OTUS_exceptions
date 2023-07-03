#include "Command.h"

void ExceptionCommand::Execute() {
    throw std::exception();
}

RetryCommand::RetryCommand(Command* command, int count)
    : originalCommand(command), retryCount(count) {}

void RetryCommand::Execute() {
    for (int i = 0; i < retryCount; i++) {
        try {
            originalCommand->Execute();
            return;
        } catch (...) {
            // Ignore the exception and retry
        }
    }
    throw std::exception();
}

LogExceptionCommand::LogExceptionCommand(Command* command, Logger& logger)
    : originalCommand(command), logger(logger) {}

void LogExceptionCommand::Execute() {
    try {
        originalCommand->Execute();
    } catch (const std::exception& ex) {
        // Log the exception
        logger.Log("Exception caught: " + std::string(ex.what()));
    } catch (...) {
        // Log other types of exceptions
        logger.Log("Unknown exception caught.");
    }
}
