cmake_minimum_required(VERSION 3.8)
project(ttt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

set(SOURCE_FILES
        main.cpp
        game/board/board.cpp
        game/board/board.h
        ecell.h
        ewinner.h
        game/board/board_printer.cpp
        game/board/board_printer.h
        game/board/board_printer_factory.h
        controllers/controller.h
        game/move.h
        controllers/user_controller.cpp
        controllers/user_controller.h
        input/console.h
        input/linux/console.cpp
        input/windows/console.cpp
        input/console.cpp
        input/input_manager.cpp
        input/input_manager.h
        game/game.cpp
        game/game.h
)

add_executable(ttt ${SOURCE_FILES})
