cmake_minimum_required(VERSION 3.10)

project(TicTacToe VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR cmake-build-debug)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TicTacToe
        src/TicTacToe.cpp
        src/game/Board.cpp
        src/game/Board.h
        src/Utils.h
        src/view/Menu.cpp
        src/view/Menu.h)

add_executable(TicTacToe_TestSuite
        src/game/Board.cpp
        src/game/Board.h
        test/game/Board_Test.cpp)

target_link_libraries(TicTacToe_TestSuite gtest_main)
include(GoogleTest)
gtest_discover_tests(TicTacToe_TestSuite)
