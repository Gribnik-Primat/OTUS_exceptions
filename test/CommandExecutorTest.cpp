#include "gtest/gtest.h"
#include "../src/Command.h"
#include "../src/CommandExecutor.h"

TEST(CommandExecutorTest, ProcessCommands_Success) {
    // Create a command executor
    CommandExecutor executor;

    // Create an exception command
    ExceptionCommand exceptionCommand;

    // Add the exception command to the executor
    executor.AddCommand(&exceptionCommand);

    // Process the commands
    executor.ProcessCommands();
}
