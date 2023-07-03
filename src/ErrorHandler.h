#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "Command.h"
#include "CommandExecutor.h"

class ErrorHandler {
private:
    CommandExecutor* executor;

public:
    ErrorHandler(CommandExecutor* executor);
    void HandleError(Command* command);
};

#endif // ERRORHANDLER_H
