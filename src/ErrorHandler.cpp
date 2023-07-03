#include "ErrorHandler.h"

ErrorHandler::ErrorHandler(CommandExecutor* executor) : executor(executor) {}

void ErrorHandler::HandleError(Command* command) {
    RetryCommand* retryCommand = new RetryCommand(command, 2);
    executor->AddCommand(retryCommand);
}
