cmake_minimum_required(VERSION 3.8)
project(ttt)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp board.cpp board.h ecell.h ewinner.h board_printer.cpp board_printer.h board_printer_factory.h)
add_executable(ttt ${SOURCE_FILES})