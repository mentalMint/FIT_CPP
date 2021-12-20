cmake_minimum_required(VERSION 3.19)
project(factory)

set(CMAKE_CXX_STANDARD 14)

add_executable(factory main.cpp WorkflowExecutor.cpp WorkflowExecutor.h WorkflowParser.cpp WorkflowParser.h SimpleBlocks/ReadFile.h Common/BlockFactory.h SimpleBlocks/Sort.h Common/IBlockMaker.h Common/BlockMaker.h SimpleBlocks/Sort.cpp SimpleBlocks/ReadFile.cpp Exceptions/UndefinedBlock.h Exceptions/WrongWorkflowDescription.h Exceptions/WrongNumberOfArguments.h Exceptions/Exception.h SimpleBlocks/WriteFile.cpp SimpleBlocks/WriteFile.h SimpleBlocks/Grep.cpp SimpleBlocks/Grep.h Exceptions/RegisteredBlock.h Exceptions/FileOpeningFail.h SimpleBlocks/Dump.cpp SimpleBlocks/Dump.h)