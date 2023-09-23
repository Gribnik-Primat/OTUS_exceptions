#include "gtest/gtest.h"
#include "../src/Command.h"
#include "../src/CommandExecutor.h"
#include "../src/ErrorHandler.h"

TEST(CommandTest, RetryCommand_Execute_Success) {
    // Create an exception command
    ExceptionCommand exceptionCommand;

    // Create the retry command with 2 retries
    RetryCommand retryCommand(&exceptionCommand, 2);

    // Execute the retry command
    EXPECT_THROW(retryCommand.Execute(), std::exception);
}
