cmake_minimum_required(VERSION 3.10)

project(TicTacToe VERSION 1.0.1 LANGUAGES CXX)

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
        src/view/Menu.h
        src/game/Game.cpp
        src/game/Game.h
        src/game/player/Player.cpp
        src/game/player/Player.h
        src/game/player/HumanPlayer.cpp
        src/game/player/HumanPlayer.h
        src/game/player/ComputerPlayer.cpp
        src/game/player/ComputerPlayer.h)

add_executable(TicTacToe_TestSuite
        src/view/Menu.cpp
        src/view/Menu.h
        src/game/Board.cpp
        src/game/Board.h
        src/game/player/Player.cpp
        src/game/player/Player.h
        src/game/player/HumanPlayer.cpp
        src/game/player/HumanPlayer.h
        src/game/Game.cpp
        src/game/Game.h
        src/game/player/ComputerPlayer.cpp
        src/game/player/ComputerPlayer.h
        test/view/Menu_Test.cpp
        test/game/Board_Test.cpp
        test/game/Game_Test.cpp
        test/game/player/HumanPlayer_Test.cpp
        test/game/player/ComputerPlayer_Test.cpp)

target_link_libraries(TicTacToe_TestSuite gtest_main)
include(GoogleTest)
gtest_discover_tests(TicTacToe_TestSuite)
