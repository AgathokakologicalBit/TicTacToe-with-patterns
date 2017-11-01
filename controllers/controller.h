// Copyright 2017 Ermishin Michael

#pragma once

#include "../game/board/board.h"
#include "../game/move.h"
#include "../game/game.h"

/**
 * Game controller interface
 */
class IController
{
public:
    // Pure virtual methods (must be overwritten)

    virtual void init(const Game& game) = 0;
    virtual const Move do_turn(const Board& board) = 0;
};
