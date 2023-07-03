#ifndef COMMAND_H
#define COMMAND_H

#include <exception>
#include <iostream>
#include "Logger.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

class ExceptionCommand : public Command {
public:
    void Execute() override;
};

class RetryCommand : public Command {
private:
    Command* originalCommand;
    int retryCount;

public:
    RetryCommand(Command* command, int count);

    void Execute() override;
};

class LogExceptionCommand : public Command {
private:
    Command* originalCommand;
    Logger& logger;

public:
    LogExceptionCommand(Command* command, Logger& logger);

    void Execute() override;
};

#endif // COMMAND_H
