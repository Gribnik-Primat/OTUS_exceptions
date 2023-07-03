cmake_minimum_required(VERSION 3.10)
project(ExceptionHandling)

set(CMAKE_CXX_STANDARD 11)

# Locate GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include directories
include_directories(include)

# Add source files
set(SOURCES
    src/Command.cpp
    src/CommandExecutor.cpp
    src/ErrorHandler.cpp
    src/Logger.cpp
)

# Add executable for tests
add_executable(ExceptionHandlingTest
    test/CommandTest.cpp
    test/CommandExecutorTest.cpp
    test/ErrorHandlerTest.cpp
    test/LoggerTest.cpp
    test/main.cpp
    ${SOURCES}
)
target_link_libraries(ExceptionHandlingTest ${GTEST_LIBRARIES} pthread gtest gmock)
