#include "gtest/gtest.h"
#include "../src/Logger.h"

TEST(LoggerTest, Log_Success) {
    testing::internal::CaptureStdout();

    std::string message = "Test log message";
    Logger logger;
    logger.Log(message);

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Logging: " + message + "\n");
}
