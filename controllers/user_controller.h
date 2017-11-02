// Copyright 2017 Ermishin Michael

#pragma once

#include "controller.h"
#include "../input/console.h"


class UserController : public IController
{
private:
    Console* input = nullptr;

public:
    void init() final;
    const Move do_turn(const Board& board) final;
};
