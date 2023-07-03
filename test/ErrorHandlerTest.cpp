#include "gtest/gtest.h"
#include "../src/Command.h"
#include "../src/CommandExecutor.h"
#include "../src/ErrorHandler.h"

TEST(ErrorHandlerTest, HandleError_Success) {
    // Create a command executor
    CommandExecutor executor;

    // Create an error handler with the executor
    ErrorHandler errorHandler(&executor);

    // Create an exception command
    ExceptionCommand exceptionCommand;

    // Create a logger
    Logger logger;

    // Create a log exception command with the exception command and logger
    LogExceptionCommand logExceptionCommand(&exceptionCommand, logger);

    // Call the error handler to handle the error
    errorHandler.HandleError(&logExceptionCommand);

    // Process the commands
    executor.ProcessCommands();

    // Check if the exception was logged
    EXPECT_EQ(logger.GetLastLog(), "Exception occurred: std::exception");
}
