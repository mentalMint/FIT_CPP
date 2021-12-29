cmake_minimum_required(VERSION 3.19)
project(ticTacToeMVC)

set(CMAKE_CXX_STANDARD 14)

add_executable(ticTacToeMVC main.cpp Players/Player.h TicTacToeModel.cpp TicTacToeModel.h TicTacToeView.cpp TicTacToeView.h TicTacToeController.cpp TicTacToeController.h Players/Human.cpp Players/Human.h Players/Computer.cpp Players/Computer.h)