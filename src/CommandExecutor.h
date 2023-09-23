#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include "Command.h"
#include <queue>

class CommandExecutor {
private:
    std::queue<Command*> commandQueue;

public:
    void AddCommand(Command* command);
    void ProcessCommands();
};

#endif // COMMANDEXECUTOR_H
