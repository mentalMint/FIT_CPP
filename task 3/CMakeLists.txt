cmake_minimum_required(VERSION 3.19)
project(factory)

set(CMAKE_CXX_STANDARD 14)

add_executable(factory main.cpp WorkflowExecutor.cpp WorkflowExecutor.h WorkflowParser.cpp WorkflowParser.h ReadFile.h BlockFactory.h Sort.h IBlockMaker.h BlockMaker.h Sort.cpp ReadFile.cpp)