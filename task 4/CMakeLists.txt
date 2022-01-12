cmake_minimum_required(VERSION 3.19)
project(ticTacToeMVC)

set(CMAKE_CXX_STANDARD 14)

add_executable(ticTacToeMVC main.cpp Players/Player.h Model.cpp Model.h
        Controller.cpp Controller.h Players/Human.h
        Players/Computer.h Observer/Observable.h Observer/Observer.h Observer/Observable.cpp View.cpp View.h
        Players/Player.h Players/Human.h Players/Computer.h Exceptions/Exception.h Exceptions/NullPointer.h Exceptions/WrongGameState.h)