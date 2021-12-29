cmake_minimum_required(VERSION 3.19)
project(hashTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(hashTable main.cpp HashTable.cpp HashTable.h Exceptions/Exception.h Exceptions/NullPointer.h Exceptions/NoValue.h)

add_subdirectory(Google_tests)