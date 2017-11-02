// Copyright 2017 Ermishin Michael

#include "user_controller.h"
#include "../input/input_manager.h"
#include "../game/game.h"


void UserController::init()
{
    input = InputManager::get().console();
}

const Move UserController::do_turn(const Board& board)
{
    input->write(" ", "Place", Game::get().current_symbol(), "on (x, y): ");
    auto x = input->read<uint16_t>(),
         y = input->read<uint16_t>();

    return Move {x, y};
}
