#include "CommandExecutor.h"
#include <iostream>

void CommandExecutor::AddCommand(Command* command) {
    commandQueue.push(command);
}

void CommandExecutor::ProcessCommands() {
    while (!commandQueue.empty()) {
        Command* command = commandQueue.front();
        commandQueue.pop();
        try {
            command->Execute();
        } catch (const std::exception& e) {
            // Handle the exception
            std::cout << "Exception caught: " << e.what() << std::endl;
            // (You can add your custom logic here, like logging the exception)
        }

    }
}
