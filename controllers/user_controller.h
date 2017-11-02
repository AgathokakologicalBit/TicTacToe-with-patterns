// Copyright 2017 Ermishin Michael

#pragma once

#include "controller.h"


class UserController : public IController
{
public:
    void init() final;
    const Move do_turn(const Board& board) final;
};
