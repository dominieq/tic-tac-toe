cmake_minimum_required(VERSION 3.10)

project(TicTacToe VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR cmake-build-debug)

add_executable(TicTacToe src/TicTacToe.cpp src/game/Board.cpp src/game/Board.h src/Utils.h src/view/Menu.cpp src/view/Menu.h)
